all: f_gamma.x f_bessel.x random.x random-histogram.x random.cpp random-histogram.cpp f_gamma.txt f_bessel.txt random.txt random-histogram.txt f_gamma.pdf f_bessel.pdf random.pdf random-histogram.pdf

%.x: %.cpp
	g++ -std=c++17 $< -o $@

%.txt: %.x
	./$< > $@

%.pdf: %.gp %.txt
	gnuplot $<

.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#

