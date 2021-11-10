#include <stdio.h>
#include <stdlib.h>
#include "../lib/boolean.h"
#include "readfile.c"

static FILE * tape;

Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;

void mulai(){
  boolean endmulai = false;
  int command;
  while(!endmulai){
    printf("Permainan Dimulai!\n");
    endl;
    printf("1. MOVE\n");
    printf("2. PICK_UP\n");
    printf("3. DROP_OFF\n");
    printf("4. MAP\n");
    printf("5. TO_DO\n");
    printf("6. IN_PROGRESS\n");
    printf("7. BUY\n");
    printf("8. INVENTORY\n");
    printf("9. HELP\n");
    printf("ENTER COMMAND:");
    scanf("%d",&command);
    

    while((command!=1) && (command!=2 )&& (command!=3)&& (command!=4)&& (command!=5)&& (command!=6)&& (command!=7)&& (command!=8)&& (command!=9)){
    printf("Tolong Masukkan Pilihan yang Sesuai!\n");
    printf("1. MOVE\n");
    printf("2. PICK_UP\n");
    printf("3. DROP_OFF\n");
    printf("4. MAP\n");
    printf("5. TO_DO\n");
    printf("6. IN_PROGRESS\n");
    printf("7. BUY\n");
    printf("8. INVENTORY\n");
    printf("9. HELP\n");
    printf("ENTER COMMAND:");
    scanf("%d",&command);
    }

    if(command == 1){
      //move
    }else if(command == 2){
      // pick_up
    }else if(command == 3){
      // drop_off
    }else if(command ==4){
      // map
    }else if(command == 5){
      // to-do
    }else if(command == 6){
      // in_progress
    }else if(command == 7){
      // buy
    }else if(command == 8){
      // inventory
    }else if(command == 9){
      // help
    }
  }
}

int main(){
  boolean end = false;
  int pilihanMain;
  char fileName[30];
  while(!end){
    printf("Welcome to Kurir Mobita!\n");
    endl;
    printf("Masukkan Pilihan Anda:\n");
    printf("1. NEW GAME\n");
    printf("2. LOAD GAME\n");
    printf("3. EXIT\n");
    endl;
    printf("Input (angka) : ");
    tape = stdin;
    startLine(tape);
    pilihanMain = StrToInt(currentWord);
    while((pilihanMain!=1) && (pilihanMain!=2 )&& (pilihanMain!=3)){
      printf("Tolong Masukkan Pilihan yang Sesuai!\n");
      printf("1. NEW GAME\n");
      printf("2. LOAD GAME\n");
      printf("3. EXIT\n");
      endl;
      printf("Input (angka) : ");
      startLine(tape);
      pilihanMain = StrToInt(currentWord);
    }

    if(pilihanMain == 1){
      endl;
      printf("=============================== NEW GAME =================================");
      endl;
      printf("Input konfigurasi game (path) : ");;
      startLine(tape);
      readFile(currentWord.contents);
      displayMap(MAP);
      endl;
      // gatau cara cek nama filenya bener atau ga
    }else if(pilihanMain ==3){
      printf("Terimakasih Sudah Bermain!");
      return 0;
    }else{
      endl;
      printf("=============================== LOAD GAME =================================");
      endl;
      printf("Input konfigurasi game (path) :");
      startLine(tape);
      endl;
      printf("%s", currentWord.contents);
      printf("Input data saved (path) : ");
      startLine(tape);
      printf("%s", currentWord.contents);
      // gatau cara cek nama filenya bener atau ga
    }

  }

  fclose(tape);
  return 0;
}