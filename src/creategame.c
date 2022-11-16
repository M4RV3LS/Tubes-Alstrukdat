#include <stdio.h>
#include "creategame.h"

void CREATEGAME(ArrayDin *ListGames)
{
    printf("Masukkan nama game yang akan ditambahkan : ");
    STARTCOMMANDGAME();
    char string[1000];
    char *gamename = (char*) malloc (currentCMD.Length * sizeof(char));
    // char * gamename;
    int j = 0;
    //
    wordToString(currentCMD , string);
    //printf("%s\n",string);

    while (j <= currentCMD.Length)
    {
        gamename[j] = string[j];
        j++;
    }
        //gamename[j] = '\0';
        //InsertIn(string , ListGames , i);

    boolean found = false;
    for (int i = 0; i < ListGames->Neff; i++)
    {
        if (CompareString(gamename, ListGames->A[i]))
        {
            found = true;
            printf("Game sudah ada di dalam list game.\n");
        }
        
    }
    if (!found)
    {
        InsertLast(ListGames, gamename);
        printf("Game berhasil ditambahkan.\n");
    }
}


