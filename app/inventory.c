#include <stdio.h>
#include <math.h>
#include "readfile.c"
#include "../lib/player.c"
#include "../lib/listgadget/listgadget.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;

void displayInventory(Player *p, ListGadget l)
{
    printf("1. %s\n", GDGT(l,0));
	printf("2. %s\n", GDGT(l,1));
	printf("3. %s\n", GDGT(l,2));
	printf("4. %s\n", GDGT(l,3));
	printf("5. %s\n", GDGT(l,4));
	printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
}

void useKain(Player p, ListGadget l)
{
    if(GDGT(l,0) != STRIP)
    {
        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
        deleteGadget(&l, 0);
    }
    else
    {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

void useSenter(Player p, ListGadget l)
{
    if(GDGT(l,1) != STRIP)
    {
        printf("Senter Pembesar berhasil digunakan!\n");
        deleteGadget(&l, 1);
    }
    else
    {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

void usePintu(Player p, ListGadget l)
{
    if(GDGT(l,2) != STRIP)
    {
        printf("Pintu Kemana Saja berhasil digunakan!\n");
        deleteGadget(&l, 2);
    }
    else
    {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

void useMesin(Player p, ListGadget l)
{
    if(GDGT(l,3) != STRIP)
    {
        printf("Mesin Waktu berhasil digunakan!\n");
        deleteGadget(&l, 3);
    }
    else
    {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

int main()
{
    int command;

	readFile();
    Player p;
    ListGadget l;
  	CreateListGadget(&l);
    createPlayer(&p,Bangunan);
	
	addGadget(&l,0);

    displayInventory(&p, l);

    printf("\nENTER COMMAND: ");
    scanf("%d", &command);

    if(command == 1)
    {
        useKain(p, l);
    }
    else if(command == 2)
    {
        useSenter(p, l);
    }
    else if(command == 3)
    {
        usePintu(p, l);
    }
    else if(command == 4)
    {
        useMesin(p, l);
    }

  	return 0;
}