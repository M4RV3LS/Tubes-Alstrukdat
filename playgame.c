#include <stdio.h>
#include "playgame.h"
#include "queuegame.h"
#include "RNG.h"
#include "queue.h"

void PLAY(Queue *queuegame)
{
    ElType A;
    if (isEmpty(*queuegame))
    {
        queuegame(); // nunggu queuegame
    }

    else
    {
        if (queuegame->buffer[0] == "RNG")
        {
            printf("Loading %s ...", queuegame->buffer[0]);
            dequeue(queuegame, &A);
            gameRNG();
        } 

        else if (queuegame->buffer[0] == "Dinner DASH")
        {
            printf("Loading %s ...", queuegame->buffer[0]);
            dequeue(queuegame, &A);
            dinnerdash(); //nunggu fungsi game dinner dash
        }

        else
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", queuegame->A[0]);
        }

    }
    