/* File : queue.h */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_H
#define QUEUE_H

#include "../../boolean.h"

#define IDX_UNDEF -1

/* Definisi elemen dan address */

typedef struct {
        int tMasuk;
        char pick_up;
        char drop_off;
        char type;
        int duration;
} Item;

#define TMASUK(x)  (x).tMasuk
#define PICKUP(x)  (x).pick_up
#define DROPOFF(x) (x).drop_off
#define TYPE(x)    (x).type
#define DURATION(x)(x).duration

Item makeItem (int tMasuk, char pick_up, char drop_off, char type, int dur);

Item copyItem(Item ITEM);

void displayItem(Item ITEM);

boolean isSame (Item item1, Item item2);

typedef struct {
	Item buffer[100]; 
	int idxHead;
	int idxTail;
} Queue;


/* ********* AKSES (Selektor) ********* */
/* Jika q adalah Queue, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]
#define ELMT_Q(q,i) (q).buffer[(i)]

/* *** Kreator *** */
void CreateQueue(Queue *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isEmptyQueue(Queue q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isFullQueue(Queue q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu jika index head bernilai 0 dan index tail bernilai 100-1 */
int lengthQueue(Queue q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Item val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
        Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
        menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */

void dequeue(Queue *q, Item *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
        q mungkin kosong */

/* *** Display Queue *** */
void displayQueue(Queue q);
/* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */


#endif