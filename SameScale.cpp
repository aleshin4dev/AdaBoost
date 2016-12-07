#include "iostream"
#include "opencv/cv.hpp"
#include "opencv/highgui.h"

#include <sstream>
#include <string>
#include <vector>

#include "readFileNamesInDir.h"

using namespace cv;
using namespace std;
vector<int> AlsameScale() {
	vector<int> FandNoF = vector<int>();
	vector<string> namesIm = vector<string>();
	namesIm = getFileNames();
	
	istringstream isF (namesIm[namesIm.size() - 1], istringstream::in);
	int ao, at;
	ao = namesIm.size() - 5;
	isF >> at;
	at = at - 2;
	FandNoF.push_back(ao);
	FandNoF.push_back(at);

	istringstream iss (namesIm[namesIm.size() - 1], istringstream::in);
	int NumofImwithFace;
	iss >> NumofImwithFace;
	int numEl = namesIm.size() - 5;
	Mat *images = new Mat[numEl];
	int point = 0;
	for (int i = 0; i < NumofImwithFace; i++) {
		if ((namesIm[i] != ".") && (namesIm[i] != "..")) {
			ostringstream anOut;
			anOut << "/home/aleshin8sergey/Workspace/Coursework/Images/1/" << namesIm[i];
			images[i - point] = imread(anOut.str(), IMREAD_GRAYSCALE).clone();
		} else point++;
	}

	for (int i = NumofImwithFace; i < namesIm.size() - 1; i++) {
		if ((namesIm[i] != ".") && (namesIm[i] != "..")) {
			ostringstream anOut;
			anOut << "/home/aleshin8sergey/Workspace/Coursework/Images/0/" << namesIm[i];
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
		anOut << "/home/aleshin8sergey/Workspace/Coursework/SameScaleImages/" << i << ".png";
		resize(images[i], images[i], Size(minCol, minRow));
		imwrite(anOut.str(), images[i], compression_params);
	}
	FandNoF.push_back(minRow);
	FandNoF.push_back(minCol);
	return FandNoF;
}
