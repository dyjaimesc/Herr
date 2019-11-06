#include<cstdio>

int main(void)
{
  #pragma omp parallel
  {
    std::printf("hola mundo\n");
  }
  return 0;
}
