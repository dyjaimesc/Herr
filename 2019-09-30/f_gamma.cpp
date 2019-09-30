#include<cstdio>
#include<cmath>



int main()
{
  const double xini=0.0;
  const double xfin=8.0;
  const double dx=0.0001;
  const double pasos=(xfin-xini)/dx;
  
  
  double x=xini;
  
  for(int i=0;i<pasos;i++)
    {
      x+=dx;
      printf("%10.5f %10.5f \n",x,std::tgamma(x));

      
    }
  return 0;
}
