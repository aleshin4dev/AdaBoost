#include "iostream"
#include "Viola-Jones.h"
using namespace std;
size_t** funcIntegralImage(size_t **A,int n, int m)
{
   int i, j, k, l;
   size_t **M;
   M = new size_t*[m + 1];
   for(i = 0; i < m + 1; i++) M[i] = new size_t[n + 1];
   M = A;
   for(i = m; i > 0; i--)
      for(j = n; j > 0; j--)
         for(k = m; k >= 0; k--)
            for(l = n; l >= 0; l--)
               if(((k <= i) && (l < j)) || ((k < i) && (l <= j)))
                  M[i][j] += M[k][l];
   return M;
}