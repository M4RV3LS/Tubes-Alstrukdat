#include <stdio.h>
#include <stdlib.h>
#include "arrayHangman.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmpty (ListKata *T)
{
    (*T).TI [IdxMax - IdxMin + 1];
    (*T).Neff = 0;
}
/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int BanyakElemenListKata (ListKata T)
{
    return T.Neff;
}

int MaxNbEl (ListKata T)
{
    return IdxMax;
}

IdxType GetFirstIdx (ListKata T)
{
    return IdxMin;
}

IdxType GetLastIdx (ListKata T)
{
    return BanyakElemenListKata(T);
}

Word GetElmt (ListKata T, IdxType i)
{
    return T.TI[i];
}

void SetTab (ListKata Tin, ListKata *Tout)
{
    int i;
    for (i = IdxMin; i <= IdxMax; i++){
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetEl (ListKata *T, IdxType i, Word v)
{
    T->TI[i] = v;
    if (i == GetLastIdx(*T) + 1)
    {
        T->Neff++;
    }
}

void SetNeff (ListKata *T, IdxType N)
{
    T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (ListKata T, IdxType i)
{
    return (i>= IdxMin && i <= IdxMax);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrayHangman (ListKata T)
{
    return (BanyakElemenListKata(T) == 0);
}

boolean IsFullHangman (ListKata T)
{
    return (BanyakElemenListKata(T) == MaxNbEl(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (ListKata T)
{
    if (IsEmptyArrayHangman(T)){
        printf("Tabel kosong\n");
    } else {
        for (int i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
            printf("%d:%d\n", i, GetElmt(T, i));
        }
    }
}