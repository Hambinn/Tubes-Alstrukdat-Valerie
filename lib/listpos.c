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
    for(i=0; i<=CAPACITYLISTPOS-1; i++){
        ELMTListPos(*l, i)=VAL_UNDEF;
    }
    return;
}
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITYLISTPOS */
/* Proses: Inisialisasi semua elemen List l dengan VAL_UNDEF */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int lengthListPos(ListPos l){
    int count = 0;
    if(ELMTListPos(l,0)!=VAL_UNDEF){
        boolean found = false;
        while(count<=CAPACITYLISTPOS-1 && !(found)){
            if(ELMTListPos(l,count)!=VAL_UNDEF){
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
boolean isIdxValidListPos(ListPos l, int i){
    return (0<=i && i<=CAPACITYLISTPOS-1);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container */
boolean isIdxEffListPos(ListPos l, int i){
    return (0<=i && i<=lengthListPos(l)-1);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..lengthListPos(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmptyListPos(ListPos l){
    return (lengthListPos(l)==0);
}
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFullListPos(ListPos l){
    return (lengthListPos(l)==CAPACITYLISTPOS);
}
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListPos *l){
    int size;
    scanf("%d",&size);
    while(size<0 ||CAPACITYLISTPOS<size){
        scanf("%d",&size);
    }
    CreateListPos(l);
    if(size>0){
        int i;
        for(i=0; i<=size-1; i++){
            scanf("%d",&ELMTListPos(*l,i));
        }
    }
    return;
}
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITYLISTPOS */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITYLISTPOS; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void displayList(ListPos l){
    if(isEmptyListPos(l)){
        printf("[]");
    }
    else{
        int i;
        printf("[");
        for(i=0;i<=lengthListPos(l)-1;i++){
            if(i==0){
                printf("%d",ELMTListPos(l,i));
            }
            else{
                printf(",%d",ELMTListPos(l,i));
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
    for(i=0;i<=lengthListPos(l1)-1;i++){
        if(plus==true){
            ELMTListPos(l,i)=ELMTListPos(l1,i)+ELMTListPos(l2,i);
        }
        else{
            ELMTListPos(l,i)=ELMTListPos(l1,i)-ELMTListPos(l2,i);
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
    if(lengthListPos(l1)==lengthListPos(l2)){
        sign=true;
        int i=0;
        while(i<=lengthListPos(l1)-1 && sign){
            if(ELMTListPos(l1,i)!=ELMTListPos(l2,i)){
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
int indexOf(ListPos l, ListType val){
    int idx=IDX_UNDEF;
    if(lengthListPos(l)!=0){
        boolean found=false;
        int i=0;
        while(i<=lengthListPos(l)-1 && !(found)){
            if(ELMTListPos(l,i)==val){
                found=true;
                idx=i;
            }
            i++;
        }
    }
    return idx;
}
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMTListPos(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes(ListPos l, ListType *max, ListType *min){
    int i;
    *max=ELMTListPos(l,0);
    *min=ELMTListPos(l,0);
    for(i=1;i<=lengthListPos(l)-1;i++){
        if(ELMTListPos(l,i)>*max){
            *max=ELMTListPos(l,i);
        }
        if(ELMTListPos(l,i)<*min){
            *min=ELMTListPos(l,i);
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
    while(i<=lengthListPos(l)-1 && sign){
        if(ELMTListPos(l,i)%2!=0){
            sign=false;
        }
        i++;
    }
    return sign;
}
/* Menghailkan true jika semua elemen l genap */

/* ********** SORTING ********** */
void sort(ListPos *l, boolean asc){
    if(lengthListPos(*l)>1){
        if(asc==true){
            int pass;   // index
            for(pass=0;pass<=lengthListPos(*l)-2;pass++){
                int IMin=pass;
                int i;
                for(i=pass+1;i<=lengthListPos(*l)-1;i++){
                    if(ELMTListPos(*l,i)<ELMTListPos(*l,IMin)){
                        IMin=i;
                    }
                }
                ListType temp=ELMTListPos(*l,IMin);
                ELMTListPos(*l,IMin)=ELMTListPos(*l,pass);
                ELMTListPos(*l,pass)=temp;
            }
        }
        else{
            int pass;   // index
            for(pass=0;pass<=lengthListPos(*l)-2;pass++){
                int IMax=pass;
                int i;
                for(i=pass+1;i<=lengthListPos(*l)-1;i++){
                    if(ELMTListPos(*l,i)>ELMTListPos(*l,IMax)){
                        IMax=i;
                    }
                }
                ListType temp=ELMTListPos(*l,IMax);
                ELMTListPos(*l,IMax)=ELMTListPos(*l,pass);
                ELMTListPos(*l,pass)=temp;
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
void insertLast(ListPos *l, ListType val){
    ELMTListPos(*l,lengthListPos(*l))=val;
    return;
}
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListPos *l, ListType *val){
    *val=ELMTListPos(*l,lengthListPos(*l)-1);
    ELMTListPos(*l,lengthListPos(*l)-1)=VAL_UNDEF;
}
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

int charToIntLP(char c){
    int x;
    if (c=='8'){
        x = 0;
    }
    else{
        x =((int)c - 64);
    }
    return x;
}

boolean isIn(ListPos l, char X){
    boolean isin = false;
    if (!isEmptyListPos(l)){    
        int i = 0 ;
        while ( i < lengthListPos(l) && !isin){
            if ( ELMTListPos(l,i)==charToIntLP(X) ){
                isin = true;
            }
            else{
                i++;
            }
        }
    }
    return isin;
}
