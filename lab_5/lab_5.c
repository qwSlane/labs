#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "lab_5.h"

list *init(int a)
{
  list *lst;

  lst = (list *)malloc(sizeof(list));
  lst->field = a;
  lst->next = NULL;
  lst->prev = NULL;
  return (lst);
}

list *additem(list *lst, int number)
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

int Nod(int m, int n)
{
  if (n % m == 0)
    return m;
  if (m % n == 0)
    return n;

  return (n > m) ? Nod(n % m, m) : Nod(n, m % n);
}

#ifndef TESTING

int main()
{
  int a, b, nod;
  list *lst;
  scanf("%d", &a);
  scanf("%d", &b);
  lst = init(a);
  additem(lst, b);
  nod = Nod(a, b);
  printf("%d\n", nod);
  (nod == 1) ? printf("+") : printf("-");
}

#endif