#ifndef __RNG__
#define __RNG__

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ADT/mesinkar2.h"
#include "ADT/mesinkata2.h"

void gameRNG();
/*BNMO tidak selalu menikmati game yang sudah pasti outcome-nya. Karena itu, ia suka dengan game yang melibatkan 
RNG (Random number generator).  Berikut adalah spesifikasi game ini:
Setiap permainan dimulai dengan program sudah menentukan sebuah angka acak X yang berada pada rentang 1- 50.
Di setiap giliran, pemain diberi kesempatan menebak angka X Game akan memberi tahu apakah tebakan pemain 
dibandingkan terhadap X lebih besar atau lebih kecil.
Permainan selesai jika pemain menebak angka X dengan benar dengan skor maksimal 49 (Menebak pada urutan pertama).
Skor untuk game ini tergantung dengan seberapa cepat pemain menebak X. Formula skor dari game ini adalah jumlah range 
angka X yang ditebak yaitu 50 dikurang dengan banyaknya penebakan yang dilakukan.
*/

#endif