/* File : queue.h */
/* Definisi ADT QUEUEDD dengan representasi array secara eksplisit dan alokasi statik */

#ifndef QUEUE_HYBRID_H
#define QUEUE_HYBRID_H

//#include "boolean.h"
#include "mesinkata.h"

#define IDX_UNDEF -1
#define CAPACITY 100

/* Definisi elemen dan address */
typedef char *string;
typedef struct
{
    Kata ID;
    int Durasi;
    int Tahan;
    int Harga;
} Food;

typedef Food FoodType;
typedef struct
{
    FoodType buffer[CAPACITY];
    int idxHead;
    int idxTail;
    int Neff;
} QUEUEDD;

/* ********* AKSES (Selektor) ********* */
/* Jika q adalah QUEUEDD, maka akses elemen : */
#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define HEAD(q) (q).buffer[(q).idxHead]
#define TAIL(q) (q).buffer[(q).idxTail]

/* *** Kreator *** */
void CreateQUEUEDD(QUEUEDD *q);
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk dengan kondisi sbb: */
/* - Index head bernilai IDX_UNDEF */
/* - Index tail bernilai IDX_UNDEF */
/* Proses : Melakukan alokasi, membuat sebuah q kosong */

/* ********* Prototype ********* */
boolean isKosong(QUEUEDD q);
/* Mengirim true jika q kosong: lihat definisi di atas */
boolean isPenuh(QUEUEDD q);
/* Mengirim true jika tabel penampung elemen q sudah penuh */
/* yaitu IDX_TAIL akan selalu di belakang IDX_HEAD dalam buffer melingkar*/
boolean isAnggota(QUEUEDD q, Kata w);
/* Mengembalikan true apabila f ditemukan di queue q*/

int nbElement(QUEUEDD q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong. */

/* *** Primitif Add/Delete *** */
void ENQUEUEDD(QUEUEDD *q, FoodType val);
/* Proses: Menambahkan val pada q dengan aturan FIFO */
/* I.S. q mungkin kosong, tabel penampung elemen q TIDAK penuh */
/* F.S. val menjadi TAIL yang baru, IDX_TAIL "mundur" dalam buffer melingkar. */

void DEQUEUEDD(QUEUEDD *q, FoodType *val);
/* Proses: Menghapus val pada q dengan aturan FIFO */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen HEAD pd I.S., IDX_HEAD "mundur";
        q mungkin kosong */

void DELETEATDD(QUEUEDD *q, int i, Food *f);
/* Proses: Menghapus f pada q di index i */
/* I.S. q tidak mungkin kosong */
/* F.S. val = nilai elemen pada index i 
pd I.S., IDX_TAIL "mundur" q mungkin kosong */

int findBuffer(Kata code,QUEUEDD q);
/* Menemukan indeks */

#endif