#include <assert.h>
#include <stdio.h>

#include "task_2.h"

int test_fact() {
    assert(fact(5) == 120);
    assert(fact(6) == 720);
}

#undef task_2

int main() {

   test_fact();
    printf("Test succesfully completed");
    return 0;

}