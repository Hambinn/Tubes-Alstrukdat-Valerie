#include <stdio.h>
#include <math.h>
#include "readfile.c"

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
ListPos giveAdjacency(Matrix adjacency, LOCATION currentloc){
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

void displayNextPlace(ListPos nextPlace, ListDin location){
    int i;
    int idx;
    for(i = 0; i < lengthListPos(nextPlace); i++){
        idx = ELMTList(nextPlace,i);
        
    }
}

Matrix adjacency;
Map MAP;
ListDin Location;
Queue QueueOrder;

int main(){
    readFile();
    displayMap(MAP);
}