#ifndef LAB_6H
#define LAB_6

typedef struct Node
{
    char *data;
    struct Node *left;
    struct Node *right;
    struct Node *root;
} Node;

typedef struct List
{
    struct List *pnext;
    char *data;
} List;

Node *freenode(char *data, Node *parent);
void add(Node **root, char *data);

int proof(char *data);

void treescan(Node *root, List **tmp);

char *pop(List **stack);
void push(List **head, char *data);

#endif