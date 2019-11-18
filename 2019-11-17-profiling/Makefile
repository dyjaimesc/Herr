all: 1_test_gprof.x ejecutar profiling

1_test_gprof.x: 1_test_gprof.c
	gcc -Wall -pg $< -o 1_test_gprof.x

ejecutar:
	./1_test_gprof.x

profiling:
	gprof 1_test_gprof.x gmon.out>analisis.txt


.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#  *.pdf 0 *.gp *.dat 3 gmon.out
