#include <stdio.h>
#include "readfile.h"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
Queue QueueOrder;
LOCATION HQ;

int StrToInt(Word w) {
    int x = 0;
    int i;
    for (i = 0; i < w.length; i++) {
        x = 10*x + ((int)w.contents[i]-48);
    }
    return x;
}

void readFile(char path[]) {
    FILE *fp;
    fp=fopen(path, "r");
    
    // ../config/config.txt
    // membuat map dari input ukuran
    
    startLine(fp);
    int n, m;
    n = StrToInt(currentWord);
    advWord();
    m = StrToInt(currentWord);
    CreateMap(n, m, &MAP);
    
    // memasukkan HQ pada buffer LOCATION
    
    startLine(fp);
    n = StrToInt(currentWord);
    advWord();
    m = StrToInt(currentWord);
    POINT hq = MakePOINT(n, m);
    char name = '8';
    ELMT(MAP, 0, 0) = '8';
    LOCATION HQ = makeLocation(name, hq);
    
    // memasukkan input beberapa lokasi pada buffer LOCATION
    
    startLine(fp);
    n = StrToInt(currentWord);
    CreateListDin(&Bangunan, n+1);
    listdin_insertList(&Bangunan, HQ);
    // printf("%c ",Bangunan.buffer[0].name);
    // TulisPOINT(Bangunan.buffer[0].loc);
    // endl;
    int i;
    for (i = 0; i < n; i++) {
        int x, y;
        char name;
        startLine(fp);
        name = currentWord.contents[0];
        advWord();
        x = StrToInt(currentWord);
        advWord();
        y = StrToInt(currentWord);
        ELMT(MAP, x-1, y-1) = name;
        POINT p = MakePOINT(x, y);
        LOCATION l = makeLocation(name, p);
        listdin_insertList(&Bangunan, l);
        // printf("%c ",Bangunan.buffer[i+1].name);
        // TulisPOINT(Bangunan.buffer[i+1].loc);
        // endl;
    }
    // displayMap(MAP);
    
    // Matrix Adjacency

    // Matrix adjacency;
    CreateMatrix(n+1, n+1, &adjacency);
    for (i=0; i<n+1; i++) {
        int j, elmt;
        startLine(fp);
        for (j = 0; j < n; j++) {
            elmt = StrToInt(currentWord);
            ELMT(adjacency, i, j) = elmt;
            advWord();
        }
        elmt = StrToInt(currentWord);
        ELMT(adjacency, i, j) = elmt;
    }
    // printf("\n");
    // displayMatrix(adjacency);
    // printf("\n");

    // Order Pesanan

    startLine(fp);
    n = StrToInt(currentWord);
    // Queue QueueOrder;
    CreateQueue(&QueueOrder);
    for (i=0; i<n; i++) {
        char pick, drop, type;
        int tmasuk, dur;
        startLine(fp);
        tmasuk = StrToInt(currentWord);
        advWord();
        pick = currentWord.contents[0];
        advWord();
        drop = currentWord.contents[0];
        advWord();
        type = currentWord.contents[0];
        if (type == 'P') {
            advWord();
            dur = StrToInt(currentWord);
        } else {
            dur = -1;
        }
        Item ITEM = makeItem(tmasuk, pick, drop, type, dur);
        // displayItem(ITEM);
        // printf("\n");
        enqueue(&QueueOrder, ITEM);
    }
    fclose(fp);
    // displayQueue(QueueOrder);
}