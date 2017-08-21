#include "iostream"
#include "fstream"
#include "vector"
#include "string"

#include "SameScale.h"
#include "IntImg.h"
#include "AdaBoost.h"
#include "math.h"

#include <opencv2/opencv.hpp>
#include "opencv/highgui.h"

using namespace cv;
using namespace std;

int main() {
	vector<double> Alfa = vector<double>();
        vector<int> numofAandF = vector<int>();
	vector<int> HaarVote = vector<int>();
	
	numofAandF = AlsameScale(); // [0] - количество изображений, [1] - количество с лицом, [2] - число строк, [3] - число столбцов
	integralImg(numofAandF[1], numofAandF[0] - numofAandF[1], numofAandF[2], numofAandF[3]);

	Alfa = AdaBoost(numofAandF[0], numofAandF[1], numofAandF[0] - numofAandF[1], numofAandF[2], numofAandF[3]);
	
	/*
	вычисленные альфа с номерами сильнеших классификаторов загоняем в файл
	*/
	fstream fileAlfa("alfa.txt");
	for(int i = 0; i < Alfa.size() - 1; i+=2)
		fileAlfa << Alfa.at(i) << " " << Alfa.at(i + 1) << " ";
	fileAlfa.close();
		
	return 0;
}
