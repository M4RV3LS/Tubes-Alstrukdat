#include <stdio.h>
#include "arrayHangman.h"

int main() {
    ListKata T;
    MAKEEMPTYLISTKATA(&T);

    printf("=========== IsEmptyArrayHangman ===========\n");
    if (IsEmptyArrayHangman(T) == 1) {
        printf("Test IsEmptyArrayHangman: Passed\n");
    } else {
        printf("Test IsEmptyArrayHangman: Failed\n");
    }
    printf("=========== TEST BanyakElementListKataMaksimum ===========\n");
    if (BanyakElementListKataMaksimum(T) == 100) {
        printf("Test BanyakElementListKataMaksimum : Passed\n");
    } else {
        printf("Test BanyakElementListKataMaksimum : Failed\n");
    }
    printf("=========== TEST IsFullHangman ===========\n");
    if (IsFullHangman(T) == 0) {
        printf("Test IsFullHangman: Passed\n");
    } else {
        printf("Test IsFullHangman: Failed\n");
    }

    printf("=========== TEST SetElListKata ===========\n");
    SetElListKata(&T, 1, stringToWord("1"));
    SetElListKata(&T, 2, stringToWord("2"));
    SetElListKata(&T, 3, stringToWord("3"));
    SetElListKata(&T, 4, stringToWord("4"));
    SetElListKata(&T, 5, stringToWord("5"));
    printf("\n");

    printf("=========== TEST AmbilIndeksPertama ===========\n");
    printf("Indeks pertama dari array : %d\n",AmbilIndeksPertama(T));
    //Expected output : 1

    printf("=========== TEST AmbilIndeksTerakhir ===========\n");
    printf("Indeks terakhir dari array : %d\n",AmbilIndeksTerakhir(T));
    //Expected output : 5
    printf("\n");

    printf("Banyak elemen efektif pada array : %d\n",BanyakElementListKata(T));
    printf("\n");
    //Expected output : 5

    printf("=========== TEST AmbilElement ===========\n");
    printf("Mendapatkan dan menampilkan elemen pada indeks ke-2 di array : \n");
    AmbilElement(T,2);
    printf("\n");
    printf("\n");

    printf("=========== TEST ApakahIndeksValid ===========\n");
    printf("Apakah indeks ke-100 valid? (0 jika tidak valid, 1 jika valid)\n");
    printf("%d\n",ApakahIndeksValid(T,100));
    //Expected output : 0

    printf("Apakah indeks ke-1 valid? (0 jika tidak valid, 1 jika valid)\n");
    printf("%d\n",ApakahIndeksValid(T,1));
    //Expected output : 1

    printf("=========== TEST TulisIsi ===========\n");
    TulisIsi(T);
    printf("Test TulisIsi: Passed\n");
   
    printf("=========== TEST SalinTabListKata ===========\n");
    printf("Membuat array baru hasil salinan array lama\n");
    ListKata T2;
    MAKEEMPTYLISTKATA(&T2);
    SalinTabListKata(T,&T2);
    printf("\n");

    printf("=========== TEST SetEFEKTIFListKata ===========\n");
    printf("Mengubah banyaknya elemen efektif pada array menjadi 2 dan menuliskan isi array ke layar : \n");
    SetEFEKTIFListKata(&T,2);
    TulisIsi(T);
    printf("\n");

    return 0;
}


