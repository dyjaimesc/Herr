//Ejercicio que aproxima la constante de euler restando el valor de la suma armonica al valor del logaritmo

#include<cstdio>
#include<cmath>

double f_armonica(int);


int main(void)
{
  int n=50000;
  double euler1=0.0;
  double euler2=0.0;
  double arm=0.0;

  for(int i=1;i<n;i+=50)
    {
     arm=f_armonica(i);
      euler1=arm-std::log(i);

      euler2=arm-std::log(i+0.5);
     printf("%5d %30.20f %30.20f\n",i,euler1,euler2);
    }
  return 0;
}

double f_armonica(int N)
{
  double x=0.0;
  double y=0.0;
  for(int i=N;i>0;--i)
    {
      y=1.0/i;
      x+=y;
    }
  return x;
}

