#include <stdio.h>
#include "skipgame.h"

void SKIPGAME(Queue *q, int n)
{
    printf("Berikut adalah daftar game-mu.\n");
    int i;
    for (i = 0; i < length(*q1); i++){
        printf("%d. %s\n",i+1, q1->buffer[i]);
    }

    ElType x;
    if (n<length(*q)) // valid, jumlah game yang di skip ada di range antiran
    {
        int i = 0;
        while (i<n)
        {
            dequeue(q,&x);
        }
        PLAYGAME(q);
    } else { // 
        while(!IsEmpty(*q))
        {
            dequeue(q,&x);
        } // seluruh game di skip
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
}
