#include <stdio.h>
#include "player.h"
#define endl printf("\n")

/* Awalnya currentLocation di HQ (berdasarkan readFile)
           time = 0.0 (float)
           money = 0
           speed = 1
           bagCapacity = 3*/
void createPlayer(Player *p, ListDin bangunan){
    PCurLocation(*p) = LISTDIN_ELMT(bangunan,0);
    PTime(*p) = 0.0;
    PMoney(*p) = 0;
    PSpeed(*p) = 1;
    PBagCapa(*p) = 3;
}

void displayTime(Player p){
    int roundTime = PTime(p);
    printf("Waktu: %d", roundTime);
}
void displayMoney(Player p){
    printf("Money(sen): %d", PMoney(p));
}
void displaySpeed(Player p){
    printf("Speed: %d", PSpeed(p));
}
void displayBagCapa(Player p){
    printf("Capasitas Tas: %d", PBagCapa(p));
}

void displayStatus(Player p){
    printf("Player berada di: ");displayLocation(PCurLocation(p));endl;
    displayTime(p);endl;
    displayMoney(p);endl;
    displaySpeed(p);endl;
    displayBagCapa(p);
}