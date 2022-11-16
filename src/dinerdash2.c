#include "dinerdash2.h"

// Menampilkan tabel
void DisplayPesanan(QUEUEDD q)
{
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("============================================\n");
    if(!isKosong(q))
    {
        int i;
        for (i=0;i<nbElement(q);i++)
        {   Kata mk = q.buffer[i].ID;
            //wordToString(q.buffer[i].ID , *mk);
            //printf("%s\n", mk);
            int dr = q.buffer[i].Durasi;
            //printf("%d\n" , dr);
            int kt = q.buffer[i].Tahan;
            //printf("%d\n" , kt);
            int hr = q.buffer[i].Harga;
            printKata(mk);
            if (mk.Length==1)
            {
                printf("       | %d              | %d         | %d\n", dr,kt,hr);
            } else {
                printf("      | %d              | %d         | %d\n", dr,kt,hr);
            }    
        }
    } else {
        printf("        |                |           |\n");
    }
}

void DisplayMasakan(QUEUEDD q)
{
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("=============================\n");
    if(!isKosong(q))
    {
        int i;
        for (i=0;i<nbElement(q);i++)
        {
            Kata mk = q.buffer[i].ID;
            int dr = q.buffer[i].Durasi;
            printKata(mk);
            if (mk.Length==2)
            {
                printf("      | %d\n",dr);
            } else {
                printf("       | %d\n",dr);
            }
        }
    } else {
        printf("        |\n");
    }
}

void DisplaySajian(QUEUEDD q)
{
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("================================\n");
    if(!isKosong(q))
    {
        int i;
        Kata mk;
        int kt;
        for (i=0;i<nbElement(q);i++)
        {
            mk = q.buffer[i].ID;
            kt = q.buffer[i].Tahan;
            printKata(mk);
            if (mk.Length==2)
            {
                printf("      | %d\n",kt);
            } else {
                printf("       | %d\n",kt);
            }
        }
    } else {
        printf("        |\n");
    }
}

// Validasi command
boolean isValid(Kata a)
{
    return isCook(a) || isServe(a) || isSkip(a);
}

boolean isCook(Kata a)
{
    return wordStringEq(getCommand(a),"COOK");
}

boolean isServe(Kata a)
{
    return wordStringEq(getCommand(a),"SERVE");
}

boolean isSkip(Kata a)
{
    return wordStringEq(getCommand(a),"SKIP");
}

// Autogenerate pesanan
void generateFood(Food *pes,int i)
{
    pes->Durasi = randint(1,5);
    pes->Tahan = randint(1,5);
    pes->Harga = randint(10000,50000);
    
    // membuat ID / Label 
    Kata m;
    m.TabKata[0] = 'M';
    m.Length = 1;
    Kata idcode = IntToKata(i);
    joinKata(&m,idcode);
    salinKata(&pes->ID,m);
}

// Menyalin info makanan
void copyFood(Food *copy,Food f)
{
    copy->Durasi = f.Durasi;
    copy->Harga = f.Harga;
    copy->Tahan = f.Tahan;
    salinKata(&copy->ID,f.ID);
}

// Command in-game

void COOK(Kata code, QUEUEDD *Pesanan, QUEUEDD *Masakan)
// Memasak makanan yang ada di urutan paling atas di
// antrian pesanan dan memasukkannnya ke dalam antrian masakan
{
    Food f;
    copyFood(&f,Pesanan->buffer[findBuffer(code,*Pesanan)]);
    f.Durasi++;
    ENQUEUEDD(Masakan,f);

    printf("\n");
    printf("Berhasil memasak ");
    printKata(code);
    printf("\n");
}

void SERVE(QUEUEDD *Pesanan, QUEUEDD *Sajian, int *Saldo)
// Menyajikan makanan yang ada di urutan paling atas di
// antrian makanan siap saji
{
    Food saji;
    Food saji2;
    DEQUEUEDD(Pesanan,&saji);
    DEQUEUEDD(Sajian,&saji2);
    *Saldo += saji2.Harga;

    printf("\n");
    printf("Berhasil menyajikan ");
    printKata(saji2.ID);
    printf("\n");
}

int randint(int lower, int upper)
{
    int num = (rand() % (upper - lower + 1)) + lower;
    return num;
}

void dinnerdash()
{
    // Kamus
    boolean finished = false;
    int countserve = 0;
    int saldo = 0;

    // Membuat queue pesanan, masakan, sajian
    QUEUEDD pesanan;
    QUEUEDD masakan;
    QUEUEDD sajian;
    CreateQUEUEDD(&pesanan);
    CreateQUEUEDD(&masakan);
    CreateQUEUEDD(&sajian);

    //Generate pesanan awal
    int i = 0;
    Food temp;
    while (i<3)
    {
        generateFood(&temp,i);
        ENQUEUEDD(&pesanan,temp);
        i++;
    }

    printf("==============================WELCOME TO===========================\n");
    printf("=================== K E L O M P O K = 9 = P U N Y A ===============\n");
	printf(" ==================================================================\n");
	printf("  ____  _____ _____ _____ _____    ____  _____ _____ _____ \n");
	printf(" |    \\|     |   | |   __| __  |  |    \\|  _  |   __|  |  |\n");
	printf(" |  |  |-   -| | | |   __|    -|  |  |  |     |__   |     |\n");
	printf(" |____/|_____|_|___|_____|__|__|  |____/|__|__|_____|__|__|\n\n");

    while (!finished)
    {

        printf("\n");
        printf("=========================================\n");
        printf("\n");

        printf("SALDO: %d\n", saldo);
        printf("\n");
        DisplayPesanan(pesanan);
        printf("\n");
        DisplayMasakan(masakan);
        printf("\n");
        DisplaySajian(sajian);
        printf("\n");

        boolean valid = false;
        while(!valid)
        {
            printf("MASUKKAN CMD: ");
            STARTCMD();
            if (isValid(CURRENTCOMMAND))
            {   
                if(isCook(CURRENTCOMMAND))
                {   
                    if (isAnggota(pesanan,getLabel(CURRENTCOMMAND)))
                    {   
                        if (isAnggota(masakan,getLabel(CURRENTCOMMAND)))
                        {
                            printKata(getLabel(CURRENTCOMMAND));
                            printf(" sedang dimasak!\n");
                            printf("\n");
                        } else if (isAnggota(sajian,getLabel(CURRENTCOMMAND))) {
                            printKata(getLabel(CURRENTCOMMAND));
                            printf(" sudah bisa disajikan!\n");
                            printf("\n");
                        } else {
                            valid = true;
                        }
                    } else {
                        printKata(getLabel(CURRENTCOMMAND));
                        printf(" bukan bagian dari pesanan \n");
                        printf("\n");
                    }  
                } else if (isServe(CURRENTCOMMAND)) {
                    if (isAnggota(pesanan,getLabel(CURRENTCOMMAND)))
                    {   
                        if (isAnggota(masakan,getLabel(CURRENTCOMMAND)))
                        {
                            printKata(getLabel(CURRENTCOMMAND));
                            printf(" sedang dimasak!\n");
                            printf("\n");
                        } else if (isAnggota(sajian,getLabel(CURRENTCOMMAND))) {
                            if (wordKataEq(getLabel(CURRENTCOMMAND),HEAD(pesanan).ID))
                            {
                                valid = true;
                            } else {
                                Kata bef = HEAD(pesanan).ID;
                                Kata af = getLabel(CURRENTCOMMAND);
                                printKata(af);
                                printf(" belum dapat disajikan karena ");
                                printKata(bef);
                                printf(" belum selesai\n");
                                printf("\n");
                                printf("\n");
                            }
                        } else {
                            printKata(getLabel(CURRENTCOMMAND));
                            printf(" perlu dimasak terlebih dahulu!\n");
                            printf("\n");
                        }
                    } else {
                        printKata(getLabel(CURRENTCOMMAND));
                        printf(" bukan bagian dari pesanan \n");
                        printf("\n");
                    } 
                } else { // isSkip
                    valid = true;
                }
            } 
            else {
                printf("Perintah tidak valid!\n");
                printf("\n");
            }
        }

        // command sudah valid 

        if(isCook(CURRENTCOMMAND))
        {
            COOK(getLabel(CURRENTCOMMAND),&pesanan,&masakan);
        } else if (isServe(CURRENTCOMMAND)) {
            SERVE(&pesanan,&sajian,&saldo);
            countserve++;
        } 

        if (!isKosong(masakan))
        {
            int j;
            Food masak;
            for (j=0;j<nbElement(masakan);j++)
            {
                masakan.buffer[j].Durasi--;
                if (masakan.buffer[j].Durasi==0)
                {
                    DELETEATDD(&masakan,j,&masak);
                    masak.Tahan++;
                    ENQUEUEDD(&sajian,masak);
                    printKata(masak.ID);
                    printf(" sudah selesai dimasak\n");
                }
            }
        }

        if (!isKosong(sajian))
        {
            int k;
            Food basi;
            for (k=0;k<nbElement(sajian);k++)
            {
                sajian.buffer[k].Tahan--;
                if (sajian.buffer[k].Tahan==0)
                {
                    DEQUEUEDD(&sajian,&basi);
                    printKata(basi.ID);
                    printf(" sudah tidak dapat disajikan. Segera masak ulang\n");
                }
            }
        }

        Food temp2;
        generateFood(&temp2,i);
        ENQUEUEDD(&pesanan,temp2);
        i++;

        if (nbElement(pesanan)>7 || countserve==15)
        {
            finished = true;
        }
    }
    
    printf("\n");
    printf("====G  A  M  E  -  O  V  E  R===\n");
    if (nbElement(pesanan)>7 && countserve!=15)
    {
        printf("===============================\n");
        printf("Y O U  L O S T!\n");
        printf("Amount of guests served = %d\n", countserve);
        printf("Total profit: %d\n", saldo);
        printf("Better luck next time!\n");
        printf("===============================\n");
    } else if (nbElement(pesanan)<=7 && countserve==15) {
        printf("===============================\n");
        printf("Y O U  W I N!\n");
        printf("Amount of guests served = %d\n", countserve);
        printf("Total profit: %d\n", saldo);
        printf("Good job, Chef!\n");
        printf("===============================\n");
    } else {
        printf("===============================\n");
        printf("Y O U  W O N  A N D  L O S T!\n");
        printf("Amount of guests served = %d\n", countserve);
        printf("Total profit: %d\n", saldo);
        printf("Good job, (kinda)!\n");
        printf("===============================\n");
    }
}

