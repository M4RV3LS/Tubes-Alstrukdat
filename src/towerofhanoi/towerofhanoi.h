#include <stdio.h>
#include <stdlib.h>
#include "../ADT/TowerOfHanoi/stackofdisks.h"
#include "../ADT/arrayOfString.h"
#include "../ADT/ArrayOfMap/arrayofmap.h"
#include "../console.h"

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

void towerofhanoi(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score);
/* Memainkan game tower of hanoi */

boolean win(STACKSS c, int jml_pir)
/* Memeriksa kondisi menang */

