#include "dinnerdash.h"

// Menampilkan tabel
void DisplayPesanan(Queue q)
{
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("============================================\n");
    if(!isEmpty(q))
    {
        //printf("Gagal 2");
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
            //printf("%d\n" , hr);
            printf("%s      | %d              | %d         | %d\n", mk,dr,kt,hr);
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
            string mk;
            wordToString(q.buffer[i].ID , mk);
            int dr = q.buffer[i].Durasi;
            printf("%s      | %d\n", mk,dr);
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
        for (i=0;i<length(q);i++)
        {
            string mk;
            wordToString(q.buffer[i].ID , mk);
            int kt = q.buffer[i].Tahan;
            printf("%s      | %d\n", mk,kt);
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

// Autogenerate pesanan
Food generateFood(int i)
{
    Food pes;
    pes.Durasi = randint(1,5);
    pes.Tahan = randint(1,5);
    pes.Harga = randint(10000,50000);
    
    // membuat ID / Label 
    Word m = stringToWord("M");
    //printf("%c\n",m);
    Word idcode = IntToWord(i);
    //printf("%s\n",idcode);
    MergeWord(&m,idcode);
    salinword(m , &pes.ID);
    //printf("%s\n",pes.ID);
    return pes;
}

// Menyalin info makanan
Food copyFood(Food f)
{
    Food copy;
    copy.Durasi = f.Durasi;
    copy.Harga = f.Harga;
    copy.Tahan = f.Tahan;
    salinword(f.ID,&copy.ID);
}

// Command in-game

void COOK(Word ID, Queue *Pesanan, Queue *Masakan)
// Memasak makanan yang ada di urutan paling atas di
// antrian pesanan dan memasukkannnya ke dalam antrian masakan
{
    int i = WordToInt(ID);
    Food f = copyFood(Pesanan.buffer[i]);
    enqueue(Masakan,f);

    printf("\n");
    printf("Berhasil memasak %s\n", ID);
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
    printf("Berhasil menyajikan %s\n", saji2.ID);
}

void dinnerdash()
{
    // Kamus
    boolean finished = false;
    int countserve = 0;
    int saldo = 0;
    Word currentCMD;

    // Membuat queue pesanan, masakan, sajian
    Queue pesanan;
    Queue masakan;
    Queue sajian;
    CreateQueue(&pesanan);
    CreateQueue(&masakan);
    CreateQueue(&sajian);

    // Generate pesanan awal
    int i = 0;
    while (i<3)
    {
        Food pes;
        pes = generateFood(i);
        enqueue(&pesanan,pes);
        //printf("%s\n", pesanan.buffer[i].ID);
        i++;
    }

    // Tampilan awal
    printf("Selamat Datang di Diner Dash!\n");
    printf("SALDO: %d\n", saldo);
    printf("\n");
    DisplayPesanan(pesanan);
    printf("\n");
    DisplayMasakan(masakan);
    printf("\n");
    DisplaySajian(sajian);
    printf("\n");

    while (!finished)
    {
        int asal = 1;
        while(asal == 1)
        {
            printf("%d",asal);
            printf("MASUKKAN COMMAND:");
            char*coba;
            //STARTCOMMAND();
            scanf("%s\n",coba);
            Word currentCMD = stringToWord(coba);
            if (isValid(currentCMD))
            {   Word first = currentCMD;
                //printf("%s",currentCMD);
                //ADVCOMMAND();
                Word snd = stringToWord("M1");
                //salinword(currentCMD,&snd);
                //printf("%s\n",snd);
                if(isCook(currentCMD))
                {   printf("isCook");
                    if (isMember(pesanan,snd))
                    {   printf("Pesanan");
                        if (isMember(masakan,snd))
                        {
                            
                            printf("%s sedang dimasak!\n", snd);
                        } else if (isMember(sajian,snd)) {
                            printf("%s sudah bisa disajikan!\n", snd);
                        } else {
                            asal = 0;
                        }
                    } else {
                        printf("%s bukan bagian dari pesanan \n", snd);
                    }  
                } else if (isServe(currentCMD)) {
                    if (isMember(pesanan,snd))
                    {   
                        if (isMember(masakan,snd))
                        {
                            printf("%s sedang dimasak!\n", snd);
                        } else if (isMember(sajian,snd)) {
                            if (wordAndWordSama(snd,HEAD(pesanan).ID))
                            {
                                asal = 0;
                            } else {
                                Word bef = HEAD(pesanan).ID;
                                Word af = snd;
                                printf("%s belum dapat disajikan karena %s belum selesai\n", af, bef);
                            }
                        } else {
                            printf("%s perlu dimasak terlebih dahulu!\n", snd);
                        }
                    } else {
                        printf("%s bukan bagian dari pesanan \n", snd);
                    }  
                } else { // isSkip
                    asal = 0 ;
                }
            } 
            else {
                printf("Perintah tidak valid!\n");
            }
            printf("%d",asal);
        }
        printf("\nfa");
        //printf("Perintah tidak valid!\n");
        // command sudah valid
        // perpindahan makanan dr masakan ke sajian BELUM
        printf("%s\n",kataPertama(currentCMD));
        if(isCook(currentCMD))
        {
            COOK(splitwordDD(currentCMD),&pesanan,&masakan);
        } else if (isServe(currentCMD)) {
            SERVE(&pesanan,&sajian,&saldo);
            countserve++;
        } 

        // menampilkan tampilan sebelum durasi dan ketahanan dikurangi
        // setelah command cook/serve/skip dimasukkan
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

        // Menambahkan pesanan (dimulai dari M3)
        enqueue(&pesanan,generateFood(i));
        i++;
        
        // Proses makanan
        if (!isEmpty(masakan))
        {
            int j;
            Food masak;
            for (j=0;j<length(masakan);j++)
            {
                masakan.buffer[j].Durasi--;
                if (masakan.buffer[j].Durasi==0)
                {
                    dequeue(&masakan,&masak);
                    enqueue(&sajian,masak);
                    Word a = masak.ID;
                    printf("%s sudah selesai dimasak\n", a);
                }
            }
        }

        if (!isEmpty(sajian))
        {
            int k;
            Food basi;
            for (k=0;k<length(sajian);k++)
            {
                sajian.buffer[k].Tahan++;
                if (sajian.buffer[k].Tahan==0)
                {
                    dequeue(&sajian,&basi);
                    Word a = basi.ID;
                    printf("%s sudah tidak dapat disajikan. Segera masak ulang %s\n", a);
                }
            }
        } 

        if (length(pesanan)>7 || countserve==15)
        {
            finished = true;
        }
    }
    
    printf("\n");
    printf("Skor anda %d\n", saldo);
}

int main(){
    dinnerdash();
    return 0;
}
