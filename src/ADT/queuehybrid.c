#include <stdio.h>
#include "queuehybrid.h"

void CreateQueue(Queue *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
    q->Neff = 0;
}

boolean isEmpty(Queue q)
{
    return length(q)==0;
}

boolean isFull(Queue q)
{
    return IDX_TAIL(q)==CAPACITY-1;
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
        salinWord(&TAIL(*q).ID,val.ID);
        q->Neff++;
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
        val->Durasi = HEAD(*q).Durasi;
        val->Harga = HEAD(*q).Harga;
        val->Tahan = HEAD(*q).Tahan;
        salinWord(&val->ID,HEAD(*q).ID);
        if (IDX_HEAD(*q) == IDX_TAIL(*q))
        {
            IDX_HEAD(*q) = IDX_UNDEF;
            IDX_TAIL(*q) = IDX_UNDEF;
            q->Neff--;
        }
        else
        {
            int i;
            while (i<(q->Neff)-1)
            {
                q->buffer[i] = q->buffer[i+1];
                i++;
            }
            q->Neff--;
            IDX_TAIL(*q)--;
        }
    }
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
        if (wordWordEq(q.buffer[i].ID,w))
        {
            found = true;
        }
        i++;
    }
    return found;
}

void DeleteAt(Queue *q, int i, Food *f)
{
	int length = q->Neff;
    f->Durasi = q->buffer[i].Durasi;
    f->Harga = q->buffer[i].Harga;
    f->Tahan = q->buffer[i].Tahan;
    salinWord(&f->ID,q->buffer[i].ID);
    if (!isEmpty(*q)){
        for (int a = i; a <length-1; a++) {
            q->buffer[a] = q->buffer[a + 1];
        }
        IDX_TAIL(*q)--;
        q->Neff--;
    }
}

int findBuffer(Word code,Queue q)
{
    int i = 0;
    boolean found = false;
    while (i<length(q) && !found)
    {
        if (wordWordEq(code,q.buffer[i].ID))
        {
            found = true;
        } else {
            i++;
        }
    }
    return i;
}

/*int main()
{
    Queue q;
    Food f;
    CreateQueue(&q);
    f.Durasi = 2;
    f.Tahan = 3;
    f.Harga = 15000;
    STARTCOMMAND();
    f.ID = currentCmd;
    printf("%d\n", f.ID.Length);
    return 0;

    STARTCOMMAND();
    printWord(getCommand(currentCmd));
    printf("\n");
    printWord(getLabel(currentCmd));
    printf("\n");

    Queue q;
    CreateQueue(&q);
    Food f1,f2,f3,f4,f5;

    f1.Durasi = 2;
    f1.Tahan = 3;
    f1.Harga = 15000;

    f2.Durasi = 2;
    f2.Tahan = 3;
    f2.Harga = 15000;

    f3.Durasi = 2;
    f3.Tahan = 3;
    f3.Harga = 15000;

    f4.Durasi = 2;
    f4.Tahan = 3;
    f4.Harga = 15000;

    f5.Durasi = 2;
    f5.Tahan = 3;
    f5.Harga = 15000;

    STARTCOMMAND();
    f1.ID = currentCmd;
    STARTCOMMAND();
    f2.ID = currentCmd;
    STARTCOMMAND();
    f3.ID = currentCmd;
    STARTCOMMAND();
    f4.ID = currentCmd;
    STARTCOMMAND();
    f5.ID = currentCmd;

    printWord(f1.ID);
    printf("%d %d %d\n", f1.Durasi,f1.Harga,f1.Tahan);

    printWord(f2.ID);
    printf("%d %d %d\n", f2.Durasi,f2.Harga,f2.Tahan);

    printWord(f3.ID);
    printf("%d %d %d\n", f3.Durasi,f3.Harga,f3.Tahan);

    printWord(f4.ID);
    printf("%d %d %d\n", f4.Durasi,f4.Harga,f4.Tahan);

    printWord(f5.ID);
    printf("%d %d %d\n", f5.Durasi,f5.Harga,f5.Tahan);

    enqueue(&q,f1);
    enqueue(&q,f2);
    enqueue(&q,f3);
    enqueue(&q,f4);
    enqueue(&q,f5);

    dequeue(&q,&f1);
    dequeue(&q,&f2);

    printWord(f1.ID);
    printf("%d %d %d\n", f1.Durasi,f1.Harga,f1.Tahan);

    printWord(f2.ID);
    printf("%d %d %d\n", f2.Durasi,f2.Harga,f2.Tahan);

    DeleteAt(&q,1,&f3);
    printWord(f3.ID);
    printf("%d %d %d\n", f3.Durasi,f3.Harga,f3.Tahan);

    DisplayPesanan(q);
}*/