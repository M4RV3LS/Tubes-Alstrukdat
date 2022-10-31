#include <stdio.h>
#include "listgame.h"

void LISTGAME(List *game)
{
    int i = 0;
    printf("Berikut adalah daftar game yang tersedia\n");
    for (i; i < game->neff; i++)
    {
        printf("%i. %s\n", i+1, game->A[i]);
    }
}