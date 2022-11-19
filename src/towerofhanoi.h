#include <stdio.h>
#include <stdlib.h>
#include "ADT/TowerOfHanoi/stackofdisks.h"

void scoring(int steps, int* score);
/* Menampilkan nilai dari pemain sesuai steps yang dibutuhkan */

void cekValiditas(char tow1, char tow2, Stack a, Stack b, Stack c, boolean *valid);
/* Cek validitas input command game*/

void displaystacks(Stack a, Stack b, Stack c);
/* Menampilkan tiap tower di masing-masing ronde tower of hanoi */

void towerofhanoi();
/* Memainkan game tower of hanoi */

