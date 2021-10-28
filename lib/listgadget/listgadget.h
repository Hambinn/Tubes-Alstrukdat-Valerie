#ifndef LISTGADGET_H
#define LISTGADGET_H

#include "../boolean.h"

/*  Kamus Umum */
#define CAPACITY 5
#define STRING 22
#define VAL_UNDEF "-"
#define GADGET {"Kain Pembungkus Waktu", "Senter Pembesar", "Pintu Kemana Saja", "Mesin Waktu", "Senter Pengecil"}

/* Definisi elemen dan koleksi objek */
  /* type elemen List */
typedef char ElType;
typedef struct {
   ElType* contents[CAPACITY]; /* memori tempat penyimpan elemen (container) */
} ListGadget;
ElType arr[CAPACITY][STRING] = GADGET;
/* Indeks yang digunakan [0..CAPACITY-1] */
/* Jika l adalah ListGadget, cara deklarasi dan akses: */
/* Deklarasi : l : ListGadget */
/* Maka cara akses: 
   GDGT(l,i) untuk mengakses elemen ke-i */
/* Definisi : 
   List kosong: semua elemen bernilai VAL_UNDEF
   Definisi elemen pertama: GDGT(l,i) dengan i=0 */

/* ********** SELEKTOR ********** */
#define GDGT(l, i) (l).contents[(i)]

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListGadget(ListGadget *l);
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void addGadget(ListGadget *l, int i);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteGadget(ListGadget *l, int i);
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListGadget l);
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListGadget l);
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListGadget l);
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

void displayList(ListGadget l);
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

#endif