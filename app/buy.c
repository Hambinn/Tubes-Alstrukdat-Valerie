#include <stdio.h>
#include <math.h>
// #include "readfile.c"
// #include "..\lib\player.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;

void currentMoney(Player *p)
{
    printf("Uang Anda sekarang: "); displayMoney(*p); printf(" Yen\n");
}

void displayStore(Player *p)
{
    currentMoney(p);
    printf("Gadget yang tersedia:\n");
    printf("1. Kain Pembungkus Waktu (800 Yen)\n");
    printf("2. Senter Pembesar (1200 Yen)\n");
    printf("3. Pintu Kemana Saja (1500 Yen)\n");
    printf("4. Mesin Waktu (3000 Yen)\n");
    printf("Gadget mana yang ingin kau beli? (ketik 0 jika ingin kembali)\n");
}

void buyKain(Player *p, ListGadget *l)
{
    if(PMoney(*p) >= 800)
    {
        if(!isFullInventory(*l))
        {
            printf("Kain Pembungkus Waktu berhasil dibeli!\n");
            PMoney(*p) -= 800;
            addGadget(l, 0);
            currentMoney(p);
            printf("\n");
        }
        else
        {
            printf("Inventory Full!\n");
        }
    }
    else
    {
        printf("Uang tidak cukup untuk membeli gadget!\n");
    }
}

void buySenter(Player *p, ListGadget *l)
{
    if(PMoney(*p) >= 1200)
    {
        if(!isFullInventory(*l))
        {
            printf("Senter Pembesar berhasil dibeli!\n");
            PMoney(*p) -= 1200;
            addGadget(l, 1);
            currentMoney(p);
            printf("\n");
        }
        else
        {
            printf("Inventory Full!\n");
        }
    }
    else
    {
        printf("Uang tidak cukup untuk membeli gadget!");
    }
}

void buyPintu(Player *p, ListGadget *l)
{
    if(PMoney(*p) >= 1500)
    {
        if(!isFullInventory(*l))
        {
            printf("Pintu Kemana Saja berhasil dibeli!\n");
            PMoney(*p) -= 1500;
            addGadget(l, 2);
            currentMoney(p);
            printf("\n");
        }
        else
        {
            printf("Inventory Full!\n");
        }
    }
    else
    {
        printf("Uang tidak cukup untuk membeli gadget!\n");
    }
}

void buyMesin(Player *p, ListGadget *l)
{
    if(PMoney(*p) >= 3000)
    {
        if(!isFullInventory(*l))
        {
            printf("Mesin Waktu berhasil dibeli!\n");
            PMoney(*p) -= 3000;
            addGadget(l, 3);
            currentMoney(p);
            printf("\n");
        }
        else
        {
            printf("Inventory Full!\n");
        }
    }
    else
    {
        printf("Uang tidak cukup untuk membeli gadget!\n");
    }
}

void buyGadget(Player *p, ListGadget *l){
    if (NAME(PCurLocation(*p))=='8'){
        int choice;
        displayStore(p);
        printf("\nENTER COMMAND: ");
        startLine(tape);
        choice = StrToInt(currentWord);

        while (choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4){
            printf("Pilih angka yang benar!!");
            printf("\nENTER COMMAND: ");
            startLine(tape);
            choice = StrToInt(currentWord);
        }
        if(choice == 1)
        {
            buyKain(p, l);
        }
        else if(choice == 2)
        {
            buySenter(p, l);
        }
        else if(choice == 3)
        {
            buyPintu(p, l);
        }
        else if(choice == 4)
        {
            buyMesin(p, l);
        }
    }
    else{
        printf("Lu olang beli item harus di HQ ya!");endl;
    }
}

// int main()
// {
//     int command;
    
//     readFile("../config/config.txt");
//     Player p;
//     ListGadget l;
//   	CreateListGadget(&l);
//     createPlayer(&p,Bangunan);
//     PMoney(p) = 10000;

//     displayStore(&p);
    

//     printf("\nENTER COMMAND: ");
//     scanf("%d", &command);

//     if(command == 1)
//     {
//         buyKain(&p, l);
//     }
//     else if(command == 2)
//     {
//         buySenter(&p, l);
//     }
//     else if(command == 3)
//     {
//         buyPintu(&p, l);
//     }
//     else if(command == 4)
//     {
//         buyMesin(&p, l);
//     }

//     return 0;
// }