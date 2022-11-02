#include <stdio.h>
#include <stdlib.h>
#include "creategame.h"
#include "deletegame.h"
#include "listgame.h"

void DELETE(List *game)
{
    int nomor_game;
    ListGame(&game);
    
    printf("Masukkan nomor game yang akan dihapus: ");
    fscanf(stdin, "%d", nomor_game);

    if (game->A[nomor_game] > game->A[5])
    {
        game->neff -= 1;
        printf("Game berhasil dihapus");
    }
    else
    {
        printf("Game gagal dihapus");
    }

}