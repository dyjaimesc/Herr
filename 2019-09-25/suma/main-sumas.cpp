#include <cstdio> 
#include <cmath>

#include "sum1.h"
#include "sum2.h"
#include "sum3.h"


int main(void)
{
  for(int n = 1; n <= 10000; ++n) {
    double S1 = sum1(n);
    double S2 = sum2(n);
    double S3 = sum3(n);
    double delta1 = std::fabs((S1 - S3)/S3);
    double delta2 = std::fabs((S2 - S3)/S3);
    std::printf("%10d %24.16e %24.16e %24.16e %24.16e %24.16e\n",
		n, S1, S2, S3, delta1, delta2);
  }
  
  
  return 0;
}
