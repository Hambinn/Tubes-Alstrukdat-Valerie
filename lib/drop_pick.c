#include <stdio.h>
#include <math.h>
#include "readfile.c"
#include "..\lib\player.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
Queue QueueOrder;
LOCATION HQ;

void pick(Stack *bag, ListPos *drafPick, Player p){
    ItemBag item;
    char curr = NAME(PCurLocation(p));
    boolean found = false;
    int i = 0;
    while (!found && i < lengthQueue(QueueOrder)){
        if ( PICKUP(QueueOrder.buffer[i]) == curr ){
            found = true;
        }
        else{
            i++;
        }
    }
    // Masukin ke item
    DROP_PLACE(item) = DROPOFF(QueueOrder.buffer[i]);
    ITEM_TYPE(item) = TYPE(QueueOrder.buffer[i]);
    DURATION(item) = DURATION(QueueOrder.buffer[i]);
    // Masukin ke bag
    push(&bag,item);
    if ( ITEM_TYPE(item)=='H' ){
        HEAVY(*bag)++;
    }
    deleteVal(&drafPick,charToInt(curr));
}