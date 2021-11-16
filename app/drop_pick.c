#include <stdio.h>
#include <math.h>
#include "readfile.c"
#include "..\lib\player.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
Queue QueueOrder;
LOCATION HQ;

void pickItem(Player *p, Stack *bag, ListLinked *drafPick){
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

void dropItem(Player *p, Stack *bag){
    char curr = NAME(PCurLocation(*p));
    if (TYPE(TOP(*bag)) == 'H'){
        if (HEAVY(*bag) == 0){
            REMAIN_BOOST(*p) = 10;
            COUNT_TIME(*p) = 0;
        }
    }
    gainMoney(p,TYPE(TOP(*bag)));
    Item rubbish;
    pop(&bag,&rubbish);
}