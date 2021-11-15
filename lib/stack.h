/* File : stack.h */
/* Definisi ADT Stack dengan representasi array secara eksplisit dan alokasi statik */
/* TOP adalah alamat elemen puncak */

#ifndef STACK_H
#define STACK_H

#include "boolean.h"
#include "queue.h"
#include "player.h"

#define IDX_UNDEF -1
#define CAPACITY 100

typedef struct {
  char drop_off;
  char item_type;
  int duration; // Misal perishabel itu durasi, kalo misal heavy itu banyak heavy
} ItemBag;
typedef struct {
  ItemBag buffer[CAPACITY]; /* tabel penyimpan elemen */
  int idxTop;			   /* alamat TOP: elemen puncak */
  int counter;               /* counter jumlah elemen dalam stack */
  int heavy;      // Banyaknya barang heavy
} Stack;

int countStack(Stack s);
/* Mengembalikan jumlah elemen stack */

# define DROP_PLACE(s) (s).drop_off;
# define  ITEM_TYPE(s) (s).item_type;
# define   DURATION(s) (s).duration;

/* ********* AKSES (Selektor) ********* */
/* Jika s adalah Stack, maka akses elemen : */
#define COUNTER(s) (s).counter
#define IDX_TOP(s) (s).idxTop
#define     TOP(s) (s).buffer[(s).idxTop]
#define   HEAVY(s) (s).heavy;

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
void push(Stack *s, ItemBag val);
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void pop(Stack *s, ItemBag *val);
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */

#endif
