//#include <iostream>
//#include "opencv2/imgproc/imgproc.hpp"
//#include "opencv2/highgui.hpp"
//#include "opencv2/imgcodecs.hpp"
//#include <vector>
//
//using namespace std;
//using namespace cv;
//
//Mat src, src_gray, dst;
//int thresh = 3;
//int thresh_type = 0;
//
//void kuszobol(int, void*) {
//   /* THRESH TYPE: 0 Binary - bináris
//   *               1 bináris inverze
//   *               2 Threshold Thruncated
//   *               3 Threshold to Zero
//   *               4 Threshold to Zero, inv.
//   */
//   threshold(src_gray, dst, thresh, 255, thresh_type);
//   imshow("Kuszoboles", dst);
//}
//
//int main()
//{
//   src = imread("baboon.jpg");
//   // Convert color
//   cvtColor(src, src_gray, CV_BGR2GRAY); // színes szürkévé alakítása
//
//   //dst = src_gray.clone();
//   //dst.setTo(0);
//
//   //double kuszob = mean(src_gray)[0]+30;
//
//   //for (int y = 0; y < src_gray.rows; y++)
//   //    for (int x = 0; x < src_gray.cols; x++)
//   //        if (src_gray.at<uchar>(y, x) < kuszob)
//   //            dst.at<uchar>(y, x) = src_gray.at<uchar>(y, x);
//
//   //imshow("Kuszobolt kep", dst);
//
//   namedWindow("Kuszoboles", WINDOW_AUTOSIZE);
//   createTrackbar("Kuszobolo tipusa: ", "Kuszoboles", &thresh_type, 4, kuszobol);
//   createTrackbar("Kuszob", "Kuszoboles", &thresh, 250, kuszobol);
//
//   kuszobol(0, 0);
//
//   waitKey(0);
//   return 0;
//}