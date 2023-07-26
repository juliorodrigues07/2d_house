all: house.o
	gcc house.o main.c -o main -lGL -lGLU -lglut -lm

house.o: house.h
	gcc -c house.c

clean:
	rm -rf *.o
	rm -rf main

run:
	./main