/*
NIM             : 13520090
Nama            : Rahmat Rafid Akbar
Tanggal         : 7 September 2021
Topik praktikum : ADT List
Deskripsi       : Pra Praktikum, membuat realisasi header ADT list
                  implementasi array implisit rata kiri
*/

#include <stdio.h>
#include "listpos.h"

/* Array 1)Implisit 2)Rata Kiri */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListPos(ListPos *l){
    int i;
    for(i=0; i<=CAPACITY-1; i++){
        ELMT(*l, i)=VAL_UNDEF;
    }
    return;
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListPos l){
    int count = 0;
    if(ELMT(l,0)!=VAL_UNDEF){
        boolean found = false;
        while(count<=CAPACITY-1 && !(found)){
            if(ELMT(l,count)!=VAL_UNDEF){
                count++;
            }
            else{
                found=true;
            }
        }
    }
    return count;
}
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListPos l, int i){
    return (0<=i && i<=CAPACITY-1);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container */
boolean isIdxEff(ListPos l, int i){
    return (0<=i && i<=length(l)-1);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListPos l){
    return (length(l)==0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListPos l){
    return (length(l)==CAPACITY);
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l){
    int size;
    scanf("%d",&size);
    while(size<0 ||CAPACITY<size){
        scanf("%d",&size);
    }
    CreateListPos(l);
    if(size>0){
        int i;
        for(i=0; i<=size-1; i++){
            scanf("%d",&ELMT(*l,i));
        }
    }
    return;
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void displayList(ListPos l){
    if(isEmpty(l)){
        printf("[]");
    }
    else{
        int i;
        printf("[");
        for(i=0;i<=length(l)-1;i++){
            if(i==0){
                printf("%d",ELMT(l,i));
            }
            else{
                printf(",%d",ELMT(l,i));
            }
        }
        printf("]");
    }
    return;
}
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListPos plusMinusTab(ListPos l1, ListPos l2, boolean plus){
    ListPos l;
    CreateListPos(&l);
    int i;
    for(i=0;i<=length(l1)-1;i++){
        if(plus==true){
            ELMT(l,i)=ELMT(l1,i)+ELMT(l2,i);
        }
        else{
            ELMT(l,i)=ELMT(l1,i)-ELMT(l2,i);
        }
    }
    return l;
}
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListPos l1, ListPos l2){
    boolean sign=false;
    if(length(l1)==length(l2)){
        sign=true;
        int i=0;
        while(i<=length(l1)-1 && sign){
            if(ELMT(l1,i)!=ELMT(l2,i)){
                sign=false;
            }
            i++;
        }
    }
    return sign;
}
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListPos l, ElType val){
    int idx=IDX_UNDEF;
    if(length(l)!=0){
        boolean found=false;
        int i=0;
        while(i<=length(l)-1 && !(found)){
            if(ELMT(l,i)==val){
                found=true;
                idx=i;
            }
            i++;
        }
    }
    return idx;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ElType *max, ElType *min){
    int i;
    *max=ELMT(l,0);
    *min=ELMT(l,0);
    for(i=1;i<=length(l)-1;i++){
        if(ELMT(l,i)>*max){
            *max=ELMT(l,i);
        }
        if(ELMT(l,i)<*min){
            *min=ELMT(l,i);
        }
    }
    return;
}
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** OPERASI LAIN ********** */
boolean isAllEven(ListPos l){
    boolean sign=true;
    int i=0;
    while(i<=length(l)-1 && sign){
        if(ELMT(l,i)%2!=0){
            sign=false;
        }
        i++;
    }
    return sign;
}
/* Menghailkan true jika semua elemen l genap */

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc){
    if(length(*l)>1){
        if(asc==true){
            int pass;   // index
            for(pass=0;pass<=length(*l)-2;pass++){
                int IMin=pass;
                int i;
                for(i=pass+1;i<=length(*l)-1;i++){
                    if(ELMT(*l,i)<ELMT(*l,IMin)){
                        IMin=i;
                    }
                }
                ElType temp=ELMT(*l,IMin);
                ELMT(*l,IMin)=ELMT(*l,pass);
                ELMT(*l,pass)=temp;
            }
        }
        else{
            int pass;   // index
            for(pass=0;pass<=length(*l)-2;pass++){
                int IMax=pass;
                int i;
                for(i=pass+1;i<=length(*l)-1;i++){
                    if(ELMT(*l,i)>ELMT(*l,IMax)){
                        IMax=i;
                    }
                }
                ElType temp=ELMT(*l,IMax);
                ELMT(*l,IMax)=ELMT(*l,pass);
                ELMT(*l,pass)=temp;
            }
        }
    }
    return;
}

/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListPos *l, ElType val){
    ELMT(*l,length(*l))=val;
    return;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ElType *val){
    *val=ELMT(*l,length(*l)-1);
    ELMT(*l,length(*l)-1)=VAL_UNDEF;
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */