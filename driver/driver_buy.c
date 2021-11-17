#include <stdio.h>
#include <math.h>
#include "readfile.c"
#include "buy.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;

int main()
{
    readFile("../config/config.txt");
    Player p;
    ListGadget l;
    CreateListGadget(&l);
    createPlayer(&p,Bangunan);
    PMoney(p) = 10000;

    printf("================================== BUY ===================================");
    endl;
    if (NAME(PCurLocation(p))=='8'){
        displayStore(&p);
        printf("\nENTER COMMAND: ");
        int choice;
        startLine(tape);
        choice = StrToInt(currentWord);

        if(choice == 1)
        {
            buyKain(&p, &l);
        }
        else if(choice == 2)
        {
            buySenter(&p, &l);
        }
        else if(choice == 3)
        {
            buyPintu(&p, &l);
        }
        else if(choice == 4)
        {
            buyMesin(&p, &l);
        }
    }

    return 0;
}