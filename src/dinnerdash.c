#include "dinerdash.h"
#include "mesinkata2.h"
#include "boolean.h"
#include "arraydinner.h"

//masih berantakan beut gais bntryak

void printAwal()
{
    printf("SALDO: %d\n", saldo);
    printf("\n");
    DisplayPesanan();
    printf("\n");
    DisplayMasakan();
    printf("\n");
    DisplaySajian();
    printf("\n");
}

boolean isValid(Word a)
{
    return isCook(a) || isServe(a) || isSkip(a);
}

boolean isCook(Word a)
{
    return wordAndCharSama(kataPertama(a),"COOK");
}

boolean isServe(Word a)
{
    return wordAndCharSama(kataPertama(a),"SERVE");
}

boolean isSkip(Word a)
{
    return wordAndCharSama(kataPertama(a),"SKIP");
}

boolean isFinished(int cs, int cc)
{
    return cc>7 || cs==15;
}

Food generateFood()
{
    f
}

void prosesMasakan()
{

}

void dinnerdash()
{
    // Membuat queue pesanan, masakan, sajian
    Queue pesanan;
    Queue masakan;
    Queue sajian;
    CreateEmpty(&pesanan);
    CreateEmpty(&masakan);
    CreateEmpty(&sajian);

    printf("Selamat Datang di Diner Dash!");
    boolean finished = false;
    string command;
    int countserve = 0;
    int countcus = 0;
    printAwal();

    while (!isFinished(countserve,countcus))
    {
        boolean valid = false;
        while(!valid)
        {
            printf("MASUKKAN COMMAND:");
            STARTFILE();
            if (isValid(currentWord))
            {
                if(isCook(currentWord))
                {
                    if (isIn(pesanan,kataKedua(currentWord)))
                    {
                        valid = true;
                    }
                } else if (isServe(currentWord)) {
                    if (wordAndCharSama(kataKedua(currentWord),HEAD(pesanan).ID))
                    {
                        valid = true;
                    }
                } else { // isSkip
                    valid = true;
                }
            }
        }

        // command sudah valid
        // perpindahan makanan dr masakan ke sajian BELUM
        if(isCook(currentWord))
        {
            COOK(kataKedua(currentWord),&Pesanan,&Masakan);
        } else if (isServe(currentWord)) {
            SERVE(&Pesanan,&Sajian)
        } 

        enqueue(Pesanan,generateFood());
        
        int i;
        Food masak;
        for (i=0;i<length(Masakan);i++)
        {
            Masakan.buffer[i].Durasi--;
            if (Masakan.buffer[i].Durasi==0)
            {
                dequeue(&Masakan,&masak);
                enqueue(&Sajian,masak);
            }
        }

        int j;
        Food basi;
        for (j=0;j<length(Sajian);j++)
        {
            Sajian.buffer[i].Tahan++;
            if (Sajian.buffer[i].Tahan==0)
            {
                dequeue(&Sajian,&basi);
            }
        } 
    }
}
