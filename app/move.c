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

void move(Player *p, Matrix adjacency, Stack bag){
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
        if (HEAVY(bag) != 0){   // Ada barang berat
            PTime(*p) += (1+HEAVY(bag));
        }
        else{   // Tidak ada barang berat
            if (REMAIN_BOOST(*p) != 0){     // Ada SpeedBoost
                COUNT_TIME(*p)++;
                REMAIN_BOOST(*p)--;
                if (COUNT_TIME(*p) == 2){
                    PTime(*p)++;
                    COUNT_TIME(*p) = 0;
                }
            }
            else {  // Tidak ada SpeedBoost
                PTime(*p) ++;
            }
        }
        
        printf("Mobita sekarang berada di titik ");displayLocation(PCurLocation(*p));endl;
    }
}

int main(){
    // 1. Deklarasi awal
    readFile("../config/config.txt");
    Player p;
    Stack bag;
    ListPos next;
    ListLinked draf;
    CreateStack(&bag);
    createPlayer(&p,Bangunan);
    CreateListLinked(&draf);

    // 2. Bagian Eksperimen
    HEAVY(bag) = 0;
    REMAIN_BOOST(p) = 2;
    Item val1;
    TMASUK(val1) = 0;
    PICKUP(val1) = 'C';
    DROPOFF(val1) = 'B';
    TYPE(val1) = 'N';
    DURATION(val1) = 0;
    Item val2;
    TMASUK(val2) = 0;
    PICKUP(val2) = 'P';
    DROPOFF(val2) = 'E';
    TYPE(val2) = 'N';
    DURATION(val2) = 0;
    push(&bag,val1);
    insertItem(&draf,val1);
    insertItem(&draf,val2);

    // 3. Bagian Output
    next = nextLocation(adjacency,PCurLocation(p));
    displayStatus(p);endl;
    displayMap(MAP,PCurLocation(p),bag,draf,next);endl;
    
    move(&p,adjacency,bag);

    displayStatus(p);endl;
    next = nextLocation(adjacency,PCurLocation(p));
    displayMap(MAP,PCurLocation(p),bag,draf,next);endl;

    move(&p,adjacency,bag);

    displayStatus(p);endl;
    next = nextLocation(adjacency,PCurLocation(p));
    displayMap(MAP,PCurLocation(p),bag,draf,next);endl;
    

    return 0;
}