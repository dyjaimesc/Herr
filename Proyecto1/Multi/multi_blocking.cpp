#include<iostream>
#include<cstdio>
#include<cmath>

const int N=256;

double imprimir(double *M1,int);
double multipli_mtx(double *M1,double *M2, double *P);
void mul_blocking(double *M1,double *M2, double *P,int);


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
  multipli_mtx(A,B,C);
  //imprimir(C,N);

  for(int i=1;i<10;i++)
    {
      printf("%d\n",Np);
      mul_blocking(A,B,Pr,Np);
      // imprimir(Pr,N);

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


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void mul_blocking(double *M1,double *M2, double *P,int np)
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
	  
    
}

///%%%%%%%%%%%%%%%%%%%%%%%%5
