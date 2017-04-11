#include "iostream"
#include <vector>

#include "fstream"
#include <sstream>

#include <string>

using namespace std;

vector<int> haarFunc(int numofpic, int r, int c){
	vector<int> funcHaarVote = vector<int>();

	int Haar;

	double **I;
	I = new double*[r + 1];
	for(int i = 0; i < r + 1; i++)
		I[i] = new double[c + 1];

	ostringstream intImg;
	intImg << "/home/aleshin8sergey/Workspace/Coursework/IntegralImages/" << numofpic << ".txt";
	fstream file(intImg.str().c_str());
	for(int i = 0; i < r + 1; i++){
		for(int j = 0; j < c + 1; j++)
			file >> I[i][j];
	}
	file.close();

	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][c] + I[r/2][0] - I[r/2][c] - I[r][0]);
	if (Haar <= 170.69345)
		funcHaarVote.push_back(1);
	else
		funcHaarVote.push_back(0);

	
	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][c] + I[0][r/2] - I[0][r] - I[c][r/2]);
	if (Haar <= -86.1993)
		funcHaarVote.push_back(1);
	else
		funcHaarVote.push_back(0);

	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][2*c/3] + I[0][c/3] - I[0][2*c/3] - I[r][c/3]);
	if (Haar >= 1578.325)
		funcHaarVote.push_back(1);
	else
		funcHaarVote.push_back(0);


	Haar = I[r][c] + I[0][0] - I[r][0] - I[0][c] -
		2 * (I[2*r/3][c] + I[r/3][0] - I[2*r/3][0] - I[r/3][c]);
	if (Haar <= 1376.67)
		funcHaarVote.push_back(1);
	else
		funcHaarVote.push_back(0);


	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[2*r/3][2*c/3] + I[r/3][c/3] - I[r/3][2*c/3] - I[2*r/3][c/3]);
	if (Haar >= 3723.945)
		funcHaarVote.push_back(1);
	else
		funcHaarVote.push_back(0);


	Haar = I[r][c] + I[0][0] - I[r][0] - I[0][c] -
		2 * (I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2] + I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0]);
	if (Haar >= 61.6588)
		funcHaarVote.push_back(1);
	else
		funcHaarVote.push_back(0);

	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][(int)(c * 0.80952381)] + I[0][(int)(c * 0.44047619)] - I[0][(int)(c * 0.809523813)] - I[r][(int)(c * 0.44047619)]);
	if (Haar <= 1153.8559577677)
		funcHaarVote.push_back(1);
	else
		funcHaarVote.push_back(0);

	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[(int)(r * 0.736111111)][(int)(c * 0.736111111)] + I[(int)(r * 0.125)][(int)(c * 0.125)]
		- I[(int)(r * 0.125)][(int)(c * 0.736111111)] - I[(int)(r * 0.736111111)][(int)(c * 0.125)]);
	if (Haar >= 1095.0754147813)
		funcHaarVote.push_back(1);
	else
		funcHaarVote.push_back(0);

	return funcHaarVote;
}
