#include<iostream>
#include<cstdio>
#include<cmath>

const int N=4;

double imprimir(double *M1);
double multipli_mtx(double *M1,double *M2, double *P);
void transpuesta(double *M1,double *M2);

int main()
{
  printf("Hola\n");

  double *A= new double [N*N], *B=new double[N*N],*C=new double[N*N], *AT=new double[N*N];

  //inicializo la matriz

  for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    A[i*N+j]=i+j+1.0;
	    //printf("%d %d %5.3f %f\n",i,j,A[i*N+j],i+j+1.0);
		   
	    B[i*N+j]=1.0*N*N-i-j-1.0;
	    
	    
	  }
    }
 imprimir(A);
  imprimir(B);
  multipli_mtx(A,B,C);
  imprimir(C);
  transpuesta(C,AT);
  imprimir(AT);
  delete [] A;
  delete [] B;
  delete [] C;
  delete [] AT;
  
  return 0;
}


double imprimir( double *M1)
{
 
  for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    printf("%10.3f ",M1[i*N+j]);
	  }
	printf("\n");
    }
  printf("\n");
  return 0;
}


double multipli_mtx(double *M1,double *M2, double *P)
{
  double sum=0.0;

  imprimir(M1);
  imprimir(M2);
  
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
  

  /*   for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    P[i*N+j]=1.0;
	    printf("%d %d %5.3f %f\n",i,j,P[i*N+j],i+j+1.0);
		   
	    
	    
	  }
	  }*/

  return 0;
}

void transpuesta(double *M1,double *M2)
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    M2[i*N+j]=M1[j*N+i];
	  }
    }
}
