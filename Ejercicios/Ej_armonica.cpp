#include<cstdio>
#include<cmath>

double f_armonica_dw(int);
double f_armonica_up(int);

int main(void)
{
  int n=25000;
  double dif=0.0;
  double add=0.0;

  for(int i=1;i<n;i+=10)
    {
      dif=std::fabs(f_armonica_dw(i)-f_armonica_up(i));
      add=f_armonica_dw(i)+f_armonica_up(i);
      printf("%5d %30.20f %30.20f %30.20f\n",i,dif/add,dif,add);
    }
  return 0;
}

double f_armonica_dw(int N)
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

double f_armonica_up(int N)
{
  double x=0.0;
  double y=0.0;

  for(int i=1;i<=N;i++)
    {
      y=1.0/i;
      x+=y;
    }
  return x;
}
  
