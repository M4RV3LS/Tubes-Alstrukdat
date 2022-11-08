#include <stdio.h>
#include <stdlib.h>
#include "start.h"
#include "mesinkarakterv2.h"
#include "mesinkata.h"
#include "arrayOfString.h"

void DELETE(ArrayDin *ListGames)
{
    int nomor_game;
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTWORD();
    nomor_game = (currentWord.TabWord - '0');

    if (nomor_game > 5)
    {
        int j = game->neff;
        int i = nomor_game-1;
        
        while (i < j)
        {
            game->A[i] = game->A[i+1];
            i++;
        }
        
        game->neff -= 1;
        printf("Game berhasil dihapus");

    }
    else
    {
        printf("Game gagal dihapus");
    }

}
