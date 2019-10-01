all: f_gamma.x f_bessel.x f_gamma.txt f_bessel.pdf f_gamma.pdf f_bessel.pdf

%.x: %.cpp
	g++ -std=c++17 $< -o $@

%.txt: %.x
	./$< > $@

%.pdf: %.gp %.txt
	gnuplot $<

