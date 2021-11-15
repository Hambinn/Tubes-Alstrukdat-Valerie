#ifndef NODE_H
#define NODE_H

#include <stdlib.h>
#include <stdio.h>
#include "queue.h"

typedef struct node* Address;
typedef struct node {
    Item item;
    Address next;
} Node;

#define ITEM(p) (p)->item
#define NEXT(p) (p)->next

Address newNode(Item item);

#endif