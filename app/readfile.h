#ifndef READ_FILE_h
#define READ_FILE_h

#include <stdio.h>
#include "..\lib\boolean.h"
#include "..\lib\charmachine.c"
#include "..\lib\list_linked.c"
#include "..\lib\listdin.c"
#include "..\lib\listgadget.c"
#include "..\lib\listpos.c"
#include "..\lib\location.c"
#include "..\lib\matrix.c"
#include "..\lib\point.c"
#include "..\lib\queue.c"
#include "..\lib\stack.c"
#include "..\lib\wordmachine.c"
#include "..\lib\node.c"
#include "..\lib\player.c"


extern Matrix adjacency;
extern Map MAP;
extern ListDin Bangunan;
extern Queue QueueOrder;
extern LOCATION HQ;
extern ListLinked inProgress;

int StrToInt(Word w);
void readFile(char path[]);

#endif