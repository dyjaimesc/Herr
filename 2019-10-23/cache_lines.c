#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void f1(float *** x, int n);
void f2(float *** x, int n);
void f3(float *** x, int n);

int main(){
  const int n = 128;
  clock_t cputime1, cputime2;
  float ***a;
  int i,j,k;

  // Allocating memory for array/matrix
  a = malloc(n*sizeof(float **));
  for (i=0; i<n; i++){
    a[i] = malloc(n*sizeof(float*));
    for (j=0; j<n; j++)
      a[i][j] = malloc(n*sizeof(float));
  }

  cputime1 = clock();
  f1(a, n);
  cputime2=clock() - cputime1;
  printf("Time with fast index inside: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);


  cputime1 = clock();
  f2(a, n);
  cputime2=clock() - cputime1;
  printf("Time with fast index outside: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);

  cputime1 = clock();
  f3(a, n);
  cputime2=clock() - cputime1;
  printf("Time with fast index outside substracting: %lf\n", ((double)cputime2)/CLOCKS_PER_SEC);

  // Clearing memory
  for (i=0; i<n; i++){
    for (j=0; j<n; j++)
      free(a[i][j]);
    free(a[i]);
  }
  free(a);

  return 0;
}

void f1(float *** x, int n)
{
  for (int k=0; k<n; ++k)
    for (int j=0; j<n; ++j)
      for (int i=0; i<n; ++i)
        x[i][j][k] = 1.0;
}
void f2(float *** x, int n)
{
  for(int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      for (int k=0; k<n; ++k)
        x[i][j][k] = 2.3;  
}

void f3(float *** x, int n)
{
  for(int i=n-1; i>=0; i--)
    for (int j=n-1; j>=0; j--)
      for (int k=n-1; k>=0; k--)
        x[i][j][k] = 3.2;  
}
