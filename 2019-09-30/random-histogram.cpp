#include<iostream>
#include<random>
#include<vector>

int main(void)
{
  
 const int pasos=30;
 int semilla=1; //cuelquier numero positivo  Si la semilla es constante las serie generada no cambia

 const double xmin=0.0;
 const double xmax=1.0;
 const double dx=0.05;
 const int nbins=(xmax-xmin)/dx;
 
 std::vector<double> histo(nbins);


  // std::random_device rd;//simulacion de algo que es aleatorio que e suna semilla.
  std::mt19937 gen(semilla);
  std::uniform_real_distribution<> dis(xmin,xmax);//distroibucion entre 1 y dos

  for(int n=0;n<pasos;n++)//genera 10 muestras
      {
	double r=dis(gen);
	int irdx=int(r/dx);//Parte entera de dx
	histo[irdx]+=1;
      }
  

  for(int i=0;i<nbins;i++)
    {
      for(int j=0;j<histo[i];j++)
	{
	  std::cout<<"*";
	}
      std::cout<<'\n';
    }
  
    

  return 0;
}
