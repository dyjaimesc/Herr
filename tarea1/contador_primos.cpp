#include<cstdio>

int primos(int);//funcion que regresa 1 si el numero ingresado es primo y 0 en otro caso
int suma_primos(int,int);//funcion que suma cuantos primos hay entre un valor inicial y un valor final, suma el valor de todos estos primos; los parametros de entrada son los valores inicial y final de los primos.

int main(void)
{
  int inicial=500;
  int final=12400;

  suma_primos(inicial,final);
  
  return 0;
}

int primos(int n)
{
  for(int i=2;i<n/2;i++)
    {
      if(n%i==0)
	{  return 0;}
    }
  return 1;
}

int suma_primos(int ini, int fin)
{
  
  int contador=0;
  int suma=0;

  for(int i=ini;i<=fin;i++)
    {
      if(primos(i)==1)
	{
	  // printf("%d \n",i);
	  contador=++contador;
	  suma+=i;
	}
    }
  printf("Hay %d numeros primos entre %d y %d; su suma es %d \n", contador,ini, fin,suma);
}
