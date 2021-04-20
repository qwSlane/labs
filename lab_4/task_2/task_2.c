#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "task_2.h"

int beforetest(char a)
{
  char before[] = "{([";
  char after[] = ".,;:!?}])";
  int i, boolean;

  boolean = 0;
  for (i = 0; i < strlen(before); i++)
  {
    if (a == before[i])
    {
      boolean = 1;
      return boolean;
    }
  }

  for (i = 0; i < strlen(after); i++)
  {
    if (a == after[i])
    {
      boolean = 2;
      return boolean;
    }
  }

  return boolean;
}

char *before(char *buffer, int pos)
{
  char *tempo;
  int i;
  tempo = (char *)malloc(((strlen(buffer) + 1) * sizeof(char)));
  for (i = 0; i < pos; i++)
  {
    tempo[i] = buffer[i];
  }
  tempo[i] = ' ';

  for (i = pos + 1; i < strlen(buffer) + 1; i++)
  {
    tempo[i] = buffer[i - 1];
  }
  tempo[i] = '\0';
  free(buffer);
  buffer = tempo;
  return buffer;
}

char *after(char *buffer, int pos)
{

  char *tempo;
  int i;
  tempo = (char *)malloc(((strlen(buffer) + 1) * sizeof(char)));
  for (i = 0; i <= pos; i++)
  {
    tempo[i] = buffer[i];
  }
  tempo[i] = ' ';

  for (i = pos + 2; i < strlen(buffer) + 1; i++)
  {
    tempo[i] = buffer[i - 1];
  }
  tempo[i] = '\0';

  free(buffer);
  buffer = tempo;
  return buffer;
}

#ifndef TESTING

int main()
{

  char *tempo;
  char *text;
  char buffer[80];
  FILE *file;
  int i, j, k, newsize, boolean;

  text = buffer;

  file = fopen("input.txt", "r");

  fgets(buffer, 80, file);

  for (i = 0; i < strlen(text); i++)
  {
    boolean = beforetest(text[i]);

    if (boolean == 1)
    {
      if ((i > 0) && (text[i - 1] != ' '))
      {
        text = before(text, i);
      }
    }
    else
    {
      if (boolean == 2)
      {
        if ((text[i] != '\0') && (text[i + 1] != ' '))
        {
          text = after(text, i);
        }
      }
    }
  }
  fclose(file);

  fopen("input.txt", "w");
  fprintf(file, "%s\n", text);

  fclose(file);

  printf("%s\n", text);
}

#endif