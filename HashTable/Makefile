all: lab2

lab2: main.o bstree.o hashtab.o AdditionalFunctions.o
	gcc -Wall -Werror -g main.o bstree.o hashtab.o AdditionalFunctions.o -o lab2

main.o: main.c
	gcc -Wall -Werror -g -c main.c -o main.o

hashtab.o: hashtab.c
	gcc -Wall -Werror -g -c hashtab.c -o hashtab.o

bstree.o: bstree.c
	gcc -Wall -Werror -g -c bstree.c -o bstree.o

AdditionalFunctions.o: AdditionalFunctions.c
	gcc -Wall -Werror -g -c AdditionalFunctions.c -o AdditionalFunctions.o

clean:
	-rm -rf *.o lab2