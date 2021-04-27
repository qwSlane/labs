#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "task_2.h"

void test_1()
{
    int x;
    x = beforetest(',');
    assert(x == 2);
    x = beforetest('{');
    assert(x == 1);
    x = beforetest('a');
    assert(x == 0);

}

void test_2()
{
  char* answer, *text;
  char raw[25] = "somebody{once";
  text = raw;
  answer = before(text, 8);
  assert(strcmp(answer, "somebody {once") == 0);

}

void test_3()
{
  char* answer, *text;
  char raw[25] = "told(me";
  text = raw;
  answer = before(text, 4);
  assert(strcmp(answer, "told (me") == 0);

}

void test_4()
{
  char* answer, *text;
  char raw[30] = "the.world";
  text = raw;
  answer = after(text, 3);
  
  assert(strcmp(answer, "the. world") == 0);

}

void test_5()
{
  char* answer, *text;
  char raw[30] = "is goona,roll me";
  text = raw;
  answer = after(text, 8);
  assert(strcmp(answer, "is goona, roll me") == 0);

}

#undef task_2

int main()
{
    test_1();
    test_2();
    test_3();
    test_4();
    test_5();
    printf("Test succesfully completed");
    return 0;
}