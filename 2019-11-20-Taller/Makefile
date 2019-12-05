all: omp_bug2.x  ejecutar

%.x: omp_bug2.c
	gcc -Wall -g -fsanitize=address -fsanitize=leak -fsanitize=undefined $< -o $@ -fopenmp

ejecutar:
	./omp_bug2.x




.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#  *.pdf 0 *.gp *.dat 3 gmon.out callgrind.out.*
