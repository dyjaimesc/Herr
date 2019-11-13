#include <iostream>
#include <cstdio>
#include<fstream>
#include <cstring>
#include "papi.h"

const int N =512;//matrix size/2048

int blocking_multiplication(const double * F, const double * FT, double * P,int);
int lectura();

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%              Main

int main(int argc, char **argv)
{
  // Matrix declaration : Modeled as 1D array
  // Declare as pointers and ask for memory to use the heap

  double *A = new double [N*N], *B = new double [N*N], *C = new double [N*N];
  int Np=lectura();

  // initialize matrices

  for (int ii =0; ii < N; ++ii) {
    for (int jj =0; jj < N; ++jj) {
      A[ii*N + jj] = ii + jj + 1; 
      B[ii*N + jj] = ii + jj + 2;
      C[ii*N + jj] = 0.0;
    }
  }

  // PAPI vars
  float real_time, proc_time,mflops;
  long long flpops;
  float ireal_time, iproc_time, imflops;
  long long iflpops;
  int retval;

      // PERFOMANCE MEASURE
      
      // start PAPI counters

  //printf("%d\n",Np);

  if((retval=PAPI_flops(&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK)
    {
      printf("Could not initialise PAPI_flops \n");
      printf("Your platform may not support floating point operation event.\n");
      printf("retval: %d\n", retval);
      exit(1);
    }
  /////////////////////////////////////////
  blocking_multiplication(B, A, C, Np);

     // 
     /////////////////////////////////////////////////
  if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
    {
      printf("retval: %d\n", retval);
      exit(1);
    }

  //printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n",real_time, proc_time,flpops,mflops);
 
  printf("%5d %f  %f  %lld  %f\n",lectura(),real_time, proc_time,flpops,mflops);

// Do something here, like computing the average of the resulting matrix, to avoid the optimizer deleting the code
  
  double suma=0; 

  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      suma+=C[i*N+j];
    }
  }

  delete [] A;
  delete [] B;
  delete [] C;
      
  return 0;
}


    



int blocking_multiplication(const double * F, const double * FT, double * P,int s)
{
  for (int ii = 0; ii < N; ii += s) {
    for (int jj = 0; jj < N; jj += s) {
      for(int kk = 0; kk < N; kk += s){
	for(int i = 0; i < s; i++){
	  for(int j = 0; j < s; j++){
	    for(int k = 0; k < s; k ++){
	      P[(ii + i)*N + jj + j] += 2.4368*F[(ii + i)*N + kk + k]*FT[(kk + k)*N + jj + j];
	    }
	  }
	}
      }
    }
  }
   return 0;
}


//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//////                 Funcion utilizada en la automatizacion del programa

int lectura(){
  int x=0;//Variable para guardar  el numero del bloque que viene dado del un archivo de texto externo creado en el script
  int Longitud_cadena=0;
  char buffer[6];   //Creo una variable char para guardar renglon a renglon cada uno de los renglones de los datos
  char temporal[6];
  
  std::ifstream archivo;
  std::string texto;
  archivo.open("entrada.dat",std::ios::in);
  if(archivo.fail()){
    printf("No se pudo abrir el archivo");
  }

  while(!archivo.eof()){//Mientras no sea el final del archivo
    getline(archivo,texto,'\n');
    Longitud_cadena=texto.length();
    size_t length = texto.copy(buffer,Longitud_cadena,0);   //convierto el string en char, y guardo la longitud del char en length
    //  std::cout<<temporal<<std::endl;
    buffer[length]='\0';    //despues de terminar los caracteres de mi char dejo vacia la siguiente casilla
     // std::cout<<"longitud "<<Longitud_cadena<<std::endl;
    length=texto.copy(temporal,Longitud_cadena,0);
    x=std::atoi(temporal);
  }
 
  //std::cout << x<<std::endl;

  archivo.close();
  return x;
}





