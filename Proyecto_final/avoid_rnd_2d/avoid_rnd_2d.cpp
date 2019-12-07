#include <random>
#include <iostream>
#include <cstdio>

// double desplazamiento();
 
int main()
{
  int N=1;//Repeticiones
  
   int Steps=10;
   int dim=2;//Dimension del programa

   
   double x=0.0;
   double random=0.0;

int Position[N*Steps*2];//Guarda la posicion de los puntos utilizados
 int XY[Steps+1][dim];
  int X[N];
  int Y[N];
  int Avg[Steps]; //Valor promedio de la posicion
   
  // int *X= new int[N+1];
  // int *Y= new int[N+1];
  // int *Avg= new int[Steps+1]; //Valor promedio de la posicion
  for(int i=0;i<=Steps;++i)
    for(int j=0;j<dim;++j)
      XY[i][j]=0;
  
   for(int i=0;i<N;++i)
     {
       X[i]=0;  Y[i]=0;
     }

   for(int i=0;i<Steps;++i)
     Avg[i]=0;
     
   
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0,  1.0);

 for(int i=0;i<N;++i)
   {
     // printf("%5d",n);
     for(int j=0;j<Steps;++j){
       
       random=dis(gen);
       if(random<0.25){
	 X[i]+=1;
       }
       else if(random<0.5 ){
	 Y[i]+=1;
       }
       else if(random<0.75){
	 X[i]-=1;
       }
       else{
	 Y[i]-=1;
       }
       XY[j+1][0]=X[i]+XY[j][0];
       XY[j+1][1]=Y[i]+XY[j][1];
       X[i]=0;
       Y[i]=0;
     }
   }

 for(int i=0;i<=Steps;++i){
   for(int j=0;j<dim;++j){
      printf(" %3d ",XY[i][j]);
   }
   printf("\n");
 }
// std::cout << '\n';

     // delete [] X;
     // delete [] Y;
     // delete [] Avg;
}

// double desplzamiento(){
//   return 0;
// }
