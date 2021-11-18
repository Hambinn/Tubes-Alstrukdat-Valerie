#include "location.c"
#include "point.c"

int main() {
    POINT p = MakePOINT(2,1);
    LOCATION l = makeLocation('A', p);
    displayLocation(l);
}