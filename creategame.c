#include <stdio.h>
#include "creategame.h"
#include "start.h"

void CREATEGAME(List *game)
{
    STARTWORD();
    game->A[game->neff] = currentWord.TabWord;
    game->neff += 1;
}