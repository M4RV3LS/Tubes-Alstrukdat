#include "towerofhanoi.h"

void scoring(int steps, int* score)
{
    int a = 10;
    if (steps>31)
    {
        steps-=31;
        while (steps>0)
        {
            steps-=3;
            a--;
        }
    }

    if (a<0)
    {
        a=0;
    }
    
    *score = a;
}

void cekValiditas(char tow1, char tow2, StackSS a, StackSS b, StackSS c, boolean *valid)
{
    if ((tow1=='A' || tow1=='B' || tow1=='C') && (tow2=='A' || tow2=='B' || tow2=='C'))
    {
        if (tow1!=tow2)
        {
            if (tow1=='A')
            {
                if (IsEmptySS(a))
                {
                    printf("Tower A kosong!\n");
                } else {
                    if (tow2=='B')
                    {
                        if (IsEmptySS(b))
                        {
                            *valid = true;
                        } else {
                            if (InfoTop(a).size<InfoTop(b).size)
                            {
                                *valid = true;
                            } else {
                                printf("Ukuran disk harus lebih kecil dari disk teratas tower B!\n");
                            }
                        }
                    } else { //tow2=='C
                        if (IsEmptySS(c))
                        {
                            *valid = true;
                        } else {
                        if (InfoTop(a).size<InfoTop(c).size)
                        {
                            *valid = true;
                        } else {
                            printf("Ukuran disk harus lebih kecil dari disk teratas tower C!\n");
                        }
                        }
                    }
                }
            } else if (tow1=='B') {
                if (IsEmptySS(b))
                {
                    printf("Tower B kosong!\n");
                } else {
                    if (tow2=='A')
                    {
                        if (IsEmptySS(a))
                        {
                            *valid = true;
                        } else {
                        if (InfoTop(b).size<InfoTop(a).size)
                        {
                            *valid = true;
                        } else {
                            printf("Ukuran disk harus lebih kecil dari disk teratas tower A!\n");
                        }
                        }
                    } else { //tow2=='C'
                        if (IsEmptySS(c))
                        {
                            *valid = true;
                        } else {
                        if (InfoTop(b).size<InfoTop(c).size)
                        {
                            *valid = true;
                        } else {
                            printf("Ukuran disk harus lebih kecil dari disk teratas tower C!\n");
                        }
                        }
                    }
                }
            } else { //tow1=='C
                if (IsEmptySS(c))
                {
                    printf("Tower C kosong!\n");
                } else {
                    if (tow2=='B')
                    {
                        if (IsEmptySS(b))
                        {
                            *valid = true;
                        } else {
                        if (InfoTop(c).size<InfoTop(b).size)
                        {
                            *valid = true;
                        } else {
                            printf("Ukuran disk harus lebih kecil dari disk teratas tower B!\n");
                        }
                        }
                    } else { //tow2=='A'
                        if (IsEmptySS(a))
                        {
                            *valid = true;
                        } else {
                        if (InfoTop(c).size<InfoTop(a).size)
                        {
                            *valid = true;
                        } else {
                            printf("Ukuran disk harus lebih kecil dari disk teratas tower A!\n");
                        }
                        }
                    }
                }
            }
        } else {
            printf("Tower asal tidak boleh sama dengan tower tujuan!\n");
        }
    } else {
        printf("Perintah tidak valid\n");
    } 
}

boolean win(StackSS c)
{
    // Create winning tower
    StackSS w;
    CreateEmptySS(&w);
    PushSS(&w,"*********", 5);
    PushSS(&w," ******* ", 4);
    PushSS(&w,"  *****  ", 3);
    PushSS(&w,"   ***   ", 2);
    PushSS(&w,"    *    ", 1);

    // Compare two towers
    int j = 0;
    boolean found = false;
    while (j<Maksimal && !found)
    {
        if (!diskComp(c.T[j],w.T[j]))
        {
            found = true;
        } else {
            j++;
        }
    }

    return !found;
}

void displaystacks(StackSS a, StackSS b, StackSS c)
{
    int i = Maksimal-1;

    //Display konten tower
    while (i>=0)
    {
        printf("%s",a.T[i].sym);
        printf("   ");
        printf("%s",b.T[i].sym);
        printf("   ");
        printf("%s\n",c.T[i].sym);
        i--;
    }

    //Display base
    printf("---------   ");
    printf("---------   ");
    printf("---------\n");

    printf("    A      ");
    printf("     B      ");
    printf("     C    \n");
}

void towerofhanoi(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)
{
    // Kamus
    int countsteps = 0;
    int skor = 0;

    // Menciptakan "towers"
    StackSS a;
    StackSS b;
    StackSS c;
    CreateEmptySS(&a);
    CreateEmptySS(&b);
    CreateEmptySS(&c);

    // Setting initial state tower a
    PushSS(&a,"*********", 5);
    PushSS(&a," ******* ", 4);
    PushSS(&a,"  *****  ", 3);
    PushSS(&a,"   ***   ", 2);
    PushSS(&a,"    *    ", 1);

    //Setting initial state tower b dan c
    int i = 0;
    while (i<MaxEl)
    {
        b.T[i].sym = "    |    ";
        b.T[i].size = 6;
        c.T[i].sym = "    |    ";
        c.T[i].size = 6;
        i++;
    }

    //Welcome page
    printf("\n");
    printf("Welcome to tower of hanoi!\n");
    displaystacks(a,b,c);

    //Looping game
    boolean finished = false;
    while (!finished)
    {
        boolean valid = false;
        char tow1,tow2;
        while (!valid)
        {
            printf("\n");
            printf("TOWER ASAL: ");
            STARTCMD();
            printf("\n");
            tow1 = CURRENTCOMMAND.TabKata[0];

            printf("TOWER TUJUAN: ");
            STARTCMD();
            printf("\n");
            tow2 = CURRENTCOMMAND.TabKata[0];

            cekValiditas(tow1,tow2,a,b,c,&valid);
        }

        //menambah jumlah steps yang diambil
        countsteps++;
        //perintah sudah valid
        Disk temp;
        if (tow1=='A')
        {
            PopSS(&a,&temp);
        } else if (tow1=='B') {
            PopSS(&b,&temp);
        } else { //tow1=='C'
            PopSS(&c,&temp);
        }

        if (tow2=='A')
        {
            printf("\n");
            printf("Memindahkan Disk ke tower A..\n");
            printf("\n");
            PushSS(&a,temp.sym,temp.size);
        } else if (tow2=='B') {
            printf("\n");
            printf("Memindahkan Disk ke tower B..\n");
            printf("\n");
            PushSS(&b,temp.sym,temp.size);
        } else { //tow2=='C'
            printf("\n");
            printf("Memindahkan Disk ke tower C..\n");
            printf("\n");
            PushSS(&c,temp.sym,temp.size);
        }

        displaystacks(a,b,c);

        if (win(c))
        {
            finished = true;
        }
    }

    //Menampilkan Invalidai
    scoring(countsteps,&skor);
    printf("Kamu berhasil!\n");
    printf("Skor didapatkan: %d", skor);
    score = skor;
    Username(game , ListGames , GameMap , score);
}

// int main()
// {
//     towerofhanoi();
//     return 0;
// }