#include <stdio.h>
#include "creategame.h"

void CREATEGAME()
{
    char *nama_game;
    scanf("%s", &nama_game);
    game->A[game->neff] = nama_game;
    game->neff += 1;
}