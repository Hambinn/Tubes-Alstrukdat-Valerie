#ifndef READ_FILE_h
#define READ_FILE_h

#include <stdio.h>
#include "..\lib\boolean.h"
#include "..\lib\ADT\input\charmachine.c"
#include "..\lib\ADT\linked\list_linked.c"
#include "..\lib\ADT\list\listdin.c"
#include "..\lib\ADT\gadget\listgadget.c"
#include "..\lib\ADT\list\listpos.c"
#include "..\lib\ADT\other\location.c"
#include "..\lib\ADT\matrix\matrix.c"
#include "..\lib\ADT\other\point.c"
#include "..\lib\ADT\stack\stack.c"
#include "..\lib\ADT\input\wordmachine.c"
#include "..\lib\ADT\linked\node.c"
#include "..\lib\ADT\player\player.c"


extern Matrix adjacency;
extern Map MAP;
extern ListDin Bangunan;
extern Queue QueueOrder;
extern LOCATION HQ;
extern ListLinked inProgress;

int StrToInt(Word w);
void readFile(char path[]);

#endif