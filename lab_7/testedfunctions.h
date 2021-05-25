#ifndef TESTEDFUNC_H
#define TESTEDFUNC_H

#include <string.h>

typedef struct Minor
{
    int nutrition;
    int insurance;
    char *housing;
} Minor;

typedef struct Date
{
    int day;
    int year;
    int month;
} Date;

typedef struct Mandatory
{
    float cost;
    int places;
    char* route;
    Date* date;

} Mandatory;

typedef struct TourTemplate 
{
    char* name;
    Mandatory* crucial;
    Minor* secondary;
} TourTemplate;

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

void readfile(List **cr);
TourTemplate *create(char *name, float cost, int places, char *route, int day, int year, int month);
void show(List *root);
void add(List **cr, TourTemplate *info);
void templateInfo(TourTemplate *templ);

#endif