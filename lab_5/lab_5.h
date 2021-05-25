#ifndef LAB_5H
#define LAB_5H

typedef struct list
{
  char *field;
  struct list *next;
  struct list *prev;

} list;

list *init(char *a);
list *additem(list *lst, char *number);
int comparison(int *a, int *b, int max);
int *initialize(int *a, char *str, int size);
struct arr deletechar(struct arr res);
void leadingzeros(int max, int min, int *a, char *str);
int *minus(int *a, int *b, int max);
char *subtraction(char *m, char *n);
char *Nod(char *a, char *b);

#endif