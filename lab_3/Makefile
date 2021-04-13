all: task test

task: task.c
	gcc -pedantic -ansi -o task task.c

test: task.c test.c
	gcc -pedantic -ansi -o test -D TESTING task.c test.c