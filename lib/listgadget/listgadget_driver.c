#include "listgadget.c"
#include <stdio.h>

int main()
{
	ListGadget l;
  	CreateListGadget(&l);
	
	addGadget(&l,1);
	displayList(l);

	printf("\n");

	printf("1. %s\n", GDGT(l,0));
	printf("2. %s\n", GDGT(l,1));
	printf("3. %s\n", GDGT(l,2));
	printf("4. %s\n", GDGT(l,3));
	printf("5. %s\n", GDGT(l,4));
	printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");

  	return 0;
}