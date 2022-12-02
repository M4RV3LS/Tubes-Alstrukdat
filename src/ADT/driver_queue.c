#include "queue.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
    Queue Q;
    CreateQueue(&Q);

    if(isEmpty(Q)){
        printf("Queue kosong\n");
    }
    else{
        printf("Queue tidak kosong\n");
    }
    if(isFull(Q)){
        printf("Queue penuh\n");
    }
    else{
        printf("Queue tidak penuh\n");
    }

    enqueue(&q,"Test1");
    enqueue(&q,"Test2");
    enqueue(&q,"Test3");

    printf("Elemen Head Adalah %s\n",HEAD(Q));
    printf("Elemen Tail Adalah%s\n",TAIL(Q));
    printf("Jumlah elemen queue sekarang adalah %d\n", length(Q));

    printf("Display Queue : \n");
    displayQueue(Q);

    char*string;
    dequeue(&Q , string);
    printf("String yang dideque adalah %s\n",string);
    printf("Elemen Head Adalah %s\n",HEAD(Q));
    printf("Elemen Tail Adalah%s\n",TAIL(Q));
    printf("Jumlah elemen queue sekarang adalah %d\n", length(Q));
    printf("Display Queue : \n");
    displayQueue(Q);

    if(isMember(Q, "Test2")){
        printf("Test2 ada di dalam queue\n");
    }
    else{
        printf("Test2 tidak ada di dalam queue\n");
    }
    return 0;
}