#include <stdio.h>
#include <math.h>
#include "readfile.c"
#include "inventory.c"

Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;

int main()
{
	readFile("../config/config.txt");
    Player p;
    ListGadget l;
    Stack bag;
    CreateStack(&bag);
  	CreateListGadget(&l);
    createPlayer(&p,Bangunan);
	
	addGadget(&l,0);
    addGadget(&l,1);
    addGadget(&l,2);
    addGadget(&l,3);
    addGadget(&l,4);

    printf("============================== INVENTORY =================================");
      endl;
      displayInventory(&p, l);

      printf("\nENTER COMMAND: ");
      int choice;
      startLine(tape);
      choice = StrToInt(currentWord);

      if(choice == 1)
      {
          checkSlot(&p, &l, &bag, 0);
      }
      else if(choice == 2)
      {
          checkSlot(&p, &l, &bag, 1);
      }
      else if(choice == 3)
      {
          checkSlot(&p, &l, &bag, 2);
      }
      else if(choice == 4)
      {
          checkSlot(&p, &l, &bag, 3);
      }
      else if(choice == 5)
      {
          checkSlot(&p, &l, &bag, 4);
      }


  	return 0;
}