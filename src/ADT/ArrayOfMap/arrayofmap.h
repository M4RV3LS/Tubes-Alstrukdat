

#include "../../boolean.h"
#include "../SetMap/map.h"

#ifndef ARRAYMAP_H
#define ARRAYMAP_H

/* Kamus Umum */

#define IndexAkhirArrayOfMap 99
#define IndexAwalArrayOfMap 0
#define IndexUndefArrayOfMap -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int IndexArrayOfMap;
typedef Map ElTypeArrayOfMap;

typedef struct
{
    Map ArrMap[IndexAkhirArrayOfMap - IndexAwalArrayOfMap + 1]; /* memori tempat penyimpan elemen (container) */
    int NeffArrayOfMap;                               /* banyaknya elemen efektif */
} ArrayOfMap;

/* Indeks yang digunakan [IdxMin..IdxMax] */
/* Jika Array adalah ArrayOfMap, cara deklarasi dan akses: */
/* Deklarasi : Array : ArrayOfMap */
/* Maka cara akses:
 * Array.Neff untuk mengetahui banyaknya elemen
 * Array.ArrMap untuk mengakses seluruh nilai elemen tabel
 * Array.ArrMap[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: Array.NeffArrayOfMap = 0
 * Definisi elemen pertama : Array.ArrMap[i] dengan i=0
 * Definisi elemen terakhir yang terdefinisi: Array.ArrMap[i] dengan i = Array.NeffArrayOfMap - 1 */

#define NeffAOM(T) (T).NeffArrayOfMap 
#define ElmtAOM(T, i) (T).ArrMap[(i)]
#define FirstIdxAOM(T) IndexAwalArrayOfMap
#define LastIdxAOM(T) (NeffAOM(T) - 1)


/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArrayOfMap(ArrayOfMap *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrayOfMap(ArrayOfMap T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElmtArrayOfMap(ArrayOfMap T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IndexArrayOfMap FirstIdxArrayOfMap(ArrayOfMap T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IndexArrayOfMap LastIdxArrayOfMap(ArrayOfMap T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElTypeArrayOfMap GetElmtArrayOfMap(ArrayOfMap T, IndexArrayOfMap i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SalinArrayOfMap(ArrayOfMap Tin, ArrayOfMap *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetElmtArrayOfMap(ArrayOfMap *T, IndexArrayOfMap i, ElTypeArrayOfMap v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeffArrayOfMap(ArrayOfMap *T, IndexArrayOfMap N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArrayOfMap(ArrayOfMap T, IndexArrayOfMap i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxNeffArrayOfMap(ArrayOfMap T, IndexArrayOfMap i);
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrayOfMap(ArrayOfMap T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArrayOfMap(ArrayOfMap T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void InsertFirstArrayOfMap(ArrayOfMap *T, ElTypeArrayOfMap v);
/* I.S. T terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama T. */

void InsertAtArrayOfMap(ArrayOfMap *T, ElTypeArrayOfMap v, IndexArrayOfMap i);
/* I.S. T terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di T. */
/* F.S. v disisipkan dalam T pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastArrayOfMap(ArrayOfMap *T, ElTypeArrayOfMap v);
/* I.S. T terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir T. */

void DeleteFirstArrayOfMap(ArrayOfMap *T);
/* I.S. T terdefinisi, tidak kosong. */
/* F.S. elemen pertama T dihapus dari T. */

void DeleteAtArrayOfMap(ArrayOfMap *T, IndexArrayOfMap i);
/* I.S. T terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen T pada indeks ke-i dihapus dari T. */

void DeleteLastArrayOfMap(ArrayOfMap *T);
/* I.S. T terdefinisi, tidak kosong. */
/* F.S. elemen terakhir T dihapus dari T. */
#endif
