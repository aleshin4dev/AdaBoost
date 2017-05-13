#include "iostream"
#include "math.h"
#include "opencv/cv.hpp"
#include "opencv/highgui.h"
#include <vector>
#include <string>
#include "haar.h"
#include "minE.h"
#include "betta.h"
using namespace std;
vector<double> AdaBoost(int NoI, int l, int m, int rs, int cs){
	vector<double> alfa = vector<double>();
const int ValofHS = 56;
const int Iter = 100000;
	int q, boolean;
	double *Weights, *eps, *tmpEps;
	Weights = new double[NoI];
	eps = new double[NoI];
	tmpEps = new double[2];

	double sumW, minEps;

	int *Images;
	Images = new int[NoI];
	for(int i = 0; i < l; i++)
		Images[i] = 1;
	for(int i = 0; i < m; i++)
		Images[i + l] = 0;

	int **HaarF;
	HaarF = new int*[ValofHS];
	for(int j = 0; j < ValofHS; j++)
		HaarF[j] = new int[NoI];

	vector<int> HaarVote = vector<int>();
	for(int i = 0; i < NoI; i++){
		HaarVote = haarFunc(i, rs, cs);
		for(int j = 0; j < ValofHS; j++)			
			HaarF[j][i] = HaarVote.at(j);
		HaarVote.clear();
	}

	int **HaarFuncStrongest;
	HaarFuncStrongest = new int*[Iter];
	for(int w = 0; w < Iter; w++)
		HaarFuncStrongest[w] = new int[NoI];

	for(int i = 0; i < NoI; i++){
		Weights[i] = 1;
		if(Images[i] == 0)
			Weights[i] = (1.0 / (2 * m));
		else
			
			Weights[i] = (1.0 / (2 * l));
	}

	for(int i = 0; i < Iter; i++){
		sumW = 0;
		for(int k = 0; k < NoI; k++)
			sumW += Weights[k];
		for(int k = 0; k < NoI; k++)
			Weights[k] /= sumW;

		for(int j = 0; j < ValofHS; j++){
			eps[j] = 0;
			for(int k = 0; k < NoI; k++)
				eps[j] += (Weights[k] * (fabs(HaarF[j][k] - Images[k])));
		}

		minEps = eps[0];
		q = 0;

		for(int j = 0; j < ValofHS - 1; j++){
			tmpEps = minEpsln(minEps, eps[j + 1]);
			minEps = tmpEps[0];
			boolean = (int)tmpEps[1];
			if(boolean == 1)
				q = j + 1;
		}

		for(int j = 0; j < NoI; j++)
			HaarFuncStrongest[i][j] = HaarF[q][j];

		for(int j = 0; j < NoI; j++){
			if(Images[j] == HaarFuncStrongest[i][j])
				Weights[j] *= Weights[j] * betta(minEps);
		}

		alfa.push_back(q);
		alfa.push_back(log(1.0 / betta(minEps)));
	}
	return alfa;
}
