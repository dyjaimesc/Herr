#include <iostream>
#include <cstdio>
#include <cstdlib>
#include<fstream>
#include <cstring>
#include <eigen3/Eigen/Dense>
#include "papi.h"


int code_to_be_measured(const Eigen::MatrixXd & M, Eigen::MatrixXd & MT);
int lectura();
const int N=lectura();
//const int N =8;

int main(int argc, char **argv)
{
   // Matrix declaration 
   Eigen::MatrixXd A(N, N), AT(N, N);

  // initialize matrices
    for (int ii =0; ii < N; ++ii) {
      for (int jj =0; jj < N; ++jj) {
	A(ii, jj)  = ii + jj + 1; 
  	AT(ii, jj) = 0.0;
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
   if((retval=PAPI_flops(&ireal_time,&iproc_time,&iflpops,&imflops)) < PAPI_OK)
   {
      printf("Could not initialise PAPI_flops \n");
      printf("Your platform may not support floating point operation event.\n");
      printf("retval: %d\n", retval);
      exit(1);
       }

code_to_be_measured(A, AT);
     
   if((retval=PAPI_flops( &real_time, &proc_time, &flpops, &mflops))<PAPI_OK)
   {
      printf("retval: %d\n", retval);
      exit(1);
        }

printf("%5d %f  %f  %lld  %f\n",lectura(),real_time, proc_time,flpops,mflops);
   //  printf("Real_time: %f Proc_time: %f Total flpops: %lld MFLOPS: %f\n",real_time, proc_time,flpops,mflops);
      
     // Do something here, like computing the average of the resulting matrix, to avoid the optimizer deleting the code

  int suma=0;
    for (int ii =0; ii < N; ++ii) {
     for (int jj =0; jj < N; ++jj) {
        suma +=  AT(ii, jj); 
         }
     }
    // printf("%.15e\n", suma);
      
   return 0;
}


int code_to_be_measured(const Eigen::MatrixXd & M, Eigen::MatrixXd & MT)
{
    MT = 2.4368*M.transpose().eval();
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

