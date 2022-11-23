/* Indeks yang digunakan [IndexAwalArrayOfMap..IndexAkhirArrayOfMap] */
/* Jika T adalah TabInt, cara deklarasi dan akses: */
/* Deklarasi : T : TabInt */
/* Maka cara akses:
 * T.Neff untuk mengetahui banyaknya elemen
 * T.TI untuk mengakses seluruh nilai elemen tabel
 * T.TI[i] untuk mengakses elemen ke-i */
/* Definisi :
 * Tabel kosong: T.Neff = 0
 * Definisi elemen pertama : T.TI[i] dengan i=0
 * Definisi elemen terakhir yang terdefinisi: T.TI[i] dengan i=T.Neff - 1 */
#include <stdio.h>
#include "arrayofmap.h"
#include <stdlib.h>

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create tabel kosong */
void MakeEmptyArrayOfMap(ArrayOfMap *T)
{

    (*T).NeffArrayOfMap = 0;
}
/* I.S. sembarang */
/* F.S. Terbentuk tabel T kosong dengan kapasitas IndexAkhirArrayOfMap-IndexAwalArrayOfMap+1 */

/* ********** SELEKTOR ********** */
/* *** Banyaknya elemen *** */
int NbElmtArrayOfMap(ArrayOfMap T)
{
    return (T.NeffArrayOfMap);
}
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElmtArrayOfMap(ArrayOfMap T)
{
    return (IndexAkhirArrayOfMap - IndexAwalArrayOfMap + 1);
}
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IndexArrayOfMap FirstIdxArrayOfMap(ArrayOfMap T)
{
    return IndexAwalArrayOfMap;
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen pertama */
IndexArrayOfMap LastIdxArrayOfMap(ArrayOfMap T)
{
    return (NbElmtArrayOfMap(T) - 1);
}
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen terakhir */
/* *** Menghasilkan sebuah elemen *** */
ElTypeArrayOfMap GetElmtArrayOfMap(ArrayOfMap T, IndexArrayOfMap i)
{
    return (T.ArrMap[i]);
}
/* Prekondisi : Tabel tidak kosong, i antara FirstIdx(T)..LastIdx(T) */
/* Mengirimkan elemen tabel yang ke-i */

/* *** Selektor SET : Mengubah nilai TABEL dan elemen tabel *** */
/* Untuk type private/limited private pada bahasa tertentu */
void SalinArrayOfMap(ArrayOfMap Tin, ArrayOfMap *Tout)
{   
    (*Tout).NeffArrayOfMap = Tin.NeffArrayOfMap;
    int i;
    for (i = IndexAwalArrayOfMap; i <= IndexAkhirArrayOfMap; i++)
    {
        (*Tout).ArrMap[i] = Tin.ArrMap[i];
    }
}
/* I.S. Tin terdefinisi, sembarang */
/* F.S. Tout berisi salinan Tin */
/* Assignment THsl -> Tin */
void SetElmtArrayOfMap(ArrayOfMap *T, IndexArrayOfMap i, ElTypeArrayOfMap v)
{
    (*T).ArrMap[i] = v;
    if (i == LastIdxArrayOfMap(*T) + 1)
    {
        (*T).NeffArrayOfMap++;
    }
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Elemen T yang ke-i bernilai v */
/* Mengeset nilai elemen tabel yang ke-i sehingga bernilai v */
void SetNeffArrayOfMap(ArrayOfMap *T, IndexArrayOfMap N)
{
    (*T).NeffArrayOfMap = N;
}
/* I.S. T terdefinisi, sembarang */
/* F.S. Nilai indeks efektif T bernilai N */
/* Mengeset nilai indeks elemen efektif sehingga bernilai N */

/* ********** Test Indeks yang valid ********** */
boolean IsIdxValidArrayOfMap(ArrayOfMap T, IndexArrayOfMap i)
{
    return ((i >= IndexAwalArrayOfMap) && (i <= IndexAkhirArrayOfMap));
}
/* Prekondisi : i sembarang */
/* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean IsIdxNeffArrayOfMap(ArrayOfMap T, IndexArrayOfMap i)
{
    return ((i >= FirstIdxArrayOfMap(T)) && (i <= LastIdxArrayOfMap(T)));
}
/* Prekondisi : i sembarang*/
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
/* yaitu antara FirstIdx(T)..LastIdx(T) */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArrayOfMap(ArrayOfMap T)
{
    return (NbElmtArrayOfMap(T) == 0);
}
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArrayOfMap(ArrayOfMap T)
{
    return (NbElmtArrayOfMap(T) == MaxNbElmtArrayOfMap(T));
}
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

void InsertFirstArrayOfMap(ArrayOfMap *T, ElTypeArrayOfMap v)
{
    int i;
    for (i = NbElmtArrayOfMap(*T); i > 0; i--)
    {
        (*T).ArrMap[i] = (*T).ArrMap[i - 1];
    }
    (*T).ArrMap[0] = v;
    (*T).NeffArrayOfMap++;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen pertama L. */

void InsertAtArrayOfMap(ArrayOfMap *T, ElTypeArrayOfMap v, IndexArrayOfMap i)
{
    int j;
    for (j = NbElmtArrayOfMap(*T); j > i; j--)
    {
        (*T).ArrMap[j] = (*T).ArrMap[j - 1];
    }
    (*T).ArrMap[i] = v;
    (*T).NeffArrayOfMap++;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. v disisipkan dalam L pada indeks ke-i (bukan menimpa elemen di i). */

void InsertLastArrayOfMap(ArrayOfMap *T, ElTypeArrayOfMap v)
{
    (*T).ArrMap[NbElmtArrayOfMap(*T)] = v;
    (*T).NeffArrayOfMap++;
}
/* I.S. L terdefinisi, mungkin kosong. */
/* F.S. v menjadi elemen terakhir L. */

void DeleteFirstArrayOfMap(ArrayOfMap *T)
{
    int i;
    for (i = 0; i < NbElmtArrayOfMap(*T) - 1; i++)
    {
        (*T).ArrMap[i] = (*T).ArrMap[i + 1];
    }
    (*T).NeffArrayOfMap--;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen pertama L, elemen pertama L dihapus dari L. */

void DeleteAtArrayOfMap(ArrayOfMap *T, IndexArrayOfMap i)
{
    int j;
    for (j = i; j < NbElmtArrayOfMap(*T) - 1; j++)
    {
        (*T).ArrMap[j] = (*T).ArrMap[j + 1];
    }
    (*T).NeffArrayOfMap--;
}
/* I.S. L terdefinisi, tidak kosong, i merupakan indeks lojik yang valid di L. */
/* F.S. Elemen L pada indeks ke-i dihapus dari L. */

void DeleteLastArrayOfMap(ArrayOfMap *T)
{
    (*T).NeffArrayOfMap--;
}
/* I.S. L terdefinisi, tidak kosong. */
/* F.S. F diset dengan elemen terakhir L, elemen terakhir L dihapus dari L. */

// int main(){
//     ArrayOfMap T;
//     MakeEmptyArrayOfMap(&T);
//     Map M1;
//     Map M2;
//     CreateEmptyMap(&M1);
//     CreateEmptyMap(&M2);
//     Insert(&M1, "test1", 1);
//     Insert(&M1, "test2", 2);
//     Insert(&M2, "test3", 3);
//     Insert(&M2, "test4", 4);
//     InsertFirstArrayOfMap(&T, M1);
//     InsertLastArrayOfMap(&T, M2);
//     printf("%s %d\n" , GetElmtArrayOfMap(T, 0).Elements[0].Nama, GetElmtArrayOfMap(T, 0).Elements[0].Skor);
//     CreateEmptyMap(&(T.ArrMap[0]));
//     printf("%s %d\n" , GetElmtArrayOfMap(T, 0).Elements[0].Nama, GetElmtArrayOfMap(T, 0).Elements[0].Skor);
//     if(IsEmptyMap(T.ArrMap[0])){
//         printf("M1 kosong\n");
//     }
//     else{
//         printf("M1 tidak kosong\n");
//     }
//     return 0;
// }