#include <stdio.h>
#include "listgadget.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListGadget(ListGadget *l)
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */
{
   
   int i;
   for(i=0; i<CAPACITY; i++)
   {
      GDGT(*l,i)=VAL_UNDEF;
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
   GDGT(*l,i) = VAL_UNDEF;
}

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListGadget l)
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */
{
   int i=0;
   while (GDGT(l,i)!=VAL_UNDEF && i<CAPACITY)
   {
      i++;
   }
   return i;
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListGadget l)
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
{
   return(length(l)==0);
}
boolean isFull(ListGadget l)
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */
{
   return(length(l)==CAPACITY);
}

void displayList(ListGadget l)
{
   int i;
   printf("[");
   for(i=0;i<CAPACITY;i++)
   {
      printf("%s", GDGT(l,i));
      if (i!=CAPACITY-1)
      {
         printf(",");
      }
   }
   printf("]");
}