#include<iostream>
#include<cstdio>
#include<cmath>
#include<fstream>



int main(void)
{
  std::ofstream fout("datos.txt");
  double x=0.0123;//radianes
  const int N=100;
 

  for(x=0.1;x<8.0;x+=0.1)
    {
       double sum =x;
       double term=x;
       for(int i=2;i<N;++i)
	 {
	   term=term*(-1)*x*x/((2*i)*(2*i+1));
	   sum += term;
      
	 }
       fout<<x<<"/t"<<sum << "/t" << std::sin(x) << "/n";
    }
    

  // x=sin(1.0);
  //  printf (" %10.8e\n", x);


   
  return 0;
}
