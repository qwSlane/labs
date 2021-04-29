#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lab_5.h"

void testInit()
{
  char *k = "12";
  list *test;
  test = NULL;
  test = init(k);
  assert(test != 0);
  
}

void testInit_1()
{
  char *k = "45";
  list *test;
  test = NULL;
  test = init(k);
  assert(test != 0);
  
}

void testInit_2()
{
  char *k = "1337";
  list *test;
  test = NULL;
  test = init(k);
  assert(test != 0);
  
}

void substractionTest()
{
  char *a = "22345";
  char *b = "12300";
  char *c = "10045";
  char *test ;
  
  test = subtraction(a,b);
  assert(strcmp(test,c) == 0);
}

void substractionTest_1()
{
  char *a = "36789001234234";
  char *b = "123";
  char *c = "36789001234111";
  char *test;
  
  test = subtraction(a,b);
  assert(strcmp(test,c) == 0);
}

void substractionTest_2()
{
  char *a = "123456782";
  char *b = "567892340902";
  char *c = "567768884120";
  char *test;

  test = subtraction(a,b);
  assert(strcmp(test,c) == 0);
}

void testnod()
{
  char *a = "25";
  char *b = "17";
  char * test;

  test = Nod(a, b);
  assert(atoi(test) == 1);
}

void testnod_1()
{
  char *a = "25";
  char *b = "5";
  char * test;

  test = Nod(a, b);
  assert(atoi(test) == 5);
}

int main()
{
    testInit();
    testInit_1();
    testInit_2();
    substractionTest();
    substractionTest_1();
    substractionTest_2();
    testnod();
    testnod_1();
    printf("Test succesfully completed");
    return 0;
}