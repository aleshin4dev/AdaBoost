#include "stdio.h"
#include "iostream"
#include "fstream"
#include <sstream>

#include <string>
#include "cstring"
#include <vector>

#include "opencv/cv.hpp"
#include "opencv/highgui.h"

using namespace std;
using namespace cv;

void integralImg(int f, int nof, int r, int c){
	Mat pic;
	double **M; // size_t -> double

	M = new double*[r + 1];
	for(int i = 0; i < r + 1; i++) M[i] = new double[c + 1];

	for(int np = 0; np < f + nof; np++){
		for(int q = 0; q < c + 1; q++) M[0][q] = 0;
		for(int q = 0; q < r + 1; q++) M[q][0] = 0;

		ostringstream anOut;
		anOut << "/home/aleshin8sergey/Workspace/Coursework/SameScaleImages/" << np << ".png";
		pic = imread(anOut.str());

		for(int i = 1; i < r + 1; i++)
			for(int j = 1; j < c + 1; j++)
				M[i][j] = (double)pic.at<uchar>(i - 1, j - 1) / 255.0; //изменение приведения типа из int в double

		for(int i = r; i > 0; i--)
		   for(int j = c; j > 0; j--)
		      for(int k = r; k >= 0; k--)
		         for(int l = c; l >= 0; l--)
		            if(((k <= i) && (l < j)) || ((k < i) && (l <= j)))
		            	M[i][j] += M[k][l];

		ostringstream textF;
		textF << "/home/aleshin8sergey/Workspace/Coursework/IntegralImages/" << np << ".txt";
		ofstream file(textF.str().c_str());
		for(int i = 0; i < r + 1; i++){
			for(int j = 0; j < c + 1; j++) file << M[i][j] << " ";
			file << "\n";
		}
		file.close();
	}
}
