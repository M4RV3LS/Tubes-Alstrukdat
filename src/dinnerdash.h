#include <stdio.h>
//#include "queue.h"
//#include "mesinkata2.h"
#include "ADT/queuedinner.h"

#ifndef DINERDASH_h
#define DINERDASH_H


//int saldo;

void COOK(Word ID, Queue *Pesanan, Queue *Masakan);
// Memasak makanan yang ada di urutan paling atas di
// antrian pesanan dan memasukkannnya ke dalam antrian masakan

void SERVE(Queue *Pesanan, Queue *Sajian);
// Menyajikan makanan yang ada di urutan paling atas di
// antrian makanan siap saji

void SKIP();
// Melewatkan satu ronde tanpa melakukan apa-apa

void DisplayPesanan();
// Menampilkan antrian pesanan

void DisplayMasakan();
// Menampilan antrian masakan

void DisplaySajian();
// Menampilkan antrian sajian

Word IsTop(Word ID);

#endif