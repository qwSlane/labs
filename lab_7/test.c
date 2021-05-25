#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "testedfunctions.h"

void templates()
{
    List *cr;
    readfile(&cr);
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