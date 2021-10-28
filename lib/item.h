
#ifndef ITEM_H
#define ITEM_H

#include "boolean.h"
#include "point.h"

typedef struct {
   POINT pick_up;
   POINT drop_off;
   char type;
   int duration;
} Item;

#define PICKUP(x)  (x).pick_up
#define DROPOFF(x) (x).drop_off
#define TYPE(x) (x).type
#define DURATION(x)  (x).duration

Item makeItem (POINT pick_up, POINT drop_off, char type, int dur);

#endif