#include "stack.h"
#include <stdio.h>

int lengthStack(Stack s){
	/* Mengembalikan jumlah elemen dalam stack */
	return (LEN_STACK(s));
}

/* *** Konstruktor/Kreator *** */
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S kosong dengan kondisi sbb: */
/* - Index top bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah s kosong */
void CreateStack(Stack *s){
    IDX_TOP(*s) = IDX_UNDEF;
    LEN_STACK(*s) = 0;
    HEAVY(*s) = 0;
}

/* ************ Prototype ************ */
/* Mengirim true jika s kosong: lihat definisi di atas */
boolean isEmptyStack(Stack s){
    return IDX_TOP(s) == IDX_UNDEF;
}
/* Mengirim true jika tabel penampung nilai s stack penuh */
boolean isFullStack(Stack s){
    return IDX_TOP(s) == CAPACITY-1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
/* Menambahkan val sebagai elemen Stack s */
/* I.S. s mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. val menjadi TOP yang baru,IDX_TOP bertambah 1 */
void push(Stack *s, Item val){
    if ( isEmptyStack(*s) ){
        IDX_TOP(*s) = 0;
    }
    else{
        IDX_TOP(*s) += 1;
    }
    TOP(*s) = val;
    LEN_STACK(*s)++;
    if (TYPE(val)=='H'){
        HEAVY(*s)++;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
/* Menghapus val dari Stack s */
/* I.S. s tidak mungkin kosong */
/* F.S. val adalah nilai elemen TOP yang lama, IDX_TOP berkurang 1 */
void pop(Stack *s, Item *val){
    *val = TOP(*s);
    if ( IDX_TOP(*s) == 0 ){
        IDX_TOP(*s) = IDX_UNDEF;
    }
    else{
        IDX_TOP(*s) -= 1;
    }
    LEN_STACK(*s)--;
    if (TYPE(*val)=='H'){
        HEAVY(*s)--;
    }
}

boolean isPerishableIn(Stack bag){
    boolean found = false;
    int i = 0;
    while (i < LEN_STACK(bag) && !found){
        if ( TYPE(bag.buffer[i]) == 'P' ){
            found = true;
        }
        else{
            i++;
        }
    }
    return found;
}

void cutDuration(Stack *bag){
    int i;
    for (i = 0; i < LEN_STACK(*bag); i++){
        if ( TYPE((*bag).buffer[i]) == 'P' && DURATION((*bag).buffer[i]) > 0 ){
            DURATION((*bag).buffer[i]) -= (1+HEAVY(*bag));
        }
    }
}

int isPerishableDie(Stack bag){
    boolean found = false;
    int i = 0;
    while (i < LEN_STACK(bag) && !found){
        if ( TYPE((bag).buffer[i]) == 'P' && DURATION((bag).buffer[i]) <= 0 ){
            found = true;
        }
        else{
            i++;
        }
    }
    if (!found){
        i = IDX_UNDEF;
    }
    return i;
}

// Hapus perishable kalo ada dan hangus
void deletePerishableStack(Stack *bag){
    if (IDX_TOP(*bag) == 0){
        if (TYPE(TOP(*bag)) == 'P' && DURATION(TOP(*bag)) == 0){   
            IDX_TOP(*bag) = IDX_UNDEF;
            LEN_STACK(*bag)--;
        }   
    }
    else if (IDX_TOP(*bag) > 0){
        int idx = isPerishableDie(*bag);
        boolean stiilExist = true;
        if (idx == IDX_UNDEF){
            stiilExist = false;
        }
        while ( stiilExist ){
            // hapus elemen yg Perishable Die 
            for(int i = idx; i < LEN_STACK(*bag)-1; i++){
                (*bag).buffer[i] = (*bag).buffer[i+1];
            }
            LEN_STACK(*bag)--;
            IDX_TOP(*bag)--;
            idx = isPerishableDie(*bag);
            if (idx == IDX_UNDEF){
                stiilExist = false;
            }
        }
    }
}
