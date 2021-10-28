
#ifndef LOCATION_H
#define LOCATION_H

#include "boolean.h"
#include "point.h"

typedef struct {
   char name[2];
   POINT loc;
} LOCATION;

#define NAME(x)  (x).name
#define LOC(x) (x).loc

LOCATION makeLocation (char name[2], POINT loc);

#endif