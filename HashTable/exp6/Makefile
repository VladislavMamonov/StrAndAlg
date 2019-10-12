all: exp6

exp6: main.o hashtab.o
	gcc -Wall -Werror -g main.o hashtab.o -o exp6

main.o: main.c
	gcc -Wall -Werror -g -c main.c -o main.o

hashtab.o: hashtab.c
	gcc -Wall -Werror -g -c hashtab.c -o hashtab.o

clean:
	-rm -rf *.o exp6