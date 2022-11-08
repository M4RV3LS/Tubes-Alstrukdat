#include <stdio.h>
#include "skipgame.h"

void SKIPGAME(Queue *q, int n)
{
    if (isEmpty(*q))
    {
        printf("Antrian game kosong.\n");
    }else
    {
    printf("Berikut adalah daftar antrian game-mu.\n");
    for (int i = IDX_HEAD(*q); i < IDX_HEAD(*q) + length(*q); i++){
        printf("%d. %s\n",i+1, q->buffer[i]);
    }
    }

    ElType x;
    if (n<length(*q)) // valid, jumlah game yang di skip ada di range antiran
    {
        int i = 0;
        while (i<n)
        {
            dequeue(q,&x);
            i++;
        }
        displayQueue(*q);
        //PLAYGAME(q);
    } 
    else { // 
        while(!isEmpty(*q))
        {
            dequeue(q,&x);
        } // seluruh game di skip
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
}

int main(){
    Queue game;
    CreateQueue(&game);
    enqueue(&game , "Marvel");
    enqueue(&game , "Amjad");
    enqueue(&game , "Asih");
    enqueue(&game , "Raka");
    IDX_HEAD(game) = 0;
    IDX_TAIL(game) = 3;
    displayQueue(game);
    SKIPGAME(&game , 2);
    return 0;
}