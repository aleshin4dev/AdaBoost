#include "iostream"
#include "opencv/cv.hpp"
#include "opencv/highgui.h"

#include <sstream> // заголовочный файл для потока записи в строку
#include <string>

using namespace cv;
using namespace std;

void AlsameScale() {
	const int NumofIm = 10;
	Mat *images = new Mat[NumofIm], imageFinal;

	for (int i = 0; i < NumofIm; i++) {
		ostringstream anOut; // выходной поток для создания строк
		anOut << "/home/aleshin8sergey/Images/" << i + 1 << ".jpg";
		images[i] = imread(anOut.str(), IMREAD_GRAYSCALE).clone();
	}

	int *cols, *rows, minCol, minRow;
	cols = new int[NumofIm];
	rows = new int[NumofIm];

	for (int i = 0; i < NumofIm; i++) {
		cols[i] = images[i].cols;
		rows[i] = images[i].rows;
	}

	minCol = *min_element(cols, cols + NumofIm);
	minRow = *min_element(rows, rows + NumofIm);

	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	for (int i = 0; i < NumofIm; i++) {
		ostringstream anOut; // выходной поток для создания строк
		anOut << "/home/aleshin8sergey/Images/r" << i + 1 << ".png";
		resize(images[i], images[i], Size(minCol, minRow));
		imwrite(anOut.str(), images[i], compression_params);
	}
}
