#include<cstdio>
#include<fstream>

int suma_armonica(int,int);

int main(void)
{
  int ini=1;
  int fin=1000;
  suma_armonica(ini,fin);
  
  return 0;
}

int suma_armonica(int ii,int end)
{
  std::ofstream fout("datos.txt");
  double suma=0.0;
  double div=0.0;

  for(int j=ii;j<=end;j++)
  {
    
     div=1.0/j;
     suma+=div;
     fout<<j<<"\t"<<suma<<"\n";
     // printf("%3d %8.5f\n",j,suma);
  }
}
