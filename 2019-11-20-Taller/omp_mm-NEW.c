/******************************************************************************
* FILE: omp_mm.c
* DESCRIPTION:  
*   OpenMp Example - Matrix Multiply - C Version
*   Demonstrates a matrix multiply using OpenMP. Threads share row iterations
*   according to a predefined chunk size.
* AUTHOR: Blaise Barney
* LAST REVISED: 06/28/05
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>


#define NRA 1000                /* number of rows in matrix A */
#define NCA 1000                 /* number of columns in matrix A */
#define NCB 1000                  /* number of columns in matrix B */
#define N 1000

int main (int argc, char *argv[]) 
{
int	tid, nthreads, i, j, k, chunk;

// double	a[NRA*NCA],           /* matrix A to be multiplied */
//	b[NCA*NCB],           /* matrix B to be multiplied */
//	c[NRA*NCB];           /* result matrix C */

 double *a = new double [N*N];
 double *b = new double [N*N];
 double *c = new double [N*N];

chunk = 10;                    /* set loop iteration chunk size */

/*** Spawn a parallel region explicitly scoping all variables ***/
#pragma omp parallel shared(a,b,c,nthreads,chunk) private(tid,i,j,k)
  {
  tid = omp_get_thread_num();
  if (tid == 0)
    {
    nthreads = omp_get_num_threads();
    // printf("Starting matrix multiple example with %d threads\n",nthreads);
    // printf("Initializing matrices...\n");
    }
  /*** Initialize matrices ***/
  #pragma omp for schedule (static, chunk) 
  for (i=0; i<NRA; i++)
    for (j=0; j<NCA; j++)
      a[N*i+j]= i+j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<NCA; i++)
    for (j=0; j<NCB; j++)
      b[N*i+j]= i*j;
  #pragma omp for schedule (static, chunk)
  for (i=0; i<NRA; i++)
    for (j=0; j<NCB; j++)
      c[N*i+j]= 0;

  /*** Do matrix multiply sharing iterations on outer loop ***/
  /*** Display who does which iterations for demonstration purposes ***/
  printf("Thread %d starting matrix multiply...\n",tid);
  #pragma omp for schedule (static, chunk)
  for (i=0; i<NRA; i++)    
    {
      // printf("Thread=%d did row=%d\n",tid,i);
    for(j=0; j<NCB; j++)       
      for (k=0; k<NCA; k++)
        c[N*i+j] += a[N*i+k] * b[N*k+j];
    }
  }   /*** End of parallel region ***/

/*** Print results ***/
  /*
printf("******************************************************\n");
printf("Result Matrix:\n");
for (i=0; i<NRA; i++)
  {
  for (j=0; j<NCB; j++) 
    printf("%6.2f   ", c[N*i+j]);
  printf("\n"); 
  }
printf("******************************************************\n");
printf ("Done.\n");*/

  delete [] a;
  delete [] b;
  delete [] c;
}
