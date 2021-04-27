#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "lab_5.h"

void testNod()
{
    assert(Nod(5, 6) == 1);
    assert(Nod(16, 8) == 8);
    assert(Nod(35, 45) == 5);
}

void testInit()
{
  list *test;
  test = NULL;
  test = init(12);
  assert(test != 0);
  
}

void testInit_1()
{
  list *test;
  test = NULL;
  test = init(45);
  assert(test != 0);
  
}

void testInit_2()
{
  list *test;
  test = NULL;
  test = init(1337);
  assert(test != 0);
  
}

int main()
{
    testNod();
    testInit();
    testInit_1();
    testInit_2();
    printf("Test succesfully completed");
    return 0;
}