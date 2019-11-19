ALL:	compilar out.txt


compilar: papi_example.c
	gcc  -Wall -o0 -g    $< -lpapi

out.txt: 0
	./$< >$@



.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#  *.pdf 0
