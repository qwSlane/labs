all: task_1 test

task_1: task_1.c
	gcc -pedantic -ansi -o task_1 task_1.c

test: task_1.c test.c
	gcc -pedantic -ansi -o test -D TESTING task_1.c test.c