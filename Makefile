myas: main.o check.o trans.o
	gcc -o myas main.o check.o trans.o -lm
main.o: main.c
	gcc -o wall -c main.c
check.o: check.c
	gcc -o wall -c check.c
trans.o: trans.c
	gcc -o wall -c trans.c
clean:
	rm -f main.o trans.o myas

