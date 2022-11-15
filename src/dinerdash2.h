#include <stdio.h>
#include "queuehybrid.h"
#include <time.h>
#include <stdlib.h>

#ifndef DINERDASH2_h
#define DINERDASH2_H

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

void generateFood(Food *pes,int i);
// Autogenerate pesanan

void copyFood(Food *copy,Food f);
// Menyalin info makanan

void COOK(Word ID, Queue *Pesanan, Queue *Masakan);
// Memasak makanan yang ada di urutan paling atas di
// antrian pesanan dan memasukkannnya ke dalam antrian masakan

void SERVE(Queue *Masakan, Queue *Sajian, int *Saldo);
// Menyajikan makanan yang ada di urutan paling atas di
// antrian makanan siap saji

int randint(int lower, int upper);
// Mengembalikan angka acak di range tertentu

void dinnerdash();
// procedure utama untuk menjalankan game dinner dash

#endif