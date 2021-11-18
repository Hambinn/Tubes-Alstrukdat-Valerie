#include <stdio.h>
#include "../../../app/readfile.c"
#include "../../helper/pcolor.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;
ListLinked inProgress;
Player p;

int main() {
    readFile("../config/config.txt");
    listdin_displayList(Bangunan);
}