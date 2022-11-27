
#ifndef __ARRAY_HANGMAN__
#define __ARRAY_HANGMAN__

#include "../boolean.h"
#include "../mesinkar2.h"
#include "../mesinkata2.h"

/* Kamus Umum */

#define INDEKSMAKSIMUM 100
#define INDEKSMINIMUM 1
#define INDEKSUNDEFINED -999 /* indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef int TIPEINDEKS;
typedef struct
	{
		Word TI [INDEKSMAKSIMUM-INDEKSMINIMUM+1]; /* memori tempat penyimpan elemen (container) */
		int EFEKTIF; /* banyaknya elemen efektif */
	} ListKata;

/* Indeks yang digunakan [INDEKSMINIMUM..INDEKSMAKSIMUM] */
/* Jika T adalah ListKata, cara deklarasi dan akses: */
/* Deklarasi : T : ListKata */
/* Maka cara akses:
 * T.EFEKTIF untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.EFEKTIF = 0
 * Definisi elemen pertama : T.TI[i] dengan i=1
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.EFEKTIF */

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MAKEEMPTYLISTKATA (ListKata *T);
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas INDEKSMAKSIMUM-INDEKSMINIMUM+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int BanyakElementListKata (ListKata T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int BanyakElementListKataMaksimum (ListKata T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
TIPEINDEKS AmbilIndeksPertama (ListKata T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
TIPEINDEKS AmbilIndeksTerakhir (ListKata T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
Word AmbilElement (ListKata T, TIPEINDEKS i);
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SalinTabListKata (ListKata Tin, ListKata *Tout);
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetElListKata (ListKata *T, TIPEINDEKS i, Word v);
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetEFEKTIFListKata (ListKata *T, TIPEINDEKS N);
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean ApakahIndeksValid (ListKata T, TIPEINDEKS i);
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrayHangman (ListKata T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullHangman (ListKata T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (ListKata T);
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
#endif