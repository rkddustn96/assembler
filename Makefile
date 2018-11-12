myas: main.o check.o trans.o
	gcc -o myas main.o check.o trans.o -lm
main.o: main.c
	gcc -O wall -c main.c
check.o: check.c
	gcc -O wall -c check.c
trans.o: trans.c
	gcc -O wall -c trans.c
clean:
	rm -f main.o trans.o check.o myas

