#include <stdio.h>
#include "playgame.h"
#include "queuegame.h"
#include "RNG.h"
#include "queue.h"

void PLAY(Queue *queuegame)
{
    ElType A;
    char* rng, dinner;
    rng = "RNG";
    dinner = "Dinner DASH"

    if (isEmpty(*queuegame))
    {
        queuegame(); // nunggu queuegame
    }

    else
    {
        if (queuegame->buffer[0] == rng)
        {
            printf("Loading %s ...", rng);
            dequeue(queuegame, &A);
            gameRNG();
        } 

        else if (queuegame->buffer[0] == dinner)
        {
            printf("Loading %s ...", dinner);
            dequeue(queuegame, &A);
            dinnerdash(); //nunggu fungsi game dinner dash
        }

        else
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", queuegame->buffer[0]);
        }

    }
    