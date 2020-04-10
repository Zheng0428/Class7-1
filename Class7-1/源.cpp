#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
int main()
{
	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\a\\lena.jpg", 1);
	if (srcMat.empty())  return -1;

	float angle = -10.0, scale = 1;
	cv::Point2f center(srcMat.cols * 0.5, srcMat.rows * 0.5);
	Mat affine_matrix = cv::getRotationMatrix2D(center, angle, scale);
	cv::Rect bbox = cv::RotatedRect(center, srcMat.size(), angle).boundingRect();
	affine_matrix.at<double>(0, 2) += bbox.width / 2 - center.x;
	affine_matrix.at<double>(1, 2) += bbox.height / 2 - center.y;
	cv::warpAffine(srcMat, dstMat, affine_matrix, bbox.size());
	cv::imshow("src", srcMat);
	cv::imshow("dst", dstMat);
	cv::waitKey(0);
}