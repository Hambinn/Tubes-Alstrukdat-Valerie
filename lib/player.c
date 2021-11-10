#include <stdio.h>
#include "player.h"
#include "..\app\readfile.c"

/* Awalnya currentLocation di HQ (berdasarkan readFile)
           time = 0
           money = 0
           speed = 1
           bagCapacity = 3*/
void createPlayer(Player *p, ListDin bangunan){
    PCurLocation(*p) = LISTDIN_ELMT(bangunan,0);
    PTime(*p) = 0;
    PMoney(*p) = 0;
    PSpeed(*p) = 1;
    PBagCapa(*p) = 3;
}

void displayStatus(Player p){
    LOCATION temp = PCurLocation(p);
    printf("Player berada di: %c ", NAME(temp));TulisPOINT(LOC(temp));endl;
    printf("Waktu: %d", PTime(p));endl;
    printf("Money(sen): %d", PMoney(p));endl;
    printf("Speed: %d", PSpeed(p));endl;
    printf("Capasitas Tas: %d", PBagCapa(p));
}