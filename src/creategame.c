#include <stdio.h>
#include "creategame.h"

void CREATEGAME(ArrayDin *ListGames)
{
    printf("Masukkan nama game yang akan ditambahkan : ");
    STARTCOMMANDGAME();
    InsertLast(ListGames, currentCMD.TabWord);
    printf("Game berhasil ditambahkan\n");
}


