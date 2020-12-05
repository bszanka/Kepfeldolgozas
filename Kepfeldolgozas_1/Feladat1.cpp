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
    // #1 Olvassa be a szita.jpg nevû képet (színes képként).
    src = imread("szita.jpg");
    //imshow("Szita original", src);

    // #2 Végezzen Gauss elmosást 5x5-ös kernelmérettel,1.5-ös sigma paraméterrel.
    GaussianBlur(src, dst, Size(5, 5), 1.5);
    //imshow("Szita mosott", dst);

    // #3 Alakítsa át HSV színtérbe az elmosott képet.
    Mat hsv;
    //cvtColor(dst, hsv, CV_BGR2HSV);
    cvtColor(dst, hsv, COLOR_BGR2HSV);

    // #4 A HUE csatornája felhasználásával hozza létre a szitakötõ szárnyán lévõ folt maszkját (a szárnytõ is megjelenthet).
    Mat planes[3];
    split(hsv, planes);
    // Szegmentálás.
    // Kiküszöböljük a szétdarabolt képet, ahol 45 (mi adjuk meg) intenzitás feletti a kép, ott legyen fekete (255), ahol nem ott 0. 
    threshold(planes[0], bin_img, 45, 255, 0); // 0, mert binárisat kért
    //imshow("Binaris szita", bin_img);

    // #5 Határozza meg a külsõ kontúrokat maszkon, majd keresse meg a legnagyobb területû foltot.
    // szegmentálás utáni utófeldolgozás (simább élek) - bónusz (?)
    int struct_element_size = 6;
    Mat element = getStructuringElement(MORPH_ELLIPSE, Size(2 * struct_element_size +1,2*struct_element_size+1));
    erode(bin_img, bin_img, element);
    dilate(bin_img, bin_img, element);
    //imshow("Erodált kép", bin_img);

    Mat canny_output;
    int thresh_low = 100;
    // Detektáljuk az éleket.
    Canny(bin_img, canny_output, thresh_low, 2.0 * thresh_low);
    //imshow("Canny", canny_output);

    // #6 Rajzolja ki a kontúrt az eredetikép másolatára 2 pont vastagsággal, zöld színnel.
    Mat drawing = src.clone();
    // a kontúr pontok halmazaiból álló vektorokból épül fel
    vector<vector<Point>> contours;
    vector<Vec4i> h;
    findContours(canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

    // #7 Írja a standard kimenetre a folt területét.
    for (size_t i = 0; i < contours.size(); i++)
    {
        Scalar color = Scalar(0, 255, 0); // zöld szín
        drawContours(drawing, contours, (int)i, color, 2, LINE_8); // 2 = vonalvastagság
        cout << i+1 << " edik kontur merete " << contourArea(contours[i]) << endl; // kontúrok (folt) területe
        // azért vannak párossával mert külsõ belsõ kontúrok is vannak
        // elég a legnagyobbat kiíratni mert az a feladat által kért kontúr
    }
    // #8 Jelenítse meg az maszkot és az eredményképet és várakoztasson karakter leütéséig.
    imshow("Konturozott kep", drawing);


    waitKey(0);
    return 0;
}