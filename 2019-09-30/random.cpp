#include<iostream>
#include<random>

int main(void)
{
  const int pasos=10000;
  int semilla=1; //cuelquier numero positivo  Si la semilla es constante las serie generada no cambia
  // std::random_device rd;//simulacion de algo que es aleatorio que e suna semilla.
  std::mt19937 gen(semilla);
  std::uniform_real_distribution<> dis(0.0,1.0);//distroibucion entre 1 y dos
  for(int n=0;n<pasos;n++)//genera 10 muestras
      {
	std::cout<<dis(gen)<<'\n';
      }

  return 0;
}
