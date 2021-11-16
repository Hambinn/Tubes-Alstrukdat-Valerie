#ifndef PLAYER_H
#define PlAYER_H

#include "boolean.h"
#include "charmachine.h"
#include "listdin.h"
#include "listpos.h"
#include "matrix.h"
#include "point.h"
#include "wordmachine.h"
#include "location.h"
#include "queue.h"
#define endl printf("\n")

typedef struct {
    int remainBoost;
    int countTime;
}BoosT;
typedef struct
{
    LOCATION currentLocation;
    float time;
    int money;
    int speed;
    int bagCapacity;
    ListLinked drafPick;
    BoosT boost;
}Player;



// ACCESORR
#define        PTime(p) (p).time
#define       PMoney(p) (p).money
#define       PSpeed(p) (p).speed
#define     PBagCapa(p) (p).bagCapacity
#define PCurLocation(p) (p).currentLocation
#define        PDRAF(p) (p).drafPick
#define REMAIN_BOOST(p) (p).boost.remainBoost
#define COUNT_TIME(p) (p).boost.countTime

/* PRIMITIVE Player */
/* Awalnya currentLocation di HQ (berdasarkan readFile)
           time = 0
           money = 0
           speed = 1
           bagCapacity = 3*/
void createPlayer(Player *p, ListDin bangunan);

// Menampilkan status player
void displayStatus(Player p);

// Procedure menampilkan untuk status...!!!
void displayTime(Player p);
void displayMoney(Player p);
void displaySpeed(Player p);
void displayBagCapa(Player p);
int charToInt(char c);
char intToChar(int n);

#endif