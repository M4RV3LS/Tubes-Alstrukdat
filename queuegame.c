#include <stdio.h>
#include "queuegame.h"


void QUEUEGAME(Queue *q1){
    List *game;

    printf("Berikut adalah daftar antrian game-mu.\n");
    for (int i = 0; i < length(*q1); i++){
        printf("%d. %c",i, q1->buffer[i]);
    }

    LISTGAME(game);

    Queue q;
    int nomor_game;
    CreateQueue(&q);
    printf("Nomor Game yang mau ditambahkan ke antrian : %d", &nomor_game);
    if (nomor_game > game->neff){
         printf("Nomor permainan tidak valid\n");
    } else {
        char val = game->A[nomor_game - 1];
        for (int i = 0; i< game->neff; i++){
            enqueue(&q, game->A[i]);
        }
    enqueue(&(*q1), val);
    printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }
}

