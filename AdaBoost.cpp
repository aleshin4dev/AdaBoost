#include <iostream>
#include <math.h>

using namespace std;
double* minEpsln(double, double); //finding minimal error
double betta(double); //calculates betta
int main()
{
	double Weights[15], sumW, eps[6], minEps, *tmpEps = new double[2], alfa[17];
	int i, j, k, m = 0, l = 0, q, boolean;
	int   /*
		  there are 6 classifiers (HaarF[6][15])
		  */
		Images[15] = { 1,1,0,1,0,0,1,1,1,0,1,0,0,0,1 }, //learning images
		HaarF[6][15] = {
	{ 1,0,0,1,0,0,0,1,1,1,0,0,1,1,0 },
	{ 1,0,1,0,1,1,0,0,1,0,1,0,1,1,1 },
	{ 1,0,0,0,1,0,1,1,0,1,0,0,1,0,0 },
	{ 1,1,1,1,1,0,0,1,1,1,0,0,0,1,0 },
	{ 1,0,0,0,1,1,1,1,0,1,0,0,1,0,0 },
	{ 0,1,1,0,1,0,0,1,1,1,0,0,0,1,0 }
	},
		//array of strongest classifiers
		HaarFuncStrongest[17][15];
	//inicialized weights
	for (i = 0; i < 15; i++)
	{
		if (Images[i] == 0) m++;
		else l++;
	}
	for (i = 0; i < 15; i++)
	{
		Weights[i] = 1;
		if (Images[i] == 0) Weights[i] = (1.0 / (2 * m));
		else Weights[i] = (1.0 / (2 * l));
	}
	/*
	'i' is 't'
	*/
	for (i = 0; i < 17; i++)
	{
		sumW = 0;
        //sum of weight for normalize
		for (k = 0; k < 15; k++) sumW += Weights[k];
		/*
		normalize
		*/
		for (j = 0; j < 15; j++) Weights[j] /= sumW;
		/*
		choose 6 classifiers: training everyine if them (2)
		*/
		for (j = 0; j < 6; j++)
		{
			eps[j] = 0;
			for (k = 0; k < 15; k++)
			{
				eps[j] += (Weights[k] * (fabs(HaarF[j][k] - Images[k])));
			}
		}
		/*
		choose minimal error
		*/
		minEps = eps[0];
		q = 0;
		for (j = 0; j < 5; j++)
		{
			tmpEps = minEpsln(minEps, eps[j + 1]);
			minEps = tmpEps[0];
			boolean = (int)tmpEps[1];
			if (boolean == 1) q = j + 1;
		}
		/*
		choose classifier which has minimal error (3)
		*/
		for (j = 0; j < 15; j++)
		{
			HaarFuncStrongest[i][j] = HaarF[q][j];
		}
		/*
		update weights (4)
		*/
		for (j = 0; j < 15; j++)
		{
			if (Images[j] == HaarFuncStrongest[i][j])
			{
				Weights[j] *= Weights[j] * betta(minEps);
			}
		}
		alfa[i] = log(1.0 / betta(minEps)); /*
											for get strongest classifier
											*/
	}
	/*
	alfa-t for find images
	*/
	for (int t = 0; t < 15; t++) cout << alfa[t] << " "; cin.get();
	return 0;
}
double* minEpsln(double a, double b)
{
	double *eps_num = new double[2];
	if (a < b)
	{
		eps_num[0] = a;
		eps_num[1] = 0;
	}
	else
	{
		eps_num[0] = b;
		eps_num[1] = 1;
	}
	return eps_num;
}
double betta(double e)
{
	return (e / (1 - e));
}