#include <stdio.h>
#include <stdlib.h>
#include "arrayHangman.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MAKEEMPTYLISTKATA (ListKata *T)
{
    (*T).TI [INDEKSMAKSIMUM - INDEKSMINIMUM + 1];
    (*T).EFEKTIF = 0;
}
/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int BanyakElementListKata (ListKata T)
{
    return T.EFEKTIF;
}

int BanyakElementListKataMaksimum (ListKata T)
{
    return INDEKSMAKSIMUM;
}

TIPEINDEKS AmbilIndeksPertama (ListKata T)
{
    return INDEKSMINIMUM;
}

TIPEINDEKS AmbilIndeksTerakhir (ListKata T)
{
    return BanyakElementListKata(T);
}

Word AmbilElement (ListKata T, TIPEINDEKS i)
{
    return T.TI[i];
}

void SalinTabListKata (ListKata Tin, ListKata *Tout)
{
    int i;
    for (i = INDEKSMINIMUM; i <= INDEKSMAKSIMUM; i++){
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->EFEKTIF = Tin.EFEKTIF;
}

void SetElListKata (ListKata *T, TIPEINDEKS i, Word v)
{
    T->TI[i] = v;
    if (i == AmbilIndeksTerakhir(*T) + 1)
    {
        T->EFEKTIF++;
    }
    //printf("EFEKTIF = %d\n", T->EFEKTIF);
}

void SetEFEKTIFListKata (ListKata *T, TIPEINDEKS N)
{
    T->EFEKTIF = N;
}

/* ********** Test Indeks yang valid ********** */
boolean ApakahIndeksValid (ListKata T, TIPEINDEKS i)
{
    return (i>= INDEKSMINIMUM && i <= INDEKSMAKSIMUM);
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrayHangman (ListKata T)
{
    return (BanyakElementListKata(T) == 0);
}

boolean IsFullHangman (ListKata T)
{
    return (BanyakElementListKata(T) == BanyakElementListKataMaksimum(T));
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (ListKata T)
{
    if (IsEmptyArrayHangman(T)){
        printf("Tabel kosong\n");
    } else {
        for (int i = AmbilIndeksPertama(T); i <= AmbilIndeksTerakhir(T); i++){
            printf("%d:%d\n", i, AmbilElement(T, i));
        }
    }
}