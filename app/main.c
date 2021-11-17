#include <stdio.h>
#include <stdlib.h>
#include "readfile.c"
#include "move.c"
#include "map.c"
#include "to_do.c"
#include "inprogress.c"
#include "drop_pick.c"
#include "buy.c"
#include "inventory.c"
#include "help.c"

static FILE * tape;
// path: ../config/config.txt
Matrix adjacency;
Map MAP;
ListDin Bangunan;
LOCATION HQ;
Queue QueueOrder;
ListLinked inProgress;
Player p;
Stack bag;
ListPos next;
ListGadget l;

#define endl printf("\n")

boolean finish(Player p, Queue Q, Stack bag){
  boolean fin = false;
  if( isListLinkedEmpty(PDRAF(p)) && isEmptyQueue(Q) && isEmptyStack(bag) && NAME(PCurLocation(p))=='8' ){
    fin = true;
  }
  return fin;
}

void endGame(){
  printf("==========================================   TAMAT   ==========================================");endl;endl;
  printf("SELAMAT Player..!! KAMU telah MENYELAMATKAN bisnis Mobita dari KEHANCURAN..!!!!");endl;
  printf("KAMU telah mengantarkan semua PESANAN KEMATIAN ke pada tempat SEHARUSNYA");endl;
  printf("Oleh karena itu kamu akan dihadiahi dengan NILAI INDEKS SSR++ setelah ini...!!!");endl;
  printf("MARVELOUSSSS, HAMPURA, MORTE VORTE...!!!");endl;endl;
}

void mulai(){
  // Player p;
  // Stack bag;
  // ListPos next;
  // ListGadget l;
  // CreateListGadget(&l);
  // CreateStack(&bag);
  // createPlayer(&p,Bangunan);
  // PMoney(p) = 20000;
  // PTime(p) = 14;
  // POINT titik = MakePOINT(8,2);
  // LOCATION cheat = makeLocation('M',titik);
  // PCurLocation(p) = cheat;
  
  boolean endmulai = false;
  int command;
  tape = stdin;
  printf("Permainan Dimulai!\n");
  endl;
  while(!endmulai){
    // Cek QueueOrder, masukkan ke drafPick
    fillDrafToDO(&p);
    if( isListLinkedEmpty(PDRAF(p)) && isEmptyQueue(QueueOrder) && isEmptyStack(bag) && NAME(PCurLocation(p))=='8' ){
    endmulai = true;
    }
    if (!endmulai){
      printf("=============================== COMMAND ==================================");
      endl;
      displayTime(p);endl;
      displayMoney(p);endl;
      displayCurLoc(p);endl;
      endl;
      printf("1. MOVE\n");
      printf("2. PICK_UP\n");
      printf("3. DROP_OFF\n");
      printf("4. MAP\n");
      printf("5. TO_DO\n");
      printf("6. IN_PROGRESS\n");
      printf("7. BUY\n");
      printf("8. INVENTORY\n");
      printf("9. SAVE GAME\n");
      printf("10. HELP\n");
      printf("11. HESOYAM (Cheat)\n");
      printf("99. Main Menu\n");
      printf("ENTER COMMAND:");
      // scanf("%d",&command);
      startLine(tape);
      command = StrToInt(currentWord);

      while((command!=1) && (command!=2 )&& (command!=3)&& (command!=4)&& (command!=5)&& (command!=6)&& (command!=7)&& (command!=8)&& (command!=9)&&(command!=10)&& (command!=11)&& (command!=99)){
        printf("Tolong Masukkan Pilihan yang Sesuai!\n");endl;
        printf("1. MOVE\n");
        printf("2. PICK_UP\n");
        printf("3. DROP_OFF\n");
        printf("4. MAP\n");
        printf("5. TO_DO\n");
        printf("6. IN_PROGRESS\n");
        printf("7. BUY\n");
        printf("8. INVENTORY\n");
        printf("9. SAVE GAME\n");
        printf("10. HELP\n");
        printf("11. HESOYAM (Cheat)\n");
        printf("99. Main Menu\n");
        printf("ENTER COMMAND:");
        startLine(tape);
        command = StrToInt(currentWord);
      }

      if(command == 1){
        printf("================================= MOVE ===================================");
        endl;
        move(&p,adjacency,&bag);
        fillDrafToDO(&p);
      }else if(command == 2){
        printf("=============================== PICK UP ==================================");
        endl;
        pickItem(&p,&bag);
        inProgress = copyBag(bag);
      }else if(command == 3){
        printf("=============================== DROP OFF =================================");
        endl;
        dropItem(&p,&bag);
        inProgress = copyBag(bag);
      }else if(command ==4){
        printf("================================== MAP ===================================");
        endl;
        map(MAP,adjacency,bag,p);
      }else if(command == 5){
        printf("================================= TO DO ==================================");
        endl;
        to_do(&p);
      }else if(command == 6){
        printf("============================== IN PROGRESS ===============================");
        endl;
        in_progress(bag);
      }else if(command == 7){
        printf("================================== BUY ===================================");
        endl;
        buyGadget(&p,&l);
      }else if(command == 8){
        printf("============================== INVENTORY =================================");
        endl;
        useInventory(&p,&l,&bag);
      }else if(command == 9){
        printf("============================== SAVE GAME =================================");
        endl;
        saveFile(p, bag);
      }else if(command == 10) {
        printf("================================= HELP ===================================");
        endl;
        help();
      }
      else if(command == 11){
        PMoney(p)+=10000;
        PCurLocation(p) = HQ;
      }
      else if(command == 99){
        break;
      }
      endmulai = finish(p,QueueOrder,bag);
    } // End of IF checking

  } // End of while MUlAI

  endGame();

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
      CreateListGadget(&l);
      CreateStack(&bag);
      createPlayer(&p,Bangunan);
      PMoney(p) = 100000;
      PTime(p) = 50;
      mulai();
      endl;
    }else if(pilihanMain ==3){
      printf("Terimakasih Sudah Bermain!");
      return 0;
    }else if(pilihanMain == 2){
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
      mulai();
    }
  }

  fclose(tape);
  return 0;
}