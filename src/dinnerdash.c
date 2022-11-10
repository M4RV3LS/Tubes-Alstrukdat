#include "dinnerdash.h"

// Menampilkan tabel
void DisplayPesanan(Queue q)
{
    printf("Daftar Pesanan\n");
    printf("Makanan | Durasi memasak | Ketahanan | Harga\n");
    printf("—---------------------------------------------\n");
    if(!isEmpty(q))
    {
        int i;
        for (i=0;i<length(q);i++)
        {
            string mk = q.buffer[i].ID;
            int dr = q.buffer[i].Durasi;
            int kt = q.buffer[i].Tahan;
            int hr = q.buffer[i].Harga;
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
    printf("—-----------------------------\n");
    if(!isEmpty(q))
    {
        int i;
        for (i=0;i<length(q);i++)
        {
            string mk = q.buffer[i].ID;
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
    printf("—-----------------------------\n");
    if(!isEmpty(q))
    {
        int i;
        for (i=0;i<length(q);i++)
        {
            string mk = q.buffer[i].ID;
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
    
    // membuat ID
    string m = 'M';
    string idcode;
    sprintf(idcode,"%d",i);
    stringConcat(m,idcode,pes.ID);
    return pes;
}

// Menyalin info makanan
Food copyFood(Food f)
{
    Food copy;
    copy.Durasi = f.Durasi;
    copy.Harga = f.Harga;
    copy.Tahan = f.Tahan
    copystr(f.ID,copy.ID);
}

// Command in-game

void COOK(Word ID, Queue *Pesanan, Queue *Masakan)
// Memasak makanan yang ada di urutan paling atas di
// antrian pesanan dan memasukkannnya ke dalam antrian masakan
{
    Word num = splitwordDD(ID);
    int i = WordToInt(num);
    Food f = copyFood(Pesanan.buffer[i]);
    enqueue(Masakan,f);

    string label;
    wordToString(ID,label);
    printf("\n");
    printf("Berhasil memasak %s\n", label);
}

void SERVE(Queue *Masakan, Queue *Sajian, int *Saldo)
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
    Word currentWord;

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
        i++;
    }

    // Tampilan awal
    printf("Selamat Datang di Diner Dash!");
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
        boolean valid = false;
        while(!valid)
        {
            printf("MASUKKAN COMMAND:");
            STARTFILE();
            if (isValid(currentWord))
            {
                Word snd = kataKedua(currentWord);
                string temp;
                wordToString(snd,temp);
                if(isCook(currentWord))
                {
                    if (isMember(pesanan,snd))
                    {
                        if (isMember(masakan,snd))
                        {
                            printf("%s sedang dimasak!\n", temp);
                        } else if (isMember(sajian,snd)) {
                            printf("%s sudah bisa disajikan!\n", temp);
                        } else {
                            valid = true;
                        }
                    } else {
                        printf("%s bukan bagian dari pesanan \n", temp);
                    }  
                } else if (isServe(currentWord)) {
                    if (isMember(pesanan,snd))
                    {
                        if (isMember(masakan,snd))
                        {
                            printf("%s sedang dimasak!\n", temp);
                        } else if (isMember(sajian,snd)) {
                            if (wordAndCharSama(snd,HEAD(pesanan).ID))
                            {
                                valid = true;
                            } else {
                                string bef = HEAD(pesanan).ID;
                                string af = temp;
                                printf("%s belum dapat disajikan karena %s belum selesai\n", af, bef);
                            }
                        } else {
                            printf("%s perlu dimasak terlebih dahulu!\n", temp);
                        }
                    } else {
                        printf("%s bukan bagian dari pesanan \n", temp);
                    }  
                } else { // isSkip
                    valid = true;
                }
            } else {
                printf("Perintah tidak valid!\n");
            }
        }

        // command sudah valid
        // perpindahan makanan dr masakan ke sajian BELUM
        if(isCook(currentWord))
        {
            COOK(kataKedua(currentWord),&pesanan,&masakan);
        } else if (isServe(currentWord)) {
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
        enqueue(pesanan,generateFood(i));
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
                    string a = masak.ID;
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
                    string a = basi.ID;
                    printf("%s sudah tidak dapat disajikan. Segera masak ulang %s\n", a);
                }
            }
        } 

        if (length(pesanan)>7 || countserve==15)
        {
            finished = true;
        }
    }
}
