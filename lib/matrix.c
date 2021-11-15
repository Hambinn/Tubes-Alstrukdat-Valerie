#include <stdio.h>
#include <math.h>
#include "matrix.h"


/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk Matrix *** */

void CreateMap(int nRow, int nCol, Map *m) {
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
    int i, j;
    for (i = 0; i < nRow; i++) {
        for (j = 0; j < nCol; j++) {
            ELMT(*m, i, j) = ' ';
        }
    }
}

void displayMap(Map m,LOCATION curLoc,ListPos nextPlace) {
    int i, j;
    char name;
    for(i=-1; i<ROWS(m)+1; i++){
        for(j=-1; j<COLS(m)+1; j++){
            if(i==-1 || i==ROWS(m) || j==-1 || j==COLS(m)){
                printf("#");
            }
            else{
                name = ELMT(m, i, j);
                // char drop = DROP_PLACE(TOP(bag));
                char pick = 'a';
                if ( name == NAME(curLoc) ){
                    print_yellow(name);
                }
                else if (isIn(nextPlace,name)){
                    print_green(name);
                }
                // else if ( name == drop ){
                //     print_blue(name);
                // }
                else if ( name == pick ){

                }
                else{
                    printf("%c",name);
                }
            }
        }
        if(i != ROWS(m)){
            printf("\n");
        }
    }
}

void CreateMatrix(int nRow, int nCol, Matrix *m){
    ROWS(*m) = nRow;
    COLS(*m) = nCol;
}
/* Membentuk sebuah Matrix "kosong" yang siap diisi berukuran nRow x nCol di "ujung kiri" memori */
/* I.S. nRow dan nCol adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks m sesuai dengan definisi di atas terbentuk */


/* *** Selektor "DUNIA Matrix" *** */
boolean isIdxValid(int i, int j){
    return ( 0<=i && i<ROW_CAP ) && ( 0<=j && j<COL_CAP );
}
/* Mengirimkan true jika i, j adalah Index yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks m yang terdefinisi: *** */

Index getLastIdxRow(Matrix m){
    return (ROWS(m)-1);
}
/* Mengirimkan Index baris terbesar m */

Index getLastIdxCol(Matrix m){
    return (COLS(m)-1);
}
/* Mengirimkan Index kolom terbesar m */

boolean isIdxEff(Matrix m, Index i, Index j){
    return ( 0<=i && i<ROWS(m) ) && ( 0<=j && j<COLS(m) );
}
/* Mengirimkan true jika i, j adalah Index efektif bagi m */

int getElmtDiagonal(Matrix m, Index i){
    return ELMT(m, i, i);
}
/* Mengirimkan elemen m(i,i) */


/* ********** Assignment  Matrix ********** */
void copyMatrix(Matrix mIn, Matrix *mRes){
    CreateMatrix(ROWS(mIn), COLS(mIn), mRes);
    ROWS(*mRes) = ROWS(mIn);
    COLS(*mRes) = COLS(mIn);
    int i, j;
    for(i=0; i<ROWS(mIn); i++){
        for(j=0; j<COLS(mIn); j++){
            ELMT(*mRes, i, j) = ELMT(mIn, i, j);
        }
    }
}
/* Melakukan assignment MRes = MIn */


/* ********** KELOMPOK BACA/TULIS ********** */
void readMatrix(Matrix *m, int nRow, int nCol){
    CreateMatrix(nRow, nCol, m);
    int i, j;
    for(i=0; i<nRow; i++){
        for(j=0; j<nCol; j++){
            if(j == nCol-1){
                scanf("%d", &ELMT(*m, i, j));
            }
            else{
                scanf("%d \t", &ELMT(*m, i, j));
            }
        }
    }
}
/* I.S. isIdxValid(nRow,nCol) */
/* F.S. m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol */
/* Proses: Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika nRow = 3 dan nCol = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/

void displayMatrix(Matrix m){
    int i, j;
    for(i=0; i<ROWS(m); i++){
        for(j=0; j<COLS(m); j++){
            printf("%d", ELMT(m, i, j));
            if(j != COLS(m)-1){
                printf(" ");
            }
        }
        if(i != ROWS(m)-1){
            printf("\n");
        }
    }
}
/* I.S. m terdefinisi */
/* F.S. Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom */
/* Contoh: Menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/


/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */
Matrix addMatrix(Matrix m1, Matrix m2){
    Matrix m;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    int i, j;
    for(i=0; i<ROWS(m); i++){
        for(j=0; j<COLS(m); j++){
            ELMT(m, i, j) = ELMT(m1, i, j) + ELMT(m2, i, j);
        }
    }
    return m;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil penjumlahan matriks: m1 + m2 */

Matrix subtractMatrix(Matrix m1, Matrix m2){
    Matrix m;
    CreateMatrix(ROWS(m1), COLS(m1), &m);
    int i, j;
    for(i=0; i<ROWS(m); i++){
        for(j=0; j<COLS(m); j++){
            ELMT(m, i, j) = ELMT(m1, i, j) - ELMT(m2, i, j);
        }
    }
    return m;
}
/* Prekondisi : m1 berukuran sama dengan m2 */
/* Mengirim hasil pengurangan matriks: salinan m1 – m2 */

Matrix multiplyMatrix(Matrix m1, Matrix m2){
    Matrix m;
    CreateMatrix(ROWS(m1), COLS(m2), &m);
    // Fill with default (0) for all element
    int i, j, k;
    for(i=0; i<ROWS(m); i++){
        for(j=0; j<COLS(m); j++){
            ELMT(m, i, j) = 0;
        }
    }

    // iterate through rows of m1
    for(i=0; i<ROWS(m); i++){
        // iterate through columns of m2
        for(j=0; j<COLS(m); j++){
            // iterate through rows of m2
            for(k=0; k<ROWS(m2); k++){
                ELMT(m, i, j) += ELMT(m1, i, k) * ELMT(m2, k, j);
            }
        }
    }
    return m;
}
/* Prekondisi : Ukuran kolom efektif m1 = ukuran baris efektif m2 */
/* Mengirim hasil perkalian matriks: salinan m1 * m2 */

Matrix multiplyConst(Matrix m, int x){
    Matrix mNew;
    CreateMatrix(ROWS(m), COLS(m), &mNew);
    int i, j;
    for(i=0; i<ROWS(mNew); i++){
        for(j=0; j<COLS(mNew); j++){
            ELMT(mNew, i, j) = x*ELMT(m, i, j);
        }
    }
    return mNew;
}
/* Mengirim hasil perkalian setiap elemen m dengan x */

void pMultiplyConst(Matrix *m, int k){
    int i, j;
    for(i=0; i<ROWS(*m); i++){
        for(j=0; j<COLS(*m); j++){
            ELMT(*m, i, j)*=k;
        }
    }
}
/* I.S. m terdefinisi, k terdefinisi */
/* F.S. Mengalikan setiap elemen m dengan k */


/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP Matrix ********** */
boolean isEqual(Matrix m1, Matrix m2){
    boolean sign = false;
    if( isSizeEqual(m1, m2) ){
        sign = true;
        Index i=0;
        while( i<ROWS(m1) && sign ){
            Index j=0;
            while( j<COLS(m1) && sign ){
                if(ELMT(m1, i, j) != ELMT(m2, i, j)){
                    sign=false;
                }
                else{
                    j++;
                }
            }
            i++;
        }
    }
    return sign;
}
/* Mengirimkan true jika m1 = m2, yaitu count(m1) = count(m2) dan */
/* untuk setiap i,j yang merupakan Index baris dan kolom m1(i,j) = m2(i,j) */
/* Juga merupakan strong eq karena getLastIdxCol(m1) = getLastIdxCol(m2) */

boolean isNotEqual(Matrix m1, Matrix m2){
    return ( !(isEqual(m1, m2)) );
}
/* Mengirimkan true jika m1 tidak sama dengan m2 */

boolean isSizeEqual(Matrix m1, Matrix m2){
    return ( (ROWS(m1) == ROWS(m2)) && (COLS(m1) == COLS(m2)) );
}
/* Mengirimkan true jika ukuran efektif matriks m1 sama dengan ukuran efektif m2 */


/* ********** Operasi lain ********** */
int count(Matrix m){
    return ( ROWS(m)*COLS(m) );
}
/* Mengirimkan banyaknya elemen m */


/* ********** KELOMPOK TEST TERHADAP Matrix ********** */
boolean isSquare(Matrix m){
    return ( ROWS(m) == COLS(m) );
}
/* Mengirimkan true jika m adalah matriks dg ukuran baris dan kolom sama */

boolean isSymmetric(Matrix m){
    boolean sign = false;
    if(isSquare(m)){
        sign = true;
        Index i=0;
        while( i<ROWS(m) && sign ){
            Index j=0;
            while( j<COLS(m) && sign ){
                if(ELMT(m, i, j) != ELMT(m, j, i)){
                    sign=false;
                }
                else{
                    j++;
                }
            }
            i++;
        }
    }
    return sign;
}
/* Mengirimkan true jika m adalah matriks simetri : isSquare(m) 
   dan untuk setiap elemen m, m(i,j)=m(j,i) */
   
boolean isIdentity(Matrix m){
    boolean sign = true;
    if( isSquare(m)){
        Index i=0;
        while( i<ROWS(m) && sign ){
            Index j=0;
            while( j<COLS(m) && sign ){
                if( i==j ){
                    if(ELMT(m, i, j) != 1){
                        sign = false;
                    }
                }
                else{
                    if(ELMT(m, i, j) != 0){
                    sign = false;
                    }
                }
                j++;
            }
            i++;
        }
    }
    else{sign=false;}
    return sign;
}
/* Mengirimkan true jika m adalah matriks satuan: isSquare(m) dan 
   setiap elemen diagonal m bernilai 1 dan elemen yang bukan diagonal bernilai 0 */

boolean isSparse(Matrix m){
    float max = count(m)*0.05;
    int countX = 0;
    int i, j;
    for(i=0; i<ROWS(m); i++){
        for(j=0; j<COLS(m); j++){
            if(ELMT(m, i, j) != 0){
                countX++;
            }
        }
    }
    return (countX <= max);
}
/* Mengirimkan true jika m adalah matriks sparse: matriks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */

Matrix inverse1(Matrix m){
    return multiplyConst(m,-1);
}
/* Menghasilkan salinan m dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */

void pInverse1(Matrix *m){
    pMultiplyConst(m,-1);
}
/* I.S. m terdefinisi */
/* F.S. m di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */

// float determinant(Matrix m){
    
//     // Section 1: Establish n parameter and copy A
//     int n = ROWS(m);
//     float mF[ROWS(m)][COLS(m)];
//     for(int a=0; a<ROWS(m); a++){
//         for(int b=0; b<COLS(m); b++){
//             mF[a][b] = ELMT(m, a, b)*1.0;
//         }
//     }

//     // Section 2: Row ops on A to get in upper triangle form
//     for(int ldOne=0; ldOne<n; ldOne++){
//         for(int i=ldOne+1; i<n; i++){
//             // Jika element diagonal bukan leading one
//             if(ELMT(m, ldOne, ldOne)==0){
//                 mF[ldOne][ldOne] = 1.0e-18;
//             }
//             // Jadikan 0 dibawah leading one
//             float crScaler = mF[i][ldOne] / mF[ldOne][ldOne];
//             for(int j=0; j<n; j++){
//                 mF[i][j] = mF[i][j] - crScaler*mF[ldOne][j] ;
//             }
//         }
//     }

//     // Section 3: Once AM is in upper triangle form ...
//     float product = 1.0;
//     for(int c=0; c<n; c++){
//         product*=mF[c][c];
//     }
//     if(product == -0.0){
//         product=0.0;
//     }
    
//    return (product);
// }
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m dengan cara reduksi baris menjadi
   matriks segitiga atas */

void transpose(Matrix *m){
    Matrix mCopy;
    copyMatrix(*m, &mCopy);
    int i, j;
    for(i=0; i<ROWS(mCopy); i++){
        for(j=0; j<COLS(mCopy); j++){
            ELMT(*m, i, j) = ELMT(mCopy, j, i);
        }
    }
}
/* I.S. m terdefinisi dan isSquare(m) */
/* F.S. m "di-transpose", yaitu setiap elemen m(i,j) ditukar nilainya dengan elemen m(j,i) */



/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
Matrix minorMatrix(Matrix m, int idx){
    Matrix mNew;
    ROWS(mNew) = ROWS(m)-1;
    COLS(mNew) = COLS(m)-1;
    int i, j;
    for(i=0; i<ROWS(mNew); i++){
        for(j=0; j<COLS(mNew); j++){
            if( i>=idx ){
                ELMT(mNew, i, j) = ELMT(m, i+1, j+1);
            }
            else{
                ELMT(mNew, i, j) = ELMT(m, i, j+1);
            }
        }
    }
    return mNew;
}
/* Prekondisi: Matrix m terdefinisi dengan COLS(m)>2 dan ROWS(m)>2 */
/* Memberikan minor matrix dari elemen-elemen kolom pertama
   *HANYA KOLOM PERTAMA* */

float determinant(Matrix m){
// int determinantCofactor(Matrix m){
    int product=0;
    if(ROWS(m)==2){
        product = ELMT(m, 0, 0)*ELMT(m, 1, 1) - ELMT(m, 0, 1)*ELMT(m, 1, 0);
    }
    else{
        int i;
        for(i=0; i<ROWS(m); i++){
            int sign = pow((-1), i);
            product += sign*ELMT(m, i, 0)*determinant(minorMatrix(m, i));
        }
    }
    return product*1.0;
}
/* Prekondisi: isSquare(m) */
/* Menghitung nilai determinan m dengan cara ekspansi kofaktor
   berdasarkan first column pada matriks m */