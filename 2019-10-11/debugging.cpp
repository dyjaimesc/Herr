#include <iostream>
#include <cstdlib> //funciones de la libreria estandar

int main(int argc, char **argv)//se puede pasar argumentos a la funcion-
{
  // declare variables
  const int N = 10;
  double * array;
  //reserve memory
  array = new double [N];
  // initialise array
  for (int ii = 0; ii < N; ++ii) {
    array[ii] = 2*(++ii); // != 2*(ii++) ? 
  }
  // print some values 
  int idx = 2;
  std::cout << array[idx] << std::endl;
  idx = 10;
  std::cout << array[idx] << std::endl; // compiles, but ... 

  // free memory}x
  delete [] array;

  
  return EXIT_SUCCESS;
}
