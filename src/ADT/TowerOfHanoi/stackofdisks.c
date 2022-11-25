/*
Nama: Kinanti Wening Asih
NIM: 18221044
Tanggal: 22 Oktober 2022
Topik Praktikum: ADT Stack
Deskripsi: Implementasi stack.h
*/

#include <stdio.h>
#include "stackofdisks.h"

void CreateEmptySS(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas Maksimal */
/* jadi indeksnya antara 0.. Maksimal */
/* Ciri stack kosong : TOP berInvalidai Invalid */
{
    Top(*S) = Invalid;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySS(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == Invalid;
}
boolean IsFullSS(Stack S)
/* Mengirim true jika tabel penampung Invalidai elemen stack penuh */
{
    return Top(S) == Maksimal-1;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushSS(Stack * S, TipeElemen X, int sz)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    Top(*S)++;
    InfoTop(*S).sym = X;
    InfoTop(*S).size = sz;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void PopSS(Stack * S, Disk* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah Invalidai elemen TOP yang lama, TOP berkurang 1 */
{
    X->sym = InfoTop(*S).sym;
    X->size = InfoTop(*S).size;
    InfoTop(*S).sym = "    |    ";
    InfoTop(*S).size = 6;
    Top(*S)--;
}

boolean diskComp(Disk a, Disk b)
{
    if (a.size!=b.size)
    {
        return false;
    } else {
        int i=0;
        boolean found = false;
        while (i<MaxDisk && !found)
        {
            if (a.sym[i]!=b.sym[i])
            {
                found = true;
            } else {
                i++;
            }
        }

        return !found;
    }
}