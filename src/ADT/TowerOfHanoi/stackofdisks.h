/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef stacks_H
#define stacks_H

#include "../boolean.h"
#include "../DinerDash/mesinkata.h"

#define Invalid -1
#define Maksimal 5
#define MaxDisk 9

/* InvalidTowerOfHanoi adalah stack dengan elemen kosong . */

typedef char* TipeElemen;
typedef int address;   /* indeks tabel */

typedef struct {
    TipeElemen sym;
    int size;
} Disk;

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  Disk T[Maksimal]; /* tabel penyimpan elemen */
  address TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = InvalidTowerOfHanoi */
/* Elemen yang dipakai menyimpan InvalidTowerOfHanoiai Stack T[0]..T[Maksimal-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySS(Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas Maksimal */
/* jadi indeksnya antara 0.. Maksimal */
/* Ciri stack kosong : TOP berInvalidTowerOfHanoiai InvalidTowerOfHanoi */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySS(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullSS(Stack S);
/* Mengirim true jika tabel penampung Invalidai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushSS(Stack * S, TipeElemen X, int sz);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopSS(Stack * S, Disk* X);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah Invalidai elemen TOP yang lama, TOP berkurang 1 */

boolean diskComp(Disk a, Disk b);
/* Mengembalikan true jika kedua disk sama */

#endif
