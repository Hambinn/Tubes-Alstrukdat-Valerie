
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

Item copyItem(Item item) {
    Item x;
    TMASUK(x) = TMASUK(item);
    PICKUP(x) = PICKUP(item);
    DROPOFF(x) = DROPOFF(item);
    TYPE(x) = TYPE(item);
    DURATION(x) = DURATION(item);
    return x;
}

void displayItem(Item item) {
    printf("%c ", PICKUP(item));
    printf("-> %c ", DROPOFF(item));
    if (TYPE(item) == 'P') {
        printf("(Perishable Item, ");
        printf("sisa waktu %d)\n", DURATION(item));
    } else if (TYPE(item) == 'N') {
        printf("(Normal Item)\n");
    } else if (TYPE(item) == 'H') {
        printf("(Heavy Item)\n");
    } else if (TYPE(item) == 'V') {
        printf("(VIP Item)\n");
    }
}

boolean isSame (Item item1, Item item2) {
    return (TMASUK(item1) == TMASUK(item2) && PICKUP(item1) == PICKUP(item2) && DROPOFF(item1) == DROPOFF(item2) && TYPE(item1) == TYPE(item2) && DURATION(item1) == DURATION(item2));
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
boolean isEmptyQueue(Queue q) {
    /* Mengirim true jika q kosong: lihat definisi di atas */
    
    /* ALGORITMA */
    return (IDX_HEAD(q) > IDX_TAIL(q) || (IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF));
}

boolean isFullQueue(Queue q) {
    /* Mengirim true jika tabel penampung elemen q sudah penuh */
    /* yaitu jika index head bernilai 0 dan index tail bernilai 100-1 */

    /* ALGORITMA */
    return (IDX_HEAD(q) == 0 && IDX_TAIL(q) == 100-1);
}

int lengthQueue(Queue q) {
    /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

    /* ALGORITMA */
    if (isEmptyQueue(q)) {
        return 0;
    } else {
        return IDX_TAIL(q) - IDX_HEAD(q) + 1;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, Item item) {
    /* Proses: Menambahkan val pada q dengan aturan FIFO */
    /* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
    /* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur".
            Jika q penuh semu, maka perlu dilakukan aksi penggeseran "maju" elemen-elemen q
            menjadi rata kiri untuk membuat ruang kosong bagi TAIL baru  */
    
    /* ALGORITMA */
    if (isEmptyQueue(*q)) {
        IDX_HEAD(*q) = 0;
        IDX_TAIL(*q) = 0;
        (*q).buffer[0] = item;
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
        while (i <= tail && TMASUK(item) >= TMASUK((*q).buffer[i])) {
            i++;
        }
        while (tail >= i) {
            (*q).buffer[tail+1] = (*q).buffer[tail];
            tail--;
        }
        (*q).buffer[i] = item;
        IDX_TAIL(*q) ++;
    }
}

void dequeue(Queue *q, Item *item) {
    /* Proses: Menghapus val pada q dengan aturan FIFO */
    /* I.S. q tidak mungkin kosong */
    /* F.S. val = nilai elemen HEAD pd I.S., HEAD dan IDX_HEAD "mundur"; 
            q mungkin kosong */

    /* ALGORITMA */
    *item = HEAD(*q);
    if (IDX_HEAD(*q) == IDX_TAIL(*q)){
        IDX_HEAD(*q) = IDX_UNDEF;
        IDX_TAIL(*q) = IDX_UNDEF;
    }
    else{
        IDX_HEAD(*q)++;
    }
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
    if (isEmptyQueue(q)) {
        printf("Tidak Ada Pesanan\n");
    } else {
        int i = IDX_HEAD(q);
        int j = 1;
        if (HEAD(q).tMasuk > time) {
            printf("List Pesanan :\n\n");
            while (i <= IDX_TAIL(q)) {
                if (q.buffer[i].tMasuk <= time) {
                    if (q.buffer[i].type == 'P') {
                        if (q.buffer[i].tMasuk <= time && time < q.buffer[i].tMasuk + q.buffer[i].duration ) {
                            printf("%d. ", j);
                            j++;
                            displayItem(q.buffer[i]);
                            printf("\n");
                        }
                    } else {
                        printf("%d. ", j);
                        j++;
                        displayItem(q.buffer[i]);
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