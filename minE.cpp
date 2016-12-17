#include "iostream"
#include "math.h"
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
