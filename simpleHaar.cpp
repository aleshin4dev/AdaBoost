#include "iostream"
#include <vector>

#include "fstream"
#include <sstream>

#include <string>

using namespace std;

vector<int> haarFunc(int numofpic, int r, int c){
	vector<int> funcHaarVote = vector<int>();
	size_t Haar1, Haar2, Haar3, Haar4, Haar5, Haar6;

	size_t **I;
	I = new size_t*[r + 1]
	for(int i = 0; i < r + 1; i++) I[i] = new size_t[c + 1];

    for(int np = 0; np < numofpic; np++){
	ostringstream intImg;
	intImg << "/home/aleshin8sergey/Workspace/Coursework/IntegralImages/" << np << ".txt";
	fstream file(intImg.str().c_str());
	for(int i = 0; i < r + 1; i++){
		for(int j = 0; j < c + 1; j++)
			file >> I[i][j];
	}
    }


	Haar1 = I[x+48][y+24] + I[x][y] - I[x+48][y] - I[x][y+24] -
		2 * (I[x+48][y+24] + I[x][y+12] - I[x+48][y+12] - I[x][y+24]);
	Haar2 = I[x+24][y+48] + I[x][y] - I[x+24][y] - I[x][y+48] -
		2 * (I[x+24][y+48] + I[x+12][y] - I[x+24][y] - I[x+12][y+48]);
	Haar3 = I[x+48][y+12] + I[x][y] - I[x+48][y] - I[x][y+12] -
		2 * (I[x+32][y+12] + I[x+16][y] - I[x+32][y] - I[x+16][y+12]);
	Haar4 = I[x+12][y+48] + I[x][y] - I[x][y+48] - I[x+12][y] -
		2 * (I[x+12][y+32] + I[x][y+16] - I[x][y+32] - I[x+12][y+16]);
	Haar5 = I[x+48][y+48] + I[x][y] - I[x+48][y] - I[x][y+48] -
		2 * (I[x+32][y+32] + I[x+16][y+16] - I[x+32][y+16] - I[x+16][y+32]);
	Haar6 = I[x+48][y+48] + I[x+12][y+12] - I[x+48][y+12] - I[x+12][y+48] +
		I[x+12][y+12] + I[x][y] - I[x+12][y] - I[x][y+12] -
		(I[x+48][y+12] + I[x+12][y] - I[x+48][y] - I[x+12][y+12]) -
		(I[x+12][y+48] + I[x][y+12] - I[x+12][y+12] - I[x][y+48]);
}
