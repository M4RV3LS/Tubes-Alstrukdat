#include "dinerdash2.h"

// Menampilkan tabel
void DisplayPesanan(Queue q)
{
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("============================================\n");
    if(!isEmpty(q))
    {
        int i;
        for (i=0;i<length(q);i++)
        {   Word mk = q.buffer[i].ID;
            //wordToString(q.buffer[i].ID , *mk);
            //printf("%s\n", mk);
            int dr = q.buffer[i].Durasi;
            //printf("%d\n" , dr);
            int kt = q.buffer[i].Tahan;
            //printf("%d\n" , kt);
            int hr = q.buffer[i].Harga;
            printWord(mk);
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

void DisplayMasakan(Queue q)
{
    printf("Daftar Makanan yang sedang dimasak\n");
    printf("Makanan | Sisa durasi memasak\n");
    printf("=============================\n");
    if(!isEmpty(q))
    {
        int i;
        for (i=0;i<length(q);i++)
        {
            Word mk = q.buffer[i].ID;
            int dr = q.buffer[i].Durasi;
            printWord(mk);
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

void DisplaySajian(Queue q)
{
    printf("Daftar Makanan yang dapat disajikan\n");
    printf("Makanan | Sisa ketahanan makanan\n");
    printf("================================\n");
    if(!isEmpty(q))
    {
        int i;
        Word mk;
        int kt;
        for (i=0;i<length(q);i++)
        {
            mk = q.buffer[i].ID;
            kt = q.buffer[i].Tahan;
            printWord(mk);
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
boolean isValid(Word a)
{
    return isCook(a) || isServe(a) || isSkip(a);
}

boolean isCook(Word a)
{
    return wordStringEq(getCommand(a),"COOK");
}

boolean isServe(Word a)
{
    return wordStringEq(getCommand(a),"SERVE");
}

boolean isSkip(Word a)
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
    Word m;
    m.TabWord[0] = 'M';
    m.Length = 1;
    Word idcode = IntToWord(i);
    joinWord(&m,idcode);
    salinWord(&pes->ID,m);
}

// Menyalin info makanan
void copyFood(Food *copy,Food f)
{
    copy->Durasi = f.Durasi;
    copy->Harga = f.Harga;
    copy->Tahan = f.Tahan;
    salinWord(&copy->ID,f.ID);
}

// Command in-game

void COOK(Word code, Queue *Pesanan, Queue *Masakan)
// Memasak makanan yang ada di urutan paling atas di
// antrian pesanan dan memasukkannnya ke dalam antrian masakan
{
    Food f;
    copyFood(&f,Pesanan->buffer[findBuffer(code,*Pesanan)]);
    f.Durasi++;
    enqueue(Masakan,f);

    printf("\n");
    printf("Berhasil memasak ");
    printWord(code);
    printf("\n");
}

void SERVE(Queue *Pesanan, Queue *Sajian, int *Saldo)
// Menyajikan makanan yang ada di urutan paling atas di
// antrian makanan siap saji
{
    Food saji;
    Food saji2;
    dequeue(Pesanan,&saji);
    dequeue(Sajian,&saji2);
    *Saldo += saji2.Harga;

    printf("\n");
    printf("Berhasil menyajikan ");
    printWord(saji2.ID);
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
    Queue pesanan;
    Queue masakan;
    Queue sajian;
    CreateQueue(&pesanan);
    CreateQueue(&masakan);
    CreateQueue(&sajian);

    //Generate pesanan awal
    int i = 0;
    Food temp;
    while (i<3)
    {
        generateFood(&temp,i);
        enqueue(&pesanan,temp);
        i++;
    }

    printf("Selamat Datang di Diner Dash!\n");

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
            printf("MASUKKAN COMMAND: ");
            STARTCOMMAND();
            if (isValid(currentCmd))
            {   
                if(isCook(currentCmd))
                {   
                    if (isMember(pesanan,getLabel(currentCmd)))
                    {   
                        if (isMember(masakan,getLabel(currentCmd)))
                        {
                            printWord(getLabel(currentCmd));
                            printf(" sedang dimasak!\n");
                            printf("\n");
                        } else if (isMember(sajian,getLabel(currentCmd))) {
                            printWord(getLabel(currentCmd));
                            printf(" sudah bisa disajikan!\n");
                            printf("\n");
                        } else {
                            valid = true;
                        }
                    } else {
                        printWord(getLabel(currentCmd));
                        printf(" bukan bagian dari pesanan \n");
                        printf("\n");
                    }  
                } else if (isServe(currentCmd)) {
                    if (isMember(pesanan,getLabel(currentCmd)))
                    {   
                        if (isMember(masakan,getLabel(currentCmd)))
                        {
                            printWord(getLabel(currentCmd));
                            printf(" sedang dimasak!\n");
                            printf("\n");
                        } else if (isMember(sajian,getLabel(currentCmd))) {
                            if (wordWordEq(getLabel(currentCmd),HEAD(pesanan).ID))
                            {
                                valid = true;
                            } else {
                                Word bef = HEAD(pesanan).ID;
                                Word af = getLabel(currentCmd);
                                printWord(af);
                                printf(" belum dapat disajikan karena ");
                                printWord(bef);
                                printf(" belum selesai\n");
                                printf("\n");
                                printf("\n");
                            }
                        } else {
                            printWord(getLabel(currentCmd));
                            printf(" perlu dimasak terlebih dahulu!\n");
                            printf("\n");
                        }
                    } else {
                        printWord(getLabel(currentCmd));
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

        if(isCook(currentCmd))
        {
            COOK(getLabel(currentCmd),&pesanan,&masakan);
        } else if (isServe(currentCmd)) {
            SERVE(&pesanan,&sajian,&saldo);
            countserve++;
        } 

        if (!isEmpty(masakan))
        {
            int j;
            Food masak;
            for (j=0;j<length(masakan);j++)
            {
                masakan.buffer[j].Durasi--;
                if (masakan.buffer[j].Durasi==0)
                {
                    DeleteAt(&masakan,j,&masak);
                    masak.Tahan++;
                    enqueue(&sajian,masak);
                    printWord(masak.ID);
                    printf(" sudah selesai dimasak\n");
                }
            }
        }

        if (!isEmpty(sajian))
        {
            int k;
            Food basi;
            for (k=0;k<length(sajian);k++)
            {
                sajian.buffer[k].Tahan--;
                if (sajian.buffer[k].Tahan==0)
                {
                    dequeue(&sajian,&basi);
                    printWord(basi.ID);
                    printf(" sudah tidak dapat disajikan. Segera masak ulang\n");
                }
            }
        }

        Food temp2;
        generateFood(&temp2,i);
        enqueue(&pesanan,temp2);
        i++;

        if (length(pesanan)>7 || countserve==15)
        {
            finished = true;
        }
    }
    
    printf("\n");
    printf("Skor anda %d\n", saldo);
}


int main(){
    srand(time(0));
    dinnerdash();
    return 0;
}
