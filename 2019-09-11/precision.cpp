#include<iostream>
#include<cstdio>

int main(void)
{
  float eps=1.0;
  float one=1.0;

  for(int i=1;i<300;i++)
    {
      eps=eps/2;
      
      one=1.0+eps;
       printf ("%5d %15.10e %15.10e\n", i, one,eps);
  
    }
   
 
  return 0;
}
