#include <stdio.h>
#include "ADT/queuedinner.h"

#ifndef DINERDASH_h
#define DINERDASH_H

void DisplayPesanan(Queue q);
// Menampilkan antrian pesanan

void DisplayMasakan(Queue q);
// Menampilkan antrian makanan

void DisplaySajian(Queue q);
// Menampilkan antrian sajian

boolean isValid(Word a);
// Memeriksa validitas command

boolean isCook(Word a);
// Memeriksa apakah command berupa COOK

boolean isServe(Word a);
// Memeriksa apakah command berupa SERVE

boolean isSkip(Word a);
// Memeriksa apakah command berupa SKIP

Food generateFood(int i);
// Autogenerate pesanan

Food copyFood(Food f);
// Menyalin info makanan

void COOK(Word ID, Queue *Pesanan, Queue *Masakan);
// Memasak makanan yang ada di urutan paling atas di
// antrian pesanan dan memasukkannnya ke dalam antrian masakan

void SERVE(Queue *Pesanan, Queue *Sajian, int *Saldo);
// Menyajikan makanan yang ada di urutan paling atas di
// antrian makanan siap saji

void dinnerdash();
// procedure utama untuk menjalankan game dinner dash

#endif
