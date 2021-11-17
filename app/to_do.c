#include <stdio.h>
#include <stdlib.h>
// #include "readfile.h"
// #include "..\lib\player.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
Queue QueueOrder;
LOCATION HQ;
ListLinked inProgress;

void fillDrafToDO(Player *p) {
    while (TMASUK(HEAD(QueueOrder)) <= PTime(*p) && !isEmptyQueue(QueueOrder)) {
        Item temp;
        dequeue(&QueueOrder, &temp);
        insertItemLast(&PDRAF(*p), temp);
    }
}

void to_do(Player *p){
    printf("List To Do : \n");
    displayListLinked(PDRAF(*p));
}

// int main () {
//     readFile("../config/config.txt");
//     Player p;
//     createPlayer(&p,Bangunan);
//     PTime(p) = 29;
//     displayStatus(p);endl;
//     fillDrafToDO(&p);
//     to_do(p);
// }