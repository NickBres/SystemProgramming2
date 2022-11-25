CFLAGS = -Wall -Wextra -fPIC

all: connections

connections: main.o matlib.a
	gcc $(CFLAGS) main.o -o connections matlib.a

matlib.a: my_mat.o my_mat.h
	ar rc matlib.a my_mat.o my_mat.h

main.o: main.c
	gcc $(CFLAGS) -c main.c

my_mat.o: my_mat.c my_mat.h
	gcc $(CFLAGS) -c my_mat.c

clean:
	rm  *.o *.a connections
