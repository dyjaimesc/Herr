#include "sum2.h"

double sum2(int N)
{
  double sumA = 0.0, sumB = 0.0;
  for(int ii = 1; ii <= N; ++ii){
    sumA += (2*ii-1.0)/(2*ii);
    sumB += (2*ii)/(2*ii+1.0);
  }
  return -sumA + sumB;
}
