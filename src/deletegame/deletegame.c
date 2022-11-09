#include <stdio.h>
#include <stdlib.h>
#include "deletegame.h"


void DELETE(ArrayDin *ListGames, Queue *q1)
{
    int nomor_game;
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();
    nomor_game = WordToInt(currentCMD);
    int panjang = LengthKalimat(ListGames->A[nomor_game-1]);
    char *nama_game = (char*) malloc ( panjang * sizeof(char));    

    int i = 0;
    while (i < panjang)
    {
        nama_game[i] = ListGames->A[nomor_game-1][i];
        i++;
    }
    printf("%s\n", nama_game);

    if (nomor_game > 5 && !isMember(*q1,nama_game) )
    {
        int j = ListGames->Neff;
        int i = nomor_game-1;
        
        while (i < j)
        {
            ListGames->A[i] = ListGames->A[i+1];
            i++;
        }
        free(ListGames->A[j]);
        
        ListGames->Neff -= 1;
        printf("Game berhasil dihapus\n");

    }
    else
    {
        printf("Game gagal dihapus\n");
    }

}


int main()
{   
    ArrayDin ListGames = CreateDynArray();
    ListGames.A[0] = "amjad";
    ListGames.A[1] = "raka";
    ListGames.A[2] = "marvel";
    ListGames.A[3] = "marvel1";
    ListGames.A[4] = "marvel2";
    ListGames.A[5] = "marvel3";
    ListGames.A[6] = "marvel4";
    ListGames.A[7] = "marvel5";
    ListGames.Neff = 8;
    Queue anjay;
    CreateQueue(&anjay);
    enqueue(&anjay, "ganteng");
    enqueue(&anjay, "cantik");
    enqueue(&anjay, "marvel4");


    DELETE(&ListGames, &anjay);

    for (int i = 0; i < ListGames.Neff;i++)
    {
        printf("%i. %s\n", i+1, ListGames.A[i]);

    }
    printf("mampus lu anjeng\n");
}
