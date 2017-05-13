#include "iostream"
#include <vector>

#include "fstream"
#include <sstream>

#include <string>

using namespace std;

vector<int> haarFunc(int numofpic, int r, int c){
	vector<int> funcHaarVote = vector<int>();

	double Haar;

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

/* первый вид признаков (целое, по половине [верт, гориз разделения], по четвертям) */
/*0*/	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][c] + I[r/2][0] - I[r/2][c] - I[r][0]);
if (Haar < 107.65)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);
	
/*1*/		Haar = I[r][c] + I[0][c/2] - I[0][c] - I[r][c/2] -
			2 * (I[r][c] + I[r/2][c/2] - I[r/2][c] - I[r][c/2]);
if (Haar < -5.89046)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*2*/		Haar = I[r][c/2] + I[0][0] - I[0][c/2] - I[r][0] -
			2 * (I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0]);
if (Haar < 113.54)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*3*/		Haar = I[r][c] + I[r/2][0] - I[r/2][c] - I[r][0] -
			2 * (I[r][c] + I[3*r/4][0] - I[3*r/4][c] - I[r][0]);
if (Haar >= 270.376)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*4*/		Haar = I[r/2][c] + I[0][0] - I[0][c] - I[r/2][0] -
			2 * (I[r/2][c] + I[r/4][0] - I[r/4][c] - I[r/2][0]);
if (Haar < -308.602)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*5*/		Haar = I[r][c] + I[r/2][c/2] - I[r/2][c] - I[r][c/2] -
			2 * (I[r][c] + I[3*r/4][c/2] - I[3*r/4][c] - I[r][c/2]);
if (Haar >= 123.547)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*6*/		Haar = I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0] -
			2 * (I[r][c/2] + I[3*r/4][0] - I[3*r/4][c/2] - I[r][0]);
if (Haar >= 146.829)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*7*/		Haar = I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2] -
			2 * (I[r/2][c] + I[r/4][c/2] - I[r/4][c] - I[r/2][c/2]);
if (Haar < -170.625)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*8*/		Haar = I[r/2][c/2] + I[0][0] - I[0][c/2] - I[r/2][0] -
			2 * (I[r/2][c/2] + I[3*r/4][0] - I[3*r/4][c/2] - I[r/2][0]);
if (Haar >= 2536.08)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/* второй вид признаков (целое, по половине [верт, гориз разделения], по четвертям) */
/*0*/	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][c] + I[0][c/2] - I[0][c] - I[r][c/2]);
if (Haar < -436.177)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*1*/		Haar = I[r][c] + I[0][c/2] - I[0][c] - I[r][c/2] -
			2 * (I[r][c] + I[0][3*c/4] - I[0][c] - I[r][3*c/4]);
if (Haar < -65.7428)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*2*/		Haar = I[r][c/2] + I[0][0] - I[0][c/2] - I[r][0] -
			2 * (I[r][c/2] + I[0][3*c/4] - I[0][c/2] - I[r][3*c/4]);
if (Haar >= 5148.95)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*3*/		Haar = I[r][c] + I[r/2][0] - I[r/2][c] - I[r][0] -
			2 * (I[r][c] + I[r/2][c/2] - I[r/2][c] - I[r][c/2]);
if (Haar < -277.804)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*4*/		Haar = I[r/2][c] + I[0][0] - I[0][c] - I[r/2][0] -
			2 * (I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2]);
if (Haar < -158.373)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*5*/		Haar = I[r][c] + I[r/2][c/2] - I[r/2][c] - I[r][c/2] -
			2 * (I[r][c] + I[r/2][3*c/4] - I[r/2][c] - I[r][3*c/4]);
if (Haar >= -31.7182)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*6*/		Haar = I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0] -
			2 * (I[r][c/2] + I[r/2][c/4] - I[r/2][c/2] - I[r][c/4]);
if (Haar < -90.3731)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*7*/		Haar = I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2] -
			2 * (I[r/2][c] + I[0][3*c/4] - I[0][c] - I[r/2][3*c/4]);
if (Haar < -34.0246)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*8*/		Haar = I[r/2][c/2] + I[0][0] - I[0][c/2] - I[r/2][0] -
			2 * (I[r/2][c/2] + I[0][c/4] - I[0][c/2] - I[r/2][c/4]);
if (Haar >= -55.6644)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);
	

/* третий вид признаков (целое, по половине [верт, гориз разделения], по четвертям) */
/*0*/	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][2*c/3] + I[0][c/3] - I[0][2*c/3] - I[r][c/3]);
if (Haar < 1631.93)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*1*/		Haar = I[r][c] + I[0][c/2] - I[0][c] - I[r][c/2] -
			2 * (I[r][5*c/6] + I[0][2*c/3] - I[0][5*c/6] - I[r][2*c/3]);
if (Haar >= 983.038)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*2*/		Haar = I[r][c/2] + I[0][0] - I[0][c/2] - I[r][0] -
			2 * (I[r][c/3] + I[0][c/6] - I[0][c/3] - I[r][c/6]);
if (Haar < 839.73)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*3*/		Haar = I[r][c] + I[r/2][0] - I[r/2][c] - I[r][0] -
			2 * (I[r][2*c/3] + I[r/2][c/3] - I[r/2][2*c/3] - I[r][c/3]);
if (Haar < 786.932)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*4*/		Haar = I[r/2][c] + I[0][0] - I[0][c] - I[r/2][0] -
			2 * (I[r/2][2*c/3] + I[0][c/3] - I[0][2*c/3] - I[r/2][c/3]);
if (Haar < 844.997)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*5*/		Haar = I[r][c] + I[r/2][c/2] - I[r/2][c] - I[r][c/2] -
			2 * (I[r][5*c/6] + I[r/2][2*c/3] - I[r/2][5*c/6] - I[r][2*c/3]);
if (Haar >= 485.509)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*6*/		Haar = I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0] -
			2 * (I[r][c/3] + I[r/2][c/6] - I[r/2][c/3] - I[r][c/6]);
if (Haar < 402.737)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*7*/		Haar = I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2] -
			2 * (I[r/2][5*c/6] + I[0][2*c/3] - I[0][5*c/6] - I[r/2][2*c/3]);
if (Haar >= 497.529)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*8*/		Haar = I[r/2][c/2] + I[0][0] - I[0][c/2] - I[r/2][0] -
			2 * (I[r/2][c/3] + I[0][c/6] - I[0][c/3] - I[r/2][c/6]);
if (Haar < 436.993)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/* четвёртый вид признаков (целое, по половине [верт, гориз разделения], по четвертям) */
/*0*/	Haar = I[r][c] + I[0][0] - I[r][0] - I[0][c] -
		2 * (I[2*r/3][c] + I[r/3][0] - I[r/3][c] - I[2*r/3][0]);
if (Haar < 1263.45)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*1*/		Haar = I[r][c] + I[0][c/2] - I[0][c] - I[r][c/2] -
			2 * (I[2*r/3][c] + I[r/3][c/2] - I[r/3][c] - I[2*r/3][c/2]);
if (Haar < 699.868)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*2*/		Haar = I[r][c/2] + I[0][0] - I[0][c/2] - I[r][0] -
			2 * (I[2*r/3][c/2] + I[r/3][0] - I[r/3][c/2] - I[2*r/3][0]);
if (Haar < 563.579)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*3*/		Haar = I[r][c] + I[r/2][0] - I[r/2][c] - I[r][0] -
			2 * (I[5*r/6][c] + I[2*r/3][0] - I[2*r/3][c] - I[5*r/6][0]);
if (Haar >= 818.858)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*4*/		Haar = I[r/2][c] + I[0][0] - I[0][c] - I[r/2][0] -
			2 * (I[r/3][c] + I[r/6][0] - I[r/6][c] - I[r/3][0]);
if (Haar >= 909.452)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*5*/		Haar = I[r][c] + I[r/2][c/2] - I[r/2][c] - I[r][c/2] -
			2 * (I[5*r/6][c] + I[2*r/3][c/2] - I[2*r/3][c] - I[5*r/6][c/2]);
if (Haar >= 442.722)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*6*/		Haar = I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0] -
			2 * (I[5*r/6][c/2] + I[2*r/3][0] - I[2*r/3][c/2] - I[5*r/6][0]);
if (Haar >= 376.136)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*7*/		Haar = I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2] -
			2 * (I[r/3][c] + I[r/6][c/2] - I[r/6][c] - I[r/3][c/2]);
if (Haar >= 485.452)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*8*/		Haar = I[r/2][c/2] + I[0][0] - I[0][c/2] - I[r/2][0] -
			2 * (I[r/3][c/2] + I[r/6][0] - I[r/6][c/2] - I[r/3][0]);
if (Haar >= 423.999)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);
	

/* пятый вид признаков (целое, по половине [верт, гориз разделения], по четвертям) */
/*0*/	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[2*r/3][2*c/3] + I[r/3][c/3] - I[r/3][2*c/3] - I[2*r/3][c/3]);
if (Haar < 3813.94)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*1*/		Haar = I[r][c] + I[0][c/2] - I[0][c] - I[r][c/2] -
			2 * (I[2*r/3][5*c/6] + I[r/3][2*c/3] - I[r/3][5*c/6] - I[2*r/3][2*c/3]);
if (Haar >= 2130.42)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*2*/		Haar = I[r][c/2] + I[0][0] - I[0][c/2] - I[r][0] -
			2 * (I[2*r/3][c/3] + I[r/3][c/6] - I[r/3][c/3] - I[2*r/3][c/6]);
if (Haar < 1791.82)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*3*/		Haar = I[r][c] + I[r/2][0] - I[r/2][c] - I[r][0] -
			2 * (I[5*r/6][2*c/3] + I[2*r/3][c/3] - I[2*r/3][2*c/3] - I[5*r/6][c/3]);
if (Haar < 1938.72)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*4*/		Haar = I[r/2][c] + I[0][0] - I[0][c] - I[r/2][0] -
			2 * (I[r/3][2*c/3] + I[r/6][c/3] - I[r/6][2*c/3] - I[r/3][c/3]);
if (Haar >= 2076.66)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*5*/		Haar = I[r][c] + I[r/2][c/2] - I[r/2][c] - I[r][c/2] -
			2 * (I[5*r/6][5*c/6] + I[2*r/3][2*c/3] - I[2*r/3][5*c/6] - I[5*r/6][2*c/3]);
if (Haar >= 1092.21)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*6*/		Haar = I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0] -
			2 * (I[5*r/6][c/3] + I[2*r/3][c/6] - I[2*r/3][c/3] - I[5*r/6][c/6]);
if (Haar < 893.841)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*7*/		Haar = I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2] -
			2 * (I[r/3][5*c/6] + I[r/6][2*c/3] - I[r/6][5*c/6] - I[r/3][2*c/3]);
if (Haar >= 1112.93)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*8*/		Haar = I[r/2][c/2] + I[0][0] - I[0][c/2] - I[r/2][0] -
			2 * (I[r/3][c/3] + I[r/6][c/6] - I[r/6][c/3] - I[r/3][c/6]);
if (Haar >= 983.394)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);
	

/* шестой вид признаков (целое, по половине [верт, гориз разделения], по четвертям) */
/*0*/	Haar = I[r][c] + I[0][0] - I[r][0] - I[0][c] -
		2 * (I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2] + I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0]);
if (Haar >= 119.431)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*1*/		Haar = I[r][c] + I[0][c/2] - I[0][c] - I[r][c/2] -
			2 * (I[r/2][c] + I[0][3*c/4] - I[0][c] - I[r/2][3*c/4] + I[r][3*c/4] + I[r/2][c/2] - I[r/2][3*c/4] - I[r][c/2]);
if (Haar < -2.30639)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*2*/		Haar = I[r][c/2] + I[0][0] - I[0][c/2] - I[r][0] -
			2 * (I[r/2][c/2] + I[0][c/4] - I[0][c/2] - I[r/2][c/4] + I[r][c/4] + I[r/2][0] - I[r/2][c/4] - I[r][0]);
if (Haar >= 34.7086)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*3*/		Haar = I[r][c] + I[r/2][0] - I[r/2][c] - I[r][0] -
			2 * (I[3*r/4][c] + I[r/2][c/2] - I[r/2][c] - I[3*r/4][c/2] + I[r][c/2] + I[3*r/4][0] - I[3*r/4][c/2] - I[r][0]);
if (Haar >= 23.2817)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*4*/		Haar = I[r/2][c] + I[0][0] - I[0][c] - I[r/2][0] -
			2 * (I[r/4][c] + I[0][c/2] - I[0][c] - I[r/4][c/2] + I[r/2][c/2] + I[r/4][0] - I[r/4][c/2] - I[r/2][0]);
if (Haar >= 32.6475)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*5*/		Haar = I[r][c] + I[r/2][c/2] - I[r/2][c] - I[r][c/2] -
			2 * (I[3*r/4][c] + I[r/2][3*c/4] - I[r/2][c] - I[3*r/4][3*c/4] + I[r][3*c/4] + I[3*r/4][c/2] - I[3*r/4][3*c/4] - I[r][c/2]);
if (Haar >= 38.3773)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*6*/		Haar = I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0] -
			2 * (I[3*r/4][c/2] + I[r/2][c/4] - I[r/2][c/2] - I[3*r/4][c/4] + I[r][c/4] + I[3*r/4][0] - I[3*r/4][c/4] - I[r][0]);
if (Haar >= -37.4948)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*7*/		Haar = I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2] -
			2 * (I[r/4][c] + I[0][3*c/4] - I[0][c] - I[r/4][3*c/4] + I[r/2][3*c/4] + I[r/4][c/2] - I[r/4][3*c/4] - I[r/2][c/2]);
if (Haar < -29.3093)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

/*8*/		Haar = I[r/2][c/2] + I[0][0] - I[0][c/2] - I[r/2][0] -
			2 * (I[r/4][c/2] + I[0][c/4] - I[0][c/2] - I[r/4][c/4] + I[r/2][c/4] + I[r/4][0] - I[r/4][c/4] - I[r/2][0]);
if (Haar >= 43.1452)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);
	

/* седьмой вид признаков (целое, по половине [верт, гориз разделения], по четвертям) */
	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][(int)(c * 0.80952381)] + I[0][(int)(c * 0.44047619)] - I[0][(int)(c * 0.809523813)] - I[r][(int)(c * 0.44047619)]);
if (Haar < 1145.65)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);
	

/* восьмой вид признаков (целое, по половине [верт, гориз разделения], по четвертям) */
	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[(int)(r * 0.736111111)][(int)(c * 0.736111111)] + I[(int)(r * 0.125)][(int)(c * 0.125)]
		- I[(int)(r * 0.125)][(int)(c * 0.736111111)] - I[(int)(r * 0.736111111)][(int)(c * 0.125)]);
if (Haar < 1106.62)
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);	

	return funcHaarVote;
}
/*
if (Haar <= 170.69345)
		funcHaarVote.push_back(1);
	else
		funcHaarVote.push_back(0);
*/
