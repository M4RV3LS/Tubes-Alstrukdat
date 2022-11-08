#include <stdio.h>
#include <stdlib.h>
#include "queuegame.h"


void QUEUEGAME(Queue *q1, ArrayDin *game){
    //List *game;

    printf("Berikut adalah daftar antrian game-mu.\n");
    for (int i = IDX_HEAD(*q1); i < IDX_HEAD(*q1) + length(*q1); i++){
        printf("%d. %s\n",i+1, q1->buffer[i]);
    }

    LISTGAME(game);


    Queue q;
    printf("Nomor Game yang mau ditambahkan ke antrian : ");
    int nomor_game;
    CreateQueue(&q);
    STARTCOMMANDGAME();
    nomor_game = WordToInt(currentCMD);
    if (nomor_game > game->Neff){
         printf("Nomor permainan tidak valid\n");
    } else {
        char *val = game->A[nomor_game - 1];
        for (int i = 0; i< game->Neff; i++){
            enqueue(&q, game->A[i]);
        }
    enqueue(q1, val);
    printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }
}
/*
int main(){
    Queue game;
    CreateQueue(&game);
    game.buffer[0] = "Marvel";
    game.buffer[1] = "Asih";
    game.buffer[2] = "Amjad";
    game.buffer[3] = "Raka";
    IDX_HEAD(game) = 0;
    IDX_TAIL(game) = 3;
    ArrayDin listgame ;
    listgame.A[0] = "Asih";
    listgame.A[1] = "Marvel";
    listgame.A[2] = "Amjad";
    listgame.A[3] = "Raka" ;
    listgame.A[4] = "Carissa";
    listgame.Neff = 5;
    QUEUEGAME(&game , &listgame);
    QUEUEGAME(&game, &listgame);
    return 0;
    
}

*/