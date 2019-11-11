#include<iostream>
#include<cstdio>
#include<cmath>
#include "papi.h"

const int N=1024;

//double imprimir(double *M1,int);
//double multipli_mtx(double *M1,double *M2, double *P);
int mul_blocking(double *M1,double *M2, double *P,int);


int main()
{
  
  double *A= new double [N*N], *B=new double[N*N],*C=new double[N*N], *Pr=new double[N*N];
  int Np=N;

  //inicializo la matriz

  for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    A[i*N+j]=i+j+1.0;
	    //printf("%d %d %5.3f %f\n",i,j,A[i*N+j],i+j+1.0);
	    B[i*N+j]=1.0*N*i+j;
	    Pr[i*N+j]=0.0;
	  }
    }
  
  //imprimir(A,N);
  //imprimir(B,N);
  //multipli_mtx(A,B,C);
  //imprimir(C,N);

   // PAPI vars
      float real_time, proc_time,mflops;
      long long flpops;
      float ireal_time, iproc_time, imflops;
      long long iflpops;
      int retval;

      //Empeizo mi buclq eue cambia los valores del bloque

  for(int i=1;i<12;i++)
    {
      printf("%d\n",Np);

  if((retval=PAPI_flops(&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK)
        {
        printf("Could not initialise PAPI_flops \n");
        printf("Your platform may not support floating point operation event.\n");
        printf("retval: %d\n", retval);
        exit(1);
        }
      
      mul_blocking(A,B,Pr,Np);
      // imprimir(Pr,N);

      if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
        {
        printf("retval: %d\n", retval);
        exit(1);
        }


      printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n",
  	 real_time, proc_time,flpops,mflops);

      //Reinicio matriz producto
      for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	   Pr[i*N+j]=0.0;
      
      Np/=2;
    }

  
  delete [] A;
  delete [] B;
  delete [] C;
  delete [] Pr;
  
  return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
/*
double imprimir( double *M1,int n)
{
 
  for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
	  {
	    printf("%10.3f ",M1[i*n+j]);
	  }
	printf("\n");
    }
  printf("\n");
  return 0;
}

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

double multipli_mtx(double *M1,double *M2, double *P)
{
  double sum=0.0;

  //imprimir(M1,N);
  //imprimir(M2,N);
  
  for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    for(int k=0;k<N;k++)
	      {
		sum+=M1[i*N+k]*M2[k*N+j];
	      }
	    P[i*N+j]=sum;
	    sum=0.0;
	  }
    }
  

     for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    P[i*N+j]=1.0;
	    printf("%d %d %5.3f %f\n",i,j,P[i*N+j],i+j+1.0);
	  }
	  }

  return 0;
}
*/

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

int mul_blocking(double *M1,double *M2, double *P,int np)
{
  //  int n=N/np;
  // imprimir(M1,N);
  //imprimir(P,N);
 
  for(int m=0; m<N ; m+=np)
    for(int l=0; l<N ;l+=np)
      for(int k=0; k<N ; ++k)
	for(int j=l; j<std::min(l+np,N) ;j++)
	  for(int i=m; i<std::min(m+np,N) ;i++)
	    {
	      P[N*k+j]+=M1[N*k+i]*M2[N*i+j];
	    }
	  
  return 0;   
}

///%%%%%%%%%%%%%%%%%%%%%%%%5
