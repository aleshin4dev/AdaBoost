#include "iostream"
#include "string"
#include "fstream"
#include "vector"
#include "math.h"
#include "haar.h"

using namespace std;

int main(){
	const double EPS = 1e-7;
	vector<double> funcH_and_alfa = vector<double>();
	vector<int> voteH = vector<int>();
	double tmp, ALFA = 0, pAandH = 0;
	fstream ha("/home/aleshin8sergey/Workspace/Coursework/AdaBoost/alfa.txt");
	for(int i = 0; i < 200; i++){
		ha >> tmp;
		funcH_and_alfa.push_back(tmp);
	}
	ha.close();
	ofstream res("res.txt");
for(int j = 0; j < 576; j++){
	voteH = haarFunc(j, 112, 92);
	for(int i = 0; i < 199; i+=2){
		ALFA += funcH_and_alfa.at(i + 1);
		pAandH += (funcH_and_alfa.at(i + 1) * voteH.at(funcH_and_alfa.at(i)));
	}
	ALFA = fabs(ALFA);
	pAandH = fabs(pAandH);
	if((pAandH > (0.5 * ALFA))||(fabs(pAandH - 0.5 * ALFA) < EPS))
		res << j << " " << 1 << "\n";
	else
		res << j << " " << 0 << "\n";
	ALFA = 0;
	pAandH = 0;
}
	res.close();
	return 0;
}
