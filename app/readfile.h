#ifndef READ_FILE_h
#define READ_FILE_h

#include <stdio.h>
#include "..\lib\boolean.h"
#include "..\lib\charmachine.h"
#include "..\lib\charmachine.c"
#include "..\lib\help.c"
#include "..\lib\list_linked.h"
#include "..\lib\list_linked.c"
#include "..\lib\listdin.h"
#include "..\lib\listdin.c"
#include "..\lib\listgadget.h"
#include "..\lib\listgadget.c"
#include "..\lib\listpos.h"
#include "..\lib\listpos.c"
#include "..\lib\location.h"
#include "..\lib\location.c"
#include "..\lib\matrix.h"
#include "..\lib\matrix.c"
#include "..\lib\point.h"
#include "..\lib\point.c"
#include "..\lib\queue.h"
#include "..\lib\queue.c"
#include "..\lib\stack.h"
#include "..\lib\stack.c"
#include "..\lib\wordmachine.h"
#include "..\lib\wordmachine.c"


extern Matrix adjacency;
extern Map MAP;
extern ListDin Bangunan;
extern Queue QueueOrder;
extern LOCATION HQ;

int StrToInt(Word w);
void readFile(char path[]);

#endif