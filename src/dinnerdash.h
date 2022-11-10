#include <stdio.h>
#include "queue.h"
#include "mesinkata2.h"

#ifndef DINERDASH_h
#define DINERDASH_H

typedef char *string;
typedef struct
{
    string ID;
    int Durasi;
    int Tahan;
    int Harga;
} Food;

int saldo;

void COOK(string ID, Queue *Pesanan, Queue *Masakan);
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

function IsTop(string ID);

#endif