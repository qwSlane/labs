#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int toRank(int a)
{
  int rank;
  for (rank = 0; a > 0; rank++)
  {
    a /= 2;
  }

  return (rank);
}

void toBinary(int a)
{

  int rank = toRank(a);

  int remains;
  int i, j;
  char *str = malloc(sizeof(char) * rank + 1);

  for (i = 0; i < rank; i++)
  {
    remains = a % 2;
    str[rank - i] = remains;
    a /= 2;
  }

  if (i == rank)
  {
    for (j = 0; j < rank; j++)
    {
      printf("%d", str[j + 1]);
    }
    printf("\n");
  }
  free(str);
}

#ifndef TESTING
int main()
{
  char maneString[50];
  int i, counter, character;

  fgets(maneString, 50, stdin);
  character = atoi(maneString);
  i = 0;
  counter = 0;

  if (atoi(maneString))
  {
    for (; i * 8 < character; counter++)
    {
      if (counter % 2 == 0)
      {
        i = i * 8;
        if (i != 0)
        {
          printf("%d\t", i);
          toBinary(i);
        }
      }
      else
      {
        i = i * 8 + 7;
        printf("%d\t", i);
        toBinary(i);
      }
    }
  }
  else
  {
    printf("Invalid input");
  }
 
  return(0);
}
#endif