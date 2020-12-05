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
    // Olvassa be a szita.jpg nevû képet (színes képként).
    src = imread("szita.jpg");
    //imshow("Szita original", src);

    // Végezzen Gauss elmosást 5x5-ös kernelmérettel,1.5-ös sigma paraméterrel.
    GaussianBlur(src, dst, Size(5, 5), 1.5);

    // Alakítsa át HSV színtérbe az elmosott képet.
    Mat hsv;
    cvtColor(dst, hsv, CV_BGR2HSV);

    waitKey(0);
    return 0;
}