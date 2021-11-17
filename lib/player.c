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
    ListLinked drafPick;
    CreateListLinked(&drafPick);
    PDRAF(*p) = drafPick;
    REMAIN_BOOST(*p) = 0;
    COUNT_TIME(*p) = 0;
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

void displayCurLoc(Player p){
    printf("Kamu berada di posisi %c ",NAME(PCurLocation(p)));TulisPOINT(PCurLocation(p).loc);
}

void displayStatus(Player p){
    printf("Player berada di: ");displayLocation(PCurLocation(p));endl;
    displayTime(p);endl;
    displayMoney(p);endl;
    displaySpeed(p);endl;
    displayBagCapa(p);
}
int charToInt(char c){
    int x;
    if (c=='8'){
        x = 0;
    } else if (c=='@') {
        x = 69;
    } else{
        x =((int)c - 64);
    }
    return x;
}

char intToChar(int n){
    char c;
    if (n==0){
        c = '8';
    }
    else{
        c = (n + (int)'@');
    }
    return c;
}

void gainMoney(Player *p, char cc){
    switch (cc)
    {
    case 'N':
        PMoney(*p) += 200;
        break;
    case 'H':
        PMoney(*p) += 400;
        break;
    case 'P':
        PMoney(*p) += 400;
        break;
    case 'V':
        PMoney(*p) += 600;
        break;
    default:
        break;
    }
}
int itemMoney(char cc){
    int money;
    switch (cc)
    {
    case 'N':
        money = 200;
        break;
    case 'H':
        money = 400;
        break;
    case 'P':
        money = 400;
        break;
    case 'V':
        money = 600;
        break;
    default:
        money = 0;
        break;
    }
    return money;
}