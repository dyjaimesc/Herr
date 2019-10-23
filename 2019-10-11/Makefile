all: compilar ejecutar

compilar: debugging.cpp
	g++ -Wall -g -fsanitize=address -fsanitize=leak -fsanitize=undefined $< -o $@

ejecutar: a.out
	gdb --tui ./a.out


.PHONY: clean
clean:
	rm -f *.x  *~ a.out *# *.txt *.pdf
