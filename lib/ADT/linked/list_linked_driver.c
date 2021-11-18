#include <stdio.h>
#include "list_linked.c"
#include "../queue/queue.h"
#include "node.c"

int main() {
    ListLinked l;
    Item x = makeItem(10, 'A', 'Z', 'N', 10);
    CreateListLinked(&l);
    insertItemFirst(&l, x);
    displayListLinked(l);
    x = makeItem(7, 'B', 'Y', 'H', -1);
    insertItemLast(&l, x);
    printf("\n");
    displayListLinked(l);
}