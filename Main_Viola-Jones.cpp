#include "iostream"
#include "Viola-Jones.h"
#include "math.h"
#include "opencv/cv.hpp"
#include "opencv/highgui.h"
using namespace cv;
using namespace std;
void main()
{
	Mat img = imread("C:\\LearningImages\\01.jpg");
	int cols = img.cols, rows = img.rows;
	size_t **A;
	A = new size_t*[rows];
	for (int i = 0; i < rows; i++) A[i] = new size_t[cols];
	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			A[i][j] = img.at<uchar>(i, j);
	A = funcIntegralImage(A, cols, rows);
}