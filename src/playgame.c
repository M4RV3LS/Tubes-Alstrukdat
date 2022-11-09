#include <stdio.h>
#include <stdlib.h>
#include "playgame.h"


void PLAYGAME(Queue *q1)
{
    ElType A;
    char *rng, *dinner;
    rng = "RNG";
    dinner = "Dinner DASH";

    if (isEmpty(*q1))
    {
        printf("Antrian game kosong.\n");
    }

    else
    {
        if (HEAD(*q1) == rng)
        {
            printf("Loading %s ...", rng);
            dequeue(q1, &A);
            gameRNG();
        } 

        else if(HEAD(*q1) == "DINOSAUR IN EARTH")
        {
            printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");
        }

        else if(HEAD(*q1) == "RISEWOMAN")
        {
            printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");

        }

        else if(HEAD(*q1) == "EIFFEL TOWER")
        {
            printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");

        }


        /*else if (HEAD(*q1) == Diner DASH)
        {
            printf("Loading %s ...", dinner);
            dequeue(q1, &A);
            dinnerdash(); //nunggu fungsi game dinner dash
        }*/


        else
        {
            srand(time(NULL));
            int random = rand();
            printf("%d\n",random);
        }

    }
}   
/*
int main()
{
    Queue q;
    CreateQueue(&q);
    enqueue(&q, "RNG");
    PLAYGAME(&q);

    return 0;

}
*/