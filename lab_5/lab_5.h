#ifndef LAB_5H
#define LAB_5

typedef struct list
{
    int field;
    struct list *next;
    struct list *prev;

} list;

list *init(int a);
list *additem(list *lst, int number);
int Nod(int m, int n);

#endif