/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "../../boolean.h"
#include "../queue/queue.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef struct {
  Item buffer[CAPACITY]; /* tabel penyimpan elemen */
  int idxTop;			   /* alamat TOP: elemen puncak */
  int length;               /* length jumlah elemen dalam stack */
  int heavy;      // Banyaknya barang heavy
} Stack;

int lengthStack(Stack s);
/* Mengembalikan jumlah elemen stack */

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define LEN_STACK(s) (s).length
#define   IDX_TOP(s) (s).idxTop
#define       TOP(s) (s).buffer[(s).idxTop]
#define     HEAVY(s) (s).heavy

/* *** Konstruktor/Kreator *** */
void CreateStack(Stack *s);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */

/* ************ Prototype ************ */
boolean isEmptyStack(Stack s);
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isFullStack(Stack s);
/* Mengirim true jika tabel penampung nilai s stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void push(Stack *s, Item val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, Item *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

boolean isPerishableIn(Stack bag);
void cutDuration(Stack *bag);
int isPerishableDie(Stack bag);
void deletePerishableStack(Stack *bag);

#endif
