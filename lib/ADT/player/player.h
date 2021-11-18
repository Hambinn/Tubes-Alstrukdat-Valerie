#ifndef PLAYER_H
#define PlAYER_H

#include "../../boolean.h"
#include "../input/wordmachine.h"
#include "../list/listdin.h"
#include "../list/listpos.h"
#include "../matrix/matrix.h"
#include "../other/point.h"
#include "../other/location.h"
#include "../queue/queue.h"
#include "../linked/list_linked.h"
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
#define   COUNT_TIME(p) (p).boost.countTime

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
void gainMoney(Player *p, char cc);
#endif