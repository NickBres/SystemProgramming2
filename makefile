all: connections

connections: main.o my_mat.o
	gcc main.o my_mat.o -o connections 

matlib.a: my_mat.o my_mat.h
	ar rc matlib.a my_mat.o my_mat.h

main.o: main.c
	gcc -c main.c

my_mat.o: my_mat.c my_mat.h
	gcc -c my_mat.c

clean:
	clear
	rm  *.o *.a *so connections
