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




void CREATEGAME(ArrayDin *ListGames);

void DELETE(ArrayDin *ListGames, Queue q1);

void HELP();

void LISTGAME(ArrayDin *ListGames);

void LOADFILE(ArrayDin *ListGames , char* filename);

void PLAYGAME(Queue *q1);

void QUEUEGAME(Queue *q1, ArrayDin game);

void QUIT(); 

void gameRNG(); 

void SAVEBNMO(ArrayDin* GamesList, char* filename);

void SKIPGAME(Queue *q, int n);

void STARTGAME(ArrayDin *ListGames);

int pertambahan(int skor);

int pengurangan(int skor);

int perkalian(int skor);

int mathquiz();

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

void dinnerdash();
// procedure utama untuk menjalankan game dinner dash