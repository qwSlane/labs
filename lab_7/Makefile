main:
	gcc -pedantic -o santaren list.c santaren.c
test:
	gcc -coverage -pedantic -o test testedfunctions.c test.c -lm

runtest:
	./test

clear:
	del  test.gcda, test.gcno, testedfunctions.c.gcov, testedfunctions.gcda, testedfunctions.gcno test.gcno test.exe

checkcov:
	gcov testedfunctions