CXXFLAGS=-O2 -Wall

OBJ=sum1.o sum2.o sum3.o

all: $(OBJ) main-sumas.x

%.o: %.cpp
	g++ -c $< -o $@

# sum1.o: sum1.cpp
# 	g++ -c $< -o $@

# sum2.o: sum2.cpp
# 	g++ -c $< -o $@

# sum3.o: sum3.cpp
# 	g++ -c $< -o $@

main-sumas.x: main-sumas.cpp $(OBJ)
	g++ $^ -o $@

.PHONY: clean
clean:
	rm -f a.out *.o *~ *.x
