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

void in_progress(Stack bag) {
    printf("List In Progress : \n");
    displayListLinked(inProgress);
}

// int main () {
//     readFile("../config/config.txt");
//     Player p;
//     createPlayer(&p,Bangunan);
//     PTime(p) = 2;
//     displayStatus(p);endl;
//     in_progress(p);
// }