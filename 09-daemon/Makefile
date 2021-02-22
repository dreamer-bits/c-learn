main: daemon.c main.c
	gcc daemon.h daemon.c main.c -o main

.PHONY: clean run

clean:
	rm -rf main
	rm -rf test

run: main
	./main
