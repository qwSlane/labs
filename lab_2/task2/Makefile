all: task_2 test

task_2: task_2.c
	gcc -pedantic -ansi -o task_2 task_2.c

test: task_2.c test.c
	gcc -pedantic -ansi -o test -D TESTING task_2.c test.c