ALL:	compilar ejecutar


compilar: multi_Matrix.cpp
	g++ -std=c++11 -Wall -g -fsanitize=address -fsanitize=leak -fsanitize=undefined $<

ejecutar: a.out
	./$<



.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#  *.pdf
