all: house.o
	g++ house.o main.cpp -o main -lGL -lGLU -lglut -lm

house.o: house.hpp
	g++ -c house.cpp

clean:
	rm -rf *.o
	rm -rf main

run:
	./main