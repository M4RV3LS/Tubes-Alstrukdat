#include <stdio.h>
#include "queue.h"

int main()
{
    Queue Pesanan , Time;
    CreateQueue(&Pesanan);
    CreateQueue(&Time);
    int i = 0 ;
    int Count_Pesanan = 0;
    int minimal = 0;
    int maksimal = 0;
    int temp_aksi , temp_Time , temp_Time_2;
    boolean awal = true;
    scanf("%d",&temp_aksi);
	while (temp_aksi != 0)
    {
        if (temp_aksi == 1)
        {
            scanf(" %d",&temp_Time);
            // printf("\ntemp Time = %d\n", temp_Time);
            if ((awal) && (temp_Time > 0))
			{
				maksimal = temp_Time;
				minimal = temp_Time;
                enqueue(&Time, temp_Time);
                enqueue(&Pesanan, 1);
                awal = false;
                // printf("\nBoolean awal = %d\n",awal);
			}
            else if (temp_Time > 0)
            {
                enqueue(&Time, temp_Time);
                enqueue(&Pesanan, 1);
            }
            // displayQueue(Time);
            // printf("\n");
        }
        else if (temp_aksi == 2)
        {
            if (!isEmpty(Pesanan))
            {
                dequeue(&Pesanan, &temp_aksi);
                Count_Pesanan += temp_aksi;
                dequeue(&Time, &temp_Time_2);
                // printf("\ntemp_Time_2 = %d\n", temp_Time_2);
                if (temp_Time_2 >= maksimal)
                {
                    maksimal = temp_Time_2;
                }
                else if (temp_Time_2 <= minimal)
                {
                    minimal = temp_Time_2;
                }
                // printf("\nMinimal = %d , Maksimal = %d\n",minimal,maksimal);
            }
            // displayQueue(Time);
            // printf("\n");
        }
        scanf("%d",&temp_aksi);
    }
    if (Count_Pesanan == 0)
    {
        minimal = 0;
        maksimal = 0;
    }
    if (Count_Pesanan == 1)
    {
        minimal = temp_Time_2;
        maksimal = temp_Time_2;
    }
    printf("%d\n",Count_Pesanan);
	printf("%d\n",minimal);
	printf("%d\n",maksimal);
	return 0;
}