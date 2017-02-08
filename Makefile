CFLAGS = -g -Wall

PA3: main.o input_output.o tree.o
	gcc $(CFLAGS) main.o input_output.o tree.o -lm -o PA3

main.o: main.h main.c
	gcc $(CFLAGS) -c main.c

input_output.o: input_output.h input_output.c
	gcc $(CFLAGS) -c input_output.c

tree.o: tree.h tree.c
	gcc $(CFLAGS) -c tree.c

clean:
	rm -f main.o input_output.o tree.o PA3
	
all: PA3