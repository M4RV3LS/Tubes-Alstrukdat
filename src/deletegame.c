#include <stdio.h>
#include <stdlib.h>
#include "start.h"
#include "mesinkar2.h"
#include "mesinkata2.h"
#include "arrayOfString.h"

void DELETE(ArrayDin *ListGames)
{
    int nomor_game;
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();
    nomor_game = (currentCMD.TabWord[0] - '0');

    if (nomor_game > 5)
    {
        int j = ListGames->Neff;
        int i = nomor_game-1;
        
        while (i < j)
        {
            ListGames->A[i] = ListGames->A[i+1];
            free(ListGames->A[i+1]);
            i++;
        }
        
        ListGames->Neff -= 1;
        printf("Game berhasil dihapus");

    }
    else
    {
        printf("Game gagal dihapus");
    }

}

int main()
{   
    ArrayDin ListGames;
    DELETE(&ListGames);
}