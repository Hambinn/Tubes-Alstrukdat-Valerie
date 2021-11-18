#include <stdio.h>
#include "readfile.h"
#include <string.h>

Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;
ListLinked inProgress;
static FILE * tape;

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
    HQ = makeLocation(name, hq);
    
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
    CreateListLinked(&inProgress);
    fclose(fp);
    // displayQueue(QueueOrder);
}

void saveFile (Player p, Stack bag, ListGadget l) {
    FILE *fp;
    int i,j;

    printf("Masukkan nama file save (jangan memakai spasi) : ");
    tape = stdin;
    startLine(tape);
    char *name = malloc(currentWord.length * sizeof(char));
    for ( i=0; i<currentWord.length; i++ ) {
        name[i] = currentWord.contents[i];
    }
    printf("Data anda berhasil disimpan di ../save/%s.txt\n", name);
    char filename[100] = "";
    strcat(filename, "../save/");
    strcat(filename, name);
    strcat(filename, ".txt");
    fp = fopen (filename, "w");
    int col = MAP.colEff; int row = MAP.rowEff;
    fprintf(fp, "%d %d\n", row, col);
    fprintf(fp, "%d %d\n", Bangunan.buffer[0].loc.X, Bangunan.buffer[0].loc.Y);
    fprintf(fp, "%d\n", Bangunan.nEff-1);
    for ( i=1; i<Bangunan.nEff; i++ ) {
        fprintf(fp, "%c %d %d\n", Bangunan.buffer[i].name, Bangunan.buffer[i].loc.X, Bangunan.buffer[i].loc.Y);
    }
    row = adjacency.rowEff; col = adjacency.colEff;
    for ( i=0; i<row; i++ ) {
        for ( j=0; j<col-1; j++ ) {
            fprintf(fp, "%d ", adjacency.contents[i][j]);
        }
        fprintf(fp, "%d\n", adjacency.contents[i][col-1]);
    }
    fprintf(fp, "%d\n", lengthQueue(QueueOrder));
    for ( i=IDX_HEAD(QueueOrder); i<=IDX_TAIL(QueueOrder); i++ ) {
        if (QueueOrder.buffer[i].type != 'P') {
            fprintf(fp, "%d %c %c %c\n", QueueOrder.buffer[i].tMasuk, QueueOrder.buffer[i].pick_up, QueueOrder.buffer[i].drop_off, QueueOrder.buffer[i].type);
        } else {
            fprintf(fp, "%d %c %c %c %d\n", QueueOrder.buffer[i].tMasuk, QueueOrder.buffer[i].pick_up, QueueOrder.buffer[i].drop_off, QueueOrder.buffer[i].type, QueueOrder.buffer[i].duration);
        }
    }
    fprintf(fp, "%d %d\n", bag.length, bag.heavy);
    for ( i=IDX_TOP(bag)+bag.length-1; i>=IDX_TOP(bag); i-- ) {
        if (bag.buffer[i].type != 'P') {
            fprintf(fp, "%d %c %c %c\n", bag.buffer[i].tMasuk, bag.buffer[i].pick_up, bag.buffer[i].drop_off, bag.buffer[i].type);
        } else {
            fprintf(fp, "%d %c %c %c %d\n", bag.buffer[i].tMasuk, bag.buffer[i].pick_up, bag.buffer[i].drop_off, bag.buffer[i].type, bag.buffer[i].duration);
        }
    }
    fprintf(fp, "%d\n", lengthLinkedList(inProgress));
    Address ptr = FIRST(inProgress);
    while ( ptr != NULL ) {
        if ( ITEM(ptr).type != 'P') {
            fprintf(fp, "%d %c %c %c\n", ITEM(ptr).tMasuk, ITEM(ptr).pick_up, ITEM(ptr).drop_off, ITEM(ptr).type);
        } else {
            fprintf(fp, "%d %c %c %c %d\n", ITEM(ptr).tMasuk, ITEM(ptr).pick_up, ITEM(ptr).drop_off, ITEM(ptr).type, ITEM(ptr).duration);
        }
        ptr = NEXT(ptr);
    }
    fprintf(fp, "%d %d %d %d %d %d\n", p.bagCapacity, p.boost.remainBoost, p.boost.countTime, p.money, p.speed, (int) p.time);
    fprintf(fp, "%c %d %d\n", p.currentLocation.name, p.currentLocation.loc.X, p.currentLocation.loc.Y);
    fprintf(fp, "%d\n", lengthLinkedList(p.drafPick));
    ptr = FIRST(p.drafPick);
    while ( ptr != NULL ) {
        if ( ITEM(ptr).type != 'P') {
            fprintf(fp, "%d %c %c %c\n", ITEM(ptr).tMasuk, ITEM(ptr).pick_up, ITEM(ptr).drop_off, ITEM(ptr).type);
        } else {
            fprintf(fp, "%d %c %c %c %d\n", ITEM(ptr).tMasuk, ITEM(ptr).pick_up, ITEM(ptr).drop_off, ITEM(ptr).type, ITEM(ptr).duration);
        }
        ptr = NEXT(ptr);
    }
    for ( i=0; i<5; i++ ) {
        fprintf(fp, "%s\n", l.contents[i]);
    }
    fclose(fp);
}

void loadFile (char path[], Player *p, Stack *bag, ListGadget *l) {
    // printf("%s\n", path);
    FILE *fp;
    fp=fopen(path, "r");
    
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
    HQ = makeLocation(name, hq);
    
    // memasukkan input beberapa lokasi pada buffer LOCATION
    
    startLine(fp);
    n = StrToInt(currentWord);
    CreateListDin(&Bangunan, n+1);
    listdin_insertList(&Bangunan, HQ);
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
    }

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
        enqueue(&QueueOrder, ITEM);
    }
    int len, heavy;
    startLine(fp);
    len = StrToInt(currentWord);
    advWord();
    heavy = StrToInt(currentWord);
    CreateStack(bag);
    bag->length = len; bag->heavy = heavy;
    for ( i=0; i<len; i++ ) {
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
        push(bag, ITEM);
    }
    startLine(fp);
    len = StrToInt(currentWord);
    CreateListLinked(&inProgress);
    for (i=0; i<len; i++) {
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
        insertItemLast(&inProgress, ITEM);
    }

    startLine(fp);
    int bagCap, remainboost, countboost, money, speed;
    float time;
    bagCap = StrToInt(currentWord);
    advWord();
    remainboost = StrToInt(currentWord);
    advWord();
    countboost = StrToInt(currentWord);
    advWord();
    money = StrToInt(currentWord);
    advWord();
    speed = StrToInt(currentWord);
    advWord();
    time = (float) StrToInt(currentWord);
    
    createPlayer(p, Bangunan);
    p->bagCapacity = bagCap;
    p->boost.remainBoost = remainboost;
    p->boost.countTime = countboost;
    p->money = money;
    p->speed = speed;
    p->time = time;
    
    int x,y;
    startLine(fp);
    name = currentWord.contents[0];
    advWord();
    x = StrToInt(currentWord);
    advWord();
    y = StrToInt(currentWord);
    POINT titik = MakePOINT(x,y);
    LOCATION loc = makeLocation(name, titik);
    p->currentLocation = loc;

    startLine(fp);
    len = StrToInt(currentWord);
    ListLinked temp;
    CreateListLinked(&temp);
    for (i=0; i<len; i++) {
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
        insertItemLast(&temp, ITEM);
    }
    p->drafPick = temp;
    // displayListLinked(p->drafPick);
    CreateListGadget(l);
    for (i=0; i<5; i++) {
        startLine(fp);
        if (currentWord.contents[0] != '-') {
            if (currentWord.contents[0] == 'K') {
                addGadget(l, 0);
                advWord();
            } else if (currentWord.contents[0] == 'S') {
                addGadget(l, 1);
            } else if (currentWord.contents[0] == 'P') {
                addGadget(l, 2);
            } else if (currentWord.contents[0] == 'M') {
                addGadget(l,3);
            }
            advWord();
        }
    }
    fclose(fp);
}