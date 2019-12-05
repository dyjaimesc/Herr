#include <random>
#include <iostream>
#include <cstdio>

// double desplazamiento();
 
int main()
{
  int N=5;//Repeticiones
   int Steps=4;
   //int x=0;

  int *X= new int[N+1];
  
   for(int i=0;i<=N;++i)
     {
       X[i]=0;
     } 
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0,  1.0);

   
for (int n = 1; n <=Steps; ++n) {
  printf("%3d",n);
	 
  for(int i=1;i<=N;++i)
   {
      if(dis(gen)>0.5){
	X[i]+=1;
	      }
      else{
	X[i]-=1;
		
      }
      printf("%3d",X[i]);
	
      //std::cout << dis(gen) << ' ';
   }
 std::cout << '\n';
 }
 std::cout << '\n';
    
     delete [] X;
}

// double desplzamiento(){
//   return 0;
// }
