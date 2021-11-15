#include <stdio.h>
#include "list_linked.h"
#define endl printf("\n")


/* Definisi List : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
/* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return FIRST(l) == NULL;
}
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    int i = 0;
    Address p = FIRST(l);   // p di idx 0
    while ( i < idx ){
        i++;
        p = NEXT(p);
    }   // Terminate saat p di idx: i==idx
    return INFO(p);
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    int i = 0;
    Address p = FIRST(*l);   // p di idx 0
    while ( i < idx ){
        i++;
        p = NEXT(p);
    }   // Terminate saat p di idx: i==idx
    INFO(p) = val;
}
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    Address p = FIRST(l);   // p di idx 0
    int i = 0;
    boolean found = false;
    while ( !found && p!=NULL ){
        if ( INFO(p)==val ){
            found = true;
        }
        else{
            p = NEXT(p);
            i++;
        }
    }   // Terminate saat info(p)==val
    if ( !found ){
        i = IDX_UNDEF;
    }
    return i;
}
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address new = newNode(val);
    if ( new!=NULL){
        if ( isEmpty(*l) ){     // Jika kosong
            FIRST(*l) = new;
        }
        else{                   // Pegang yang awal dulu
            Address old = FIRST(*l);
            FIRST(*l) = new;
            NEXT(new) = old;
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    Address new = newNode(val);
    if ( new!=NULL ){
        if ( isEmpty(*l) ){     // Jika kosong
            FIRST(*l) = new;
        }
        else{
            Address p = FIRST(*l);   // p di idx 0
            while( NEXT(p)!=NULL ){
                p = NEXT(p);
            }   // Terminate saat udah di ujung ( NEXT(p)==NULL )
            NEXT(p) = new;
        }
    }
    
}
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    if ( idx == 0 ){
        insertFirst(l, val);
    }
    else{
        Address new = newNode(val);
        if ( new!=NULL ){
            int i = 0;
            Address p = FIRST(*l);
            while ( i < idx-1 ){
                i++;
                p = NEXT(p);
            }   // Terminate saat p tepat sebelum indek yg dicari (i == idx-1)
            NEXT(new) = NEXT(p);
            NEXT(p) = new;
        }
    }
}
/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address p1 = FIRST(*l);
    *val = INFO(p1);
    if ( NEXT(p1)==NULL ){      // Jika hanya ada 1 elemen
        FIRST(*l) = NULL;
    }
    else{                       // Jika lebih 1 elemen, first next ke kanan
        FIRST(*l) = NEXT(p1);
    }
    free(p1);
}
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address p1 = FIRST(*l);   // p di idx 0
    if ( NEXT(p1)==NULL ){      // Jika hanya ada 1 elemen
        *val = INFO(p1);
        FIRST(*l) = NULL;
        free(p1);
    }
    else{
        Address p2 = NEXT(p1);
        while( NEXT(p2)!=NULL ){
            p1 = NEXT(p1);
            p2 = NEXT(p2);
        }   // Terminate saat udah di ujung ( NEXT(p)==NULL )
        *val = INFO(p2);
        NEXT(p1) = NULL;
        free(p2);
    }
}
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    if ( idx==0 ){          // Kasus jika 1 elemen tercover
        deleteFirst(l, val);
    }
    else if ( idx==length(*l)-1 ){   // Jika yang dihapus yg terakhir
        deleteLast(l,val);
    }
    else{                   // Jika lebih dari 1 elemen dan yg dihapus elemen tengah            
        int i = 0;
        Address p1 = FIRST(*l);
        Address p2 = NEXT(p1);
        while ( i < idx-1 ){
            i++;
            p1 = NEXT(p1);
            p2 = NEXT(p2);
        }   // Terminate saat p tepat sebelum indek yg dicari (i == idx-1)
        *val = INFO(p2);
        NEXT(p1) = NEXT(p2);
        free(p2);
    }
}
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    if ( isEmpty(l) ){
        printf("[]");
    }
    else{
        printf("[");
        Address p1 = FIRST(l);
        printf("%d", INFO(p1));
        p1 = NEXT(p1);
        while ( p1!=NULL ){
            printf(",%d", INFO(p1));
            p1 = NEXT(p1);
        }
        printf("]");
    }
}
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int len = 0;
    if ( !isEmpty(l) ){
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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean fSearch(List L, Address P){
    boolean found = false;
    if ( isEmpty(L) ){
        found = false;
    }
    else {
        Address pt = FIRST(L);
        found = false;
        while( !found && pt!=NULL ){
            if (pt==P){
                found = true;
            }
            else{
                pt = NEXT(pt);
            }
        }
    }
    return found;
}
/* Mencari apakah ada elemen list yang beralamat P */
/* Mengirimkan true jika ada, false jika tidak ada */
Address searchPrec(List L, ElType X){
    Address p,p1,p2;
    if ( isEmpty(L) ){
        p = NULL;
    }
    else{       // Minimal 1 elemen
        boolean found = false;
        p = NULL;
        p1 = FIRST(L);
        p2 = NEXT(p1);
        if ( INFO(p1)==X ){
            found = true;
            p = NULL;
        }
        while ( !found && p2!=NULL ){
            if ( INFO(p2)==X ){
                found = true;
                p = p1;
            }
            else{
                p1 = NEXT(p1);
                p2 = NEXT(p2);
            }
        }
    }
    return p;
}
/* Mengirimkan address elemen sebelum elemen yang nilainya=X */
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address Prec, dengan Next(Prec)=P dan Info(P)=X. */
/* Jika tidak ada, mengirimkan Nil */
/* Jika P adalah elemen pertama, maka Prec=Nil */
/* Search dengan spesifikasi seperti ini menghindari */
/* traversal ulang jika setelah Search akan dilakukan operasi lain */

/*** Prekondisi untuk Max/Min/rata-rata : List tidak kosong ***/
ElType max(List l){
    Address p = FIRST(l);
    ElType max = INFO(p);
    p = NEXT(p);
    while ( p != NULL ){
        if ( INFO(p) > max){
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return max;
}
/* Mengirimkan nilai info(P) yang maksimum */
Address adrMax(List l){
    Address p = FIRST(l);
    Address pmax = p;
    ElType max = INFO(p);
    p = NEXT(p);
    while ( p != NULL ){
        if ( INFO(p) > max){
            pmax = p;
            max = INFO(p);
        }
        p = NEXT(p);
    }
    return pmax;
}
/* Mengirimkan address P, dengan info(P) yang bernilai maksimum */
ElType min(List l){
    Address p = FIRST(l);
    ElType min = INFO(p);
    p = NEXT(p);
    while ( p != NULL ){
        if ( INFO(p) < min){
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return min;
}
/* Mengirimkan nilai info(P) yang minimum */
Address adrMin(List l){
    Address p = FIRST(l);
    Address pmin = p;
    ElType min = INFO(p);
    p = NEXT(p);
    while ( p != NULL ){
        if ( INFO(p) < min){
            pmin = p;
            min = INFO(p);
        }
        p = NEXT(p);
    }
    return pmin;
}
/* Mengirimkan address P, dengan info(P) yang bernilai minimum */
float average(List l){
    ElType sum = 0;
    Address p = FIRST(l);
    sum += INFO(p);
    p = NEXT(p);
    while ( p != NULL ){
        sum += INFO(p);
        p = NEXT(p);
    }
    float mean = sum*1.0/length(l);
    return mean;
}
/* Mengirimkan nilai rata-rata info(P) */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
    List l3;
    CreateList(&l3);
    // Iterate l1 dulu
    Address p = FIRST(l1);
    if ( p!=NULL ){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    while ( p!=NULL ){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }   // Terminate saat diujung l1
    // Iterate l2, lanjut
    p = FIRST(l2);
    if ( p!=NULL ){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }
    while ( p!=NULL ){
        insertLast(&l3, INFO(p));
        p = NEXT(p);
    }   // Terminate saat diujung l2, langsung tertutup dengan nil
    return l3;
}
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */

void delAll(List *l){
    if ( !isEmpty(*l) ){
        Address p1,p2;
        p1 = FIRST(*l);
        p2 = NEXT(p1);
        FIRST(*l) = NULL;
        free(p1);
        while ( p2 != NULL ){
            p1 = p2;
            p2 = NEXT(p2);
            free(p1);
        }
    }
}
/* Delete semua elemen list dan alamat elemen di-dealokasi */

void inverseList(List *l){
    if ( length(*l)>=2 ){
        Address p1,p2,p3;
        if ( length(*l)==2 ){
            p1 = FIRST(*l);
            p2 = NEXT(p1);
            FIRST(*l) = p2;
            NEXT(p1) = NULL;
            NEXT(p2) = p1;
        }
        else{
            p1 = FIRST(*l);
            p2 = NEXT(p1);
            p3 = NEXT(p2);
            NEXT(p1) = NULL;
            // Mulai Looping pertama
            NEXT(p2) = p1;      // .
            p1 = p2;            // .
            p2 = p3;            // .
            p3 = NEXT(p3);      // .
            // NEXT(p2) = p1;   REDUNDANT
            while ( p3 != NULL ){
                NEXT(p2) = p1;
                p1 = p2;
                p2 = p3;
                p3 = NEXT(p3);
            }
            NEXT(p2) = p1;      // Karena REDUNDAN ga jadi,.... harus dikasi catch di akhir
            FIRST(*l) = p2;
        }
    }
}
/* I.S. sembarang. */
/* F.S. elemen list dibalik : */
/* Elemen terakhir menjadi elemen pertama, dan seterusnya. */
/* Membalik elemen list, tanpa melakukan alokasi/dealokasi. */

List fInverseList(List l){
    List l2;
    CreateList(&l2);
    if ( !isEmpty(l) ){
        boolean fail = false;
        // Coba elemen pertama dulu
        Address p = FIRST(l);
        int old = length(l2);
        insertFirst(&l2, INFO(p));
        if ( length(l2) == old ){
            fail = true;
        }
        else{
            old = length(l2);
            p = NEXT(p);
        }
        // Mulai dari elemen ke-2 kalo ada
        while ( !fail && p!=NULL ){
            insertFirst(&l2, INFO(p));
            if ( length(l2) == old ){
                fail = true;
                delAll(&l2);
            }
            else{
                old = length(l2);
                p = NEXT(p);
            }
        }
    }
    return l2;
}
/* Mengirimkan list baru, hasil invers dari L */
/* dengan menyalin semua elemn list. Alokasi mungkin gagal. */
/* Jika alokasi gagal, hasilnya list kosong */
/* dan semua elemen yang terlanjur di-alokasi, harus didealokasi */

void copyList(List *l1, List *l2){
    FIRST(*l2) = FIRST(*l1);
}
/* I.S. L1 sembarang. F.S. L2=L1 */
/* L1 dan L2 "menunjuk" kepada list yang sama.*/
/* Tidak ada alokasi/dealokasi elemen */

List fCopyList(List l){
    List l2;
    CreateList(&l2);
    if ( !isEmpty(l) ){
        boolean fail = false;
        // Coba elemen pertama dulu
        Address p = FIRST(l);
        int old = length(l2);
        insertLast(&l2, INFO(p));
        if ( length(l2) == old ){
            fail = true;
        }
        else{
            old = length(l2);
            p = NEXT(p);
        }
        // Mulai dari elemen ke-2 kalo ada
        while ( !fail && p!=NULL ){
            insertLast(&l2, INFO(p));
            if ( length(l2) == old ){
                fail = true;
                delAll(&l2);
            }
            else{
                old = length(l2);
                p = NEXT(p);
            }
        }
    }
    return l2;
}
/* Mengirimkan list yang merupakan salinan L */
/* dengan melakukan alokasi. */
/* Jika ada alokasi gagal, hasilnya list kosong dan */
/* semua elemen yang terlanjur di-alokasi, harus didealokasi */

void cpAllocList(List lIn, List *lOut){
    CreateList(lOut);
    if ( !isEmpty(lIn) ){
        boolean fail = false;
        // Coba elemen pertama dulu
        Address p = FIRST(lIn);
        int old = length(*lOut);
        insertLast(lOut, INFO(p));
        if ( length(*lOut) == old ){
            fail = true;
        }
        else{
            old = length(*lOut);
            p = NEXT(p);
        }
        // Mulai dari elemen ke-2 kalo ada
        while ( !fail && p!=NULL ){
            insertLast(lOut, INFO(p));
            if ( length(*lOut) == old ){
                fail = true;
                delAll(lOut);
            }
            else{
                old = length(*lOut);
                p = NEXT(p);
            }
        }
    }
}
/* I.S. lIn sembarang. */
/* F.S. Jika semua alokasi berhasil,maka lOut berisi hasil copy lIn */
/* Jika ada alokasi yang gagal, maka lOut=Nil dan semua elemen yang terlanjur dialokasi, didealokasi */
/* dengan melakukan alokasi elemen. */
/* lOut adalah list kosong jika ada alokasi elemen yang gagal */

void splitList(List *l1, List *l2, List l){
    CreateList(l1);
    CreateList(l2);
    if ( isEmpty(l) ){  // Jika kosong ya dua"nya kosong
        FIRST(*l1) = NULL;
        FIRST(*l2) = NULL;
    }
    else{
        int i, temp;
        int n = length(l);
        int n1 = n / 2;
        int n2 = n - n1;
        Address p = FIRST(l);
        for( i = 0 ; i < n1 ; i++){
            temp = getElmt(l, i);
            insertLast(l1, temp);
            p = NEXT(p);
        }
        for( i = n1 ; i < n ; i++){
            temp = getElmt(l, i);
            insertLast(l2, temp);
            p = NEXT(p);
        }
    }
}
/* I.S. l mungkin kosong */
/* F.S. Berdasarkan L, dibentuk dua buah list l1 dan l2 */
/* L tidak berubah: untuk membentuk l1 dan l2 harus alokasi */
/* l1 berisi separuh elemen L dan l2 berisi sisa elemen L */
/* Jika elemen L ganjil, maka separuh adalah length(L) div 2 */