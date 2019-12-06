#include <random>
#include <iostream>
#include <cstdio>

// double desplazamiento();
 
int main()
{
  int N=1000;//Repeticiones
  
   int Steps=10000;
   int x1=0,y1=0,z1=0;
   
   double x=0.0;
   double random=0.0;
   double width=1.0/6.0;

  int *X= new int[N+1];
  int *Y= new int[N+1];
  int *Z= new int[N+1];
  int *Avg= new int[Steps+1]; //Valor promedio de la posicion
  
   for(int i=0;i<=N;++i)
     {
       X[i]=0;
       Y[i]=0;
       Z[i]=0;
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
      if(random<width){
	X[i]+=1;
      }
      else if(random<width*2.0 && random>=width){
	Y[i]+=1;
      }
      else if(random<width*3.0 && random>=width*2.0){
	Z[i]+=1;
      }
      else if(random<width*4.0 && random>=width*3.0){
	X[i]-=1;
      }
      else if(random<width*5.0 && random>=width*4.0){
	Y[i]-=1;
      }else{
	Z[i]-=1;
      }
      
      printf(" %5d %5d %6d ",X[i],Y[i],Z[i]);
	
      //std::cout << dis(gen) << ' ';
      x1=X[i]*X[i];
      y1=Y[i]*Y[i];
      z1=Z[i]*Z[i];
      Avg[n]+=x1+y1+z1;
   }
  x=Avg[n]*1.0/N;

  printf(" %5.1f ",x);

  std::cout << '\n';
 }
// std::cout << '\n';

     delete [] X;
     delete [] Y;
     delete [] Z;
     delete [] Avg;
}

// double desplzamiento(){
//   return 0;
// }
