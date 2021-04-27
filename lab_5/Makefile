all: lab_5 test

lab_5: lab_5.c
	gcc -pedantic -ansi -o lab_5 lab_5.c

test: lab_5.c test.c
	gcc -pedantic -ansi -o test -D TESTING lab_5.c test.c