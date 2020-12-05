#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <vector>

using namespace std;
using namespace cv;

Mat src, src_gray, dst, edges;



int main()
{
    // Olvassa be a szita.jpg nev� k�pet (sz�nes k�pk�nt).
    src = imread("szita.jpg");
    //imshow("Szita original", src);

    // V�gezzen Gauss elmos�st 5x5-�s kernelm�rettel,1.5-�s sigma param�terrel.
    GaussianBlur(src, dst, Size(5, 5), 1.5);

    // Alak�tsa �t HSV sz�nt�rbe az elmosott k�pet.
    Mat hsv;
    cvtColor(dst, hsv, CV_BGR2HSV);

    waitKey(0);
    return 0;
}