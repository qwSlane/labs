#ifndef LIST_H
#define LIST_H
#include "template.h"

typedef struct Trip
{
    int occupied;
    char *passengers;
    int len;
} Trip;

typedef struct Node
{
    int position;
    Trip *trip;
    TourTemplate *info;
    struct Node *next;
    struct Node *prev;
} Node;

typedef struct List
{
    Node *head;
    Node *tail;
} List;

TourTemplate *create(char *name, float cost, int places, char *route, int day, int year, int month);
void templateInfo(TourTemplate *templ);

void add(List **cr, TourTemplate *info);
TourTemplate *createCustom();
TourTemplate *secondary(TourTemplate *temp);
void readfile(List **cr);

void preview(List *root);
void change(List **root, int pos);

void show(List *root);
void load(List *root);

int insurance();
int hous();
int nutritions();

#endif