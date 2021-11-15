#include <stdio.h>
#include <stdlib.h>
#include "readfile.c"
#include "..\lib\player.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
Queue QueueOrder;
LOCATION HQ;
ListLinked toDo;
ListLinked inProgress;

void to_do(Player p) {
    while (TMASUK(HEAD(QueueOrder)) <= PTime(p) && !isEmptyQueue(QueueOrder)) {
        Item temp;
        dequeue(&QueueOrder, &temp);
        insertItem(&toDo, temp);
    }
    deletePerishable(&toDo, PTime(p));
    printf("List To Do : \n\n");
    displayListLinked(toDo, PTime(p));
    endl;
}

int main () {
    readFile("../config/config.txt");
    Player p;
    createPlayer(&p,Bangunan);
    PTime(p) = 29;
    displayStatus(p);endl;
    to_do(p);
}