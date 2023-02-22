#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    void *data;
    struct Node *next;
    struct Node *prev;
} Node_t;

typedef struct Linked_List
{
    Node_t *head;
    Node_t *tail;
    unsigned int size;
} List_t;

List_t *newList(void);
Node_t *create_Node(void *val);
bool empty(List_t *root);
unsigned int size(List_t *root);
Node_t *add(List_t *root, void *val, void (*f_ptr)(List_t *root, Node_t *newNode));
Node_t *append(List_t *head, void *val);
void appendHelp(List_t *root, Node_t *node);
Node_t *push(List_t *root, void *val);
void pushHelp(List_t *root, Node_t *node);
Node_t *pop(List_t *root);
Node_t *search(List_t *root, void *val, bool compare(Node_t *node, void *val));
bool compareINT(Node_t *node, void *val);
bool compareCHAR(Node_t *node, void *val);
bool compareFLOAT(Node_t *node, void *val);
void printList(List_t *root, void (*f_ptr)(Node_t *node));
void printInt(Node_t *node);
void printChar(Node_t *node);
void printFloat(Node_t *node);
#endif