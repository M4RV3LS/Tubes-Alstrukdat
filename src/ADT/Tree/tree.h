/* ADT POHON BINER */

#ifndef pohon_h
#define pohon_h

#include <stdio.h>
#include <stdlib.h>
#include "../boolean.h"
#include "../DinerDash/mesinkar.h"

#define NILBUATTREE NULL

// Definisi Tipe Pohon Biner
typedef char Infotype;
typedef struct treeNode *AddressTree;
typedef struct treeNode {
	Infotype Info;
	AddressTree Left;
	AddressTree Right;
} Node;
typedef AddressTree BinTree;

/*** PROTOTYPE ***/

//SELEKTOR
#define Akar(P) (P)->Info //Mengirimkan info pohon
#define Left(P) (P)->Left //Mengirimkan alamat dari cabang kiri suatu pohon
#define Right(P) (P)->Right //Mengirimkan alamat dari cabang kanan suatu pohon

//KONSTRUKTOR 
BinTree Tree (Infotype Akar, BinTree L, BinTree R);
// Menghasilkan sebuah pohon biner dari Akar, L, dan R, jika alokasi berhasil
// Menghasilkan pohon kosong (NILBUATTREE) jika alokasi gagal

void MakeTree (Infotype Akar, BinTree L, BinTree R, BinTree *P);
// I.S. Sembarang
// F.S. Menghasilkan sebuah pohon P
// Menghasilkan sebuah pohon biner P dari Akar , L, dan R, jika alokasi berhasil
// Menghasilkan pohon P yang kosong (NILBUATTREE) jika alokasi gagal

//PREDIKAT
boolean IsTreeEmpty (BinTree P);
// Mengirimkan true jika P adalah pohon biner kosong

boolean IsOneElmt (BinTree P);
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1
elemen */

boolean IsUnerRight (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P hanya
mempunyai subpohon kanan */

boolean IsUnerLeft (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P hanya
mempunyai subpohon kiri */

boolean IsBiner (BinTree P);
/* Mengirimkan true jika pohon biner tidak kosong P mempunyai
subpohon kiri dan subpohon kanan */

//SEARCHING
boolean SearchTree (BinTree P, Infotype X);
/* Mengirimkan true jika ada node dari P yang berNILBUATTREEai X */

//OPERASI ADDITION DAN DELETION
void AddDaunLeft (BinTree *P, Infotype X);
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */

void AddDaun (BinTree *P, Infotype X, Infotype Y, boolean Kiri);
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X (jika Kiri = true), atau
sebagai anak k@anan X (jika Kiri = false) */

void DelDaunLeft (BinTree *P, Infotype *X);
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
disimpan pada daun terkiri yang dihapus */

void DelDaun (BinTree *P, Infotype X);
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. Semua daun berNILBUATTREEai X dihapus dari P */

//FUNGSI TAMBAHAN
int NbElmtTree (BinTree P);
/* Mengirimkan banyaknya elemen (node) pohon biner P */

int NbLeaf (BinTree P);
/* Mengirimkan banyaknya daun (node) pohon biner P */

void printTree (BinTree P);
/* Mencetak elemen Tree ke layar */

#endif
