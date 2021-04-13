all: lab_1 test

lab_1: lab_1.c
	gcc -pedantic -ansi -o lab_1 lab_1.c

test: lab_1.c lab_1test.c
	gcc -pedantic -ansi -o test -D TESTING lab_1.c lab_1test.c