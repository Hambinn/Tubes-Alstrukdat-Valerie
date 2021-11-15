#include <stdio.h>
#include <math.h>
#include "readfile.c"
#include "..\lib\player.h"


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
        c = (n + (int)'@');
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

void move(Player *p, Matrix adjacency){
    // Cari next lokasi yang memenuhi
    ListPos nextLoc = nextLocation(adjacency, PCurLocation(*p));
    // Tampilkan next lokasi
    displayNextPlace(nextLoc, Bangunan);
    printf("Posisi yang ingin dipilih? (ketik 0 untuk kembali)");endl;
    // Pilih lokasi selanjutnya
    int op;
    scanf("%d",&op);
    while(op<0 || op>lengthListPos(nextLoc)){
        printf("Harap Masukkan angka yg benar");endl;
        scanf("%d",&op);
    }
    if (op == 0){
        return;
    }
    else{
        int idx = ELMTListPos(nextLoc,op-1);
        PCurLocation(*p) = LISTDIN_ELMT(Bangunan,idx);
        if (PSpeed(*p)==1){
            PTime(*p)++;
        }
        else if (PSpeed(*p)==2){
            PTime(*p) += 0.5;
        }
        
        printf("Mobita sekarang berada di titik ");displayLocation(PCurLocation(*p));endl;
    }
}

int main(){
    readFile("../config/config.txt");
    Player p;
    createPlayer(&p,Bangunan);
    displayStatus(p);endl;
    ListPos next = nextLocation(adjacency,PCurLocation(p));
    displayMap(MAP,PCurLocation(p),next);endl;
    move(&p,adjacency);
    displayStatus(p);endl;
    next = nextLocation(adjacency,PCurLocation(p));
    displayMap(MAP,PCurLocation(p),next);endl;
    

    return 0;
}