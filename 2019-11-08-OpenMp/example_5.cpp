#include <omp.h>
  #include <stdio.h>
#include<cmath>

    int main(int argc, char *argv[]) {
      const int N = 30000000;
      int i, *a;
      a=new int [N];
      

    #pragma omp parallel for
      for(i = 0; i < N; i++)
        {
	  a[i] = 2*std::sin(i)*std::cos(i)/3.98;
  	}

      double suma=0;

#pragma omp parallel for
      for(i = 0; i < N; i++)
        {
	  a[i] = 2*std::sin(i)*std::cos(i)/3.98;
  	}

      printf("%.16e\n",suma/N);
 
 delete [] a;
      return 0;
      
    }

