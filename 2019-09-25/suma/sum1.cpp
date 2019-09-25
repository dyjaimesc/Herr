#include "sum1.h"

double sum1(int N)
{
  double sum=0.0;
  double sign = -1.0;
  for(int ii = 1; ii <= 2*N; ++ii){
    sum += sign*ii/(ii+1);
    sign *= -1;
  }
  return sum;
}
