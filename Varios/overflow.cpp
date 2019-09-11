#include <iostream>

int fsuma(int);

int main()
{ int variable=0;
  variable=fsuma(variable);
  std::cout<<"el mayor entero es "<<variable<< " \n";
  return 0;
}

int fsuma(int n)
{int x=1,y=0;
  
  while(x>0)
    { y=x;
      x+=1;
    }
  return y;
}
