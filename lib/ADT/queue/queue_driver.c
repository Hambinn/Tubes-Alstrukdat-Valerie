#include <stdio.h>
#include "queue.c"

int main() {
    Item x = makeItem(10, 'A', 'Z', 'N', 10);
    Queue q;
    CreateQueue(&q);
    enqueue(&q, x);
    displayQueue(q);
    dequeue(&q, &x);
    displayQueue(q);
    return 0;
}