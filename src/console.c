#include "console.h"
#include <stdio.h>
void CREATEGAME(ArrayDin *ListGames)
{
    printf("Masukkan nama game yang akan ditambahkan : ");
    STARTCOMMANDGAME();
        char string[1000];
    char *gamename = (char*) malloc (currentCMD.Length * sizeof(char));
    // char * gamename;
    int j = 0;
    //
    wordToString(currentCMD , string);
    //printf("%s\n",string);

    while (j <= currentCMD.Length)
    {
        gamename[j] = string[j];
        j++;
    }
        //gamename[j] = '\0';
        //InsertIn(string , ListGames , i);

    boolean found = false;
    for (int i = 0; i < ListGames->Neff; i++)
    {
        if (CompareString(gamename, ListGames->A[i]))
        {
            found = true;
            printf("Game sudah ada di dalam list game.\n");
        }
        
    }
    if (!found)
    {
        InsertLast(ListGames, gamename);
        printf("Game berhasil ditambahkan.\n");
    }
}


void DELETE(ArrayDin *ListGames, Queue q1)
{
    LISTGAME(ListGames);
    printf("\n");
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();
    printf("\n");
    int input;
    input = WordToInt(currentCMD);
    if ((input > 0 && input <=5)  || input>(*ListGames).Neff) {
        printf("Game ke-%d gagal dihapus\n" , input);
    } else {
        boolean found;
        found = false;
        int j;
        j = 0;
        while (j<length(q1) && !found)
         {
            if (CompareString((q1).buffer[j] , (*ListGames).A[input-1])) {
                found = true;
            } j++;
        }
        if (found) {
            printf("Game ke-%d gagal dihapus\n" , input);
        } else {
            int i;
            i = input-1;
            while (i<(*ListGames).Neff) {
                (*ListGames).A[i] = (*ListGames).A[i+1];
                i++;  
            } 
            (*ListGames).Neff--;
            printf("Game berhasil dihapus");
        }
    }
    printf("\n");
}



void HELP()
{
    printf("Berikut command-command yang dapat anda gunakan: \n");
    printf("1. SAVE <nama_file> \n2. CREATE GAME \n3. LIST GAME \n4. DELETE GAME \n5. QUEUE GAME \n6. PLAY GAME \n7. SKIPGAME <Jumlah Game>\n8. QUIT \n9. HELP\n");
}

void LISTGAME(ArrayDin *ListGames)
{
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int i = 0; i < (*ListGames).Neff; i++)
    {
        printf("%i. %s\n", i+1, (*ListGames).A[i]);
    }
}

void LOADFILE(ArrayDin *ListGames , ArrayDin *GameHistory , char* filename ,Map *RNG , Map *DinerDASH , Map *HANGMAN , Map *TOWEROFHANOI , Map *SNAKEONMETEOR , Map *MATHQUIZ){
    char path[NMax];
    stringConcat("../data/",filename,path);
    //printf("%s\n",path);
    FILE *open = fopen(path,"r");
    if (open != NULL)
    {
        STARTWORD(path);
        int nGame = WordToInt(currentWord);
        //nGame -= 10;
        printf("%d\n" , nGame);
        char string[NMax];
        for (int i = 1; i <= nGame; i++){
            char *gamename = (char*) malloc (currentWord.Length * sizeof(char));
            // char * gamename;
            int j = 0;
            ADVLine();
            wordToString(currentWord , string);
            //printf("%s\n",string);
            while (j <= currentWord.Length)
            {
                gamename[j] = string[j];
                j++;
            }
            //gamename[j] = '\0';  
            //InsertIn(string , ListGames , i);
            InsertLast(ListGames , gamename);
            printf("%s\n" , (*ListGames).A[i-1]);
        }
        /*GAME HISTORY*/
        ADVLine(); //printf("%s\n" , currentCMD);
        nGame = WordToInt(currentWord);
        printf("%d\n" , nGame);
        char *kata;
        for (int i = 1; i <= nGame; i++){
            //char *gamename = (char*) malloc (currentWord.Length * sizeof(char));
            ADVLine();
            kata = WORDTOSTRING(currentWord);
            //printf("%s\n",kata);
            // while (j <= currentWord.Length)
            // {
            //     gamename[j] = kata[j];
            //     j++;
            // }
            //gamename[j] = '\0';  
            //InsertIn(string , ListGames , i);
            InsertLast(GameHistory, kata); 
            printf("%s\n" , (*GameHistory).A[i-1]);
        }
        /*MAP RNG*/
        ADVLine(); //printf("%s\n" , currentCMD);
        nGame = WordToInt(currentWord);
        printf("%d\n" , nGame);
        int i = 0;
        int score ;
        while(i < nGame){
            //char *gamename = (char*) malloc (currentWord.Length * sizeof(char));
            //printf("%s\n" , currentWord);
            //printf("panjang currentWord sekarang %d\n" , currentWord.Length);
            ADVWORD();
            kata = WORDTOSTRING(currentWord);
            //printf("Panjang currentWord Kata = %d\n" , currentWord.Length);
            //printf("%s\n",kata);
            //printf("%s\n" , currentWord);
            ADVWORD();
            score = WordToInt(currentWord);
            //printf("panjang currentWord score = %d\n" , currentWord.Length);
            //printf("%d\n",score);
            // while (j <= currentWord.Length)
            // {
            //     gamename[j] = kata[j];
            //     j++;
            // }
            //gamename[j] = '\0';  
            //InsertIn(string , ListGames , i);
            Insert(RNG, kata, score);
            printf("%s %d\n" , (*RNG).Elements[i].Nama , (*RNG).Elements[i].Skor);
            i++;
        }
        /*MAP Diner DASH*/
        ADVLine(); 
        nGame = WordToInt(currentWord);
        printf("%d\n" , nGame);
        i = 0;
        while(i < nGame){
            ADVWORD();
            kata = WORDTOSTRING(currentWord);
            ADVWORD();
            score = WordToInt(currentWord);
            Insert(DinerDASH, kata, score);
            printf("%s %d\n" , (*DinerDASH).Elements[i].Nama , (*DinerDASH).Elements[i].Skor);
            i++;
        }
        /*MAP HANGMAN*/
        ADVLine(); 
        nGame = WordToInt(currentWord);
        printf("%d\n" , nGame);
        i = 0;
        while(i < nGame){
            ADVWORD();
            kata = WORDTOSTRING(currentWord);
            ADVWORD();
            score = WordToInt(currentWord);
            Insert(HANGMAN, kata, score);
            printf("%s %d\n" , (*HANGMAN).Elements[i].Nama , (*HANGMAN).Elements[i].Skor);
            i++;
        }
        /*MAP TOWER OF HANOI*/ 
        ADVLine();
        nGame = WordToInt(currentWord);
        printf("%d\n" , nGame);
        i = 0;
        while(i < nGame){
            ADVWORD();
            kata = WORDTOSTRING(currentWord);
            ADVWORD();
            score = WordToInt(currentWord);
            Insert(TOWEROFHANOI, kata, score);
            printf("%s %d\n" , (*TOWEROFHANOI).Elements[i].Nama , (*TOWEROFHANOI).Elements[i].Skor);
            i++;
        }
        /*MAP SNAKE ON METEOR*/
        ADVLine();
        nGame = WordToInt(currentWord);
        printf("%d\n" , nGame);
        i = 0;
        while(i < nGame){
            ADVWORD();
            kata = WORDTOSTRING(currentWord);
            ADVWORD();
            score = WordToInt(currentWord);
            Insert(SNAKEONMETEOR, kata, score);
            printf("%s %d\n" , (*SNAKEONMETEOR).Elements[i].Nama , (*SNAKEONMETEOR).Elements[i].Skor);
            i++;
        }
        if(foundmathquiz(ListGames)){
            /*MAP MATH QUIZ*/
        ADVLine();
        nGame = WordToInt(currentWord);
        printf("%d\n" , nGame);
        i = 0;
        while(i < nGame){
            ADVWORD();
            kata = WORDTOSTRING(currentWord);
            printf("%s\n" , kata);
            ADVWORD();
            score = WordToInt(currentWord);
            Insert(MATHQUIZ, kata, score);
            printf("%s %d\n" , (*MATHQUIZ).Elements[i].Nama , (*MATHQUIZ).Elements[i].Skor);
            i++;
        }
        }
        if(!IsEmpty(*ListGames)) 
        { 
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n"); 
        } 
    }
    else
    {
        printf("%s tidak dikenali.\n",filename);
    }
}

void PLAYGAME(Queue *q1)
{
    ElType A;
    char *rng, *dinerDash , *dino ,*risewoman ,*eiffel ,*MTK;
    
    rng = "RNG";
    dinerDash = "Diner DASH";
    dino = "DINOSAUR IN EARTH";
    risewoman = "RISEWOMAN";
    eiffel = "EIFFEL TOWER";
    MTK = "MATH QUIZ";

    if (isEmpty(*q1))
    {
        printf("Antrian game kosong.\n");
    }

    else
    {
        char*game;
        dequeue(q1 , &game);
        
        if (CompareString(game , rng))
        {
            printf("Loading %s ...\n", rng);
            delay(2);
            gameRNG();
        } 

        else if(CompareString(game , dino))
        {
            printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");
        }

        else if(CompareString(game , risewoman))
        {
            printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");

        }

        else if(CompareString(game , eiffel))
        {
            printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.\n");

        }
        else if(CompareString(game , MTK))
        {
            printf("Loading MATH QUIZ ...\n");
            delay(2);
            mathquiz();
        }

        else if (CompareString(game , dinerDash))
        {
            printf("Loading %s ...\n", dinerDash);
            delay(2);
            dinnerdash(); 
        }


        else
        {
            srand(time(NULL));
            int random = rand();
            printf("Skor Kamu Adalah %d\n",random);
        }

    }
}   

void QUEUEGAME(Queue *q1, ArrayDin game){
    if (isEmpty(*q1))
    {
        printf("Antrian game kosong.\n");
    }else
    {
    printf("Berikut adalah daftar antrian game-mu.\n");
    for (int i = IDX_HEAD(*q1); i < IDX_HEAD(*q1) + length(*q1); i++){
        printf("%d. %s\n",i+1, q1->buffer[i]);
    }
    }
    printf("\n");
    LISTGAME(&game);


    // Queue q;
    printf("Nomor Game yang mau ditambahkan ke antrian : ");
    int nomor_game;
    // CreateQueue(&q);
    STARTCOMMAND();
    nomor_game = WordToInt(currentCMD);
    if (nomor_game > game.Neff){
         printf("Nomor permainan tidak valid\n");
    } else {
        char *string = game.A[nomor_game - 1];
        char *gamename = (char*) malloc (LengthKalimat(game.A[nomor_game - 1]) * sizeof(char));
        int j = 0;
        while (j <= LengthKalimat(game.A[nomor_game - 1]))
        {
            gamename[j] = string[j];
            j++;
        }
        enqueue(q1, gamename);
        printf("Game berhasil ditambahkan kedalam daftar antrian.\n");
    }
}

void QUIT() {
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
    exit(0);
}

void printRNG(){
    printf("    ____   _   _______\n");
    printf("   / __  / | / / ____/\n");
    printf("  / /_/ /  |/ / / __\n");  
    printf(" / _, _/ /| / /_/ /\n");  
    printf("/_/ |_/_/ |_/____/\n"); 
}

void printMathQuiz(){
printf("   ▄▄▄▄███▄▄▄▄      ▄████████     ███        ▄█    █▄         ████████▄   ███    █▄   ▄█   ▄███████▄\n");
printf(" ▄██▀▀▀███▀▀▀██▄   ███    ███ ▀█████████▄   ███    ███        ███    ███  ███    ███ ███  ██▀     ▄██ \n");
printf(" ███   ███   ███   ███    ███    ▀███▀▀██   ███    ███        ███    ███  ███    ███ ███▌       ▄███▀ \n");
printf(" ███   ███   ███   ███    ███     ███   ▀  ▄███▄▄▄▄███▄▄      ███    ███  ███    ███ ███▌  ▀█▀▄███▀▄▄ \n");
printf(" ███   ███   ███ ▀███████████     ███     ▀▀███▀▀▀▀███▀       ███    ███  ███    ███ ███▌   ▄███▀   ▀ \n");
printf(" ███   ███   ███   ███    ███     ███       ███    ███        ███    ███  ███    ███ ███  ▄███▀       \n");
printf(" ███   ███   ███   ███    ███     ███       ███    ███        ███  ▀ ███  ███    ███ ███  ███▄     ▄█  \n");
printf("  ▀█   ███   █▀    ███    █▀     ▄████▀     ███    █▀          ▀██████▀▄█ ████████▀  █▀    ▀████████▀  \n");       
printf("+ - x : + - x : + - x : + - x : + - x : + - x : + - x : + - x : + - x : + - x : + - x : + - x : + - x :\n");
}

void gameRNG()  
{   printRNG();
    printf("\n");
    srand(time(NULL));
    int maxTry = 50;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak sebuah angka X yang rentangnya berada diantara 1 - 50.\n");
    int random = rand() % 50 + 1;
    int tebakan;
    int skor = 0;
    printf("Tebakan : ");
    STARTCOMMAND();
    tebakan = WordToInt(currentCMD);
    int nTebakan = 1;
    while(tebakan != random && (nTebakan < maxTry)){
        if(tebakan < random){
            printf("Lebih Besar\n");
        }
        else if(tebakan > random){
            printf("Lebih Kecil\n");
        }
        printf("Tebakan : ");
        STARTCOMMAND();
        tebakan = WordToInt(currentCMD);
        nTebakan++;
    }
    if(nTebakan >= maxTry){
        printf("GAME OVER!\n");
        skor = maxTry - nTebakan;
    }
    else{
        printf("YA , X Adalah %d\n" , random);
        skor = maxTry - nTebakan + 1;
    }
    printf("skor = %d\n" , skor);
}

void SAVEBNMO(ArrayDin* GamesList, char* filename) 
 { 
    FILE* fp; 
    char path[50]; 
  
    stringConcat("../data/",filename,path); 
    fp = fopen (path,"w+"); 
    fprintf(fp,"%d",Length(*GamesList)); 
    for(int i = 0; i < Length(*GamesList);i++) 
    { 
        fprintf(fp,"\n%s",(*GamesList).A[i]); 
    } 
    fclose(fp); 
  
    fp = fopen(path, "r"); 
    if (fp != NULL) 
    { 
        printf("Save file berhasil disimpan.\n"); 
        fclose(fp); 
    } 
 }

void SKIPGAME(Queue *q, int n)
{
    if (isEmpty(*q))
    {
        printf("Antrian game kosong.\n");
    }else
    {
    printf("Berikut adalah daftar antrian game-mu.\n");
    int j = 1;
    for (int i = IDX_HEAD(*q); i < IDX_HEAD(*q) + length(*q); i++){
        printf("%d. %s\n",j, q->buffer[i]);
        j++;
    }
    }

    ElType x;
    if (n<length(*q)) // valid, jumlah game yang di skip ada di range antiran
    {
        int i = 0;
        while (i<n)
        {
            dequeue(q,&x);
            i++;
        }
    PLAYGAME(q);
        //displayQueue(*q);
        //PLAYGAME(q);
        //for (int i = IDX_HEAD(*q) - n; i < IDX_HEAD(*q) - n + length(*q); i++){
        //printf("%d. %s\n",i+1, q->buffer[i]);
    }
     
    else { 
        while(!isEmpty(*q))
        {
            dequeue(q,&x);
        } // seluruh game di skip
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
}

void STARTGAME(ArrayDin *ListGames){
    char path[NMax];
    char *filename = "config.txt";
    stringConcat("../data/",filename,path);
    //printf("%s\n",path);
    STARTWORD(path);
    int nGame = WordToInt(currentWord);
    //nGame -= 10;
    //printf("%d\n" , nGame); 
    char string[NMax];
    for (int i = 1; i <= nGame; i++){
        char *gamename = (char*) malloc (currentWord.Length * sizeof(char));
        // char * gamename;
        int j = 0;
        ADVLine();
        wordToString(currentWord , string);
        //printf("%s\n",string);
        while (j <= currentWord.Length)
        {
            gamename[j] = string[j];
            j++;
        }
        //gamename[j] = '\0';
        //InsertIn(string , ListGames , i);
        InsertLast(ListGames , gamename);
        //printf("%s\n" , (*ListGames).A[i-1]);

    }
    if(!IsEmpty(*ListGames)) 
    { 
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n"); 
    } 
}




    int pertambahan(int skor){
    printf("Pilih Tingkat Kesulitan ! \n");
    printf("1.Mudah\n2.Normal\n3.Sulit\n");
    int batasbawah , batasatas;
    boolean input = false;
    while(!input){
        printf("ENTER COMMAND : ");
        STARTCOMMANDGAME();
        if(wordAndCharSama(currentCMD,"Mudah")){
            input = true;
            batasbawah = 0;
            batasatas = 100;
        }
        else if(wordAndCharSama(currentCMD,"Normal")){
            input = true;
            batasbawah = 101;
            batasatas = 500;
        }
        else if(wordAndCharSama(currentCMD,"Sulit")){
            input = true;
            batasbawah = 501;
            batasatas = 1000;
        }
        else{
            printf("Masukan Command Anda Salah , Silahkan Ulangi\n");
        }
    }
    
    printf("Loading Mode pertambahan...\n");
    delay(2);
        for(int i = 0;i < 10;i++){
                int a = randint(batasbawah,batasatas);
                int b = randint(batasbawah,batasatas);
                int c = a + b;
                //printf("hasil adalah %d\n" , c);
                printf("%d + %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    int masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        skor = skor + 10;
                    }
                }
                printf("Jawabannya adalah %d\n",c);
                printf("Skor kuis kamu sekarang adalah %d\n" , skor);
            //printf("%d\n",a);
            
            //printf("%d\n",b);    
        
        printf("\n");
}

return skor;
}

int pengurangan(int skor){
    printf("Pilih Tingkat Kesulitan ! \n");
    printf("1.Mudah\n2.Normal\n3.Sulit\n");
    int batasbawah , batasatas;
    boolean input = false;
    while(!input){
        printf("ENTER COMMAND : ");
        STARTCOMMANDGAME();
        if(wordAndCharSama(currentCMD,"Mudah")){
            input = true;
            batasbawah = 0;
            batasatas = 100;
        }
        else if(wordAndCharSama(currentCMD,"Normal")){
            input = true;
            batasbawah = 101;
            batasatas = 500;
        }
        else if(wordAndCharSama(currentCMD,"Sulit")){
            input = true;
            batasbawah = 501;
            batasatas = 1000;
        }
        else{
            printf("Masukan Command Anda Salah , Silahkan Ulangi\n");
        }
    }
    
    printf("Loading Mode pengurangan...\n");
    delay(2);
        for(int i = 0;i < 10;i++){
                int c;
                int a = randint(batasbawah,batasatas);
                while(a == 0){
                    a = randint(batasbawah,batasatas);
                }
                int b = randint(batasbawah,batasatas);
                while(b < a){
                     b = randint(batasbawah,batasatas);
                }
                if (a >= b){
                    c = a - b;
                    //printf("hasil adalah %d\n" , c);
                    printf("%d - %d = ", a , b);
                }
                else{
                    c = b - a;
                    printf("%d - %d = ", b , a);
                }
                
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    int masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        skor = skor + 10;
                    }
                }
                printf("Jawabannya adalah %d\n",c);
                printf("Skor kuis kamu sekarang adalah %d\n" , skor);
            //printf("%d\n",a);
            
            //printf("%d\n",b);    
        
        printf("\n");
}

return skor;
}

int perkalian(int skor){
    printf("Pilih Tingkat Kesulitan ! \n");
    printf("1.Mudah\n2.Normal\n3.Sulit\n");
    int batasbawah , batasatas;
    boolean input = false;
    while(!input){
        printf("ENTER COMMAND : ");
        STARTCOMMANDGAME();
        if(wordAndCharSama(currentCMD,"Mudah")){
            input = true;
            batasbawah = 0;
            batasatas = 10;
        }
        else if(wordAndCharSama(currentCMD,"Normal")){
            input = true;
            batasbawah = 11;
            batasatas = 30;
        }
        else if(wordAndCharSama(currentCMD,"Sulit")){
            input = true;
            batasbawah = 31;
            batasatas = 100;
        }
        else{
            printf("Masukan Command Anda Salah , Silahkan Ulangi\n");
        }
    }
    
    printf("Loading Mode perkalian...\n");
    delay(2);
        for(int i = 0;i < 10;i++){
                int a = randint(batasbawah,batasatas);
                int b = randint(batasbawah,batasatas);
                int c = a * b;
                //printf("hasil adalah %d\n" , c);
                printf("%d x %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    int masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        skor = skor + 10;
                    }
                }
                printf("Jawabannya adalah %d\n",c);
                printf("Skor kuis kamu sekarang adalah %d\n" , skor);
            //printf("%d\n",a);
            
            //printf("%d\n",b);    
        
        printf("\n");
}

return skor;
}

int mathquiz(){      
    printMathQuiz();
    printf("\n");
    printf("<SELAMAT DATANG DI GAME MATHQUIZ>\n");
    delay(1);
    printf("GAME RULE : \n");
    printf("1.Pilih Mode Quiz Matematika\n");
    printf("2.Pilih Tingkat Kesulitan Mode , Semakin Tinggi Tingkat Kesulitannya, Semakin Besar Angka Yang Akan Dihitung\n");
    printf("3.Jawaban Kuis Tidak Perlu Dispasi\n");
    printf("4.Setiap Mode terdiri dari 10 soal\n");
    printf("5.Skor Maksimal Dari Setiap Permainan Adalah 100\n\n");
    printf("SELAMAT BERMAIN!\n");
    delay(1);
    printf("Pilih Mode Quiz Matematika ! \n");
    printf("1.Pertambahan\n2.Pengurangan\n3.Perkalian\n");
    int skormath = 0;
    boolean masukanbenar = false;
    while (!masukanbenar){
        printf("ENTER COMMAND : ");
        STARTCOMMANDGAME();
        if(wordAndCharSama(currentCMD,"Pertambahan")){
            masukanbenar = true;
            skormath = pertambahan(skormath);
        
        }
        else if(wordAndCharSama(currentCMD,"Pengurangan")){
            masukanbenar = true;
            skormath = pengurangan(skormath);
        }
        else if(wordAndCharSama(currentCMD,"Perkalian")){
            masukanbenar = true;
            skormath = perkalian(skormath);
        }
        else {
            printf("Masukan Command Anda Salah , Silahkan Ulangi\n");
        }
    }
    
    
    return skormath;
}
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
    
    pes->Durasi = RANDINTDD(1,5);
    pes->Tahan = RANDINTDD(1,5);
    pes->Harga = RANDINTDD(10000,50000);
    
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
            printf("MASUKKAN COMMAND: ");
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

boolean foundmathquiz(ArrayDin *ListGames){
    boolean found = false;
    int i = 0;
    while(i < (*ListGames).Neff && !found)
    {
        if (CompareString((*ListGames).A[i], "MATH QUIZ"))
        {
            found = true;
            //printf("Ketemu\n");
        }
        else{
            i++;
        }
    }
    return found;
}

