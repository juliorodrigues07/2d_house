all: base.o
	g++ base.o main.cpp -o house -lGL -lGLU -lglut -lm

base.o: base.hpp
	g++ -c base.cpp

clean:
	rm -rf *.o
	rm -rf house

run:
	./house