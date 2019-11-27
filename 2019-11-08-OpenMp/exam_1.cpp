  #include <stdio.h>
    int main(void)
    {

      int a=9;
    #pragma omp parallel num_threads (4)
      {
	
	double x=0;
	printf("Hello, world.\n");
	a+=3;
	//printf("%p\n",&x);
	printf("%d\n",a);
      }
      printf("%d\n",a);
      
      return 0;
    }

