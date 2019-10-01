#include<iostream>
#include<random>
#include<vector>
#include<cstdio>

int main(void)
{
  
 const int pasos=1000000;
 int semilla=1; //cuelquier numero positivo  Si la semilla es constante las serie generada no cambia

 const double xmin=0.0;
 const double xmax=1.0;
 const double dx=0.01;
 const int nbins=(xmax-xmin)/dx;
 
 std::vector<double> histo(nbins);

  // std::random_device rd;//simulacion de algo que es aleatorio que e suna semilla.
  std::mt19937 gen(semilla);
  std::normal_distribution<> dis{0.5,0.1};//distribucion normal  con media 0.5 y desviacion estandar 0.2
  
  for(int n=0;n<pasos;n++)//genera 10 muestras
      {
	double r=dis(gen);
	int irdx=int(r/dx);//Parte entera de dx
	if (0 <= irdx and irdx < nbins){
	histo[irdx]+=1;
	}
	}
	
  
  for(int i=0;i<=nbins;i++)
    {
      printf("%10.3f %10.5f\n",xmin+i*dx,histo[i]/pasos/dx);
     }

   return 0;
}
