#include "iostream"
#include "fstream"
#include "vector"
#include "string"
#include "haar.h"
//#include "SameScale.h"
//#include "readFileNamesInDir.h"
//#include "IntImg.h"
#include "AdaBoost.h"
#include "math.h"

#include <opencv2/opencv.hpp>
#include "opencv/highgui.h"

#include <ctime>

using namespace cv;
using namespace std;

int main() {
	vector<double> Alfa = vector<double>();
        //vector<int> numofAandF = vector<int>();

/* сделано*/	//numofAandF = AlsameScale(); // [0] - количество изображений, [1] - количество с лицом, [2] - число строк, [3] - число столбцов
		//cout << numofAandF[0] << " " << numofAandF[1] << " " << numofAandF[2] << " " << numofAandF[3] << endl;
/* сделано*/	//integralImg(/*numofAandF[1], numofAandF[0] - numofAandF[1], numofAandF[2], numofAandF[3]*/1326, (1640 - 1326), 112, 92);
		//Alfa = AdaBoost(numofAandF[0], numofAandF[1], numofAandF[0] - numofAandF[1]);
		Alfa = AdaBoost(1640, 1326, (1640 - 1326));
		cout << "hey hey";
		fstream fileAlfa("/home/aleshin8sergey/Workspace/Coursework/AdaBoost/alfa.txt");
		for(int i = 0; i < 227; i+=2)
			fileAlfa << Alfa.at(i) << " " << Alfa.at(i + 1) << " ";
		fileAlfa.close();
	return 0;
}
