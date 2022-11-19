#include <stdio.h>
#include "snakeonmeteor.h"
#include <stdlib.h>

boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (Head(L) == Nil && Tail(L) == Nil);
}

void CreateEmpty (List L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    Head(L) = Nil;
    Tail(L) = Nil;
}

void CreatePoint (Point P, int X, int Y)
{
    Absis(P) = X;
    Ordinat(P) = Y;
}

Point CreateNextPoint(Point P)
{
    Point Pnew;
    if (Absis(P) > 0)
    {
        Absis(Pnew) = Absis(P) - 1;
        Ordinat(Pnew) = Ordinat(P);
        return Pnew;
    }
    else if (Ordinat(P) > 0)
    {
        Absis(Pnew) = Absis(P);
        Ordinat(Pnew) = Ordinat(P) - 1;
        return Pnew;
    }
    else
    {
        Absis(Pnew) = Absis(P) + 1;
        Ordinat(Pnew) = Ordinat(P);
    }
    return Pnew;
}

address Alokasi (Point X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address) malloc(sizeof(ElmtList));
    Info(P) = X;
    Next(P) = Nil;
    Prev(P) = Nil;
    return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    if IsEmpty(List L)
    {
        return 0;
    }
    else
    {
        address P = Head(L);
        while (P != Nil)
        {
            count++;
            P = Next(P);
        }
        return count;
    }
}

