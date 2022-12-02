#include "arrayofmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    ArrayOfMap T; 
    MakeEmptyArrayOfMap(&T); //inisiasi array of map
    /*Membuat Map kosong*/
    Map M1;
    Map M2;
    CreateEmptyMap(&M1);
    CreateEmptyMap(&M2);

    /*Membuat Map*/
    Insert(&M1, "test1", 1);
    Insert(&M1, "test2", 2);
    Insert(&M1, "test3", 3);
    Insert(&M2, "test4", 4);
    Insert(&M2, "test5", 5);
    Insert(&M2, "test6", 6);
    Insert(&M3, "test7", 7);

    /*Menambahkan Map ke ArrayOfMap*/
    InsertFirstArrayOfMap(&T, M1);
    InsertLastArrayOfMap(&T, M2);
    InsertAtArrayOfMap(&T, M3, 1);
    
    /*Mencetak index elemen pertama*/
    printf("%d\n", FirstIdxArrayOfMap(T));

    /*Menetak index elemen terakhir*/
    printf("%d\n", LastIdxArrayOfMap(T));

    /*Cek apakah array penuh*/
    if(IsFullArrayOfMap(T)){
        printf("Array of map penuh\n");
    }

    /*Cek apakah indeks valid*/{
    if(IsIdxValidArrayOfMap(T, 1)){
            printf("Indeks valid\n");
        }
    }

    /*Cek apakah indeks terdefinisi*/
    if(IsIdxNeffArrayOfMap(T,10)){
        printf("Indeks valid\n");
    }
    else{
        printf("Indeks tidak valid\n");
    }

    /*Melakukan perubahan pada indeks efektif array*/
    SetNeffArrayOfMap(&T,5);
    printf("Indeks efektif array sekarang adalah %d\n", NbElmtArrayOfMap(T));

    /*Element T ke i bernilai v*/
    SetElmtArrayOfMap(&T , 4 , M3);

    /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
    printf("Maksimum elemen yang dapat ditampung adalah %d\n", MaxNbElmtArrayOfMap(T));

    /*salin array*/
    ArrayOfMap T2;
    MakeEmptyArrayOfMap(&T2);
    SalinArrayOfMap(T1,&T2);
    printf("ini adalah Map pada indeks 0 array of map T2 %s %d\n" , GetElmtArrayOfMap(T2, 0).Elements[0].Nama, GetElmtArrayOfMap(T2, 0).Elements[0].Skor);

    /*Mencetak ArrayOfMap*/
    printf("ini adalah Map pada indeks 0 array of map T1 %s %d\n" , GetElmtArrayOfMap(T, 0).Elements[0].Nama, GetElmtArrayOfMap(T, 0).Elements[0].Skor);
    printf("ini adalah Map pada indeks 1 array of map T1 %s %d\n" , GetElmtArrayOfMap(T, 1).Elements[0].Nama, GetElmtArrayOfMap(T, 1).Elements[0].Skor);
    
    /*Delete elemen array*/
    DeleteFirstArrayOfMap(&T);
    printf("ini adalah Map pada indeks 0 array of map %s %d\n" , GetElmtArrayOfMap(T, 0).Elements[0].Nama, GetElmtArrayOfMap(T, 0).Elements[0].Skor);
    DeleteAtArrayOfMap(&T, 1);
    printf("ini adalah Map pada indeks 0 array of map %s %d\n" , GetElmtArrayOfMap(T, 0).Elements[0].Nama, GetElmtArrayOfMap(T, 0).Elements[0].Skor);
    DeleteLastArrayOfMap(&T);
    printf("ini adalah Map pada indeks 0 array of map %s %d\n" , GetElmtArrayOfMap(T, 0).Elements[0].Nama, GetElmtArrayOfMap(T, 0).Elements[0].Skor);
    
    /*Cek apakah array kosong*/
    if(IsEmptyArrayOfMap(T)){
        printf("array of map kosong\n");
    }
    else{
        printf("array of map tidak kosong\n");
    }
    return 0;
}