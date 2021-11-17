#include <stdio.h>
#include "list_linked.h"


/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateListLinked(ListLinked *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isListLinkedEmpty(ListLinked l){
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/

void insertItemFirst(ListLinked *l, Item item){
    Address new = newNode(item);
    if ( new!=NULL ){
        NEXT(new) = FIRST(*l);
        FIRST(*l) = new;
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertItemLast(ListLinked *l, Item item){
    Address new = newNode(item);
    if ( new!=NULL ){
        if (isListLinkedEmpty(*l)) {
            FIRST(*l) = new;
        } else {
            Address p = FIRST(*l);
            while (NEXT(p) != NULL) {
                p = NEXT(p);
            }
            NEXT(p) = new;
        }
    }
}

/*** PENGHAPUSAN ELEMEN ***/
void deleteItem(ListLinked *l, Item item){
    Address p = FIRST(*l);   // p di idx 0
    if (isSame(ITEM(p), item)) {
        FIRST(*l) = NEXT(p);
        free(p);
    } else {
        boolean found = false;
        while ( !found && NEXT(p)!=NULL ){
            if ( isSame(ITEM(NEXT(p)), item) ){
                found = true;
            }
            else{
                p = NEXT(p);
            }
        }   // Terminate saat info(p)==val
        NEXT(p) = NEXT(NEXT(p)); 
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayListLinked(ListLinked l){
    if ( isListLinkedEmpty(l) ){
        printf("Tidak ada orderan");
    }
    else{
        Address p1 = FIRST(l);
        int i = 1;
        printf("%d. ", i);
        displayItem(ITEM(p1));
        p1 = NEXT(p1);
        while ( p1!=NULL ){
            i++;
            printf("%d. ", i);
            displayItem(ITEM(p1));
            p1 = NEXT(p1);
        }
    }
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int lengthLinkedList(ListLinked l){
    int len = 0;
    if ( !isListLinkedEmpty(l) ){
        len++;
        Address p = FIRST(l);
        p = NEXT(p);
        while( p!=NULL ){
            len++;
            p = NEXT(p);
        }   // Terminate saat udah di ujung ( NEXT(p)==NULL )
    }
    return len;
}
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

boolean isInLinkedList(ListLinked L, char name){
    boolean found = false;
    if ( isListLinkedEmpty(L) ){
        found = false;
    }
    else {
        Address pt = FIRST(L);
        found = false;
        while( !found && pt!=NULL ){
            if (name == PICKUP(ITEM(pt))){
                found = true;
            }
            else{
                pt = NEXT(pt);
            }
        }
    }
    return found;
}
/* Mencari apakah ada elemen list yang it */
/* Mengirimkan true jika ada, false jika tidak ada */