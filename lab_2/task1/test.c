#include <assert.h>
#include <stdio.h>

#include "task_1.h"

int nod(){

    assert(nod(2,6)==2);
}


#undef main

int main() {
    nod();
    printf("Test succesfully completed");
    return 0;
}