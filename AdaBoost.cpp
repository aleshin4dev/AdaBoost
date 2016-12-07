#include "iostream"
#include "math.h"
#include "opencv/cv.hpp"
#include "opencv/highgui.h"
using namespace std;

double AdaBoost(int, int*);
double* minEpsln(double, double);
double betta(double);

double AdaBoost(int NoI, int *FaceOrNoFace){
	const int ValOfHaarSimples = 6;

	double *Weights, *eps;
	Weights = new double[NoI];
	eps = new double[NoI];

	double sumW, minEps, *tmpEps = new double[2], alfa[17];
	int *Images;
	Images = new int[NoI];
	Images = FaceOrNoFace;
	int i, j, k, m = 0, l = 0, q, boolean;
	
int **HaarF;
	HaarF = new int*[NoI];
	for (int j = 0; j < NoI; j++) HaarF[j] = new int[ValOfHaarSimples]; // J - число используемых простых (слабых) примитивов
	int HaarFuncStrongest[17][15];
	for (i = 0; i < 15; i++)
	{
		if (Images[i] == 0) m++;
		else l++;
	}
	for (i = 0; i < 15; i++)
	{
		Weights[i] = 1;
		if (Images[i] == 0)
		{
			Weights[i] = (1.0 / (2 * m));
		}
		else
		{
			Weights[i] = (1.0 / (2 * l));
		}
	}



	for (i = 0; i < 17; i++)
	{
		sumW = 0;
		for (k = 0; k < 15; k++) sumW += Weights[k];
		for (j = 0; j < 15; j++) Weights[j] /= sumW;
		for (j = 0; j < 6; j++)
		{
			eps[j] = 0;
			for (k = 0; k < 15; k++)
				eps[j] += (Weights[k] * (fabs(HaarF[j][k] - Images[k])));
		}
		minEps = eps[0];
		q = 0;
		for (j = 0; j < 5; j++)
		{
			tmpEps = minEpsln(minEps, eps[j + 1]);
			minEps = tmpEps[0];
			boolean = (int)tmpEps[1];
			if (boolean == 1)
				q = j + 1;
		}
		for (j = 0; j < 15; j++)
		{
			HaarFuncStrongest[i][j] = HaarF[q][j];
		}
		for (j = 0; j < 15; j++)
		{
			if (Images[j] == HaarFuncStrongest[i][j])
			{
				Weights[j] *= Weights[j] * betta(minEps);
			}
		}
		alfa[i] = log(1.0 / betta(minEps));
	}
	return alfa[0];
}
double* minEpsln(double a, double b){
	double *eps_num = new double[2];
	if (a < b){
		eps_num[0] = a;
		eps_num[1] = 0;
	}else{
		eps_num[0] = b;
		eps_num[1] = 1;
	}
	return eps_num;
}
double betta(double e){
	return (e / (1 - e));
}
