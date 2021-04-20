#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task_1.h"

char* doublewords(char *text)
{
  char *first, *next, *current, *newanswer;
  char *answer = NULL;
  char *a = " ";

  current = strtok(text, " ");

  while (current != NULL)
  {
    first = current;

    current = strtok(NULL, " ");
   
    if (current != NULL)
    {
      if (strcmp(first, current) != 0)
      {
        if (answer == NULL)
        {
          answer = (char *)malloc(strlen(first) * sizeof(char));
          strcpy(answer, first);
        }
        else
        {
          answer = strcat(answer, a);
          answer = strcat(answer, first);  
        }
      }
    }
    else
    {
      answer = strcat(answer, a);
      answer = strcat(answer, first);
    }
  }

  return answer;
}

char* uppercase(char *ans)
{
  int i, num;

  for (i = 0; i < strlen(ans); i++)
  {
   
    if ((int)ans[i] == '.')
    {
      i += 2;
      num = (int)ans[i];

      if ((num >= 61) && (num <= 122))
      {
        num -= 32;
        ans[i] = (char)num;
      }
    }
  }
  return ans;
}

#ifndef TESTING

int main()
{
  char *text, raw[80];
  int i, num;
  char *ans;

  text = raw;
  gets(raw);

  ans = doublewords(text);

  ans = uppercase(ans);

  printf("answer %s\n", ans);
}
#endif