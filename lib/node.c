/* File: node.c */
/* Implementasi Node */

#include "node.h"
#include <stdlib.h>

Address newNode(Item item) {
    Address p = (Address) malloc(sizeof(Node));
    if (p!=NULL) {
        TMASUK(ITEM(p)) = TMASUK(item);
        PICKUP(ITEM(p)) = PICKUP(item);
        DROPOFF(ITEM(p)) = DROPOFF(item);
        TYPE(ITEM(p)) = TYPE(item);
        DURATION(ITEM(p)) = DURATION(item);
        NEXT(p) = NULL;
    }
    return p;
}