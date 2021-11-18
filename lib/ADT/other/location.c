#include "location.h"
#include <stdio.h>

LOCATION makeLocation (char name, POINT loc) {
    LOCATION l;
    NAME(l) = name;
    LOC(l) = loc;
    return l;
}

void displayLocation (LOCATION loc){
    printf("%c ", NAME(loc));TulisPOINT(LOC(loc));
}