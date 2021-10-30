
#include <stdio.h>
#include "queue.h"
#include "boolean.h"

Item makeItem (int tMasuk, char pickup_location, char dropoff_location, char type, int dur) {
    Item x;
    TMASUK(x) = tMasuk;
    PICKUP(x) = pickup_location;
    DROPOFF(x) = dropoff_location;
    TYPE(x) = type;
    DURATION(x) = dur;
    return x;
}

Item copyItem(Item ITEM) {
    Item x;
    TMASUK(x) = TMASUK(ITEM);
    PICKUP(x) = PICKUP(ITEM);
    DROPOFF(x) = DROPOFF(ITEM);
    TYPE(x) = TYPE(ITEM);
    DURATION(x) = DURATION(ITEM);
    return x;
}

void displayItem(Item ITEM) {
    printf("Waktu pesanan masuk : %d\n", TMASUK(ITEM));
    printf("Lokasi pick-up : %c\n", PICKUP(ITEM));
    printf("Lokasi drop-off : %c\n", DROPOFF(ITEM));
    printf("Jenis item : ");
    if (TYPE(ITEM) == 'P') {
        printf("Perishable\n");
        printf("Duration : %d\n", DURATION(ITEM));
    } else if (TYPE(ITEM) == 'N') {
        printf("Normal\n");
    } else if (TYPE(ITEM) == 'H') {
        printf("Heavy\n");
    } else if (TYPE(ITEM) == 'V') {
        printf("VIP\n");
    }
}

/* *** Kreator *** */
void CreateQueue(Queue *q) {
    /* I.S. sembarang */
    /* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
    /* - Index head bernilai IDX_UNDEF */
    /* - Index tail bernilai IDX_UNDEF */
    /* Proses : Melakukan alokasi, membuat sebuah q kosong */

    /* ALGORITMA */
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q) {
    /* Mengirim true jika q kosong: lihat definisi di atas */
    
    /* ALGORITMA */
    return (IDX_HEAD(q) > IDX_TAIL(q) || (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF));
}

boolean isFull(Queue q) {
    /* Mengirim true jika tabel penampung elemen q sudah penuh */
    /* yaitu jika index head bernilai 0 dan index tail bernilai 100-1 */

    /* ALGORITMA */
    return (IDX_HEAD(q) == 0 && IDX_TAIL(q) == 100-1);
}

int length(Queue q) {
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

    /* ALGORITMA */
    if (isEmpty(q)) {
        return 0;
    } else {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Item ITEM) {
    /* Proses: Menambahkan val pada q dengan aturan FIFO */
    /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
    /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
            Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
            menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    
    /* ALGORITMA */
    if (isEmpty(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        (*q).buffer[0] = ITEM;
    } else {
        int i;
        if (IDX_TAIL(*q) == 99) {
            i = 0;
            int head = IDX_HEAD(*q);
            while (i <= 99-head) {
                (*q).buffer[i] = (*q).buffer[i+head];
                i++;
            }
            IDX_HEAD(*q) = 0;
            IDX_TAIL(*q) -= head;
        }
        i = 0;
        int tail = IDX_TAIL(*q);
        while (i <= tail && TMASUK(ITEM) >= TMASUK((*q).buffer[i])) {
            i++;
        }
        while (tail >= i) {
            (*q).buffer[tail+1] = (*q).buffer[tail];
            tail--;
        }
        (*q).buffer[i] = ITEM;
        IDX_TAIL(*q) ++;
    }
}

void dequeue(Queue *q, Item *ITEM) {
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. q tidak mungkin kosong */
    /* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
            q mungkin kosong */

    /* ALGORITMA */
    *ITEM = HEAD(*q);
    IDX_HEAD(*q)++;
}

/* *** Display Queue *** */
void displayQueue(Queue q) {
    /* Proses : Menuliskan isi Queue dengan traversal, Queue ditulis di antara kurung 
    siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
    karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
    /* I.S. q boleh kosong */
    /* F.S. Jika q tidak kosong: [e1,e2,...,en] */
    /* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
    /* Jika Queue kosong : menulis [] */

    /* ALGORITMA */
    if (isEmpty(q)) {
        printf("Tidak Ada Pesanan");
    } else {
        int i = IDX_HEAD(q);
        printf("List Pesanan\n\n");
        while (i <= IDX_TAIL(q)) {
            displayItem(q.buffer[i]);
            printf("\n");
            i++;
        }
    }
}