#include <stdio.h>
#include "listgame.h"

void LISTGAME(ArrayDin *ListGames)
{
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int i=0; i < ListGames->Neff; i++)
    {
        printf("%d. %s\n", i+1, ListGames->A[i]);
    }
}


