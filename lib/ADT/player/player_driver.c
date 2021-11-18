#include <stdio.h>
#include "../../../app/readfile.c"


int main() {
    POINT hq = MakePOINT(1, 1);
    char name = '8';
    LOCATION HQ = makeLocation(name, hq);

    POINT a = MakePOINT(2, 3);
    name = 'A';
    LOCATION A = makeLocation(name, a);

    ListDin Bangunan;
    CreateListDin(&Bangunan, 10);
    listdin_insertList(&Bangunan, HQ);
    listdin_insertList(&Bangunan, A);

    Player p;
    createPlayer(&p, Bangunan);
    displayStatus(p);
}