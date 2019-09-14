#include<iostream>
#include<cstdio>

int main(void)
{
  double eps=1.0;
  double one=1.0;

  for(int i=1;i<300;i++)
    {
      eps=eps/2.0;
      
      one=1.0+eps;
       printf ("%5d %25.20e %25.20e\n", i, one,eps);
  
    }
   
 
  return 0;
}
