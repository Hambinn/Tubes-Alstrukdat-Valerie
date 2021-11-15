
#include <stdio.h>
#include "queue.h"

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

void displayItem(Item ITEM, float time) {
    printf("%c ", PICKUP(ITEM));
    printf("-> %c ", DROPOFF(ITEM));
    if (TYPE(ITEM) == 'P') {
        printf("(Perishable Item, ");
        printf("sisa waktu %d)\n", DURATION(ITEM) - ((int)time - TMASUK(ITEM)));
    } else if (TYPE(ITEM) == 'N') {
        printf("(Normal Item)\n");
    } else if (TYPE(ITEM) == 'H') {
        printf("(Heavy Item)\n");
    } else if (TYPE(ITEM) == 'V') {
        printf("(VIP Item)\n");
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
void displayQueue(Queue q, float time) {
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
        int j = 1;
        if (q.buffer[0].tMasuk <= time) {
            printf("List Pesanan :\n\n");
            while (i <= IDX_TAIL(q)) {
                if (q.buffer[i].tMasuk <= time) {
                    if (q.buffer[i].type == 'P') {
                        if (q.buffer[i].tMasuk <= time && time < q.buffer[i].tMasuk + q.buffer[i].duration ) {
                            printf("%d. ", j);
                            j++;
                            displayItem(q.buffer[i], time);
                            printf("\n");
                        }
                    } else {
                        printf("%d. ", j);
                        j++;
                        displayItem(q.buffer[i], time);
                        printf("\n");
                    }
                }
                i++;
            }
        } else {
            printf("Tidak Ada Pesanan");
        }
    }
}