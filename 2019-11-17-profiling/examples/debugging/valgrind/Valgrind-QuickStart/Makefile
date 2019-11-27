all: b.x ejecutar

%.x: b.c
	gcc -g -Wall  $< -o $@


ejecutar:
	valgrind --tool=memcheck --leak-check=yes  ./a.x

profiling:
	gprof cache_lines.x gmon.out>analisis.txt


.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#  *.pdf 0 *.gp *.dat 3 gmon.out
