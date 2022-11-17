#include <stdio.h>
#include "queuehybrid.h"

void CreateQUEUEDD(QUEUEDD *q)
{
    IDX_HEAD(*q) = IDX_UNDEF;
    IDX_TAIL(*q) = IDX_UNDEF;
    q->Neff = 0;
}

boolean isKosong(QUEUEDD q)
{
    return nbElement(q)==0;
}

boolean isPenuh(QUEUEDD q)
{
    return IDX_TAIL(q)==CAPACITY-1;
}

int nbElement(QUEUEDD q)
{
    return q.Neff;
}

void ENQUEUEDD(QUEUEDD *q, FoodType val)
{
    if (isPenuh(*q))
    {
        printf("QUEUEDD is full!\n");
    }
    else
    {
        if (isKosong(*q))
        {
            IDX_HEAD(*q)++;
        }
        IDX_TAIL(*q)++;
        TAIL(*q).Durasi = val.Durasi;
        TAIL(*q).Harga = val.Harga;
        TAIL(*q).Tahan = val.Tahan;
        salinKata(&TAIL(*q).ID,val.ID);
        q->Neff++;
    }
}

void DEQUEUEDD(QUEUEDD *q, FoodType *val)
{
    if (isKosong(*q))
    {
        printf("QUEUEDD is empty!\n");
    }
    else
    {
        val->Durasi = HEAD(*q).Durasi;
        val->Harga = HEAD(*q).Harga;
        val->Tahan = HEAD(*q).Tahan;
        salinKata(&val->ID,HEAD(*q).ID);
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

boolean isAnggota(QUEUEDD q, Kata w)
{
    boolean found = false;
    boolean same = false;
    int i = IDX_HEAD(q);
    if (isKosong(q))
    {
        return found;
    }
    while (i <= IDX_TAIL(q) && !found)
    {
        if (wordKataEq(q.buffer[i].ID,w))
        {
            found = true;
        }
        i++;
    }
    return found;
}

void DELETEATDD(QUEUEDD *q, int i, Food *f)
{
	int nbElement = q->Neff;
    f->Durasi = q->buffer[i].Durasi;
    f->Harga = q->buffer[i].Harga;
    f->Tahan = q->buffer[i].Tahan;
    salinKata(&f->ID,q->buffer[i].ID);
    if (!isKosong(*q)){
        for (int a = i; a <nbElement-1; a++) {
            q->buffer[a] = q->buffer[a + 1];
        }
        IDX_TAIL(*q)--;
        q->Neff--;
    }
}

int findBuffer(Kata code,QUEUEDD q)
{
    int i = 0;
    boolean found = false;
    while (i<nbElement(q) && !found)
    {
        if (wordKataEq(code,q.buffer[i].ID))
        {
            found = true;
        } else {
            i++;
        }
    }
    return i;
}

int RANDINTDD(int lower , int upper){
    
    int random = (rand() % (upper - lower + 1)) + lower; 
    return random;
}

/*int main()
{
    QUEUEDD q;
    Food f;
    CreateQUEUEDD(&q);
    f.Durasi = 2;
    f.Tahan = 3;
    f.Harga = 15000;
    STARTCMD();
    f.ID = currentCmd;
    printf("%d\n", f.ID.Length);
    return 0;

    STARTCMD();
    printKata(getCommand(currentCmd));
    printf("\n");
    printKata(getLabel(currentCmd));
    printf("\n");

    QUEUEDD q;
    CreateQUEUEDD(&q);
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

    STARTCMD();
    f1.ID = currentCmd;
    STARTCMD();
    f2.ID = currentCmd;
    STARTCMD();
    f3.ID = currentCmd;
    STARTCMD();
    f4.ID = currentCmd;
    STARTCMD();
    f5.ID = currentCmd;

    printKata(f1.ID);
    printf("%d %d %d\n", f1.Durasi,f1.Harga,f1.Tahan);

    printKata(f2.ID);
    printf("%d %d %d\n", f2.Durasi,f2.Harga,f2.Tahan);

    printKata(f3.ID);
    printf("%d %d %d\n", f3.Durasi,f3.Harga,f3.Tahan);

    printKata(f4.ID);
    printf("%d %d %d\n", f4.Durasi,f4.Harga,f4.Tahan);

    printKata(f5.ID);
    printf("%d %d %d\n", f5.Durasi,f5.Harga,f5.Tahan);

    ENQUEUEDD(&q,f1);
    ENQUEUEDD(&q,f2);
    ENQUEUEDD(&q,f3);
    ENQUEUEDD(&q,f4);
    ENQUEUEDD(&q,f5);

    DEQUEUEDD(&q,&f1);
    DEQUEUEDD(&q,&f2);

    printKata(f1.ID);
    printf("%d %d %d\n", f1.Durasi,f1.Harga,f1.Tahan);

    printKata(f2.ID);
    printf("%d %d %d\n", f2.Durasi,f2.Harga,f2.Tahan);

    DELETEATDD(&q,1,&f3);
    printKata(f3.ID);
    printf("%d %d %d\n", f3.Durasi,f3.Harga,f3.Tahan);

    DisplayPesanan(q);
}*/