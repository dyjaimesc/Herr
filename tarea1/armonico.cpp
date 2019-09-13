#include<cstdio>

int suma_armonica(int,int);

int main(void)
{
  int ini=1;
  int fin=10;
  suma_armonica(ini,fin);
  
  return 0;
}

int suma_armonica(int ini,int fin)
{
  double suma=0.0;
  double div=0.0;
  for(int i=ini;i<=fin;i++);
  {
    div=1.0;
    suma+=div;
    printf("%d %6.5f",i,suma);
  }
}
