#include <stdio.h>
#include "creategame.h"
#include "start.h"

void CREATEGAME(List *game)
{
    char *nama_game;
    scanf("%s", &nama_game);
    game->A[game->neff] = nama_game;
    game->neff += 1;
}