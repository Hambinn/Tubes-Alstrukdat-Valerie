#include "boolean.h"
#include "item.h"

Item makeItem (POINT loc_pu, POINT loc_do, char type, int dur) {
    Item x;
    PICKUP(x) = loc_pu;
    DROPOFF(x) = loc_do;
    TYPE(x) = type;
    DURATION(x) = dur;
    return x;
}