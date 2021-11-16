#include <stdio.h>
#include <math.h>
#include "readfile.c"
#include "..\lib\player.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
Queue QueueOrder;
LOCATION HQ;

void pick(Stack *bag, ListLinked *drafPick, Player *p){
    char curr = NAME(PCurLocation(*p));
    boolean found = false;
    int i = 0;
    Address P1 = FIRST(*drafPick);
    while (!found && P1!=NULL){
        if ( PICKUP(ITEM(P1)) == curr ){
            found = true;
        }
        else{
            P1 = NEXT(P1);
        }
    }

    // Masukin ke bag
    push(&bag,ITEM(P1));
    if ( TYPE(ITEM(P1))=='H' ){
        HEAVY(*bag)++;
        if (REMAIN_BOOST(*p) != 0){
            if (REMAIN_BOOST(*p)%2 == 1){
                PTime(*p)++;
            }
            REMAIN_BOOST(*p) = 0;
            COUNT_TIME(*p) = 0;
        }
    }
    deleteItem(&drafPick,ITEM(P1));
}