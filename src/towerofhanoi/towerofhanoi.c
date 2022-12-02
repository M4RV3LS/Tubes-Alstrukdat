#include "towerofhanoi.h"

void createDisk(int i,int jml_pir, Disk* a)
{
    int width = jml_pir*2-1;
    int border = (width-(i*2-1))/2;
    int ctr;
    for (ctr=0;ctr<width;ctr++)
    {
        if (ctr>=border && ctr<width-border)
        {
            a->sym[ctr] = '*';
        } else {
            a->sym[ctr] = ' ';
        }
    }
    a->size = i;
}

void createStick(int jml_pir, Disk *a)
{
    int width = jml_pir*2-1;
    int ctr;
    for (ctr=0;ctr<width;ctr++)
    {
        if (ctr==jml_pir-1)
        {
            a->sym[ctr] = '|';
        } else {
            a->sym[ctr] = ' ';
        }
    }
    a->size = 6;
}

void scoring(int steps, int* score, int jml_disk)
{
    int ms = pow(2,jml_disk)-1 ;//minimum steps
    int a = jml_disk*2;
    if (steps>ms)
    {
        steps-=ms;
        while (steps>0)
        {
            steps--;
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

boolean win(STACKSS c, int jml_pir)
{
    // Create winning tower
    int x = jml_pir;
    STACKSS w;
    CreateEmptySS(&w);
    Disk tempp;
    while (x>0)
    {
        tempp.sym = (char *) malloc (MaxEl*sizeof(char));
        createDisk(x,jml_pir,&tempp);
        PushSS(&w,tempp.sym,tempp.size);
        x--;
    }

    // Compare two towers
    int j = 0;
    boolean found = false;
    while (j<jml_pir && !found)
    {
        if (!diskComp(c.T[j],w.T[j]))
        {
            found = true;
        } else {
            j++;
        }
    }
    free(tempp.sym);

    return !found;
}

void displaystacks(STACKSS a, STACKSS b, STACKSS c, int jml_pir)
{
    int i = jml_pir-1;

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
    int outer = 0;
    while (outer<3)
    {
        int pr = 0;
        while (pr<(jml_pir*2)-1)
        {
            printf("-");
            pr++;
        }
        printf("   ");
        outer++;
    }
    printf("\n");

    int width1 = jml_pir*2-1;
    //Display tower names
    //Print A
    int letter_a;
    for (letter_a=0;letter_a<width1;letter_a++)
    {
        if (letter_a == jml_pir-1)
        {
            printf("A");
        } else {
            printf(" ");
        }
    }
    printf("   ");

    //Print B
    int letter_b;
    for (letter_b=0;letter_b<width1;letter_b++)
    {
        if (letter_b == jml_pir-1)
        {
            printf("B");
        } else {
            printf(" ");
        }
    }
    printf("   ");

    //Print C
    int letter_c;
    for (letter_c=0;letter_c<width1;letter_c++)
    {
        if (letter_c == jml_pir-1)
        {
            printf("C");
        } else {
            printf(" ");
        }
    }
    printf("   \n");
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

    //Welcome page
    printf("\n");
    printf("**************************************** K E L O M P O K   9   P U N Y A ****************************************\n");
    printf("   ████████╗ ██████╗ ██╗    ██╗███████╗██████╗      ██████╗ ███████╗    ██╗  ██╗ █████╗ ███╗   ██╗ ██████╗ ██╗\n");
    printf("   ╚══██╔══╝██╔═══██╗██║    ██║██╔════╝██╔══██╗    ██╔═══██╗██╔════╝    ██║  ██║██╔══██╗████╗  ██║██╔═══██╗██║\n");
    printf("      ██║   ██║   ██║██║ █╗ ██║█████╗  ██████╔╝    ██║   ██║█████╗      ███████║███████║██╔██╗ ██║██║   ██║██║\n");
    printf("      ██║   ██║   ██║██║███╗██║██╔══╝  ██╔══██╗    ██║   ██║██╔══╝      ██╔══██║██╔══██║██║╚██╗██║██║   ██║██║\n");
    printf("      ██║   ╚██████╔╝╚███╔███╔╝███████╗██║  ██║    ╚██████╔╝██║         ██║  ██║██║  ██║██║ ╚████║╚██████╔╝██║\n");
    printf("      ╚═╝    ╚═════╝  ╚══╝╚══╝ ╚══════╝╚═╝  ╚═╝     ╚═════╝ ╚═╝         ╚═╝  ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝\n");
    printf("*****************************************************************************************************************\n");

    printf("\n");
    boolean lanjut = false;
    do
    {
        printf("Ketik 'START' dengan huruf kapital untuk bermain!\n");
        STARTCMD();
        if (wordStringEq(CURRENTCOMMAND,"START"))
        {
            lanjut = true;
        }
    } while (!lanjut);
    printf("\n");

    // Print how to play
    printf("Hore! Mari kita bermain tower of hanoi ๑(◕‿◕)๑\n");
    printf("Sebelumnya, apakah kamu pernah bermain tower of hanoi? (✌ﾟ∀ﾟ)☞ \n");
    boolean htp = false;
    do
    {
        printf("Ketik (Y/N)\n");
        STARTCMD();
        if (wordStringEq(CURRENTCOMMAND,"Y") || wordStringEq(CURRENTCOMMAND,"N"))
        {
            htp = true;
        }
    } while (!htp);

    if (wordStringEq(CURRENTCOMMAND,"Y"))
    {
        printf("\n");
        printf("Baiklah, mari kita langsung bermain!");
        printf("\n");
    } else {
        printf("\n");
        printf("Baiklah, berikut adalah HOW TO PLAY tower of hanoi! ( ๑‾̀◡‾́)o\n");
        printf("\n");
        printf("1. Akan terdapat 3 tower, ABC. Tower A akan terisi penuh dengan piringan.\n");
        printf("2. Tower B dan C kosong. Tujuanmu adalah memindahkan seluruh piringan dari Tower A ke C.\n");
        printf("3. Kamu hanya bisa memindahkan piringan ke tower kosong atau yang piringan teratasnya ukurannya\n");
        printf("   lebih besar dari piringan yang mau dipindahkan.\n");
        printf("4. Input untuk tower harus berupa huruf kapital A,B, atau C.\n");
        printf("\n");
        printf("Selamat bermain!\n");
    }

                                                                                                           
    // Menentukan tinggi tower
    boolean valid1 = false;
    int jml_disk;
    while (!valid1)
    {
        printf("\n");
        printf("Masukkan jumlah piringan yang diinginkan ᕙ(⇀‸↼‶)ᕗ: ");
        STARTCMD();
        printf("\n");
        jml_disk = KataToInt(CURRENTCOMMAND);
        if (jml_disk>0 && jml_disk<=20)
        {
            valid1 = true;
        } else {
            printf("Piringan terlalu banyak!\n");
        }
    }

    // Setting initial state tower a
    int x = jml_disk;
    Disk tempd;
    while (x>0)
    {
        tempd.sym = (char *) malloc (MaxEl*sizeof(char));
        createDisk(x,jml_disk,&tempd);
        PushSS(&a,tempd.sym,tempd.size);
        x--;
    }

    //Setting initial state tower b dan c
    int i = 0;
    Disk tempst;
    tempst.sym = (char *) malloc (MaxEl*sizeof(char));
    createStick(jml_disk,&tempst);
    while (i<jml_disk)
    {
        b.T[i].sym = tempst.sym;
        b.T[i].size = tempst.size;
        c.T[i].sym = tempst.sym;
        c.T[i].size = tempst.size;
        i++;
    }

    displaystacks(a,b,c,jml_disk);

    //Looping game
    boolean finished = false;
    while (!finished)
    {
        boolean valid = false;
        char tow1,tow2;
        Kata tow1ch, tow2ch;
        while (!valid)
        {
            printf("\n");
            printf("TOWER ASAL: ");
            STARTCMD();
            printf("\n");
            tow1ch = CURRENTCOMMAND;
            tow1 = CURRENTCOMMAND.TabKata[0];

            printf("TOWER TUJUAN: ");
            STARTCMD();
            printf("\n");
            tow2ch = CURRENTCOMMAND;
            tow2 = CURRENTCOMMAND.TabKata[0];

            if (tow1ch.Length>1 || tow2ch.Length>1)
            {
                printf("Perintah tidak valid!\n");
            } else {
                cekValiditas(tow1,tow2,a,b,c,&valid);
            }
        }

        //menambah jumlah steps yang diambil
        countsteps++;
        //perintah sudah valid
        Disk temp;
        if (tow1=='A')
        {
            PopSS(&a,&temp,jml_disk,tempsti);
        } else if (tow1=='B') {
            PopSS(&b,&temp,jml_disk,tempsti);
        } else { //tow1=='C'
            PopSS(&c,&temp,jml_disk,tempsti);
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

        displaystacks(a,b,c,jml_disk);

        if (win(c,jml_disk))
        {
            finished = true;
        }
    }

    //Menampilkan Invalidai
    scoring(countsteps,&skor);
    printf("Kamu berhasil!\n");
    printf("Skor didapatkan: %d\n", skor);
    score = skor;
    Username(game , ListGames , GameMap , score);
    
    free(tempd.sym);
    free(tempst.sym);
    free(tempsti);
}
