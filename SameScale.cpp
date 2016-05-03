#include "iostream"
#include "opencv/cv.hpp"
#include "opencv/highgui.h"

#include <sstream> // заголовочный файл для потока записи в строку
#include <string>

using namespace cv;
using namespace std;

void AlsameScale()
{
	const int NumofIm = 68;
	Mat *images = new Mat[NumofIm], imageFinal;
	for (int i = 0; i < NumofIm; i++)
	{
		ostringstream anOut; // выходной поток для создания строк
		anOut << "C:\\LearningImages\\" << i + 1 << ".jpg";
		images[i] = imread(anOut.str(), IMREAD_GRAYSCALE).clone();
	}
	int *cols, *rows, minCol, minRow;
	cols = new int[NumofIm];
	rows = new int[NumofIm];
	for (int i = 0; i < NumofIm; i++)
	{
		cols[i] = images[i].cols;
		rows[i] = images[i].rows;
	}

	minCol = *min_element(cols, cols + NumofIm);
	minRow = *min_element(rows, rows + NumofIm);

	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);
	for (int i = 0; i < NumofIm; i++)
	{
		ostringstream anOut; // выходной поток для создания строк
		anOut << "C:\\LearningImages\\r" << i + 1 << ".png";
		resize(images[i], images[i], Size(minCol, minRow));
		imwrite(anOut.str(), images[i], compression_params);
	}
	/*Mat mat(Size(200, 200), CV_8UC1);
	Mat GG = imread("333.jpg");
	GG *= 4;
	//resize(GG, GG, Size(1000, 1000));
	imwrite("444.jpg",GG);*/
	//imshow("1", GG);
	//waitKey(0);

	//cout << minCol << " " << minRow << endl;


	//Mat img = imread("333.jpg", IMREAD_GRAYSCALE).clone();
	/*cout << img.rows << " " << img.cols << endl;
	cin.get();
	for (int i = 0; i < img.rows; i++)
		for (int j = 0; j < img.cols; j++)
			if ((i % 20 == 10 && j % 2 == 1) || (j % 50 == 25 && i % 2 == 1))
			{
				img.at<uchar>(i, j) = 255;
			}*/
	/*resize(img, img, Size(1000, 1000));
	imshow("1", img);
	waitKey(0);

	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);
	imwrite("444.jpg", img, compression_params);*/
}