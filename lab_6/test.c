#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "lab_6.h"

void AddNode()
{
    Node *tree;
    char *example_1, *example_2;
    tree = NULL;
    example_1 = "qwerty";
    example_2 = "Stass love strawberry";

    assert(tree == NULL);
    add(&tree, example_1);
    assert(tree != NULL);
    free(tree);

    tree = NULL;
    assert(tree == NULL);
    add(&tree, example_2);
    assert(tree != NULL);
    free(tree);
}

void Prooftest()
{
    char *example_1, *example_2, *example_3;
    example_1 = "some words";
    example_2 = "happy easter day";
    example_3 = "bbbbbbbbbbbbbbbb";
    assert(proof(example_1) == 0);
    assert(proof(example_2) == 1);
    assert(proof(example_3) == 1);
}

void Stacktest()
{
    List *stack;
    char *example_1, *example_2, *example_3;
    example_1 = "what is pop-it";
    example_2 = "what is simple-dimple";
    example_3 = "what the difference of simple-dimple and pop-it";
    stack = NULL;

    push(&stack, example_1);
    push(&stack, example_2);
    push(&stack, example_3);

    assert(strcmp(pop(&stack), example_3) == 0);
    assert(strcmp(pop(&stack), example_2) == 0);
    assert(strcmp(pop(&stack), example_1) == 0);
}

int main()
{
    AddNode();
    Prooftest();
    Stacktest();
    printf("Test succesfully completed");
    return 0;
}