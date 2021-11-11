#include <stdio.h>
#include <stdlib.h>
#include "../lib/boolean.h"
#include "readfile.c"
#include "..\lib\player.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;

void to_do(Player p) {
    displayQueue(QueueOrder, PTime(p));
}

int main () {
    readFile("../config/config.txt");
    Player p;
    createPlayer(&p,Bangunan);
    displayStatus(p);endl;
    PTime(p) = 14;
    to_do(p);
}