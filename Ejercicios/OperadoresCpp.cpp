#include<cstdio>
#include<iostream>

int main()
{
  const int x=10;
  int xi=0,yi=2;
  double xd=7.0, yd=25.0;

  std::cout<<"Teniendo x: "<<xi<<'\n';
  
  std::cout<<"++x: "<<++xi;
std::cout<<", el valor de actual x es:"<<xi<<'\n';

  std::cout<<"x++: "<<xi++;
std::cout<<", el valor de actual x es:"<<xi<<'\n';
 xi=+1;
 std::cout<<"x+=1: "<<xi;
std::cout<<", el valor de actual x es:"<<xi<<'\n';
/////////////////////////////////// %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
  std::cout<<"Teniendo x: "<<xi<<'\n';
  
  std::cout<<"--x: "<<--xi;
std::cout<<", el valor de actual x es:"<<xi<<'\n';

  std::cout<<"x--: "<<xi--;
std::cout<<", el valor de actual x es:"<<xi<<'\n';
 xi-=+1;
 std::cout<<"x-=1: "<<xi;
std::cout<<", el valor de actual x es:"<<xi<<'\n';

   // std::cout<<"x++: "<<xi++;
// std::cout<<", el valor de actual x es:"<<xi<<'\n';
//  std::cout<<"x*=y: "<<xi*=yi;
// std::cout<<", el valor de actual x es:"<<xi<<'\n';
//  std::cout<<"x=x*y-3: "<<xi=xi*yi-3;
//  std::cout<<", el valor de actual x es:"<<xi<<'\n';
 yi+=1;
 std::cout<<yi<<'\n';
 printf("yi: %d, ++yi:%d, yi:%d \n",yi,++yi,yi++);
 printf("yi: %d\n",yi);
  return 0;
}
