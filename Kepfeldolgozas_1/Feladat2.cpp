#include <iostream>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgcodecs.hpp"
#include <vector>
#include <algorithm>
using namespace std;
using namespace cv;

Mat src, src_gray, src_gray_resize, dst, bin_img;

bool compareContourAra(vector<Point> contour1, vector<Point> contour2)
{

	double i = fabs(contourArea(Mat(contour1)));
	double j = fabs( contourArea(Mat(contour2)));
	
	return (i > j);
}

int main()
{
	// #1 Olvassa be a shogi.bmp képet.
	src = imread("shogi.bmp");
	//imshow("Shogi original", src);
	cvtColor(src, src_gray, COLOR_BGR2GRAY);
	resize(src_gray, src_gray_resize, Size(700,700));
	//imshow("Shogi resize", src_gray_resize);

	Mat canny_output;
	int thresh = 100;
	Canny(src_gray_resize, canny_output, thresh, 2 * thresh);
	//imshow("Canny", canny_output);

	
	// rajzolunk egy fekete alapra (Mat:: névtér nem lett addolva)
	
	vector<vector<Point>> contours;
    vector<Vec4i> h;
	Mat drawing = Mat::zeros(canny_output.size(), CV_8UC1);
	
	findContours(canny_output, contours, RETR_TREE, CHAIN_APPROX_SIMPLE);
	sort(contours.begin(), contours.end(), compareContourAra);
	Mat babu = src_gray_resize & drawing;

	// #2 Másoljon át minden bábut egy-egy képre úgy, hogy a körvonala körül 5 pixeles keret legyen.

	for (size_t i = 0; i < contours.size(); i++)
	{
		if (((int)contourArea(Mat(contours[i]))) > 2000 && ((int)contourArea(Mat(contours[i]))) < 3000) {
			drawing = Mat::zeros(canny_output.size(), CV_8UC1);
			Scalar color = Scalar(255, 255, 255);
			drawContours(drawing, contours, (int)i, color, -1); //-1 kontúr által határolt objektum belsejét is hozzá veszi
			cout << (int)i << " edik kontur merete " << contourArea(Mat(contours[i])) << endl;
			// #3 Mentse el a kapott képeket sorszámozottan.
			babu = src_gray_resize & drawing;
			std::string fname = "babu";
			fname.append(std::to_string(i));
			fname.append(".png");
			cout << fname << endl;
			try
			{
				imwrite(fname, babu);

			}
			catch (const std::exception&)
			{
			}
		}
		else
			continue;
	}


	waitKey(0);
	return 0;
}