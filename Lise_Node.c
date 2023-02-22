#include "LL.h"

Node_t *create_Node(void *val)
{
    Node_t *self;
    if (!(self = (Node_t *)malloc(sizeof(Node_t))))
        return NULL;

    self->data = val;
    self->prev = NULL;
    self->next = NULL;

    return self;
}

Node_t *add(List_t *root, void *val, void (*f_ptr)(List_t *root, Node_t *newNode))
{
    Node_t *node = create_Node(val);
    if (!node)
        return NULL;

    if (empty(root))
        root->head = node, root->tail = node;
    else
        f_ptr(root, node);

    root->size++;
    return node;
}
