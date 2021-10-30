#include "location.h"

LOCATION makeLocation (char name, POINT loc) {
    LOCATION l;
    NAME(l) = name;
    LOC(l) = loc;
    return l;
}