#include <stdio.h>
#include "..\lib\boolean.h"
#include "..\lib\charmachine.h"
#include "..\lib\listdin.h"
#include "..\lib\listpos.h"
#include "..\lib\matrix.h"
#include "..\lib\player.h"
#include "..\lib\point.h"
#include "..\lib\stack.h"
#include "..\lib\wordmachine.h"
#include "..\lib\location.h"
#include "..\lib\item.h"
#include "..\lib\location.c"
#include "..\lib\item.c"
#include "..\lib\charmachine.c"
#include "..\lib\listdin.c"
#include "..\lib\listpos.c"
#include "..\lib\matrix.c"
#include "..\lib\player.c"
#include "..\lib\point.c"
#include "..\lib\stack.c"
#include "..\lib\wordmachine.c"

int StrToInt(Word w) {
    int x = 0;
    int i;
    for (i = 0; i < w.length; i++) {
        x = 10*x + ((int)w.contents[i]-48);
    }
    return x;
}

int main() {
    Matrix MAP;
    ListDin LocationList;
    FILE *fp;
    fp=fopen("../config/config.txt", "r");
    startLine(fp);
    int n, m;
    n = StrToInt(currentWord);
    advWord();
    m = StrToInt(currentWord);
    CreateMatrix(n, m, &MAP);
    startLine(fp);
    n = StrToInt(currentWord);
    advWord();
    m = StrToInt(currentWord);
    POINT HQ = MakePOINT(n, m);
    LOCATION hq = makeLocation("HQ", HQ);
    startLine(fp);
    n = StrToInt(currentWord);
    CreateListDin(&LocationList, n+1);
    listdin_insertList(&LocationList, hq);
    int i;
    for (i = 0; i < n; i++) {
        int x, y;
        char name[2];
        startLine(fp);
        name[0] = currentWord.contents[0];
        name[1] = currentWord.contents[1];
        advWord();
        x = StrToInt(currentWord);
        advWord();
        y = StrToInt(currentWord);
        POINT p = MakePOINT(x, y);
        LOCATION l = makeLocation(name, p);
        listdin_insertList(&LocationList, l);
        printf("%s\n", LocationList.buffer[i].name);
    }
}