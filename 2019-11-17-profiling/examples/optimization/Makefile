all: cache_lines.x ejecutar

%.x: cache_lines.c
	gcc -g -Wall  $< -o $@


ejecutar:
	./cache_lines.x

profiling:
	gprof cache_lines.x gmon.out>analisis.txt


.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#  *.pdf 0 *.gp *.dat 3 gmon.out
