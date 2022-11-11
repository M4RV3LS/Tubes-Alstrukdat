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
    return IDX_TAIL(q)==CAPACITY-1
}

boolean isMember(Queue q, Word w)
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
        Word a = q.buffer[i].ID
        if (wordAndWordSama(a,w))
        {
            found = true;
        }
        i++;
    }
    return found;
}

int length(Queue q)
{
    return q.Neff;
}

void enqueue(Queue *q, ElType val)
{
    if (isFull(*q))
    {
        printf("Queue is full!\n");
    }
    else
    {
        if (isEmpty(*q))
        {
            IDX_HEAD(*q)++;
        }
        IDX_TAIL(*q)++;
        TAIL(*q).Durasi = val.Durasi;
        TAIL(*q).Harga = val.Harga;
        TAIL(*q).Tahan = val.Tahan;
        salinword(val.ID,&(TAIL(*q).ID));
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
        salinword(HEAD(*q).ID,val.ID);
        if (IDX_HEAD(*q) == IDX_TAIL(*q))
        {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
        }
        else
        {
            int i;
            while (i<(q->Neff)-1)
            {
                q.buffer[i] = q.buffer[i+1];
                i++;
            }
            q->Neff--;
            IDX_TAIL(*q)--;
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

void DeleteAt(Queue *q, int i, Food *f)
{
	int length = length(*q);
    f->Durasi = q->buffer[i].Durasi;
    f->Harga = q->buffer[i].Harga;
    f->Tahan = q->buffer[i].Tahan;
    salinword(q->buffer[i].ID,&(f->ID));
    if (!isEmpty(*q)){
        for (int a = i; a <length-1; a++) {
            q->buffer[a] = q->buffer[a + 1];
        }
        IDX_TAIL(*q)--;
        q->Neff--;
    }
}
