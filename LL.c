#include "LL.h"

List_t *newList(void)
{
    List_t *root;
    if (!(root = (List_t *)malloc(sizeof(List_t))))
        return NULL;

    root->head = NULL;
    root->tail = NULL;
    root->size = 0;
    return root;
}

bool empty(List_t *root)
{
    return root->head == NULL;
}

unsigned int size(List_t *root)
{
    return root->size;
}

Node_t *append(List_t *root, void *val)
{
    return add(root, val, appendHelp);
}

void appendHelp(List_t *root, Node_t *node)
{
    root->tail->next = node;
    node->prev = root->tail;
    root->tail = node;
}

Node_t *push(List_t *root, void *val)
{
    return add(root, val, pushHelp);
}

void pushHelp(List_t *root, Node_t *node)
{
    node->next = root->head;
    root->head = node;
}

Node_t *pop(List_t *root)
{
    if (empty(root))
        return NULL;

    Node_t *temp = root->tail;
    root->tail = temp->prev;
    root->tail->next = NULL;
    free(temp);
    root->size--;
    return root->tail;
}

Node_t *search(List_t *root, void *val, bool compare(Node_t *node, void *val))
{
    if (empty(root))
        return NULL;

    Node_t *temp = root->head;
    while (temp)
    {
        if (compare(temp, val))
            return temp;

        temp = temp->next;
    }
    return NULL;
}

bool compareINT(Node_t *node, void *val)
{
    return *(int *)node->data == *(int *)val;
}

bool compareCHAR(Node_t *node, void *val)
{
    return *(char *)node->data == *(char *)val;
}

bool compareFLOAT(Node_t *node, void *val)
{
    return *(float *)node->data == *(float *)val;
}

void printList(List_t *root, void (*f_ptr)(Node_t *node))
{
    if (!root->head)
        printf("This Linked List is empty!.\n");
    else
    {
        Node_t *temp = root->head;
        while (temp)
        {
            f_ptr(temp);
            temp = temp->next;
        }
    }
}

void printInt(Node_t *node)
{
    printf("%d\n", *(int *)node->data);
}

void printChar(Node_t *node)
{
    printf("%c\n", *(char *)node->data);
}

void printFloat(Node_t *node)
{
    printf("%f\n", *(float *)node->data);
}