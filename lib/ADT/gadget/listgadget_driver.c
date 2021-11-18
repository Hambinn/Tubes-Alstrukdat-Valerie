#include <stdio.h>
#include "listgadget.c"

int main() {
    ListGadget g;
    CreateListGadget(&g);
    // Gadget kosong
    displayListGadget(g);
    
    // Add gadget
    addGadget(&g, 0);
    addGadget(&g, 1);
    addGadget(&g, 2);
    addGadget(&g, 3);
    printf("\n");
    displayListGadget(g);
    
    // Delete Gadget
    deleteGadget(&g, 0);
    printf("\n");
    displayListGadget(g);
}