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
//int kernel_size = 3;
//
//void gauss_filter(int, void*) {
//   if (kernel_size % 2 == 0)
//       kernel_size++;
//
//   GaussianBlur(src, dst, Size(kernel_size, kernel_size), 0, 0);
//   imshow("Gauss szures", dst);
//}
//
//void mean_filter(int, void*) {
//   if (kernel_size % 2 == 0)
//       kernel_size++;
//
//   blur(src, dst, Size(kernel_size, kernel_size));
//   imshow("Mean szures", dst);
//}
//
//void median_filter(int, void*) {
//   if (kernel_size % 2 == 0)
//       kernel_size++;
//
//   medianBlur(src, dst, kernel_size);
//   imshow("Median szures", dst);
//}
//
//
//int main()
//{
//   src = imread("baboon.jpg");
//   // Convert color
//   cvtColor(src, src_gray, CV_BGR2GRAY); // színes szürkévé alakítása
//
//   namedWindow("Gauss szures", WINDOW_AUTOSIZE);
//   namedWindow("Mean szures", WINDOW_AUTOSIZE);
//   namedWindow("Median szures", WINDOW_AUTOSIZE);
//
//   createTrackbar("Kernel szures: ", "Gauss szures", &kernel_size, 100, gauss_filter);
//   gauss_filter(0, 0); // inicializaljuk
//
//   createTrackbar("Kernel szures: ", "Mean szures", &kernel_size, 100, mean_filter);
//   mean_filter(0, 0); // inicializaljuk
//
//   createTrackbar("Kernel szures: ", "Median szures", &kernel_size, 100, median_filter);
//   median_filter(0, 0); // inicializaljuk
//
//
//   waitKey(0);
//   return 0;
//}