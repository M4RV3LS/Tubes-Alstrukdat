#include "start.h"
#include <stdio.h>
#include <stdlib.h>

static FILE *pita;
static int retval;



void STARTGAME(List *game)
{
    printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n");
    START();
    int i = (GetCC() - '0');


    game->neff = i;
    ADVGAME();
    for (int y = 0; y < game->neff; y++)
    {
        ADVGAME();
        COPYSENTENCE();
        game->A[y] = currentWord.TabWord;

    }

    /* hasil dari create game :
    list of list, contoh langsung dari file savefile.txt
    game->A[i-1] = {"RNG", "Diner DASH", "DINASAUR IN EARTH", "RISEWOMAN", "EIFFEL TOWER"}
    */
}

void ADVGAME()
{
    retval = fscanf(pita, "%c", &currentChar);
}

void COPYSENTENCE()
{
    currentWord.Length = 0;
    while (currentChar != MARK) // Mark nya backslash atau enter ( \n )
    {
        if (currentWord.Length < NMax)
        { // jika lebih akan terpotong
            currentWord.TabWord[currentWord.Length++] = currentChar;
            ADV();
        }
        else
            break;
    }
}

