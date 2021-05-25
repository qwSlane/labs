all: lab_6 test

lab_6: lab_6.c
	gcc -pedantic -ansi -o lab_6 lab_6.c

test: 
	gcc -pedantic -ansi -o test -D TESTING lab_6.c test.c