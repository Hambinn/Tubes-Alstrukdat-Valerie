/*
NIM             : 13520090
Nama            : Rahmat Rafid Akbar
Tanggal         : 14 September 2021
Topik praktikum : ADT List Dinamic
Deskripsi       : Pra Praktikum, membuat realisasi header ADT list Dinamic
                  implementasi array eksplisit rata kiri
*/

#include <stdio.h>
#include <stdlib.h>
#include "listdin.h"
#include "point.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
    LISTDIN_CAPACITY(*l)=capacity;
    LISTDIN_LOCATION(*l) = (LOCATION*) malloc(capacity*sizeof(LOCATION));
    LISTDIN_NEFF(*l)=0;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void listdin_dealocate(ListDin *l){
    LISTDIN_NEFF(*l)=0;
    LISTDIN_CAPACITY(*l)=0;
    free(LISTDIN_LOCATION(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, LISTDIN_CAPACITY(l)=0; LISTDIN_NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listdin_length(ListDin l){
    return LISTDIN_NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType listdin_getLastIdx(ListDin l){
    if(listdin_isEmpty(l)){
        return 0;
    }
    else{
        return listdin_length(l)-1;
    }
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean listdin_isIdxValid(ListDin l, int i){
    return (0<=i && i<=LISTDIN_CAPACITY(l)-1);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean listdin_isIdxEff(ListDin l, IdxType i){
    return (0<=i && i<=listdin_length(l)-1);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..LISTDIN_NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean listdin_isEmpty(ListDin l){
    return (listdin_length(l)==0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean listdin_isFull(ListDin l){
    return (listdin_length(l)==LISTDIN_CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */

/* *** Mendefinisikan isi list dari pembacaan *** */
void listdin_insertList(ListDin *l, LOCATION loc){
    if (!listdin_isFull(*l)) {
        LISTDIN_LOCATION(*l)[LISTDIN_NEFF(*l)] = loc;
        LISTDIN_NEFF(*l)++;
    }
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= LISTDIN_CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= LISTDIN_CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void listdin_displayList(ListDin l){
    if(listdin_isEmpty(l)){
        printf("[]");
    }
    else{
        int i;
        printf("[");
        for(i=0;i<=listdin_length(l)-1;i++){
            if(i!=0){
                printf(",");
            }
            printf("%d",LISTDIN_ELMT(l,i));
        }
        printf("]");
    }
    return;
}
/* Proses : Menuliskan isi list dengan traversal, list ditulis di antara kurung siku;
   antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan karakter di depan,
   di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */