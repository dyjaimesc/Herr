all: f_gamma.x f_bessel.x random.cpp f_gamma.txt f_bessel.txt random.txt f_gamma.pdf f_bessel.pdf random.pdf

%.x: %.cpp
	g++ -std=c++17 $< -o $@

%.txt: %.x
	./$< > $@

%.pdf: %.gp %.txt
	gnuplot $<

.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#

