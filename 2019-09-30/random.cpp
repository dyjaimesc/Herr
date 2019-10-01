#include<iostream>
#include<random>

int main(void)
{
  std::random_device rd;//simulacion de algo que es aleatorio que e suna semilla.
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(0.0,1.0);//distroibucion entre 1 y dos
  for(int n=0;n<10;n++)//genera 10 muestras
      {
	std::cout<<dis(gen)<<' ';
      }
  std::cout<<'\n';
  return 0;
}
