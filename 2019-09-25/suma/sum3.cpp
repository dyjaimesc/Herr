#include "sum3.h"

double sum3(int N)
{
  double sum=0.0;
  for(int ii = 1; ii <= N; ++ii){
    sum += 1.0/((2*ii)*(2*ii+1));
  }
  return sum;
}
