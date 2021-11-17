#include <stdio.h>
#include <math.h>
// #include "readfile.c"
// #include "../lib/player.c"

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

void useKain(Player *p, ListGadget *l, Stack *bag)
{
    
    int i;
    float time = PTime(*p);
    printf("Kain Pembungkus Waktu berhasil digunakan!\n");
    
    for(i = IDX_TOP(*bag); i>-1 ; i--)
    {
        if(TYPE((*bag).buffer[i])=='P')
        {
            DURATION((*bag).buffer[i]) = TMASUK((*bag).buffer[i]);
            break;
        }
    }
    inProgress = copyBag(*bag);
}

void useSenter(Player *p, ListGadget *l)
{
    printf("Senter Pembesar berhasil digunakan!\n");
    PBagCapa(*p) *= 2;
    
    if(PBagCapa(*p)>100)
    {
        PBagCapa(*p) = 100;
    } 
}

void usePintu(Player *p, ListGadget *l, char cc)
{
    printf("Pintu Kemana Saja berhasil digunakan!\n");
    PCurLocation(*p) = LISTDIN_ELMT(Bangunan, charToInt(cc));
}

void useMesin(Player *p, ListGadget *l)
{
    printf("Mesin Waktu berhasil digunakan!\n");
    PTime(*p) -= 50;
    if(PTime(*p)<0)
    {
        PTime(*p) = 0;
    } 
}

void checkSlot(Player *p, ListGadget *l, Stack *b, int i)
{
    if(GDGT(*l,i) != STRIP)
    {
        if(GDGT(*l,i)==arr[0])
        {
            useKain(p, l, b);
        }
        if(GDGT(*l,i)==arr[1])
        {
            useSenter(p, l);
        }
        if(GDGT(*l,i)==arr[2])
        {
            printf("Teleport ke :");
            startLine(tape);
            while (charToInt(currentWord.contents[0]) >= listdin_length(Bangunan) || charToInt(currentWord.contents[0]) < 0) {
                printf("Masukan lokasi yang benar :");
                startLine(tape);
            }
            usePintu(p, l, currentWord.contents[0]);
        }
        if(GDGT(*l,i)==arr[3])
        {
            useMesin(p, l);
        }
        deleteGadget(l, i);
    }
    else
    {
        printf("Tidak ada Gadget yang dapat digunakan!\n");
    }
}

void useInventory(Player *p, ListGadget *l, Stack *bag){
    int choice;
    displayInventory(p, *l);
    printf("\nENTER COMMAND: ");
    startLine(tape);
    choice = StrToInt(currentWord);


    while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 &&choice != 5)
    {
        printf("Pilih angka yang benar!!");
        printf("\nENTER COMMAND: ");
        startLine(tape);
        choice = StrToInt(currentWord);
    }
    if(choice == 1)
    {
        checkSlot(p, l, bag, 0);
    }
    else if(choice == 2)
    {
        checkSlot(p, l, bag, 1);
    }
    else if(choice == 3)
    {
        checkSlot(p, l, bag, 2);
    }
    else if(choice == 4)
    {
        checkSlot(p, l, bag, 3);
    }
    else if(choice == 5)
    {
        checkSlot(p, l, bag, 4);
    }
}

// int main()
// {
//     int command;

// 	readFile("../config/config.txt");
//     Player p;
//     ListGadget l;
//     Stack b;
//     int x;
//   	CreateListGadget(&l);
//     createPlayer(&p,Bangunan);
	
// 	addGadget(&l,0);
//     addGadget(&l,1);
//     addGadget(&l,2);
//     addGadget(&l,3);
//     addGadget(&l,4);

//     displayInventory(&p, l);

//     printf("\nENTER COMMAND: ");
//     scanf("%d", &command);

//     if(command == 1)
//     {
//         useKain(&p, l, &b);
//     }
//     else if(command == 2)
//     {
//         useSenter(&p, l);
//     }
//     else if(command == 3)
//     {
//         printf("Teleport kemana? ");
//         scanf("%d", &x);
//         usePintu(&p, l, x);
//     }
//     else if(command == 4)
//     {
//         useMesin(&p, l);
//     }


//   	return 0;
// }