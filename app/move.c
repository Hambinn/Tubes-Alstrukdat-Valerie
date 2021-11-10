#include <stdio.h>
#include <math.h>
#include "readfile.c"
#include "..\lib\player.c"


// Variable Ekstrak dari readFile
Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;

int charToInt(char c){
    int x;
    if (c=='8'){
        x = 0;
    }
    else{
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
        char c = (n + (int)'@');
    }
    return c;
}

// adjency adalah matrix adjacency, currentLoc adalah lokasi player terkini
// return Listpos yang berisi int yg merepresentasikan bangunan, 0 untuk HQ, 1 untuk A dst..
ListPos nextLocation(Matrix adjacency, LOCATION currentloc){
    ListPos nextPlace;
    CreateListPos(&nextPlace);
    int j;
    int i = charToInt(NAME(currentloc));
    for(j = 0; j < COLS(adjacency); j++){
        if ( ELMT(adjacency,i,j)==1 ){
            insertLast(&nextPlace,j);
        }
    }    
    return nextPlace;
}

void displayNextPlace(ListPos nextPlace, ListDin bangunan){
    int i,j;
    int idx;
    LOCATION temp;
    printf("Posisi yang dapat dicapai:");endl;
    // Untuk setiap i indeks dari array nextPlace
    for(i = 0; i < lengthListPos(nextPlace); i++){
        idx = ELMTListPos(nextPlace,i);
        temp = LISTDIN_ELMT(bangunan,idx);
        printf("%d. ",i+1);displayLocation(temp);endl;
    }
}

void move(Player p, ListPos nextLocation){
    
}

int main(){
    readFile();
    Player p;
    createPlayer(&p,Bangunan);
    displayStatus(p);endl;
    displayMap(MAP);endl;
    
    LOCATION currLoc = LISTDIN_ELMT(Bangunan,1);    // Mobita ada di A
    ListPos nextPlace = nextLocation(adjacency, currLoc);
    displayNextPlace(nextPlace, Bangunan);

    char c = intToChar(1);
    printf("%c", c);
}