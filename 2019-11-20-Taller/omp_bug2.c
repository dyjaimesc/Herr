/******************************************************************************
* FILE: omp_bug2.c
* DESCRIPTION:
*   Another OpenMP program with a bug. 
* AUTHOR: Blaise Barney 
* LAST REVISED: 04/06/05 
******************************************************************************/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) 
{
  int nthreads, i, tid;
  float total=0.0,suma=0.0;

  
/*** Spawn parallel region ***/
#pragma omp parallel private(tid) reduction(+:total)
  {
    suma=0.0;
  /* Obtain thread number */
  tid = omp_get_thread_num();
  /* Only master thread does this */
  if (tid == 0) {
    nthreads = omp_get_num_threads();
    printf("Number of threads = %d\n", nthreads);
    }
  printf("Thread %d is starting...\n",tid);

    #pragma omp barrier
  
  /* do some work */
  // total = 0.0;
#pragma omp  for    schedule(dynamic,2) //	\
  private(i)//				\
  reduction(+:total)
  for (i=0; i<1000000; i++) {
     total = total + i*1.0;
     suma=suma+i*1.0;
  }
  printf ("Thread %d is done! Total= %f\n",tid,total);
  //   #pragma omp barrier
  //  printf ("Thread %d is done! Total= %f\n",tid,total);
  //printf ("LA suma total es= %f\n",suma);
  
  } /*** End of parallel region ***/
     printf ("LA suma total es= %f\n",total);
}
