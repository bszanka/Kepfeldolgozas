#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <vector>
#include <algorithm>
using namespace std;
using namespace cv;

Mat src, src_gray, src_gray_resize, dst, bin_img;

bool compareContourArea(vector<Point> contour1, vector<Point> contour2)
{
	double i = fabs(contourArea(Mat(contour1)));
	double j = fabs(contourArea(Mat(contour2)));
	return true; // ????
}

int main()
{
	src = imread("shogi.bmp");
	//imshow("Shogi original", src);
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	resize(src_gray, src_gray_resize, Size(700,700));
	//imshow("Shogi resize", src_gray_resize);

	Mat canny_output;
	int thresh = 100;
	Canny(src_gray_resize, canny_output, thresh, 2 * thresh);
	imshow("Canny", canny_output);


	// rajzolunk egy fekete alapra (Mat:: névtér nem lett addolva)
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC1);

	vector<vector<Point>> contours;
    vector<Vec4i> h;
    findContours(canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);

	sort(contours.begin(), contours.end(), compareContourArea);

    for (size_t i = 0; i < contours.size(); i++)
    {
        Scalar color = Scalar(255, 255, 255);
        drawContours(drawing, contours, (int)i, color, -1); // -1 beleveszi a belsejét is (?)
    }

	Mat babu = src_gray_resize & drawing;
	imshow("babumaszk", drawing);
	imshow("rajzocska", babu);
	// mentés képre
	//imwrite("babuX.png", babu);

	waitKey(0);
	return 0;
}