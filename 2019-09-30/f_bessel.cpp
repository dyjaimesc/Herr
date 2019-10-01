#include<cstdio>
#include<cmath>

int main()
{
  const double xini=0.0;
  const double xfin=20.0;
  const double dx=0.1;
  const double pasos=(xfin-xini)/dx;
  const double nu=1.0;
  
  
  double x=xini;
  
  
  for(int i=0;i<pasos;i++)
    {
      x+=dx;
      printf("%10.5f %10.5f \n",x,std::cyl_bessel_i(nu,x));

      
    }
  return 0;
}
