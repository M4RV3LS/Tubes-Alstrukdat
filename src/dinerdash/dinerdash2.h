#ifndef DINERDASH2_H
#define DINERDASH2_H

#include <stdio.h>
#include "ADT/DinerDash/queuehybrid.h"
#include <time.h>
#include <stdlib.h>



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

int randint(int lower, int upper);
// Mengembalikan angka acak di range tertentu

void dinnerdash();
// procedure utama untuk menjalankan game dinner dash

#endif