#include "iostream"
#include "fstream"
#include "vector"
#include "string"
#include "SameScale.h"
#include "IntImg.h"
#include "math.h"

#include <opencv2/opencv.hpp>
#include "opencv/highgui.h"

#include <ctime>

using namespace cv;
using namespace std;

int main() {
	vector<int> numofAandF = vector<int>();
	numofAandF = AlsameScale(); // [0] - количество изображений, [1] - количество с лицом, [2] - число строк, [3] - число столбцов
	integralImg(numofAandF[1], numofAandF[0] - numofAandF[1], numofAandF[2], numofAandF[3]);
	return 0;
}
