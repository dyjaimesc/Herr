#include<cstdio>

int primos(int);

int main(void)
{
  int inicial=500;
  int final=12400;
  int contador=0;
  int suma=0;

  for(int i=inicial;i<=final;i++)
    {
      if(primos(i)==1)
	{
	  // printf("%d \n",i);
	  contador=++contador;
	  suma+=i;
	}
    }
  printf("Hay %d numeros primos entre %d y %d; su suma es %d \n", contador,inicial, final,suma);
  
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

