#include "iostream"
#include <vector>

#include "fstream"
#include <sstream>

#include <string>

using namespace std;

vector<int> haarFunc(int numofpic, int r, int c){
	vector<int> funcHaarVote = vector<int>();

	int ans; //переменная под ответ лицо или нет
	int Haar;

	int **I;
	I = new int*[r + 1];
	for(int i = 0; i < r + 1; i++) I[i] = new int[c + 1];

	ostringstream intImg;
	intImg << "/home/aleshin8sergey/Workspace/Coursework/IntegralImages/" << numofpic << ".txt";
	fstream file(intImg.str().c_str());
	for(int i = 0; i < r + 1; i++){
		for(int j = 0; j < c + 1; j++)
			file >> I[i][j];
	}
	file >> ans;
	/*funcHaarVote.push_back(ans); //первым элементом будет ответ лицо или нет*/
	file.close();

	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][c] + I[r/2][0] - I[r/2][c] - I[r][0]);

if(((Haar < (-50000))&&(Haar >= (-375000)))||((Haar < 25000)&&(Haar >= 0))||((Haar < 125000)&&(Haar >= 100000))||((Haar < 175000)&&(Haar >= 150000)))
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);
	
	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][c] + I[0][r/2] - I[0][r] - I[c][r/2]);

if(((Haar < (-25000))&&(Haar >= (-550000)))||((Haar < 25000)&&(Haar >= 0))||((Haar < 350000)&&(Haar >= 300000)))
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[r][2*c/3] + I[0][c/3] - I[0][2*c/3] - I[r][c/3]);

if(((Haar < 450000)&&(Haar >= 200000))||((Haar < 500000)&&(Haar >= 475000))||((Haar < 550000)&&(Haar >= 525000))||((Haar < 575000)&&(Haar >= 600000))||((Haar < 775000)&&(Haar >= 650000)))
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

	Haar = I[r][c] + I[0][0] - I[r][0] - I[0][c] -
		2 * (I[2*r/3][c] + I[r/3][0] - I[2*r/3][0] - I[r/3][c]);

if(((Haar <= (-25000))&&(Haar > (-50000)))||((Haar < 475000)&&(Haar >= 100000)))
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

	Haar = I[r][c] + I[0][0] - I[0][c] - I[r][0] -
		2 * (I[2*r/3][2*c/3] + I[r/3][c/3] - I[r/3][2*c/3] - I[2*r/3][c/3]);

if(((Haar < 100000)&&(Haar >= 75000))||((Haar < 525000)&&(Haar >= 500000))||((Haar < 1125000)&&(Haar >= 600000))||((Haar < 1275000)&&(Haar >= 1200000))||((Haar < 1350000)&&(Haar >= 1300000))||((Haar < 1400000)&&(Haar >= 1375000))||((Haar < 1450000)&&(Haar >= 1425000))||((Haar < 1800000)&&(Haar >= 1525000)))
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

	Haar = I[r][c] + I[0][0] - I[r][0] - I[0][c] -
		2 * (I[r/2][c] + I[0][c/2] - I[0][c] - I[r/2][c/2] + I[r][c/2] + I[r/2][0] - I[r/2][c/2] - I[r][0]);

if(((Haar < 0)&&(Haar >= (-175000)))||((Haar < 200000)&&(Haar >= 0))||((Haar < 350000)&&(Haar >= 225000)))
	funcHaarVote.push_back(1);
else
	funcHaarVote.push_back(0);

	return funcHaarVote;
}
