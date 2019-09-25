#include <cstdio>
#include <cmath>

typedef double  REAL; // crear un sinonimo: REAL es lo que esta a su izquierda

REAL sum1(int N);
REAL sum2(int N);
REAL sum3(int N);

int main(void)
{
  for(int n = 1; n <= 10000; ++n) {
    REAL S1 = sum1(n);
    REAL S2 = sum2(n);
    REAL S3 = sum3(n);
    REAL delta1 = std::fabs((S1 - S3)/S3);
    REAL delta2 = std::fabs((S2 - S3)/S3);
    std::printf("%10d %24.16e %24.16e %24.16e %24.16e %24.16e\n",
		n, S1, S2, S3, delta1, delta2);
  }
  
  
  return 0;
}


REAL sum1(int N)
{
  REAL sum=0.0;
  REAL sign = -1.0;
  for(int ii = 1; ii <= 2*N; ++ii){
    sum += sign*ii/(ii+1);
    sign *= -1;
  }
  return sum;
}

REAL sum2(int N)
{
  REAL sumA = 0.0, sumB = 0.0;
  for(int ii = 1; ii <= N; ++ii){
    sumA += (2*ii-1.0)/(2*ii);
    sumB += (2*ii)/(2*ii+1.0);
  }
  return -sumA + sumB;
}

REAL sum3(int N)
{
  REAL sum=0.0;
  for(int ii = 1; ii <= N; ++ii){
    sum += 1.0/((2*ii)*(2*ii+1));
  }
  return sum;
}
