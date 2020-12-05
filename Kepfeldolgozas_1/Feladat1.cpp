#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <vector>

using namespace std;
using namespace cv;

Mat src, src_gray, dst, bin_img;



int main()
{
    // #1 Olvassa be a szita.jpg nev� k�pet (sz�nes k�pk�nt).
    src = imread("szita.jpg");
    //imshow("Szita original", src);

    // #2 V�gezzen Gauss elmos�st 5x5-�s kernelm�rettel,1.5-�s sigma param�terrel.
    GaussianBlur(src, dst, Size(5, 5), 1.5);
    //imshow("Szita mosott", dst);

    // #3 Alak�tsa �t HSV sz�nt�rbe az elmosott k�pet.
    Mat hsv;
    //cvtColor(dst, hsv, CV_BGR2HSV);
    cvtColor(dst, hsv, COLOR_BGR2HSV);

    // #4 A HUE csatorn�ja felhaszn�l�s�val hozza l�tre a szitak�t� sz�rny�n l�v� folt maszkj�t (a sz�rnyt� is megjelenthet).
    Mat planes[3];
    split(hsv, planes);
    // Szegment�l�s.
    // Kik�sz�b�lj�k a sz�tdarabolt k�pet, ahol 45 (mi adjuk meg) intenzit�s feletti a k�p, ott legyen fekete (255), ahol nem ott 0. 
    threshold(planes[0], bin_img, 45, 255, 0); // 0, mert bin�risat k�rt
    //imshow("Binaris szita", bin_img);

    // #5 Hat�rozza meg a k�ls� kont�rokat maszkon, majd keresse meg a legnagyobb ter�let� foltot.
    // szegment�l�s ut�ni ut�feldolgoz�s (sim�bb �lek) - b�nusz (?)
    int struct_element_size = 6;
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2 * struct_element_size +1,2*struct_element_size+1));
    erode(bin_img, bin_img, element);
    dilate(bin_img, bin_img, element);
    //imshow("Erod�lt k�p", bin_img);

    Mat canny_output;
    int thresh_low = 100;
    // Detekt�ljuk az �leket.
    Canny(bin_img, canny_output, thresh_low, 2.0 * thresh_low);
    //imshow("Canny", canny_output);

    // #6 Rajzolja ki a kont�rt az eredetik�p m�solat�ra 2 pont vastags�ggal, z�ld sz�nnel.
    Mat drawing = src.clone();
    // a kont�r pontok halmazaib�l �ll� vektorokb�l �p�l fel
    vector<vector<Point>> contours;
    vector<Vec4i> h;
    findContours(canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // #7 �rja a standard kimenetre a folt ter�let�t.
    for (size_t i = 0; i < contours.size(); i++)
    {
        Scalar color = Scalar(0, 255, 0); // z�ld sz�n
        drawContours(drawing, contours, (int)i, color, 2, LINE_8); // 2 = vonalvastags�g
        cout << i+1 << " edik kontur merete " << contourArea(contours[i]) << endl; // kont�rok (folt) ter�lete
        // az�rt vannak p�ross�val mert k�ls� bels� kont�rok is vannak
        // el�g a legnagyobbat ki�ratni mert az a feladat �ltal k�rt kont�r
    }
    // #8 Jelen�tse meg az maszkot �s az eredm�nyk�pet �s v�rakoztasson karakter le�t�s�ig.
    imshow("Konturozott kep", drawing);


    waitKey(0);
    return 0;
}