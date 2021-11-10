all: signal.o
	gcc -o signal signal.o
signal.o: signal.c
	gcc -c signal.c
run:
	./signal
clean:
	rm *.o
	rm signal
	rm *.txt