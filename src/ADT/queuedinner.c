#include <stdio.h>
#include "queuedinner.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
}

boolean isEmpty(Queue q)
{
    return IDX_HEAD(q) == IDX_UNDEF && IDX_TAIL(q) == IDX_UNDEF;
}

boolean isFull(Queue q)
{
    return IDX_HEAD(q) == (IDX_TAIL(q) + 1) % CAPACITY;
}

int length(Queue q)
{
    if (isEmpty(q))
    {
        return 0;
    }
    else
    {
        return (IDX_TAIL(q) - IDX_HEAD(q) + CAPACITY) % CAPACITY + 1;
    }
}

void enqueue(Queue *q,  val)
{
    if (isFull(*q))
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (isEmpty(*q))
        {
            IDX_HEAD(*q) = 0;
        }
        IDX_TAIL(*q) = (IDX_TAIL(*q) + 1) % CAPACITY;
        TAIL(*q).Durasi = val.Durasi;
        TAIL(*q).Harga = val.Harga;
        TAIL(*q).Tahan = val.Tahan;
        copystr(val.ID,TAIL(*q).ID);
    }
}

void dequeue(Queue *q, ElType *val)
{
    if (isEmpty(*q))
    {
        printf("Queue is empty!\n");
    }
    else
    {
        *val.Durasi = HEAD(*q).Durasi;
        *val.Harga = HEAD(*q).Harga;
        *val.Tahan = HEAD(*q).Tahan;
        copystr(HEAD(*q).ID,*val.ID);
        if (IDX_HEAD(*q) == IDX_TAIL(*q))
        {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        }
        else
        {
            IDX_HEAD(*q) = (IDX_HEAD(*q) + 1) % CAPACITY;
        }
    }
}

boolean isMember(Queue q, ElType f)
{
    boolean found = false;
    boolean same = false;
    int i = IDX_HEAD(q);
    if (isEmpty(q))
    {
        return found;
    }
    while (i <= IDX_TAIL(q) && !found)
    {
        Word a = stringToWord(q.buffer[i].ID);
        Word b = stringToWord(f.ID);
        if (wordAndWordSama(a,b))
        {
            found = true;
        }
        i++;
    }
    return found;
}