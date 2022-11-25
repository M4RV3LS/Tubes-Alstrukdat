#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ADT/mesinkar2.h"
#include "ADT/mesinkata2.h"
#include "ADT/arrayOfString.h"
#include "boolean.h"
#include "ADT/queue.h"
#include "ADT/DinerDash/queuehybrid.h"
#include "ADT/DinerDash/mesinkar.h"
#include "ADT/DinerDash/mesinkata.h"
#include "ADT/SetMap/map.h"
#include "ADT/Stack/stack.h"
#include "scoreboard/scoreboard.h"
#include "history/history.h"
#include "ADT/towerofhanoi/towerofhanoi.h"
#include "ADT/snakeonmeteor/gameSOM.h"
#include "ADT/hangman/hangman.h"



void CREATEGAME(ArrayDin *ListGames , ArrayOfMap *GameMap);

void DELETE(ArrayDin *ListGames, Queue q1 , ArrayOfMap *GameMap);

void HELP();

void LISTGAME(ArrayDin *ListGames);

void LOADFILE(ArrayDin *ListGames , Stack *GameHistory , char* filename ,ArrayOfMap *GameMap);

void PLAYGAME(Queue *q1 , ArrayDin ListGames , ArrayOfMap *GameMap , Stack *GameHistory);

void QUEUEGAME(Queue *q1, ArrayDin game);

void QUIT(); 

void printRNG();

void printMathQuiz();

void gameRNG(char*game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)  ; 

void SAVEBNMO(ArrayDin *ListGames , Stack *GameHistory , char* filename ,ArrayOfMap *GameMap);

void SKIPGAME(Queue *q, int n , ArrayDin ListGames , ArrayOfMap *GameMap , Stack *GameHistory);

void STARTGAME(ArrayDin *ListGames);

int pertambahan(int skor);

int pengurangan(int skor);

int perkalian(int skor);

void mathquiz(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score);

void DisplayPesanan(QUEUEDD q);
// Menampilkan antrian pesanan

void DisplayMasakan(QUEUEDD q);
// Menampilkan antrian makanan

void DisplaySajian(QUEUEDD q);
// Menampilkan antrian sajian

boolean isValid(Kata a);
// Memeriksa validitas command

boolean isCook(Kata a);
// Memeriksa apakah command berupa COOK

boolean isServe(Kata a);
// Memeriksa apakah command berupa SERVE

boolean isSkip(Kata a);
// Memeriksa apakah command berupa SKIP

void generateFood(Food *pes,int i);
// Autogenerate pesanan

void copyFood(Food *copy,Food f);
// Menyalin info makanan

void COOK(Kata ID, QUEUEDD *Pesanan, QUEUEDD *Masakan);
// Memasak makanan yang ada di urutan paling atas di
// antrian pesanan dan memasukkannnya ke dalam antrian masakan

void SERVE(QUEUEDD *Masakan, QUEUEDD *Sajian, int *Saldo);
// Menyajikan makanan yang ada di urutan paling atas di
// antrian makanan siap saji

//int randint(int lower, int upper);
// Mengembalikan angka acak di range tertentu

void dinerdash(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score);
// procedure utama untuk menjalankan game dinner dash

boolean foundmathquiz(ArrayDin ListGames);

void Scoreboard(ArrayDin ListGames , ArrayOfMap GameMap);

void Username(char*game ,ArrayDin ListGames , ArrayOfMap *GameMap , int score);