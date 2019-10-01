#include<iostream>
#include<complex>

int main(void)
{
  std::complex<double> z;

  z.real(4);
  z.imag(3);

  std::complex<double> w{-2.0,3};

  std::cout<<z+w<<'\n';
  std::cout<<z*w<<'\n';
  std::cout<<z-w<<'\n';
  std::cout<<z/w<<'\n';
  std::cout<<abs(z)<<" " << arg(z) <<'\n';
  
  return 0;
}
