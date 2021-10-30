/* Nama  : Roby Purnomo */
/* NIM   : 13520106 */
/* Kelas : 02 */

#include <stdio.h>
#include "boolean.h"
#include "charmachine.h"
#include "wordmachine.h"

char currentChar;
boolean endWord;
Word currentWord;

void ignoreBlank() {
/*  Mengabaikan satu atau beberapa BLANK
    I.S. :  currentChar sembarang 
    F.S. :  currentChar ≠ BLANK atau currentChar = MARK */

    /* Algoritma */
    while (currentChar == BLANK ) {
        adv();
    }
}

void startLine(FILE *file) {
/*  I.S. :  currentChar sembarang 
    F.S. :  endWord = true, dan currentChar = MARK; 
            atau endWord = false, currentWord adalah kata yang sudah diakuisisi,
            currentChar karakter pertama sesudah karakter terakhir kata */

    /* Algoritma */
    start(file);
    ignoreBlank();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        endWord = false;
        copyWord();
    }
    ignoreBlank();
}

void advWord() {
/*  I.S. :  currentChar adalah karakter pertama kata yang akan diakuisisi 
    F.S. :  currentWord adalah kata terakhir yang sudah diakuisisi, 
            currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
            Jika currentChar = MARK, endWord = true.		  
    Proses : Akuisisi kata menggunakan procedure copyWord */

    /* Algoritma */
    ignoreBlank();
    if (currentChar == MARK) {
        endWord = true;
    } else {
        copyWord();
    }
    ignoreBlank();
}

void copyWord() {
/*  Mengakuisisi kata, menyimpan dalam currentWord
    I.S. :  currentChar adalah karakter pertama dari kata
    F.S. :  currentWord berisi kata yang sudah diakuisisi; 
            currentChar = BLANK atau currentChar = MARK; 
            currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
            Jika panjang kata melebihi 50, maka sisa kata terpotong */

    /* Algoritma */
    int i = 0;
    do {
        currentWord.contents[i] = currentChar;
        adv();
        i++;
    } while (currentChar != MARK && currentChar != BLANK && i<50);
    currentWord.length = i;
}