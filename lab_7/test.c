#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "testedfunctions.h"

void templates()
{
    
    List *cr;
    char *name, *route;
    float cost;
    int places, day, year, month;
    readfile(&cr);
    places = day = year = month = 0;
    cost = 1;
    name = "test";
    route = "t->e->s->t";
    show(cr);
    assert(cr != NULL);
    free(cr);
    return;
}

int main()
{
    templates();
    printf("Test succesfully completed");
    return 0;
}