all: base.o
	gcc base.o main.c -o house -lGL -lGLU -lglut -lm

base.o: base.h
	gcc -c base.c

clean:
	rm -rf *.o
	rm -rf house

run:
	./house