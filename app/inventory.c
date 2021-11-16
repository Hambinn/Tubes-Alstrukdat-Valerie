#include <stdio.h>
#include <math.h>
#include "readfile.c"
#include "../lib/player.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
Queue QueueOrder;
LOCATION HQ;
ListLinked toDo;

void displayInventory(Player *p, ListGadget l)
{
    printf("1. %s\n", GDGT(l,0));
	printf("2. %s\n", GDGT(l,1));
	printf("3. %s\n", GDGT(l,2));
	printf("4. %s\n", GDGT(l,3));
	printf("5. %s\n", GDGT(l,4));
	printf("Gadget mana yang ingin digunakan? (ketik 0 jika ingin kembali)\n");
}

void useKain(Player *p, ListGadget l, Stack *bag)
{
    if(GDGT(l,0) != STRIP)
    {
        int i;
        float time = PTime(*p);
        printf("Kain Pembungkus Waktu berhasil digunakan!\n");
        deleteGadget(&l, 0);
        
        for(i = LEN_STACK(*bag); i>=0 ; i--)
        {
            if(TYPE((*bag).buffer[i])=='P')
            {
                DURATION((*bag).buffer[i]) = DURATION((*bag).buffer[i]) + ((int)time + TMASUK((*bag).buffer[i]));
                break;
            }
        }
    }
    else
    {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

void useSenter(Player *p, ListGadget l)
{
    if(GDGT(l,1) != STRIP)
    {
        printf("Senter Pembesar berhasil digunakan!\n");
        deleteGadget(&l, 1);
        PBagCapa(*p) *= 2;
        
        if(PBagCapa(*p)>100)
        {
            PBagCapa(*p) = 0;
        } 
    }
    else
    {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

void usePintu(Player *p, ListGadget l, int idx)
{
    if(GDGT(l,2) != STRIP)
    {
        printf("Pintu Kemana Saja berhasil digunakan!\n");
        deleteGadget(&l, 2);
        PCurLocation(*p) = LISTDIN_ELMT(Bangunan, idx);
    }
    else
    {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

void useMesin(Player *p, ListGadget l)
{
    if(GDGT(l,3) != STRIP)
    {
        printf("Mesin Waktu berhasil digunakan!\n");
        deleteGadget(&l, 3);
        PTime(*p) -= 50;
        if(PTime(*p)<0)
        {
            PTime(*p) = 0;
        } 
    }
    else
    {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

int main()
{
    int command;

	readFile("../config/config.txt");
    Player p;
    ListGadget l;
    Stack b;
    int x;
  	CreateListGadget(&l);
    createPlayer(&p,Bangunan);
	
	addGadget(&l,0);
    addGadget(&l,1);
    addGadget(&l,2);
    addGadget(&l,3);
    addGadget(&l,4);

    displayInventory(&p, l);
    printf("\n");
    displayStatus(p);
    printf("\n");
    printf("\nENTER COMMAND: ");
    scanf("%d", &command);

    if(command == 1)
    {
        useKain(&p, l, &b);
    }
    else if(command == 2)
    {
        useSenter(&p, l);
    }
    else if(command == 3)
    {
        printf("Teleport kemana? ");
        scanf("%d", &x);
        usePintu(&p, l, x);
    }
    else if(command == 4)
    {
        useMesin(&p, l);
    }

    printf("\n");
    displayStatus(p);
  	return 0;
}