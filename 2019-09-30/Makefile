all: f_gamma.x datos.txt fig.pdf

f_gamma.x: f_gamma.cpp
	g++ -std=c++11 $< -o $@

datos.txt: f_gamma.x
	./$< > $@

fig.pdf: plot.gp datos.txt
	gnuplot $<

