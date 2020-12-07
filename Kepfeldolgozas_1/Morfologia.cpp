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
//int struct_element_type = 0; // Strukturalo elem tipusa 0: Teglalap; 1: Kereszt; 2: Ellipszis.
//int struct_element_size = 0; // Strukturalo elem merete. Mekkora a "radír" ha eroziot vegzunk
//
//void erode_cb(int, void*) {
//   int element_type = 0;
//   if (struct_element_type == 0)
//       element_type = MORPH_RECT;
//   else if (struct_element_type == 1)
//       element_type = MORPH_CROSS;
//   else
//       element_type = MORPH_ELLIPSE;
//
//   Mat element = getStructuringElement(element_type, Size(2 * struct_element_size +1,2*struct_element_size+1));
//
//   erode(src_gray, dst, element);
//
//   imshow("Erode", dst);
//}
//
//void dilate_cb(int, void*) {
//   int element_type = 0;
//   if (struct_element_type == 0)
//       element_type = MORPH_RECT;
//   else if (struct_element_type == 1)
//       element_type = MORPH_CROSS;
//   else
//       element_type = MORPH_ELLIPSE;
//
//   Mat element = getStructuringElement(element_type, Size(2 * struct_element_size + 1, 2 * struct_element_size + 1));
//
//   dilate(src_gray, dst, element);
//
//   imshow("Dilate", dst);
//}
//
//int main()  // dilattáció + erozio (lyukak tomese és csiszolasa)
//{
//   src = imread("butterfly.jpg");
//   cvtColor(src, src_gray, COLOR_BGR2GRAY);
//
//   namedWindow("Erode", WINDOW_AUTOSIZE);
//   createTrackbar("Element type: ", "Erode", &struct_element_type, 2, erode_cb);
//   createTrackbar("Element size: ", "Erode", &struct_element_size, 20, erode_cb);
//   erode_cb(0, 0);    
//   
//   namedWindow("Dilate", WINDOW_AUTOSIZE);
//   createTrackbar("Element type: ", "Dilate", &struct_element_type, 2, dilate_cb);
//   createTrackbar("Element size: ", "Dilate", &struct_element_size, 20, dilate_cb);
//   dilate_cb(0, 0);
//
//   waitKey(0);
//   return 0;
//}