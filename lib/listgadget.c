#include <stdio.h>
#include "listgadget.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListGadget(ListGadget *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas INVENTORY */
/* Proses: Inisialisasi semua elemen List l dengan STRIP */
{
   
   int i;
   for(i=0; i<INVENTORY; i++)
   {
      GDGT(*l,i)=STRIP;
   }
}

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void addGadget(ListGadget *l, int i)
/* Proses: Menambahkan gadget sebagai elemen ke-i List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. gadget ditambahkan */
{
   GDGT(*l,i) = arr[i];
}

/* ********** MENGHAPUS ELEMEN ********** */
void deleteGadget(ListGadget *l, int i)
/* Proses : Menghapus elemen ke-i List */
/* I.S. List tidak kosong */
/* F.S. Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
{
   GDGT(*l,i) = STRIP;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthGadget(ListGadget l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
   int i=0;
   while (GDGT(l,i)!=STRIP && i<INVENTORY)
   {
      i++;
   }
   return i;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyInventory(ListGadget l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
   return(lengthGadget(l)==0);
}
boolean isFullInventory(ListGadget l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
   return(lengthGadget(l)==INVENTORY);
}

void displayListGadget(ListGadget l)
{
   int i;
   printf("[");
   for(i=0;i<INVENTORY;i++)
   {
      printf("%s", GDGT(l,i));
      if (i!=INVENTORY-1)
      {
         printf(",");
      }
   }
   printf("]");
}