All: Ej_armonica.x Ej_arm_euler.x Ej_armonica.txt Ej_arm_euler.txt Ej_armonica.pdf Ej_arm_euler.pdf

%.x:%.cpp
	g++ -std=c++11 $< -o $@

%.txt:%.x
	./$< > $@

%.pdf:%.gp %.txt
	gnuplot $<

.PHONY: clean
clean:
	rm -f *~ *.x *.txt
