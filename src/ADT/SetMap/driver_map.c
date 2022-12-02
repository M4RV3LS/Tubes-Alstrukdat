#include "map.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    Map M;
    CreateEmpty(&M);
    Insert(&M, "Akk", 2);
    Insert(&M, "Bkk", 1);
    Insert(&M, "Ckk", 4);
    Insert(&M, "Dkk", 3);
    Insert(&M, "Ekk", 8);
    Insert(&M, "Fkk", 7);
    Insert(&M, "Gkk", 6);
    Insert(&M, "Hkk", 5);
    Insert(&M, "Ikk", 5);

    /*Cek apakah Map penuh*/
    if (IsFull(M))
    {
        printf("Map penuh\n");
    }
    else if (IsEmptyMap(M))
    {
        printf("Map Kosong\n");
    }
    else
    {
        printf("Map tidak penuh\n");
    }
    /*Sorting Map*/
	SortMap(&M);
	printf("\n");
	printf("ini adalah skor untuk elemen pertama map yang telah disorting %d\n",M.Elements[0].Skor);
    printf("Isi Map M:\n");
    PrintMap(M);
	printf("\n");
	printf("Banyaknya Elemen Map %d\n",M.Count);
    printf("Delete Key Akk \n");
	Delete(&M , "Akk");
    printf("Banyaknya Elemen Map %d\n",M.Count);
    printf("Isi Map M:\n");
    PrintMap(M);
	valuetype Score = Skor(M , "Ikk");
    printf("Skor dari Ikk adalah %d\n",Score);

    /*Cek Apakah Gkk merupakan elemen dari map*/
    if (IsMemberMap(M, "Gkk"))
    {
        printf("Gkk merupakan elemen dari map\n");
    }
    else
    {
        printf("Gkk bukan merupakan elemen dari map\n");
    }

    /*Mencari Index dari elemen Gkk*/
    int Index = SearchIndex(M, "Gkk");
    printf("Index dari Gkk adalah %d\n", Index);
    
    return 0;
}