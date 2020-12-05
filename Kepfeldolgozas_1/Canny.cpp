//#include <iostream>
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//Mat src, src_gray, dst, edges;
//int low_thresh = 0;
//int max_low_thresh = 100;
//int thresh_type = 0;
//
//void canny_elek(int, void*) {
//    // Kernel size-t beégetjük 3x3-ra. Utána a Sigma értékek
//    GaussianBlur(src_gray, dst, Size(3, 3), 1.2, 1.5);
//    Canny(dst, edges, low_thresh, 1.5 * low_thresh, 3);
//    imshow("Canny", edges);
//}
//
//int main() // Éltérképek.
//{
//    src = imread("butterfly.jpg");
//    // A színes képet FF-re konvertáljuk
//    cvtColor(src, src_gray, COLOR_BGR2GRAY);
//
//    namedWindow("Canny", WINDOW_AUTOSIZE);
//    // Cím szerinti paraméterátadás a low-nál! hogy megmaradjon (?)
//    createTrackbar("Min Threshold: ", "Canny", &low_thresh, max_low_thresh, canny_elek);
//    canny_elek(0, 0);
//
//    waitKey(0);
//    return 0;
//}