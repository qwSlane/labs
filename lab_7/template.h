#ifndef TEMPLATE_H
#define TEMPLATE_H

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

#endif