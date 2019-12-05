all: random_example.x ejecutar 


%.x: random_example.cpp
	g++ -std=c++11 -Wall  $< -o random_example.x

ejecutar:
	./random_example.x

profiling:
	gprof 1_test_gprof.x gmon.out>analisis.txt


.PHONY: clean
clean:
	rm -f *.x  *~ a.out *#  *.pdf 0 *.gp *.dat 3 gmon.out
