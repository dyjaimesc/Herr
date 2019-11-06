#include<iostream>
#include<cstdio>
#include<cmath>

const int N=3;
double imprimir(const double *M1);

int main()
{
  double *A= new double [N*N], *B=new double[N*N];

  //inicializo la matriz

  for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    A[i*N+j]=i+j+1.0;
	    //printf("%d %d %5.3f %f\n",i,j,A[i*N+j],i+j+1.0);
		   
	    B[i*N+j]=1.0*N-i-j;
	    
	  }
    }

 
  
  imprimir(A);
  
  return 0;
}

double imprimir(const double *M1)
{
 
  for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    printf("%5.3f ",M1[i+j]);
	  }
	printf("\n");
    }
  return 0;
}
