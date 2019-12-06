#include <random>
#include <iostream>
#include <cstdio>

// double desplazamiento();
 
int main()
{
  int N=800;//Repeticiones
  
   int Steps=100;
   
   double x=0.0;
   double random=0.0;

  int *X= new int[N+1];
  int *Y= new int[N+1];
  int *Avg= new int[Steps+1]; //Valor promedio de la posicion
  
   for(int i=0;i<=N;++i)
     {
       X[i]=0;
       Y[i]=0;
     }

   for(int i=0;i<=Steps;++i)
     {
       Avg[i]=0;
     }
   
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0,  1.0);

   
for (int n = 1; n <=Steps; ++n) {
  printf("%5d",n);

   for(int i=1;i<=N;++i)
   {
     random=dis(gen);
      if(random<0.25){
	X[i]+=1;
      }
      else if(random<0.5 && random>=0.25){
	Y[i]+=1;
      }
      else if(random<0.75 && random>=0.5){
	X[i]-=1;
      }
      else{
	Y[i]-=1;
      }
      
      printf(" %5d %5d ",X[i],Y[i]);
	
      //std::cout << dis(gen) << ' ';
      Avg[n]+=X[i]*X[i]+Y[i]*Y[i];
   }
  x=Avg[n]*1.0/N;

  printf(" %5.1f ",x);

  std::cout << '\n';
 }
// std::cout << '\n';

     delete [] X;
     delete [] Y;
     delete [] Avg;
}

// double desplzamiento(){
//   return 0;
// }
