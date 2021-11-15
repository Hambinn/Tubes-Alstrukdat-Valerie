#ifndef READ_FILE_h
#define READ_FILE_h

#include <stdio.h>
#include "..\lib\boolean.h"
#include "..\lib\charmachine.h"
#include "..\lib\listdin.h"
#include "..\lib\listpos.h"
#include "..\lib\matrix.h"
#include "..\lib\point.h"
#include "..\lib\wordmachine.h"
#include "..\lib\location.h"
#include "..\lib\queue.h"
#include "..\lib\queue.c"
#include "..\lib\location.c"
#include "..\lib\charmachine.c"
#include "..\lib\listdin.c"
#include "..\lib\listpos.c"
#include "..\lib\matrix.c"
#include "..\lib\point.c"
#include "..\lib\wordmachine.c"

extern Matrix adjacency;
extern Map MAP;
extern ListDin Bangunan;
extern Queue QueueOrder;
extern LOCATION HQ;

int StrToInt(Word w);
void readFile(char path[]);

#endif