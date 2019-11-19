#include <iostream>
#include <cstdio>
//#include <cstlib>
//#include "papi.h"

const int N = 2;


int multiplication(const double * F,const double * FT, double * P);
int imprimir(const double * D);

    int main(int argc, char **argv)
    {
      // Matrix declaration : Modeled as 1D array
      // Declare as pointers and ask for memory to use the heap
      double *A = new double [N*N], *B = new double [N*N], *C = new double [N*N];

      // initialize matrices
      for (int ii =0; ii < N; ++ii) {
        for (int jj =0; jj < N; ++jj) {
        A[ii*N + jj] = ii + jj + 1; 
	B[ii*N + jj] = ii + jj + 2;
	C[ii*N + jj] = 0.0;
        }
      }

      

      /*
      // PAPI vars
      float real_time, proc_time,mflops;
      long long flpops;
      float ireal_time, iproc_time, imflops;
      long long iflpops;
      int retval;

      // PERFOMANCE MEASURE

      // start PAPI counters
      if((retval=PAPI_flops(&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK)
        {
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n");
        printf("retval: %d\n", retval);
        exit(1);
        }
      */




      /*
      if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
        {
        printf("retval: %d\n", retval);
        exit(1);
        }


      printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n",
  	 real_time, proc_time,flpops,mflops);

     // Do something here, like computing the average of the resulting matrix, to avoid the optimizer deleting the code
      printf("%e.15\n", AT[0][0]);


      */
      
      multiplication(B, A, C);



      
      
        imprimir (B);

      	std::printf("B \n " );
	std::printf(" \n " );

       imprimir (A);
	std::printf("A \n " );
	std::printf(" \n " );

	      
      imprimir (C);
      	std::printf("C = B*A \n " );
	std::printf(" \n " );
      




      delete [] A;
      delete [] B;
      delete [] C;

      return 0;
    }


  


int multiplication(const double * F, const double * FT, double * P)
{
  for (int ii = 0; ii < N; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
	   for(int kk = 0; kk < N; ++kk){
	  P[ii*N +jj] += 1.0*F[ii*N + kk]*FT[kk*N + jj];
	   }
        }
       }
   return 0;
}


int imprimir(const double * D)
{
   for (int ii = 0; ii < N; ++ii) {
        for (int jj = 0; jj < N; ++jj) {
	  std::printf("\%5.2f   ", D[ii*N +jj]);
        }
	std::printf(" \n " );
       }
   return 0;
  
}

