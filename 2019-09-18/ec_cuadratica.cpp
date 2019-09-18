#include<cstdio>
#include<cmath>

typedef float REAL;
int main(void)
{
  int N=10;
  REAL a=1.0, b=1.0, c=0.0;
  
  
  REAL x1=0.0,x2=0.0,y1=0.0,y2=0.0;

  for(int n=1;n<N;n++)
    {
      c=std::pow(10.0,n);
      REAL det=std::sqrt(b*b-4*a*b);
      x1=(-b+det)/(2*a);
      x2=(-b+det)/(2*a);
      y1=(-2*c)/(b+det);
      y2=(-2*c)/(b-det);;
  printf("%10.6f\n",x1);
    }
  return 0;
}
