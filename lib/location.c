#include "location.h"
#include "boolean.h"

LOCATION makeLocation (char name[], POINT loc) {
    LOCATION l;
    NAME(l)[0] = name[0];
    NAME(l)[1] = name[1];
    LOC(l) = loc;
}