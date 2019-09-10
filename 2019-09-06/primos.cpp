#include<iostream>
#include<cstdio>

int primos(int);
//int suma(int);

int main(void)
{
  int inicial=5;
  int final=10;
  int salida=0;
    for(int i=inicial;i<=final;i++)
      {
	if(primos(i)==1)
	  {
	    salida=salida+i;
	    std::cout<<i<<"\n";
	  }

	
      }
    std::cout<<salida<<"\n";
  return 0;
}

int primos(int numero)
{
   for(int i=2;i<=numero/2;i++)
    {
      if(numero%i==0) return 0;
    }
   return 1; //Retorna 1 cuando el numero es primo
}



