#include <assert.h>
#include <stdio.h>

#include "lab_1.h"

int test_toRank() {
    assert(toRank(50) == 6);
}


int main() {
    test_toRank();
    printf("Test succesfully completed");
    return 0;
}