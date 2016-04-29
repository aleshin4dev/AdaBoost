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
		images[i] = imread(anOut.str());
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

	for (int i = 0; i < NumofIm; i++)
	{
		ostringstream anOut; // выходной поток для создания строк
		anOut << "C:\\LearningImages\\" << i + 1 << ".jpg";
		imageFinal = imread(anOut.str());
		resize(imageFinal, imageFinal, Size(minCol, minRow));
		imwrite(anOut.str(), imageFinal);
	}
}