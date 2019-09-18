#include<cstdio>
#include<cmath>

typedef float REAL;

REAL suma1(int);



int main(void)
{
  for(int n=1;n<10;n++)
    {
      REAL S1=suma1(n);
      printf("%10.6f\n",S1);
    }
  return 0;
}

REAL suma1(int n)
{
  REAL out=0.0;
  REAL signo=-1.0;
  for(int i=1;i<=2*n;i++)
    {
      
      out+=signo*i/(i+1);
      signo*=-1;
      
    }
    return out;
}
