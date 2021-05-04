#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lab_6.h"

void push(List **head, char *data)
{
    List *tmp = (List *)malloc(sizeof(List));
    tmp->pnext = (*head);
    tmp->data = data;

    (*head) = tmp;
}

Node *freenode(char *data, Node *parent)
{
    Node *tmp = (Node *)malloc(sizeof(Node) * 1);
    tmp->left = NULL;
    tmp->right = NULL;
    tmp->data = data;
    tmp->root = parent;
    return tmp;
}

void add(Node **root, char *data)
{

    if (*root == NULL)
    {
        *root = freenode(data, NULL);
        return;
    }
    else
    {
        Node *temp;
        temp = *root;

        while (temp)
        {
            if (strlen(data) <= strlen(temp->data))
            {
                if (temp->left)
                {
                    temp = temp->left;
                    continue;
                }
                else
                {
                    temp->left = freenode(data, temp);
                    return;
                }
            }
            else
            {
                if (strlen(data) > strlen(temp->data))
                {
                    if (temp->right)
                    {
                        temp = temp->right;
                        continue;
                    }
                    else
                    {
                        temp->right = freenode(data, temp);
                        return;
                    }
                }
            }
        }
    }
}

int proof(char *data)
{
    int i, counter;
    counter = 0;
    for (i = 0; i < strlen(data); i++)
    {
        counter += (int)data[i];
    }
    if (counter % 2 == 0)
        return 1;
    else
        return 0;
}

void treescan(Node *root, List **tmp)
{
    if (root != NULL)
    {
        if (proof(root->data))
        {
            push(tmp, root->data);
        }
        treescan(root->left, tmp);
        treescan(root->right, tmp);
    }
}

char *pop(List **stack)
{
    char *a;
    List *temp;
    a = (*stack)->data;
    temp = (*stack)->pnext;
    free(*stack);
    (*stack) = temp;
    return a;
}
#ifndef TESTING

int main()
{
    Node *tree;
    List *stack;
    char s1[] = "bbb";
    char s2[] = "ddd";
    char s3[] = "dfgas";
    char *answer;
    char *a = s1;
    char *b = s2;
    char *c = s3;

    tree = NULL;
    stack = NULL;

    add(&tree, a);
    add(&tree, b);
    add(&tree, c);

    treescan(tree, &stack);

    printf("%s\n", pop(&stack));
    printf("%s\n", pop(&stack));
}

#endif