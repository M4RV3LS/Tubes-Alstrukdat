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
#include "ADT/ArrayOfMap/arrayofmap.h"
#include "ADT/Hangman/arrayHangman.h"
#include "ADT/Hangman/hangmanprint.h"
#include "ADT/TowerOfHanoi/stackofdisks.h"
#include "ADT/SnakeOnMeteor/snakeonmeteor.h"
#include "ADT/Tree/tree.h"



void CREATEGAME(ArrayDin *ListGames , ArrayOfMap *GameMap);

void DELETE(ArrayDin *ListGames, Queue q1 , ArrayOfMap *GameMap , Stack *GameHistory);

Stack DELETEHISTORY(Stack *in , char*game);

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

boolean ya();

void ResetScoreboard(ArrayOfMap *M , ArrayDin *ListGames );

int KataTerpanjang(Map Game);

void PrintScoreBoard(Map Game);

boolean yes();

void History(Stack Game , int n);

void ResetHistory (Stack * Game);

void SnakeOnMeteor(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score);
/*GAME SNAKE On Meteor*/


void Hangman(char*game ,ArrayDin ListGames , ArrayOfMap *GameMap , int score);

void mainHangman(int*kesempatan, char*Kata);

void loadkata(ListKata *ListKata, char*filename);

void saveListKata(ListKata ListKata, char*filename);

boolean isTebakanValid(Word word);

boolean isHurufAda(char huruf, char* kata);

void underscoreToHuruf(char huruf, char* GuessedKata, char*kata);

void PrintCharWithSpace(char*kata, int len);

void PrintCharNoSpace(char*kata, int len);

int panjang_kata(char*s);

void InsertKataLast(char huruf, char*kata);

char* wordToStr(Word word);



void createDisk(int i,int jml_pir, Disk* a);
/* Membuat piringan berdasarkan besar piringan */

void createStick(int jml_pir, Disk *a);
/* Membuat tiang */

void scoring(int steps, int* score, int jml_disk);
/* Menampilkan Invalidai dari pemain sesuai steps yang dibutuhkan */

void cekValiditas(char tow1, char tow2, STACKSS a, STACKSS b, STACKSS c, boolean *valid);
/* Cek validitas input command game*/

void displaystacks(STACKSS a, STACKSS b, STACKSS c, int jml_pir);
/* Menampilkan tiap tower di masing-masing ronde tower of hanoi */

void TowerOfHanoi(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score);
/* Memainkan game tower of hanoi */

boolean win(STACKSS c, int jml_pir);
/* Memeriksa kondisi menang */

void penundaan(int number_of_seconds);

void createRoute(BinTree* route, BinTree* l, BinTree* r);

boolean end(char a);

void undertale(char*game , ArrayDin ListGames , ArrayOfMap *GameMap , int nilai);

void beginning();

void toriel(BinTree* p , char*name , int *score);

void papyrus(BinTree* p , char*name , int *score);

void lastcorridor();

void megalovania(BinTree* p , char*name , int *score);

void sansneutral(BinTree* p,char*name , int *score);

void sanspacifist(BinTree* p , char*name , int *score);

void asriel(BinTree p , char*name , int *score);

void torielfight(int *score , char*Username);;
/* Permainan Rock Paper Scissor*/

void WelcomingGamePapyrus();

int mainpapyrus();
/*Basic nya mirip mathquiz cuman bedanya semua mode pertambahan , perkalian , dan pengurangan di jadiin satu 
dan dipisahkan dengan 3 stage berbeda*/


void papyrusfight(int *score , char*Username);
/*Melakukan looping hingga health papyrus harus diatas 70*/


void sansfight(int *score , char *Username);
/*Permainan game hitung duit */

void CreateRandomPointAsriel(Point *P);
/*Membuat Random point buat generate bomb dan treasure*/

void PrintAlphabet(Map MiniGames , int index , char*input);
/*Melakukan print alphabet sesuai value yang dimilikinya*/


void Axe();
/*Axe Ascii Art*/


void WelcomingAsrielGames();
/*Welcoming game Treasure Hunt*/

void AsrielGameRule();
/*print game rule buat treasure Hunt*/

void PrintPetaAsriel(Map MiniGames);
/*Print Peta permainan untuk game Treasure Hunt*/

void InsertMapMiniGames(Map *M, keytype k, valuetype v);
/*Insert atribut ke Map buat TreasureHunt*/

int mainasriel(char*Username);
/*Main Program Treasure Hunt*/

void asrielfight(int *score , char *Username);
/*Main Game Treasure Hunt*/