/* File: location.h */
/* *** Definisi ABSTRACT DATA TYPE LOCATION *** */

#ifndef LOCATION_H
#define LOCATION_H

#include "point.h"

typedef struct {
   char name;
   POINT loc;
} LOCATION;

#define NAME(x) (x).name
#define LOC(x)  (x).loc


LOCATION makeLocation (char name, POINT loc);
void displayLocation (LOCATION loc);

#endif