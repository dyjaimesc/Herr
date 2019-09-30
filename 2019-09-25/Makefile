#activa optimizacion nivel 2

CXXFLAGS=-O2 -Wall

all: sumas.x datos.txt fig.pdf

sumas.x : suma.cpp
	g++ $(CXXFLAGS) $< -o $@ #Forma abreviada de poner g++ sumas.cpp -o sumas.x

datos.txt : sumas.x
	./$< > $@

fig.pdf : plot.gp datos.txt
	gnuplot $<

.PHONY: clean
clean:
	rm -f sumas.x datos.txt fig.pdf
