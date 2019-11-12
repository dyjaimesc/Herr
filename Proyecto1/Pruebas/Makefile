ALL:	compilar ejecutar


compilar: multi_blocking.cpp
	g++ -std=c++11 -Wall -o0 -g    $< -lpapi

ejecutar: 0
	./$<



.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#  *.pdf 0
