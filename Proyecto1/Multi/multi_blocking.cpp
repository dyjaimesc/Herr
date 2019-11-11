#include<iostream>
#include<cstdio>
#include<cmath>

const int N=4;

double imprimir(double *M1,int);
double multipli_mtx(double *M1,double *M2, double *P);
void mul_blocking(double *M1,double *M2, double *P,int);
void multi_mtx(double *M1,double *M2, double *P);

int main()
{
  

  double *A= new double [N*N], *B=new double[N*N],*C=new double[N*N], *AT=new double[N*N];
  int Np=N;

  //inicializo la matriz

  for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
	  {
	    A[i*N+j]=i+j+1.0;
	    //printf("%d %d %5.3f %f\n",i,j,A[i*N+j],i+j+1.0);
	    B[i*N+j]=1.0*N*i+j;
	  }
    }
  
  imprimir(A,N);
  imprimir(B,N);
  multipli_mtx(A,B,C);
  imprimir(C,N);

  for(int i=1;i<3;i++)
    {
      printf("%d\n",Np);
      mul_blocking(C,B,AT,Np);
      imprimir(AT,N);
      Np/=2;
    }

  
  delete [] A;
  delete [] B;
  delete [] C;
  delete [] AT;
  
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
  int n=N/np;
  n=1;
  // if(N==np){n=0;}
  // else{n=N/np;}
  double *MI1= new double [np*np], *MI2=new double[np*np]; //Matrices internas que voy a mandar a multiplicar
  
  // double sum=0.0;
  
  for(int k=0;k<n;k++)
    {
      for(int l=0;l<n;l++)
	{
	  for(int m=0;m<n;m++)
	    {
        for(int i=0;i<np;i++)
	  {
	    for(int j=0;j<np;j++)
	      {
		//MI1[i*np+j]=M1[N*(np*k+i)+np*l+j];
		//MI2[j*np+i]=M2[N*(np*l+j)+np*k+i];
		MI1[i*np+j]=M1[N*(np*k+i)+np*l+j];
		MI2[j*np+i]=M2[N*(np*l+j)+np*k+i];
	      }
	  }
	//	printf("matrices a multiplicar %d %d\n",k,l);
	//imprimir(MI1,np);	
	//imprimir(MI2,np);
	    }
	}
    }

    delete [] MI1;
    delete [] MI2;
}

///%%%%%%%%%%%%%%%%%%%%%%%%5
//Funcion que multiplica las matrices que se le introduzcan desde blocking

void multi_mtx(double *M1,double *M2, double *P)
{
  double sum=0.0;

  
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

  
}
