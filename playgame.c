#include <stdio.h>
#include "playgame.h"
#include "queuegame.h"
#include "RNG.h"
#include "queue.h"

void PLAY(Queue *q1)
{
    ElType A;
    char* rng, dinner;
    rng = "RNG";
    dinner = "Dinner DASH";

    if (isEmpty(*q1))
    {
        QUEUEGAME(*q1); // nunggu queuegame
    }

    else
    {
        if (HEAD(*q1) == rng)
        {
            printf("Loading %s ...", rng);
            dequeue(q1, &A);
            gameRNG();
        } 

        else if (HEAD(*q1) == dinner)
        {
            printf("Loading %s ...", dinner);
            dequeue(q1, &A);
            dinnerdash(); //nunggu fungsi game dinner dash
        }

        else
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", HEAD(*q1));
        }

    }
    