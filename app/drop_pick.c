#include <stdio.h>
#include <math.h>
// #include "readfile.c"
// #include "..\lib\player.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
Queue QueueOrder;
LOCATION HQ;

void pickItem(Player *p, Stack *bag){
    if ( lengthStack(*bag) >= 100 ){
        printf("Maaf slot tas maksimum adalah 100 :D");endl;
    }
    else if (lengthStack(*bag) >= PBagCapa(*p)){
        printf("Maaf tas kamu udah kepenuhan :D"); endl;
    }
    else if (lengthStack(*bag) < PBagCapa(*p) && lengthStack(*bag) < 100){
        char curr = NAME(PCurLocation(*p));
        boolean found = false;
        int i = 0;
        Address P1 = FIRST(PDRAF(*p));
        while (!found && P1!=NULL){
            if ( PICKUP(ITEM(P1)) == curr ){
                found = true;
            }
            else{
                P1 = NEXT(P1);
            }
        }
        if (found){
            // Masukin ke bag
            push(bag,ITEM(P1));
            TMASUK(TOP(*bag)) = DURATION(TOP(*bag));
            if ( TYPE(ITEM(P1))=='H' ){
                if (REMAIN_BOOST(*p) != 0){
                    if (REMAIN_BOOST(*p)%2 == 1){
                        PTime(*p)++;
                    }
                    REMAIN_BOOST(*p) = 0;
                    COUNT_TIME(*p) = 0;
                }
            }
            if (TYPE(ITEM(P1))=='N'){
                printf("Pesanan berupa Normal item berhasil diambil!");
            }
            else if (TYPE(ITEM(P1))=='H'){
                printf("Pesanan berupa Heavy item berhasil diambil!");
            }
            else if (TYPE(ITEM(P1))=='P'){
                printf("Pesanan berupa Perishable item berhasil diambil!");
            }
            else if (TYPE(ITEM(P1))=='V'){
                printf("Pesanan berupa VIP item berhasil diambil!");
            }
            endl;
            printf("Tujuan Pesanan: %c",DROPOFF(ITEM(P1)));endl;
            deleteItem(&PDRAF(*p),ITEM(P1));
        }
        else{
            printf("Lu Ngambil apa? Gw ga mesen tuh!");endl;
        }

    }
    
    
}

void dropItem(Player *p, Stack *bag){
    char curr = NAME(PCurLocation(*p));
    if (DROPOFF(TOP(*bag))==curr){
        if (TYPE(TOP(*bag)) == 'H'){
            if (HEAVY(*bag) == 1){
                printf("Selamat kamu jadi flash!");endl;
                REMAIN_BOOST(*p) = 10;
                COUNT_TIME(*p) = 0;
            }
        }
        else if (TYPE(TOP(*bag)) == 'P'){
            if (PBagCapa(*p) < 100){
                printf("Selamat kapasitas bag nambah 1!");endl;
                PBagCapa(*p)++;
            }
        }

        gainMoney(p,TYPE(TOP(*bag)));
        if (TYPE(TOP(*bag))=='N'){
            printf("Pesanan berupa Normal item berhasil diantarkan!");
        }
        else if (TYPE(TOP(*bag))=='H'){
            printf("Pesanan berupa Heavy item berhasil diantarkan!");
        }
        else if (TYPE(TOP(*bag))=='P'){
            printf("Pesanan berupa Perishable item berhasil diantarkan!");
        }
        else if (TYPE(TOP(*bag))=='V'){
            printf("Pesanan berupa VIP item berhasil diantarkan!");
        }
        endl;
        printf("Uang yang didapatkan: %d Yen",itemMoney(TYPE(TOP(*bag))));endl;
        Item rubbish;
        pop(bag,&rubbish);
    }
    else{
        printf("Kamu ngantar apa si!");endl;
    }
}