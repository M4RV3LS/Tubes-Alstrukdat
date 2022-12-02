#include <stdio.h>
#include "queuehybrid.h"

int main()
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
}
