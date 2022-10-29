# include <stdio.h>
# include "array.h"


void MakeEmpty (TabInt *T)
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
{
    // int i;
    T->Neff = 0;
    // for(i = 0 ;i = IdxMax-1; i++)
    // {
    //     T->TI[i] = IdxUndef;
    // }
}

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmt (TabInt T)
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
{
    return T.Neff;
}

int MaxNbEl (TabInt T)
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
{
    return IdxMax;
}


/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
{
    return IdxMin;
}

IdxType GetLastIdx (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
{
    return NbElmt(T);
}

/* *** Menghasilkan sebuah elemen *** */
ElType GetElmt (TabInt T, IdxType i)
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */
{
    return T.TI[i];
}

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SetTab (TabInt Tin, TabInt *Tout)
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
{
    IdxType i;
    for(i = IdxMin; i <= GetLastIdx(Tin); i++)
    {
        Tout->TI[i] = Tin.TI[i];
    }
    Tout->Neff = Tin.Neff;
}

void SetEl (TabInt *T, IdxType i, ElType v)
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
{
    T->TI[i] = v;
    T->Neff ++;
}

void SetNeff (TabInt *T, IdxType N)
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */
{
    T->Neff = N;
}

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValid (TabInt T, IdxType i)
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
{
    return (i >= IdxMin) && (i <= IdxMax - 1);
}

boolean IsIdxEff (TabInt T, IdxType i)
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */
{
    return (i >= GetFirstIdx(T)) && (i <= GetLastIdx(T));
}

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmpty (TabInt T)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (T.Neff == 0);
}

/* *** Test tabel penuh *** */
boolean IsFull (TabInt T)
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
{
    return (T.Neff == IdxMax - 1);
}

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
void TulisIsi (TabInt T)
/* Proses : Menuliskan isi tabel dengan traversal */
/* I.S. T boleh kosong */
/* F.S. Jika T tidak kosong : indeks dan elemen tabel ditulis berderet ke bawah */
/* Jika isi tabel [1,2,3] maka akan diprint
0:1
1:2
2:3
*/
/* Jika T kosong : Hanya menulis "Tabel kosong" */
{
    IdxType i;

    if(IsEmpty(T))
    {
        printf("Tabel kosong\n");
    }
    else
    {
        for (i = GetFirstIdx(T); i <= NbElmt(T); i++)
        {
            printf("%d:%d\n",i,T.TI[i]);
        }
    }
    
}

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika tabel : Penjumlahan, pengurangan, perkalian, ... *** */
TabInt PlusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 + T2 */
{
    TabInt TabPlus;
    IdxType i;

    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
    {
        TabPlus.TI[i] = T1.TI[i] + T2.TI[i];
    }
    TabPlus.Neff = NbElmt(T1);
    return TabPlus;

}

TabInt MinusTab (TabInt T1, TabInt T2)
/* Prekondisi : T1 dan T2 berukuran sama dan tidak kosong */
/* Mengirimkan T1 - T2 */
{
    TabInt TabMin;
    IdxType i;
    for (i = GetFirstIdx(T1); i <= GetLastIdx(T1); i++)
    {
        TabMin.TI[i] = T1.TI[i] - T2.TI[i];
    }
    TabMin.Neff = NbElmt(T1);
    return TabMin;
}

/* ********** NILAI EKSTREM ********** */
ElType ValMax (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai maksimum tabel */
{
    IdxType i;
    ElType max;
    max = 0;

    for (i = GetFirstIdx(T); i<= GetLastIdx(T); i++)
    {
        if (max < T.TI[i])
        {
            max = T.TI[i];
        }
    }
    return max;
}

ElType ValMin (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan nilai minimum tabel */
{
    ElType min;
    IdxType i;
    min = ValMax(T);
    for (i = GetFirstIdx(T); i<= GetLastIdx(T); i++)
    {
        if (min  > T.TI[i])
        {
            min = T.TI[i];
        }
    }
    return min;
}

/* *** Mengirimkan indeks elemen bernilai ekstrem *** */
IdxType IdxMaxTab (TabInt T)
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks i dengan elemen ke-i adalah nilai maksimum pada tabel */
{
    ElType max = ValMax(T);
    IdxType i = GetFirstIdx(T);
    while(T.TI[i] != max)
    {
        i++;
    }
    return i;
}

IdxType IdxMinTab (TabInt T)
/* Prekondisi : Tabel tidak kosong */
/* Mengirimkan indeks i */
/* dengan elemen ke-i nilai minimum pada tabel */
{
    ElType min = ValMin(T);
    IdxType i = GetFirstIdx(T);

    while(T.TI[i] != min)
    {
      i++;
    }
    return i;
}

