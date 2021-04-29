#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <math.h>

#include "lab_5.h"


list *init(char *a)
{
  list *lst;

  lst = (list *)malloc(sizeof(list));
  lst->field = a;
  lst->next = NULL;
  lst->prev = NULL;
  return (lst);
}

list *additem(list *lst, char *number)
{
  list *temp, *p;
  temp = (list *)malloc(sizeof(list));
  p = lst->next;
  lst->next = temp;
  temp->field = number;
  temp->next = p;
  temp->prev = lst;
  if (p != NULL)
    p->prev = temp;
  return (temp);
}

int comparison(int *a, int *b, int max)
{
  int i, j, rez;
  rez = 0;
  for (i = 0; i < max; i++)
  {
    if (a[i] > b[i])
    {
      rez = 1;
      return rez;
    }
    else
    {
      if (a[i] < b[i])
        rez = 2;
      return rez;
    }
  }
  return rez;
}

int *initialize(int *a, char *str, int size)
{
  int i;
  for (i = 0; i < size; i++)
  {
    a[i] = (int)str[i] - '0';
  }

  return a;
}

struct arr
{
  int *str;
  int max;
};

struct arr deletechar(struct arr res)
{
  int i;
  int *new;
  if (res.max == 1)
  {
    new = (int *)malloc(sizeof(int) * 1);
    new[0] = 0;
    res.str = new;
    return res;
  }

  new = (int *)malloc(sizeof(int) * (res.max - 1));

  for (i = 1; i < res.max; ++i)
    new[i - 1] = res.str[i];
  free(res.str);
  res.str = new;

  if (res.str[0] == 0)
  {
    res.max--;
    deletechar(res);
  }
  else
  {
    res.max--;
    return res;
  }
}

void leadingzeros(int max, int min, int *a, char *str)
{
  int i, j;
  for (i = 0; i < max - min; i++)
  {
    a[i] = 0;
  }
  for (i = max - min, j = 0; i < max; i++, j++)
  {
    a[i] = (int)str[j] - '0';
  }
}

int *minus(int *a, int *b, int max)
{
  int sign, i;
  int *res; 
  sign = 0;
  

  res = (int *)malloc(max * sizeof(int));

  for (i = max - 1; i >= 0; i--)
  {

    if (sign == 1)
    {
      a[i]--;
      sign = 0;
    }
    if (a[i] >= b[i])
      res[i] = a[i] - b[i];
    else
    {
      res[i] = (a[i] + 10) - b[i];
      sign = 1;
    }
  }
  return res;
}

char *subtraction(char *m, char *n)
{
  int i, j, major, size_m, size_n, sign, max;
  int *ch_1, *ch_2;
  int *result;
  char *answer;
  struct arr res;

  size_m = strlen(m);
  size_n = strlen(n);

  if (size_m == size_n)
  {
    ch_1 = (int *)calloc(size_m, sizeof(int));
    ch_2 = (int *)calloc(size_n, sizeof(int));
    ch_1 = initialize(ch_1, m, size_m);
    ch_2 = initialize(ch_2, n, size_m);
    max = size_m;
    major = comparison(ch_1, ch_2, max);
  }
  else
  {
    if (size_m > size_n)
    {
      ch_1 = (int *)malloc(size_m * sizeof(int));
      ch_2 = (int *)calloc(size_m, sizeof(int));
      ch_1 = initialize(ch_1, m, size_m);
      leadingzeros(size_m, size_n, ch_2, n);
      major = 1;
      max = size_m;
    }
    else
    {
      ch_1 = (int *)calloc(size_n, sizeof(int));
      ch_2 = (int *)malloc(size_n * sizeof(int));
      leadingzeros(size_n, size_m, ch_1, m);
      initialize(ch_2, n, size_n);
      major = 2;
      max = size_n;
    }
  }

  if (major == 1)
    result = minus(ch_1, ch_2, max);
  else
    result = minus(ch_2, ch_1, max);

  res.str = result;
  res.max = max;
  if (result[0] == 0)
    res = deletechar(res);
  result = res.str;
  max = res.max;

  if (max == 1)
    answer = (char *)calloc(max, sizeof(char));
  else
    answer = (char *)malloc((max - 1) * sizeof(char));

  for (i = 0; i < max; i++)
  {
    answer[i] = result[i] + '0';
  }
  answer[i] = '\0';

  return answer;
}

char *Nod(char *a, char *b)
{
  int *first, *second, i;
  int major;
  char *temp;
  char *q = "1";
  first = (int *)malloc(strlen(a) * sizeof(int));
  second = (int *)malloc(strlen(b) * sizeof(int));

  while ((strcmp(a, b) != 0))
  {
    free(first);
    free(second);
    first = (int *)malloc(strlen(a) * sizeof(int));
    second = (int *)malloc(strlen(b) * sizeof(int));
    first = initialize(first, a, strlen(a));
    second = initialize(second, b, strlen(b));
    major = (strlen(a) > strlen(b)) ? 1 : (strlen(a) < strlen(b)) ? 2
                                                                  : comparison(first, second, strlen(a));
    if (major == 1)
    {
      a = subtraction(a, b);

      if (atoi(a) == 1)
        return a;
    }
    else
    {
      b = subtraction(a, b);
    }
  }
  return a;
}

#ifndef TESTING

int main()
{
  char text[80];
  int i, q, r;
  char *a, *b, *answer;
  list *lst;
  a = (char *)malloc(sizeof(char) * 80);
  scanf("%s", a);
  lst = init(a);
  b = (char *)malloc(sizeof(char) * 80);
  scanf("%s", b);
  lst = additem(lst, b);

  answer = Nod(a, b);
  if (atoi(answer) == 1)
    printf("+");
  else
    printf("-");
}

#endif