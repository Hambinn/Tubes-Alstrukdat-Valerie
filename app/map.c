#include <stdio.h>
#include <math.h>
// #include "readfile.h"
// #include "..\lib\player.c"
// #include "move.c"

// Variable Ekstrak dari readFile
Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;
static FILE * tape;
ListPos next;

void map(Map MAP, Matrix adjacency, Stack bag, Player p){
    next = nextLocation(adjacency,PCurLocation(p));
    displayMap(MAP,PCurLocation(p),bag,PDRAF(p),next);endl;
}