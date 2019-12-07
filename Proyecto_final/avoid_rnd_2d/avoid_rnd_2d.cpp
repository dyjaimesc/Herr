#include <random>
#include <iostream>
#include <cstdio>

// double desplazamiento();
 
int main()
{
  int N=500;//Repeticiones
  
  int Steps=1000;
  int dim=2;//Dimension del programa
  int contador=0;//Cuenta los pasos que se van realizando
  double x=0.0;
  double random=0.0;

  int Position[N*Steps*2];//Guarda la posicion de los puntos utilizados
  //int XY[Steps*dim+1];
  int x1=0,x2=0;//Variables temporales
  int X1[Steps*N];
  int X2[Steps*N];
  int Avg[Steps]; //Valor promedio de la posicion
   
  // int *X= new int[N+1];
  // int *Y= new int[N+1];
  // int *Avg= new int[Steps+1]; //Valor promedio de la posicion
  // for(int i=0;i<=Steps;++i)
  //   for(int j=0;j<dim;++j)
  //     XY[i][j]=0;
  
   for(int i=0;i<Steps*N;++i)
     {
       X1[i]=0;  X2[i]=0;
     }

   for(int i=0;i<Steps;++i)
     Avg[i]=0;
     
   
    std::random_device rd;  //Will be used to obtain a seed for the random number engine
    std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
    std::uniform_real_distribution<> dis(0.0,  1.0);

 for(int i=0;i<N;++i)
   {
     // printf("%5d",n);
     for(int j=0;j<Steps-1;++j){
       
       random=dis(gen);
       if(random<0.25){
	 x1+=1;
       }
       else if(random<0.5 ){
	 x2+=1;
       }
       else if(random<0.75){
	 x1-=1;
       }
       else{
	 x2-=1;
       }
       //XY[j+1][0]=X[i]+XY[j][0];
       //XY[j+1][1]=Y[i]+XY[j][1];
       X1[j+1+i*Steps]=x1+X1[j+i*Steps];
       X2[j+1+i*Steps]=x2+X2[j+i*Steps];
       x1=0;
       x2=0;
     }
   }

 for(int i=0;i<Steps;++i){
   for(int j=i;j<Steps*N;j+=Steps){
     printf(" %4d %4d ",X1[j],X2[j]);
     Avg[i]+=X1[j]*X1[j]+X2[j]*X2[j];
   }
   printf("%7.3f %5d \n",Avg[i]*1.0/N,contador);
   contador++;
 }
// std::cout << '\n';

     // delete [] X;
     // delete [] Y;
     // delete [] Avg;
}

// double desplzamiento(){
//   return 0;
// }
