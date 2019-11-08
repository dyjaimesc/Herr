all: compilar ejecutar

compilar: example_5.cpp
	g++ -std=c++17 -fopenmp $< 

ejecutar: a.out
	 OMP_NUM_THREADS=8 /usr/bin/time ./$<

.PHONY: clean
clean:
	rm -f *.x  *~ a.out *# *.txt *.pdf

