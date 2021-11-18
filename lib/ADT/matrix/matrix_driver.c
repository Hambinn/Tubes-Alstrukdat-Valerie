#include <stdio.h>
#include <math.h>
#include "matrix.c"
#include "../other/location.c"
#include "../other/point.c"
#include "../list/listpos.c"
#include "../stack/stack.c"
#include "../linked/list_linked.c"
#include "../linked/node.c"


int main() {
    Matrix m;
    CreateMatrix(10,10,&m);
    displayMatrix(m);
}