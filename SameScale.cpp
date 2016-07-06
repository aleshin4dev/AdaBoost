#include "iostream"
#include "opencv/cv.hpp"
#include "opencv/highgui.h"

#include <sstream>
#include <string>

#include "readFileNamesInDir.h"

using namespace cv;
using namespace std;

void AlsameScale() {
	vector<string> namesIm = vector<string>();
	namesIm = getFileNames();
	istringstream iss (namesIm[namesIm.size() - 1], istringstream::in);
	int NumofImwithFace;
	iss >> NumofImwithFace;
	int numEl = namesIm.size() - 5;
	Mat *images = new Mat[numEl];
	int point = 0;
	for (int i = 0; i < NumofImwithFace; i++) {
		if ((namesIm[i] != ".") && (namesIm[i] != "..")) {
			ostringstream anOut;
			anOut << "/home/aleshin8sergey/Workspace/Coursework/AdaBoost/Images/1/" << namesIm[i];
			images[i - point] = imread(anOut.str(), IMREAD_GRAYSCALE).clone();
		} else point++;
	}

	for (int i = NumofImwithFace; i < namesIm.size() - 1; i++) {
		if ((namesIm[i] != ".") && (namesIm[i] != "..")) {
			ostringstream anOut;
			anOut << "/home/aleshin8sergey/Workspace/Coursework/AdaBoost/Images/0/" << namesIm[i];
			images[i - point] = imread(anOut.str(), IMREAD_GRAYSCALE).clone();
		} else point++;
	}

	int *cols, *rows, minCol, minRow;
	cols = new int[NumofImwithFace - 2];
	rows = new int[NumofImwithFace - 2];

	for (int i = 0; i < NumofImwithFace - 2; i++) {
		cols[i] = images[i].cols;
		rows[i] = images[i].rows;
	}

	minCol = *min_element(cols, cols + NumofImwithFace - 2);
	minRow = *min_element(rows, rows + NumofImwithFace - 2);

	vector<int> compression_params;
	compression_params.push_back(IMWRITE_PNG_COMPRESSION);
	compression_params.push_back(9);

	for (int i = 0; i < numEl; i++) {
		ostringstream anOut;
		anOut << "/home/aleshin8sergey/Workspace/Coursework/AdaBoost/SameScaleImages/" << i << ".png";
		resize(images[i], images[i], Size(minCol, minRow));
		imwrite(anOut.str(), images[i], compression_params);
	}
}
