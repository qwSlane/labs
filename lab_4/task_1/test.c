#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task_1.h"

void doubleword_1()
{
  char* answer, *text;
  char raw[25] = "somebody somebody once";
  text = raw;
  answer = doublewords(text);
  assert(strcmp(answer, "somebody once") == 0);
}

void doubleword_2()
{
  char* answer, *text;
  char raw[20] = "told told me";
  text = raw;
  answer = doublewords(text);
  assert(strcmp(answer, "told me") == 0);
}

void upper_1()
{
  char* answer, *text;
  char raw[20] = "give. three";
  text = raw;
  answer = uppercase(text);
  assert(strcmp(answer, "give. Three") == 0);
}

void upper_2()
{
  char* answer, *text;
  char raw[20] = "hundreds. bucks";
  text = raw;
  answer = uppercase(text);
  assert(strcmp(answer, "hundreds. Bucks") == 0);
}

#undef task_1

int main() {
    doubleword_1();
    doubleword_2();
    upper_1();
    printf("Test succesfully completed");
    return 0;
}