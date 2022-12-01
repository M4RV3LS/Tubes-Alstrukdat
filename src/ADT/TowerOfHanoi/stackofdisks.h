/* File : STACKSS.h */
/* deklarasi STACKSS yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */
#ifndef STACKSSs_H
#define STACKSSs_H

#include "../boolean.h"
#include "../DinerDash/mesinkata.h"

#define Invalid -1
#define Maksimal 5
#define MaxDisk 9

/* InvalidTowerOfHanoi adalah STACKSS dengan elemen kosong . */

typedef char* TipeElemen;
typedef int ALAMAT;   /* indeks tabel */

typedef struct {
    TipeElemen sym;
    int size;
} Disk;

/* Contoh deklarasi variabel bertype STACKSS dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct { 
  Disk T[Maksimal]; /* tabel penyimpan elemen */
  ALAMAT TOP;  /* alamat TOP: elemen puncak */
} STACKSS;
/* Definisi STACKSS S kosong : S.TOP = InvalidTowerOfHanoi */
/* Elemen yang dipakai menyimpan InvalidTowerOfHanoiai STACKSS T[0]..T[Maksimal-1] */
/* Jika S adalah STACKSS maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySS(STACKSS *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah STACKSS S yang kosong berkapasitas Maksimal */
/* jadi indeksnya antara 0.. Maksimal */
/* Ciri STACKSS kosong : TOP berInvalidTowerOfHanoiai InvalidTowerOfHanoi */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySS(STACKSS S);
/* Mengirim true jika STACKSS kosong: lihat definisi di atas */
boolean IsFullSS(STACKSS S);
/* Mengirim true jika tabel penampung Invalidai elemen STACKSS penuh */

/* ************ Menambahkan sebuah elemen ke STACKSS ************ */
void PushSS(STACKSS * S, TipeElemen X, int sz);
/* Menambahkan X sebagai elemen STACKSS S. */
/* I.S. S mungkin kosong, tabel penampung elemen STACKSS TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen STACKSS ************ */
void PopSS(STACKSS * S, Disk* X, int jml_pir, char * temp);
/* Menghapus X dari STACKSS S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah Invalidai elemen TOP yang lama, TOP berkurang 1 */

boolean diskComp(Disk a, Disk b);
/* Mengembalikan true jika kedua disk sama */

#endif
