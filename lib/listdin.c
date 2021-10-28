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
#define endl print("\n")

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create list kosong  */
void CreateListDin(ListDin *l, int capacity){
    CAPACITY(*l)=capacity;
    BUFFER(*l) = (ElType*) malloc(CAPACITY(*l)*sizeof(ElType));
    NEFF(*l)=0;
    return;
}
/* I.S. l sembarang, capacity > 0 */
/* F.S. Terbentuk list dinamis l kosong dengan kapasitas capacity */

void dealocate(ListDin *l){
    NEFF(*l)=0;
    CAPACITY(*l)=0;
    free(BUFFER(*l));
}
/* I.S. l terdefinisi; */
/* F.S. (l) dikembalikan ke system, CAPACITY(l)=0; NEFF(l)=0 */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int length(ListDin l){
    return NEFF(l);
}
/* Mengirimkan banyaknya elemen efektif list */
/* Mengirimkan nol jika list l kosong */
/* *** Daya tampung container *** */

/* *** Selektor INDEKS *** */
IdxType getLastIdx(ListDin l){
    if(isEmpty(l)){
        return 0;
    }
    else{
        return length(l)-1;
    }
}
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListDin l, int i){
    return (0<=i && i<=CAPACITY(l)-1);
}
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListDin l, IdxType i){
    return (0<=i && i<=length(l)-1);
}
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk list */
/* yaitu antara 0..NEFF(l) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test list kosong *** */
boolean isEmpty(ListDin l){
    return (length(l)==0);
}
/* Mengirimkan true jika list l kosong, mengirimkan false jika tidak */
/* *** Test list penuh *** */
boolean isFull(ListDin l){
    return (length(l)==CAPACITY(l));
}
/* Mengirimkan true jika list l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi list dari pembacaan *** */
void readList(ListDin *l){
    int size;
    scanf("%d",&size);
    while(size<0 ||CAPACITY(*l)<size){
        scanf("%d",&size);
    }
    CreateListDin(l,CAPACITY(*l));
    NEFF(*l)=size;
    if(size>0){
        int i;
        for(i=0; i<=size-1; i++){
            scanf("%d",&ELMT(*l,i));
        }
    }
    return;
}
/* I.S. l sembarang dan sudah dialokasikan sebelumnya */
/* F.S. List l terdefinisi */
/* Proses : membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya N */
/*    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l) */
/*    Jika N tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter */
/*    Jika N = 0; hanya terbentuk l kosong */
void displayList(ListDin l){
    if(isEmpty(l)){
        printf("[]");
    }
    else{
        int i;
        printf("[");
        for(i=0;i<=length(l)-1;i++){
            if(i!=0){
                printf(",");
            }
            printf("%d",ELMT(l,i));
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

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika list : Penjumlahan, pengurangan, perkalian, ... *** */
ListDin plusMinusList(ListDin l1, ListDin l2, boolean plus){
    ListDin l;
    CreateListDin(&l,CAPACITY(l1));
    NEFF(l)=NEFF(l1);
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
/* Prekondisi : l1 dan l2 memiliki Neff sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan list : < =, > *** */
boolean isListEqual(ListDin l1, ListDin l2){
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
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika nEff l1 = l2 dan semua elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : list boleh kosong!! *** */
IdxType indexOf(ListDin l, ElType val){
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
/* Jika ada, menghasilkan indeks i terkecil, dengan elemen ke-i = val */
/* Jika tidak ada, mengirimkan IDX_UNDEF */
/* Menghasilkan indeks tak terdefinisi (IDX_UNDEF) jika List l kosong */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremes(ListDin l, ElType *max, ElType *min){
    *max=ELMT(l,0);
    *min=ELMT(l,0);
    int i;
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
/* F.S. max berisi nilai maksimum l;
        min berisi nilai minimum l */

/* ********** OPERASI LAIN ********** */
void copyList(ListDin lIn, ListDin *lOut){
    CreateListDin(lOut, CAPACITY(lIn));
    NEFF(*lOut)=NEFF(lIn);
    int i;
    for(i=0;i<=length(lIn)-1;i++){
        ELMT(*lOut,i)=ELMT(lIn,i);
    }
    return;
}
/* I.S. lIn terdefinisi tidak kosong, lOut sembarang */
/* F.S. lOut berisi salinan dari lIn (identik, nEff dan capacity sama) */
/* Proses : Menyalin isi lIn ke lOut */
ElType sumList(ListDin l){
    ElType sum=0;
    if(!(isEmpty(l))){
        int i;
        for(i=0;i<=length(l)-1;i++){
            sum+=ELMT(l,i);
        }
    }
    return sum;
}
/* Menghasilkan hasil penjumlahan semua elemen l */
/* Jika l kosong menghasilkan 0 */
int countVal(ListDin l, ElType val){
    int count=0;
    if(!(isEmpty(l))){
        int i;
        for(i=0;i<=length(l)-1;i++){
            if(ELMT(l,i)==val){
                count++;
            }
        }
    }
    return count;
}
/* Menghasilkan berapa banyak kemunculan val di l */
/* Jika l kosong menghasilkan 0 */
boolean isAllEven(ListDin l){
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
/* Menghailkan true jika semua elemen l genap. l boleh kosong */

/* ********** SORTING ********** */
void sort(ListDin *l, boolean asc){
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
}
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListDin *l, ElType val){
    ELMT(*l,length(*l))=val;
    NEFF(*l)+=1;
    return;
}
/* Proses: Menambahkan val sebagai elemen terakhir list */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */
/* ********** MENGHAPUS ELEMEN ********** */
void deleteLast(ListDin *l, ElType *val){
    *val=ELMT(*l,length(*l)-1);
    NEFF(*l)-=1;
}
/* Proses : Menghapus elemen terakhir list */
/* I.S. List lidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen list berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********* MENGUBAH UKURAN ARRAY ********* */
void growList(ListDin *l, int num){
    CAPACITY(*l)+=num;
    // int newCapacity=CAPACITY(*l)+num;
    // // Salin isi List L ke temp, juga NEFFnya
    // ListDin temp;
    // copyList(*l,&temp);
    // // Buat ulang List L, salin temp ke L
    // dealocate(l);
    // CreateListDin(l,newCapacity);
    // NEFF(*l)=NEFF(temp);
    // int i;
    // for(i=0;i<=length(temp)-1;i++){
    //     ELMT(*l,i)==ELMT(temp,i);
    // }
    // dealocate(&temp);
}
/* Proses : Menambahkan capacity l sebanyak num */
/* I.S. List sudah terdefinisi */
/* F.S. Ukuran list bertambah sebanyak num */

void shrinkList(ListDin *l, int num){
    CAPACITY(*l)-=num;
    // int newCapacity=CAPACITY(*l)-num;
    // // Salin isi List L ke temp, juga NEFFnya
    // ListDin temp;
    // copyList(*l,&temp);
    // // Buat ulang List L, salin temp ke L
    // dealocate(l);
    // CreateListDin(l,newCapacity);
    // NEFF(*l)=NEFF(temp);
    // int i;
    // for(i=0;i<=length(temp)-1;i++){
    //     ELMT(*l,i)==ELMT(temp,i);
    // }
    // dealocate(&temp);
}
/* Proses : Mengurangi capacity sebanyak num */
/* I.S. List sudah terdefinisi, ukuran capacity > num, dan nEff < capacity - num. */
/* F.S. Ukuran list berkurang sebanyak num. */

void compactList(ListDin *l){
    CAPACITY(*l)=NEFF(*l);
    // int newCapacity=NEFF(*l);
    // // Salin isi List L ke temp, juga NEFFnya
    // ListDin temp;
    // copyList(*l,&temp);
    // // Buat ulang List L, salin temp ke L
    // dealocate(l);
    // CreateListDin(l,newCapacity);
    // NEFF(*l)=NEFF(temp);
    // int i;
    // for(i=0;i<=length(temp)-1;i++){
    //     ELMT(*l,i)==ELMT(temp,i);
    // }
    // dealocate(&temp);
}
/* Proses : Mengurangi capacity sehingga nEff = capacity */
/* I.S. List lidak kosong */
/* F.S. Ukuran nEff = capacity */