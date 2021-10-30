#include <stdio.h>
#include "point.h"
#include <math.h>

POINT MakePOINT (int X, int Y) {
    /* Membentuk sebuah POINT dari komponen-komponennya */
    POINT P;
    Absis(P) = X;
    Ordinat(P) = Y;
    return P;
}

void TulisPOINT (POINT P) {
    /* I.S. P terdefinisi */
    /* F.S. P tertulis di layar dengan format "(X,Y)" */  
    printf("(%d,%d)", Absis(P), Ordinat(P));
}

boolean EQ (POINT P1, POINT P2) {
    /* Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama */
    return (((Absis(P1)) == (Absis(P2))) && ((Ordinat(P1)) == (Ordinat(P2))));
}

boolean NEQ (POINT P1, POINT P2) {
    /* Mengirimkan true jika P1 tidak sama dengan P2 */
    return (((Absis(P1)) != (Absis(P2))) || ((Ordinat(P1)) != (Ordinat(P2))));
}

boolean IsOrigin (POINT P) {
    /* Menghasilkan true jika P adalah titik origin */
    return ((Absis(P) == 0) && (Ordinat(P) == 0));
}

boolean IsOnSbX (POINT P) {
    /* Menghasilkan true jika P terletak Pada sumbu X */
    return ((Absis(P) != 0) && (Ordinat(P) == 0));
}

boolean IsOnSbY (POINT P) {
    /* Menghasilkan true jika P terletak pada sumbu Y */
    return ((Absis(P) == 0) && (Ordinat(P) != 0));
}

int Kuadran (POINT P) {
    /* Menghasilkan kuadran dari P: 1, 2, 3, atau 4 */
    if ((Absis(P) > 0) && (Ordinat(P) > 0)) {
        return 1;
    } else if ((Absis(P) < 0) && (Ordinat(P) > 0)) {
        return 2;
    } else if ((Absis(P) < 0) && (Ordinat(P) < 0)) {
        return 3;
    } else if ((Absis(P) > 0) && (Ordinat(P) < 0)) {
        return 4;
    }
}

POINT NextX (POINT P) {
    /* Mengirim salinan P dengan absis ditambah satu */ 
    Absis(P) += 1;
    return P;
}

POINT NextY (POINT P) {
    /* Mengirim salinan P dengan ordinat ditambah satu */
    Ordinat(P) += 1;
    return P;
}

POINT PlusDelta (POINT P, int deltaX, int deltaY) {
    /* Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY */
    Absis(P) += deltaX;
    Ordinat(P) += deltaY;
    return P;
}

POINT MirrorOf (POINT P, boolean SbX) {
    /* Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu */
    if (SbX == true) {
        Ordinat(P) = -(Ordinat(P));
    } else {
        Absis(P) = -(Absis(P));
    }
    return P;
}

float Jarak0 (POINT P) {
    /* Menghitung jarak P ke (0,0) */
    return sqrt((Absis(P)*Absis(P))+(Ordinat(P)*Ordinat(P)));
}

float Panjang (POINT P1, POINT P2) {
    /* Menghitung jarak antara P1 dan P2 */
    return sqrt(((Absis(P1))-(Absis(P2)))*((Absis(P1))-(Absis(P2)))+(((Ordinat(P1))-(Ordinat(P2)))*((Ordinat(P1))-(Ordinat(P2)))));
}

void Geser (POINT *P, int deltaX, int deltaY) {
    /* I.S. P terdefinisi */
    /* F.S. P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY */
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX (POINT *P) {
    /* I.S. P terdefinisi */
    /* F.S. P berada pada sumbu X dengan absis sama dengan absis semula. */ 
    Ordinat(*P) = 0;
}

void GeserKeSbY (POINT *P) {
    /* I.S. P terdefinisi*/
    /* F.S. P berada pada sumbu Y dengan ordinat yang sama dengan semula. */
    Absis(*P) = 0;
}

void Mirror (POINT *P, boolean SbX) {
    /* I.S. P terdefinisi */
    /* F.S. P dicerminkan tergantung nilai SbX atau SbY */
    if (SbX == true) {
        Ordinat(*P) = -(Ordinat(*P));
    } else {
        Absis(*P) = -(Absis(*P));
    }
}
