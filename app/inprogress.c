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

void in_progress(Player p) {
    printf("List In Progress : \n\n");
    displayListLinked(inProgress, PTime(p));endl;
    endl;
}

int main () {
    readFile("../config/config.txt");
    Player p;
    createPlayer(&p,Bangunan);
    PTime(p) = 2;
    displayStatus(p);endl;
    in_progress(p);
}