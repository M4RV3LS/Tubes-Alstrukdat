#include "console.h"
#include <stdio.h>

void CREATEGAME(ArrayDin *ListGames , ArrayOfMap *GameMap)
/*Fitur untuk membuat Game*/
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
        if (IsUsernameEqual(gamename, ListGames->A[i]))
        {
            found = true;
            printf("Game sudah ada di dalam list game.\n");
        }
        
    }
    if (!found)
    {   Map Temp;
        CreateEmptyMap(&Temp);
        InsertLast(ListGames, gamename);
        printf("Game berhasil ditambahkan.\n");
        InsertLastArrayOfMap(GameMap, Temp);
    }
}


void DELETE(ArrayDin *ListGames, Queue q1 , ArrayOfMap *GameMap , Stack *GameHistory)
/*Fitur Untuk Menghapus Game*/
{
    LISTGAME(ListGames);
    printf("\n");
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();
    printf("\n");
    if(isInteger(currentCMD)){
        int input;
    input = WordToInt(currentCMD);
    //printf("input = %d\n",input);
    if ((input > 0 && input <=6)  || input>(*ListGames).Neff) {
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
            char*game = (*ListGames).A[input - 1];
            (*GameHistory) = DELETEHISTORY( GameHistory , game);
            while (i<(*ListGames).Neff) {
                (*ListGames).A[i] = (*ListGames).A[i+1];
                i++;  
            } 
            (*ListGames).Neff--;
            DeleteAtArrayOfMap(GameMap, input - 1);
            printf("Game berhasil dihapus");
        }
    }
    printf("\n");
    }
    else{
        printf("Masukan tidak valid\n");
        printf("\n");
    }
}

Stack DELETEHISTORY(Stack *in , char*game)
/*Mendelete History game yang gamenya telah dihapus*/
{
    Stack out;
    char*temp = game;
    CreateEmptyStack(&out);
    while (!IsEmptyStack(*in))
    {   game = temp;
        if (CompareString(game , InfoTop(*in)))
        {
            //printf("Char Game sekarang (1) = %s\n",game);
            //printf("Top sekarang (1)= %s\n",InfoTop(*in));
            //printf("wibu1\n");
            PopStack(in , &game);
        }
        else
        {
            //printf("Char Game sekarang (2) = %s\n",game);
            //printf("Top sekarang (2) = %s\n",InfoTop(*in));
            //printf("wibu2\n");
            PopStack(in , &game);
            PushStack(&out , game);
        }
    }
    out = ReverseStack(out);
    return out;
}

void HELP()
/*Fungsi untuk menampilkan fitur yang bisa dipakai*/
{
    printf("Berikut command-command yang dapat anda gunakan: \n");
    printf("1. SAVE <nama_file> \n");
    printf("2. CREATE GAME \n");
    printf("3. LIST GAME \n");
    printf("4. DELETE GAME \n");
    printf("5. QUEUE GAME \n");
    printf("6. PLAY GAME \n");
    printf("7. SKIPGAME <n>\n");
    printf("8. SCOREBOARD \n");
    printf("9. RESET SCOREBOARD \n");
    printf("10. HISTORY <n> \n");
    printf("11. RESET HISTORY \n");
    printf("12. HELP \n");
    printf("13. QUIT\n");
}

void LISTGAME(ArrayDin *ListGames)
/*Fungsi untuk menampilkan daftar game yang tersedia*/
{
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int i = 0; i < (*ListGames).Neff; i++)
    {
        printf("%i. %s\n", i+1, (*ListGames).A[i]);
    }
}

void LOADFILE(ArrayDin *ListGames , Stack *GameHistory , char* filename ,ArrayOfMap *GameMap)
/*Fungsi untuk memuat file eksternal*/
{
    char path[NMax];
    stringConcat("../data/",filename,path);
    //printf("%s\n",path);
    FILE *open = fopen(path,"r");
    if (open != NULL)
    {
        STARTWORD(path);
        int nGame = WordToInt(currentWord);
        //nGame -= 10;
        //printf("%s\n",currentWord);
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
            //printf("%s\n" , (*ListGames).A[i-1]);
        }
        /*GAME HISTORY*/
        ADVLine(); //printf("%s\n" , currentCMD);
        nGame = WordToInt(currentWord);
        printf("%d\n" , nGame);
        char *kata;
        //printf("Ini Sebelum Reverse\n");
        for (int i = 1; i <= nGame; i++){
            //char *gamename = (char*) malloc (currentWord.Length * sizeof(char));
            ADVLine();
            kata = WORDTOSTRING(currentWord);
            PushStack(GameHistory, kata); 
            //printf("%s\n" , InfoTop(*GameHistory));
        }
        (*GameHistory) = ReverseStack(*GameHistory);
        //printf("Ini Setelah Reverse\n");
        //DisplayStack(*GameHistory , Top(*GameHistory));

        /*Game Map*/
        int idxArrMap;
        int idxMap;
        int score ;

        for (idxArrMap = 0; idxArrMap < (*ListGames).Neff;idxArrMap++){
            Map Temp;
            CreateEmptyMap(&Temp);
            ADVLine(); //printf("%s\n" , currentCMD);
            nGame = WordToInt(currentWord);
            printf("%d\n" , nGame);
            idxMap = 0;
            while(idxMap < nGame){
                
                ADVWORD();
                kata = WORDTOSTRING(currentWord);
                ADVWORD();
                score = WordToInt(currentWord);
                Insert(&Temp, kata, score);
                //printf("%s %d\n" , (Temp).Elements[idxMap].Nama , (Temp).Elements[idxMap].Skor);
                idxMap++;
            }
            
            InsertLastArrayOfMap(GameMap , Temp);
                
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

void PLAYGAME(Queue *q1 , ArrayDin ListGames , ArrayOfMap *GameMap , Stack *GameHistory)
/*Fitur utuk memainkan game yang ada di antrian*/
{
    ElType A;
    char *rng, *dinerDash , *hangman ,*towerofhanoi ,*snakeonmeteor ,*MTK ,*Undertale;
    int score;
    rng = "RNG";
    dinerDash = "Diner DASH";
    hangman = "HANGMAN";
    towerofhanoi = "TOWER OF HANOI";
    snakeonmeteor = "SNAKE ON METEOR";
    MTK = "MATH QUIZ";
    Undertale = "UNDERTALE";

    if (isEmpty(*q1))
    {
        printf("Antrian game kosong.\n");
    }

    else
    {
        char*game;
        dequeue(q1 , &game);
        
        if (CompareString(game , rng))
        /*Memainkan Game RNG*/
        {
            printf("Loading %s ...\n", rng);
            delay(2);
            gameRNG(game , ListGames ,GameMap , score); 
            //printf("Skor: %d\n", score);
            PushStack(GameHistory , game);
            
        } 

        else if(CompareString(game , hangman))
        /*Memainkan game hangman*/
        {
            printf("Loading %s ...\n", hangman);
            delay(2);
            Hangman(game , ListGames , GameMap , score);
            PushStack(GameHistory , game);
        }

        else if(CompareString(game , towerofhanoi))
        /*memainkan game tower of hanoi*/
        {
            printf("Loading %s ...\n", towerofhanoi);
            delay(2);
            TowerOfHanoi(game , ListGames , GameMap , score);
            PushStack(GameHistory , game);

        }

        else if(CompareString(game , snakeonmeteor))
        /*Memainkan game snake on meteor*/
        {
            printf("Loading %s ...\n", snakeonmeteor);
            delay(2);
            SnakeOnMeteor(game , ListGames , GameMap , score);
            PushStack(GameHistory , game);

        }
        else if(CompareString(game , MTK))
        /*memainkan game math quiz*/
        {
            printf("Loading MATH QUIZ ...\n");
            delay(2);
            mathquiz(game ,ListGames , GameMap , score);
            PushStack(GameHistory , game);
            
        }

        else if (CompareString(game , dinerDash))
        /*Memainkan game diner dash*/
        {
            printf("Loading %s ...\n", dinerDash);
            delay(2);
            dinerdash(game , ListGames , GameMap , score);
            PushStack(GameHistory , game);
            
        }

        else if (CompareString(game , Undertale))
        /*memainkan game undertale*/
        {
            printf("Loading %s ...\n", Undertale);
            delay(2);
            undertale(game , ListGames , GameMap , score);
            PushStack(GameHistory , game);
            
        }


        else
        /*memainkan game random*/
        {   
                printf("Loading %s ...\n", game);
                delay(2);
                score = randint(1 , 100);
                printf("Game Over.Skor Anda adalah %d\n", score);
                Username(game , ListGames , GameMap , score);
                PushStack(GameHistory , game);
            }

        }

    } 

void QUEUEGAME(Queue *q1, ArrayDin game)
/*Fitur untuk menaruh game ke antrian*/
{
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

    boolean valid = false;
    while(!valid){
        printf("\n");
        printf("Nomor Game yang mau ditambahkan ke antrian : ");
    int nomor_game;
    // CreateQueue(&q);
    STARTCOMMANDGAME();
    if(isInteger(currentCMD)){
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
            valid = true;}
        }
        else{
            printf("Nomor permainan tidak valid\n");
        }
    }
    // Queue q;
    
    
}

void QUIT() 
/*fitur untuk keluar dari program BNMO*/
{
    printf("Anda keluar dari game BNMO.\n");
    printf("Bye bye ...\n");
    exit(0);
}

void SAVEBNMO(ArrayDin *ListGames , Stack *GameHistory , char* filename ,ArrayOfMap *GameMap) 
/*Fitur untuk melakukan save*/
 { 
    FILE* fp; 
    char path[50]; 
  
    stringConcat("../data/",filename,path); 
    //printf("%s\n",path);
    fp = fopen (path,"w+"); 
    if(fp == NULL)
    {
    printf("File tidak dapat dibuka\n");   
    exit(1);             
    }  
    fprintf(fp,"%d",Length(*ListGames)); 
    for(int i = 0; i < Length(*ListGames);i++) 
    { 
        fprintf(fp,"\n%s",(*ListGames).A[i]); 
    } 
    fprintf(fp , "\n%d" , Top(*GameHistory) + 1);
    //printf("Top = %d\n",Top(*GameHistory));
    INFOTYPE Game;
    Stack Temp;
    CreateEmptyStack(&Temp);
    while(!IsEmptyStack(*GameHistory))
    {   PopStack(GameHistory , &Game);
        PushStack(&Temp , Game);
        //printf("Game = %s\n",Game);
        fprintf(fp , "\n%s" , Game);
    }
    (*GameHistory) = ReverseStack(Temp);
    int idxArrMap;
    int idxMap;
    char *name;
    int score ;
    int MapCount;
    for (idxArrMap = 0;idxArrMap < (*ListGames).Neff;idxArrMap++){
        MapCount = GetElmtArrayOfMap(*GameMap , idxArrMap).Count;
        fprintf(fp , "\n%d" , MapCount);
        for(idxMap = 0;idxMap < MapCount ; idxMap++){
            name = GetElmtArrayOfMap(*GameMap , idxArrMap).Elements[idxMap].Nama;
            score = GetElmtArrayOfMap(*GameMap , idxArrMap).Elements[idxMap].Skor;
            fprintf(fp , "\n%s %d" , name , score);
        }
    }
     
    fclose(fp); 

  
    fp = fopen(path, "r"); 
    if (fp != NULL) 
    { 
        printf("Save file berhasil disimpan.\n"); 
        fclose(fp); 
    } 
 }

void SKIPGAME(Queue *q, int n , ArrayDin ListGames , ArrayOfMap *GameMap , Stack *GameHistory)
/*Fitur untuk mengskip game yang ada di antrian*/
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
    PLAYGAME(q ,ListGames , GameMap , GameHistory);
    }
     
    else { 
        while(!isEmpty(*q))
        {
            dequeue(q,&x);
        } // seluruh game di skip
        printf("Tidak ada permainan lagi dalam daftar game-mu.\n");
    }
}

void STARTGAME(ArrayDin *ListGames)
/*Fungsi untuk melakukan START PROGRAM BNMO*/
{
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


/***************************************  MATH QUIZ **********************************************/

    void printMathQuiz()
/*prosedure untuk menampilkan ascii math quiz*/
{
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
    
    int pertambahan(int skor)
    /*Fungsi untuk bermain mode pertambahan pada game math quiz*/
    {
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
                int masukan;
                //printf("hasil adalah %d\n" , c);
                printf("%d + %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        skor = skor + 10;
                    }
                }
                printf("Jawabannya adalah %d\n",c);
                printf("Skor kuis kamu sekarang adalah %d\n" , skor);
                IgnoreBlanksCMD();
            //printf("%d\n",a);
            
            //printf("%d\n",b);    
        
        printf("\n");
}

return skor;
}

int pengurangan(int skor)
/*Fungsi untuk bermain mode pengurangan pada game math quiz*/
{
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
                int masukan;
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        skor = skor + 10;
                    }
                }
                printf("Jawabannya adalah %d\n",c);
                printf("Skor kuis kamu sekarang adalah %d\n" , skor);
                IgnoreBlanksCMD();
            //printf("%d\n",a);
            
            //printf("%d\n",b);    
        
        printf("\n");
}

return skor;
}

int perkalian(int skor)
/*Fungsi untuk bermain mode perkalian pada game math quiz*/
{
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
                int masukan;
                //printf("hasil adalah %d\n" , c);
                printf("%d x %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        skor = skor + 10;
                    }
                }
                else{
                    printf("Masukan Anda Tidak Valid\n");
                }
                printf("Jawabannya adalah %d\n",c);
                printf("Skor kuis kamu sekarang adalah %d\n" , skor);
                IgnoreBlanksCMD();
            //printf("%d\n",a);
            
            //printf("%d\n",b);    
        
        printf("\n");
}

return skor;
}

void mathquiz(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)
/*Main Program game bonus math quiz*/
{      
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
        char*input = WORDTOSTRING(currentCMD);
        if(CompareString(input,"Pertambahan")){
            masukanbenar = true;
            skormath = pertambahan(skormath);
        
        }
        else if(CompareString(input,"Pengurangan")){
            masukanbenar = true;
            skormath = pengurangan(skormath);
        }
        else if(CompareString(input,"Perkalian")){
            masukanbenar = true;
            skormath = perkalian(skormath);
        }
        else {
            printf("Masukan Command Anda Salah , Silahkan Ulangi\n");
        }
    }
    
    score = skormath;
    Username(game , ListGames , GameMap , score);
}

/***************************************** RNG **************************************************/
void printRNG()
/*prosedure untuk menampilkan ascii RNG*/
{
    printf("    ____   _   _______\n");
    printf("   / __  / | / / ____/\n");
    printf("  / /_/ /  |/ / / __\n");  
    printf(" / _, _/ /| / /_/ /\n");  
    printf("/_/ |_/_/ |_/____/\n"); 
}



void gameRNG(char*game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)
/*Prosedure untuk bermain game RNG*/  
{   printRNG();
    printf("\n");
    srand(time(NULL));
    int maxTry = 50;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak sebuah angka X yang rentangnya berada diantara 1 - 50.\n");
    int random = rand() % 50 + 1;
    printf("Jawaban = %d\n",random);
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
    score = skor;
    printf("Score =  %d\n",score);
    Username(game , ListGames , GameMap , score);
}

/************************************ DINER DASH *****************************************************/
void DisplayPesanan(QUEUEDD q)
/*Prosedure untuk menampilkan tabel pesanan pada game diner dash*/
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
/*prosedure untuk menampilkan daftar masakan yang berjalan pada game diner dash*/
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
/*menampilkan daftar sajian pada game dinerdash*/
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
/*Fungsi untuk mengecek apakah Input dari user valid pada game Diner Dash*/
{
    return isCook(a) || isServe(a) || isSkip(a);
}

boolean isCook(Kata a)
/*FUNGSI UNTUK MENGECEK APAKAH MASUKAN BERUPA COOK*/
{
    return wordStringEq(getCommand(a),"COOK");
}

boolean isServe(Kata a)
/*FUNGSI UNTUK MENGECEK APAKAH MASUKAN BERUPA SERVE*/
{
    return wordStringEq(getCommand(a),"SERVE");
}

boolean isSkip(Kata a)
/*FUNGSI UNTUK MENGECEK APAKAH MASUKAN BERUPA SKIP*/
{
    return wordStringEq(getCommand(a),"SKIP");
}

// Autogenerate pesanan
void generateFood(Food *pes,int i)
/*MEMBENTUK SUATU PESANAN*/
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
/*MENGCOPY IDENTITAS PESANAN*/
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

void dinerdash(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)
/*PROGRAM UTAMA DINER DASH*/
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
    score = saldo;
    Username(game , ListGames , GameMap , score); 
}

/***************************** SPESIFIKASI DAN FITUR TAMBAHAN PADA MILESTONE 2 *********************/
boolean foundmathquiz(ArrayDin ListGames)
/*NYARI APAKAH ADA GAME MATHQUIZ DALAM LIST GAME*/
{
    boolean found = false;
    int i = 0;
    while(i < (ListGames).Neff && !found)
    {
        if (CompareString((ListGames).A[i], "MATH QUIZ"))
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

void Scoreboard(ArrayDin ListGames , ArrayOfMap GameMap)
/*FITUR UNTUK MENAMPILKAN SCOREBOARD UNTUK SETIAP GAME PADA DAFTAR GAME*/
{
    int idxlistgame;
    for(idxlistgame = 0 ; idxlistgame < ListGames.Neff ; idxlistgame++){
        printf("**** SCOREBOARD GAME %s ****\n", ListGames.A[idxlistgame]);
        PrintScoreBoard(GameMap.ArrMap[idxlistgame]);
        printf("\n");
    }
}

void Username(char*game ,ArrayDin ListGames , ArrayOfMap *GameMap , int score)
/*FITUR UNTUK MEMINTA USERNAME PADA SETIAP GAME DAN MEMASUKANNYA KEDALAM ARRAY OF MAP*/
{
    int index = 0;
    boolean found = false;
    while(!found){
        if (CompareString(game , (ListGames).A[index])){
            found = true;
        }
        else{
            index++;
        }
    }
    if(found){
        boolean berhasil = false;
        while(!berhasil){
            printf("Masukkan username: ");
            STARTCOMMANDGAME();
            char*name = WORDTOSTRING(currentCMD);
            if(!IsMemberMap(GameMap->ArrMap[index] , name)){
                Insert(&(GameMap->ArrMap[index]) , name , score);
                berhasil = true;
            }
            else{
                printf("Username sudah ada . Silahkan Masukan Kembali !\n");
                printf("\n");
            }
        }   
    }
    else{
        printf("Game tidak ditemukan\n");
    } 
}




boolean ya()
/*FUNGDI UNTUK MENGECEK APAKAH MASUKAN BERUPA STRING "YA" */
{
    boolean value = false;
    boolean valid = false;
    while(!valid){
        STARTCOMMANDGAME();
        char*temp = (char*) malloc (currentCMD.Length* sizeof(char));
        wordToString(currentCMD , temp);
        if (CompareString(temp, "YA")){
            value = true;
            valid = true;}
        else if (CompareString(temp, "TIDAK")){
            value = false;
            valid = true;}
        else{
            printf("Masukan tidak valid, silahkan masukan kembali\n");
            printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)?\n");
        }
    }
   return value; 
}



void ResetScoreboard(ArrayOfMap *M , ArrayDin *ListGames )
/*FITUR UNTUK MELAKUKAN RESET PADA SCOREBOARD*/
{
    printf("DAFTAR SCOREBOARD:\n");
    printf("0.ALL\n");
    for (int i = 0; i < (*ListGames).Neff; i++)
    {
        printf("%i. %s\n", i+1, (*ListGames).A[i]);
    }
    
    boolean valid = false;
    while(!valid){
        printf("SCOREBOARD YANG INGIN DIHAPUS: ");
        STARTCOMMAND();
        int input = WordToInt(currentCMD);
        ADVCOMMAND();
        if(!EndWord){
            printf("Masukan tidak valid, silahkan masukan kembali\n");
        }
        else{
            if (input == 0){
                valid = true;
                printf("\n");
                printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)?\n");
                if (ya()){
                    for(int i = 0; i < (*ListGames).Neff; i++){
                        CreateEmptyMap(&(M->ArrMap[i]));
                        // if(IsEmptyMap(M->ArrMap[i])){
                        //     printf("Scoreboard ke-%d berhasil di-reset.\n",i+1);
                        // }
                        // else{
                        //     printf("Scoreboard gagal di-reset.\n");
                        // }
                    }
                    printf("Scoreboard berhasil di-reset.\n");
                }
                else{
                    printf("Scoreboard gagal di-reset.\n");
                }
            }
            else if (input > 0 && input <= (*ListGames).Neff){
                valid = true;
                printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD %s (YA/TIDAK)?\n", (*ListGames).A[input-1]);
                if(ya()){
                    CreateEmptyMap(&(M->ArrMap[input-1]));
                    if(IsEmptyMap(M->ArrMap[input-1])){
                        printf("Scoreboard berhasil di-reset.\n");
                    }
                    else{
                        printf("Scoreboard gagal di-reset.\n");
                    }
                }
                else{
                    printf("Scoreboard gagal di-reset.\n");
                }
            }
            else{
                printf("Masukan tidak valid, silahkan masukan kembali\n");
            }
        
        }
    }
}

int KataTerpanjang(Map Game)
/*FUNGSI UNTUK MENCARI KATA TERPANJANG UNTUK KEPERLUAN PRINT SCOREBOARD*/
{
    int max = 0;
    int i = 0;
    while(i < Game.Count){
        if (string_length(Game.Elements[i].Nama) > max){
            max = string_length(Game.Elements[i].Nama);
        }
        i++;
    }
    return max;
}


void PrintScoreBoard(Map Game)
/*FUNGSI UNTUK MENAMPILKAN SCOREBOARD*/
{
    int maxstring = KataTerpanjang(Game);
    if (maxstring == 0)
    {
        printf("| %-10s | %-10s |\n", "NAMA", "SCORE");
        printf("-----SCOREBOARD KOSONG-----\n");
    }
    else
    {
        printf("| NAMA");
        for (int i = 0; i < maxstring + 2 ; i++)
        {
            printf(" ");
        }
        printf(" | %-10s |\n", "SKOR");
        for (int i = 0; i < maxstring + 23; i++)
        {
            printf("-");
        }
        printf("\n");
        for (int i = 0; i < Game.Count; i++)
        {
            printf("| %s", Game.Elements[i].Nama);
            for (int j = 0; j < maxstring - (string_length(Game.Elements[i].Nama) - 6); j++)
            {
                printf(" ");
            }
            printf(" | %-10d |\n", Game.Elements[i].Skor);
        }
    }
}

boolean yes()
/*VALIDASI APAKAH MASUKAN BERUPA STRING "YES" */
{

    boolean value = false;
    boolean valid = false;
    while(!valid){
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK)\n");
        STARTCOMMANDGAME();
        char*temp = (char*) malloc (currentCMD.Length* sizeof(char));
        wordToString(currentCMD , temp);
        if (CompareString(temp, "YA")){
            value = true;
            valid = true;}
        else if (CompareString(temp, "TIDAK")){
            value = false;
            valid = true;}
        else{
            printf("Masukan tidak valid, silahkan masukan kembali\n");
        }
    }

   return value; 
}


void History(Stack Game , int n)
/*FUNGSI UNTUK MENAMPILKAN RIWAYAT PERMAINAN YANG TELAH DIMAINKAN*/
{
    if(IsEmptyStack(Game)){
        printf("Belum ada game yang dimainkan\n");
    }
    else {
        if(n <= Top(Game) + 1 && n > 0){
            printf("Berikut adalah daftar Game yang telah dimainkan \n");
            int nomor = 0;
            // char *TOP;
            for(int i=n-1;i>=0;i--){
                nomor = nomor + 1;
                printf("%d. %s\n", nomor , Game.T[i] );
                }
        }
        else if (n > Top(Game) + 1) {
            // printf("Masuk ke kasus2 : \n");
            printf("Berikut adalah daftar Game yang telah dimainkan \n");
            int nomor = 0;
            for(int i=Top(Game);i>=0;i--){
                nomor = nomor + 1;
                printf("%d. %s\n", nomor , Game.T[i] );
                }
        }
        else if(n <= 0){
            printf("Masukan tidak valid , harap masukan angka dengan besar minimal 1\n");
        }
        else {
            printf("Masukan tidak valid , harap masukan angka dengan besar minimal 1\n");
        }
    }
}

void ResetHistory (Stack * Game)
/*FITUR UNTUK MENGHAPUS RIWAYAT PERMAINAN YANG TELAH DIMAINKAN*/
{
    
    if(yes()){
        CreateEmptyStack(Game);
        if(IsEmptyStack(*Game)){
            printf("History berhasil direset\n");
        }
        else {
            printf("History gagal direset\n");
        }
        
    }
    else{
        printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        int n = Top(*Game);
        int nomor = 0;
            for(int i=n;i>=0;i--){
                nomor = nomor + 1;
                printf("%d. %s\n", nomor , (*Game).T[i] );
                }
    }
}

/***************************************** SNAKE ON METEOR ********************************************/
void SnakeOnMeteor(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score){
    printf("============== WELCOME TO ==============\n");
    printf("===== S N A K E  O N  M E T E O R ======\n");
	printf("========================================\n");
    printf(" ▄████████▄    ▄███████▄    |\n");
    printf(" ███    ███    ███    ██    |\n");
    printf(" ███    ███    ███    ██  ▄███▄\n");
    printf(" ███    ███    ███    ██  █▀█▀█\n");
    printf(" ███    ███    ███    ██  ▀███▀\n");
    printf(" ███    ███    ███    ██   ███ \n");
    printf("  ▀█    ▀████████▀    ▀███████\n");
          
  
    
    
    
    // aturan permainan 
    printf("Peraturan permainan Snake on Meteor:\n");
    printf("1. Snake dapat bergerak ke atas, kiri, bawah, atau kanan dengan meng-input w/a/s/d TANPA SPASI!\n");
    printf("2. Tujuan permainan : Dapatkan skor tertinggi dengan menghindari obstacle dan meteor yang jatuh dari langit!\n");
    printf("3. Snake akan mati jika terkena meteor, obstacle, atau badan sendiri.\n\n");

    printf("Selamat bermain!\n\n");
    delay(5);
    printf("Mengenerate peta, snake, dan makanan . . .\n\n");
    delay(1);

    List L;
    CreateEmpty(&L);
    int X = randint(0,4);
    int Y = randint(0,4);

    Point P1;
    CreatePoint(&P1, X, Y);
    Point P2 = CreateNextPoint(P1);
    Point P3 = CreateNextNextPoint(P2,P1);

    CreateList3Elemen(&L, P1, P2, P3);

    Point Obstacle = GenerateObstacle(L);
    Point Food = GenerateFoodPertama(Obstacle, L);
    // di titik ini sudah terbentuk 3 elemen sesuai aturan dan 1 buah obstacle

//                  INTERFACE                   //

    printf("Berhasil digenerate!\n\n");

    printf("________________________________\n\n\n");

    // selanjutnya adalah pergerakan snake dan summon meteor

    int turn = 1;
    boolean turnPertama = true;
    boolean gerak = false; // kalo gerak = true, snake bergerak
    boolean input = false; // kalo input = true, lakukan operasi (belum tentu gerak, bisa aja nabrak obstacle)
    Point Meteor;
    CreatePoint(&Meteor, -1, -1);
    printmap(L, Meteor, Food, Obstacle);
    printf("\n");
    // CreatePoint(&Meteor, 5 ,5);
    do {

    printf("TURN %d\n", turn);
    printf("Silahkan masukkan command anda:");
    STARTCOMMANDGAME();
    IgnoreBlanksCMD(); // kalo ada blank
    printf("\n");

    Point Geser;
    Geser = Info(Head(L));

    if (currentCMD.Length == 1 )
    {
    if (wordAndCharSama(currentCMD,"a") || wordAndCharSama(currentCMD,"A"))
    {
        Absis(Geser) = Absis(Geser) - 1;
        while (Absis(Geser) < 0)
        {
            Absis(Geser) = Absis(Geser) + 5;
        }
        if (IsHeadBakalNabrakBadan(L, Geser))
        {
            input = false;
            printf("Input tidak valid. Dilarang bunuh diri!\n");
        }
        else
        {
            input = true;
        }
    }
    else if (wordAndCharSama(currentCMD, "d") || wordAndCharSama(currentCMD,"D"))
    {
        Absis(Geser) = Absis(Geser) + 1;
        while(Absis(Geser) > 4)
        {
            Absis(Geser) = Absis(Geser) - 5;
        }
        if (IsHeadBakalNabrakBadan(L, Geser))
        {
            input = false;
            printf("Input tidak valid. Dilarang bunuh diri!\n");
        }
        else
        {
            input = true;
        }
    }
    else if (wordAndCharSama(currentCMD, "w") || wordAndCharSama(currentCMD,"W"))
    {
        Ordinat(Geser) = Ordinat(Geser) - 1;
        while(Ordinat(Geser) < 0)
        {
            Ordinat(Geser) = Ordinat(Geser) + 5;
        }
        // printf("Geser: %d %d\n", Absis(Geser), Ordinat(Geser));
        if (IsHeadBakalNabrakBadan(L, Geser))
        {
            input = false;
            printf("Input tidak valid. Dilarang bunuh diri!\n");
        }
        else
        {
            input = true;
        }
    }
    else if (wordAndCharSama(currentCMD, "s") || wordAndCharSama(currentCMD,"S"))
    {
        Ordinat(Geser) = Ordinat(Geser) + 1;
        while(Ordinat(Geser) > 4)
        {
            Ordinat(Geser) = Ordinat(Geser) - 5;
        }
        if (IsHeadBakalNabrakBadan(L, Geser))
        {
            input = false;
            printf("Input tidak valid. Dilarang bunuh diri!\n");
        }
        else
        {
            input = true;
        }
    }
    else // input salah
    {
        printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        input = false;
    }}
    else // input salah
    {
        printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        input = false;
    }
 
    if (input) // input benar
    {
        if(IsMeteor(Geser, Meteor))
        {
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            printf("Silahkan masukkan command lainnya\n\n");
            gerak = false;
            input = false;
        }
        else 
        {
        if (IsFood(Food, Geser)) // dapet makanan
        {
            MoveList(&L, Geser);
            Food = GenerateFood(Obstacle, Meteor, L); // food auto muncul di next turn
            turn++;
            turnPertama = false;
            printf("Berhasil bergerak!\n");
            gerak = true;
        }
        else // ga dapet makanan
        {
            MoveList2(&L, Geser);
            turn++;
            turnPertama = false;
            printf("Berhasil bergerak!\n");
            gerak = true;
        } 
        }          
        
    }

    if (gerak) // fix move (gerak)
    {
        Meteor = GenerateMeteor(Obstacle, Food);
        printmap(L, Meteor, Food, Obstacle);
        if (IsBadanKenaMeteor(L, Meteor) && gerak)
        {
            DeleteDi(&L, Meteor);
            printf("\nAnda terkena meteor!\n");
            printmap(L, Meteor, Food, Obstacle);
            printf("\n");
            gerak = false;
            printf("Silahkan lanjutkan permainan\n");
        }
        else if (gerak && !IsHeadKenaMeteor(L, Meteor))
        {
            printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n\n");
            gerak = false;
        }
    }

    }while (!IsGameOver(L, Meteor, Obstacle) || (NbElmt(L) == 24));

    // INTERFACE GAMEOVER //
    int skor;
    if (IsHeadKenaMeteor(L, Meteor))
    {
        printf("Kepala snake terkena meteor!\n\n");
        skor = (NbElmt(L)*2)-2;
        printf("Game berakhir. Skor: %d\n\n", skor);
    }
    else if (IsEmptySOM(L))
    {
        printf("Snake mati karena tubuh snake terkena meteor semua!\n\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: 0.\n\n");
    }
    else if (IsObstacle(Obstacle, Info(Head(L)))) // nabrak obstacle
    {
        printf("Ada obstacle itu lho, yo jangan mbok tabrak to mas\n\n");
        gerak = false;
        input = false;
        skor = (NbElmt(L)*2)-2;
        printf("Game berakhir. Skor: %d\n\n", skor);
    }
    else if (NbElmt(L) == 24)
    {
        printf("Selamat! Anda berhasil menyelesaikan permainan!\n\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n\n", skor);
    }
    else if (!IsMasihBisaGerak(L, Obstacle, Meteor))
    {
        printf("Snake mati karena tidak bisa bergerak lagi!\n\n");
        skor = (NbElmt(L)*2)-2;
        printf("Game berakhir. Skor: %d\n\n", skor);
    }
    score = skor;
    Username(game , ListGames , GameMap , score);
}





void Hangman(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)
{
    // pilihan menu
    ListKata ListKata;
    MAKEEMPTYLISTKATA (&ListKata);
    boolean on = true;
    int skor = 0;
    while (on)
    {
        landingPage();
        STARTCOMMANDGAME();
        if ((wordAndCharSama(currentCMD, "1") && currentCMD.Length == 1) || (wordAndCharSama(currentCMD, "PLAY") && currentCMD.Length == 4))
        {
            boolean valid = false;
            while (!valid)
            {
                themePage();
                STARTCOMMANDGAME();
                if ((wordAndCharSama(currentCMD, "1") && currentCMD.Length == 1) || (wordAndCharSama(currentCMD, "KOTA") && currentCMD.Length == 4))
                {
                    loadkata(&ListKata, "KataKota.txt"); valid = true;
                }
                else if((wordAndCharSama(currentCMD, "2") && currentCMD.Length == 1) || (wordAndCharSama(currentCMD, "NEGARA") && currentCMD.Length == 6))
                {
                    loadkata(&ListKata, "KataNegara.txt"); valid = true;
                }
                else
                {
                    printInputNotValid();
                }
            }
            int kesempatan = 10;
            while (kesempatan > 0)
            {
                srand(time(NULL));
                int random = rand() % (ListKata.EFEKTIF);   
                char*Kata = WORDTOSTRING(ListKata.TI[random]);

                mainHangman(&kesempatan, Kata);
                if (kesempatan != 0) skor += panjang_kata(Kata);
            }
            printf("\nGAME OVER.");
            printf("\n\nSkor kamu adalah %d\n", skor); 
            
            on = false; 
        } 
        else if ((wordAndCharSama(currentCMD, "2") && currentCMD.Length == 1) || (wordAndCharSama(currentCMD, "HELP") && currentCMD.Length == 4))
        {
            helpHangman();
            printf("\n\nPress any key to continue..\n");
            STARTCOMMAND();
        }
        else if ((wordAndCharSama(currentCMD, "3") && currentCMD.Length == 1) || (wordAndCharSama(currentCMD, "TAMBAHKATA") && currentCMD.Length == 10))
        {
            boolean valid = false;
            char*file; char* tema;
            while (!valid)
            {
                themePage();
                STARTCOMMANDGAME();
                if ((wordAndCharSama(currentCMD, "1") && currentCMD.Length == 1) || (wordAndCharSama(currentCMD, "KOTA") && currentCMD.Length == 4))
                {
                    file = "KataKota.txt"; tema = "KOTA";
                    loadkata(&ListKata, file); valid = true;
                }
                else if ((wordAndCharSama(currentCMD, "2") && currentCMD.Length == 1) || (wordAndCharSama(currentCMD, "NEGARA") && currentCMD.Length == 6))
                {
                    file = "KataNegara.txt"; tema = "NEGARA";
                    loadkata(&ListKata, file); valid = true;
                }
                else
                {
                    printInputNotValid();
                }
            }
            printf("\nSilakan memasukkan ");
            printf("%s", tema);
            printf(" yang ingin kamu tambahkan");
            printf("\n(DALAM HURUF KAPITAL) :");
            STARTCOMMANDGAME();
            int n = ListKata.EFEKTIF;
            SetElListKata(&ListKata, n+1, currentCMD);
            saveListKata(ListKata, file);
        }
        else if ((wordAndCharSama(currentCMD, "4") && currentCMD.Length == 1) || (wordAndCharSama(currentCMD, "QUIT") && currentCMD.Length == 4))
        {
            printf("\nSad to say goodbye to you! :(((\n");
            on = false;
        }
        else
        {
            printInputNotValid();
        }
    }
    score = skor;
    Username(game , ListGames , GameMap , score);
}

void mainHangman(int*kesempatan, char*Kata)
{
    Kata[string_length(Kata)] = '\0';

    char huruf;
    char GuessedHuruf[10]; GuessedHuruf[0] = '\0';

    char GuessedKata[20];
    for (int i = 0; i < string_length(Kata); i++){
        GuessedKata[i] = '_';
    }
    GuessedKata[panjang_kata(Kata)] = '\0';

    printf("\n%s", GuessedHuruf);
    
    int n;
    boolean win = false;
    while (!win && *kesempatan > 0){
        printf("\nTebakan Sebelumnya: ");
        n = panjang_kata(GuessedHuruf);
        PrintCharWithSpace(GuessedHuruf, n);

            // print progress tebakan kata pemain
        printf("\nKata: ");
        n = panjang_kata(GuessedKata);
        PrintCharWithSpace(GuessedKata, n);

            // print kesempatan yang tersisa
        printf("\nKesempatan: %d", *kesempatan);

            // memasukkan tebakkan
        printf("\nMasukkan tebakan: ");
        STARTCOMMAND();

        wordToString(currentCMD, &huruf);

        if (currentCMD.Length == 1){

            if (isHurufAda(huruf, GuessedHuruf)){

                printf("\nKamu sudah menebak huruf %c!\n", huruf);
                (*kesempatan)-=1;

            } else {

                if (isHurufAda(huruf, Kata) == false){

                    printf("\nTebakan kamu salah!\n\n");
                    (*kesempatan)-=1;

                } else {

                    printf("\nSelamat, tebakan kamu benar!\n");
                    underscoreToHuruf(huruf, GuessedKata, Kata);

                    if (!isHurufAda('_', GuessedKata)){
                        win = true;
                    } else {
                        win = false;
                    }

                }
                InsertKataLast(huruf, GuessedHuruf);
            }
            hangedMan(*kesempatan);
        } else 
        {
            printf("\nMasukkan hanya satu huruf!\n");
            (*kesempatan)--;
        }
    }
    if (win == true){
        printf("\nBerhasil menebak "); PrintCharNoSpace(Kata, panjang_kata(Kata));
        printf("! Kamu mendapatkan %d poin!", panjang_kata(Kata));
    }
            if ((*kesempatan) == 0) printf("\nKesempatan habis! Total poin yang kamu dapatkan adalah ");
}

void loadkata(ListKata *ListKata, char*filename)
{
    char path[NMax];
    stringConcat("ADT/Hangman/",filename,path);
    STARTWORD(path);
    int nGame = WordToInt(currentWord);
    for (int i = 1; i <= nGame; i++){
        ADVLine();
        SetElListKata(ListKata, i, currentWord);
    }
}

void saveListKata(ListKata ListKata, char*filename)
{
    FILE* fp; 
    char path[50]; 
  
    stringConcat("ADT/Hangman/",filename,path); 
    fp = fopen(path,"w"); 

    fprintf(fp,"%d",ListKata.EFEKTIF); 
    for(int i = 1; i <= ListKata.EFEKTIF;i++) 
    {
        char*string = wordToStr(ListKata.TI[i]);
        fprintf(fp,"\n%s", string); 
    } 
    fclose(fp); 
  
    fp = fopen(path, "r"); 
    if (fp != NULL) 
    { 
        printf("Kata berhasil ditambahkan!\n");
        fclose(fp); 
    } else printf("Kata gagal ditambahkan!\n");
}

boolean isTebakanValid(Word word)
{
    if (word.Length =! 1) return false;
    else true;
}

boolean isHurufAda(char huruf, char* kata)
{
    int i = 0;
    boolean found = false;
	while(!found && i < panjang_kata(kata))
    {
        if (kata[i] == huruf) found = true;
        i++;
    }
    return found;
}

void underscoreToHuruf(char huruf, char* GuessedKata, char* kata)
{
    for (int i = 0; i < string_length(kata); i++)
    {
        if (huruf == kata[i]){
            *(GuessedKata+i) = huruf;
        }
    }
}

void PrintCharWithSpace(char* kata, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%c ", kata[i]);
	}
	printf("\n");
}

void PrintCharNoSpace(char* kata, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%c", kata[i]);
	}
}

int panjang_kata(char*s){
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}

void InsertKataLast(char huruf, char*kata)
{
    int n = panjang_kata(kata);
    kata[n] = huruf;
    kata[n+1] = '\0';
}

char* wordToStr(Word word)
{
    char*str = (char *)malloc(sizeof(char) * word.Length);

    int i = 0;
    while (i < word.Length)
    {
        str[i] = word.TabWord[i];
        i++;
    }
    str[i] = '\0';  

    return str;  
}





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
    int a = 10;
    if (steps>ms)
    {
        steps-=ms;
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

void cekValiditas(char tow1, char tow2, STACKSS a, STACKSS b, STACKSS c, boolean *valid)
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

void TowerOfHanoi(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)
{
    // Kamus
    int countsteps = 0;
    char * tempsti = (char *) malloc (MaxEl*sizeof(char));
    int skor = 0;

    // Menciptakan "towers"
    STACKSS a;
    STACKSS b;
    STACKSS c;
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
    scoring(countsteps,&skor,jml_disk);
    printf("Kamu berhasil!\n");
    printf("Skor didapatkan: %d\n", skor);
    score = skor;
    Username(game , ListGames , GameMap , score);
    
    free(tempd.sym);
    free(tempst.sym);
    free(tempsti);
}



// void delay(int number_of_seconds)
// {
//     // Converting time into milli_seconds
//     int milli_seconds = 1000 * number_of_seconds;
 
//     // Storing start time
//     clock_t start_time = clock();
 
//     // looping till required time is not achieved
//     while (clock() < start_time + milli_seconds);
// }

void toriel(BinTree* p , char*name , int *score)
{
    printf("              C H A P T E R - 1 , T O R I E L            \n");
    printf("************************************************************\n");
    delay(2);
    printf("Your journey in the underground have started...\n");
    printf("You encounter a flower-like creature, and it talks!\n");
    delay(2);
    printf("\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⡿⢿⣏⣉⠉⠙⠿⢿⣿⠿⠏⠉⠉⣽⡿⠿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣅⠀⣄⣴⣿⣿⠿⠿⠿⠿⠿⠿⣿⣿⣿⣤⠀⢨⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⠏⠉⠉⢿⣿⣿⠏⠀⠀⢀⣀⠀⠀⣄⡀⠀⠀⠙⢿⣿⡿⠋⠉⠙⢿⣿⣿\n");
    printf("⣿⡏⠀⠲⠶⠶⣾⣿⠀⠀⠀⠀⢸⣿⠀⠀⣿⡇⠀⠀⠀⠀⣿⣷⠶⠶⠶⠀⠙⣿\n");
    printf("⣿⣷⣦⡀⠀⠀⢸⣿⣄⠀⠰⢦⣈⣉⣀⣀⣩⣁⣰⠆⠀⢀⣿⡇⠀⠀⠀⣰⣶⣿\n");
    printf("⣿⣿⣿⣿⣶⣶⣶⡾⣿⣆⠀⠀⠙⠶⠶⠶⠶⠎⠀⠀⣠⣾⠿⣶⣶⣶⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⡿⠏⠀⢠⠿⢿⣿⣶⣄⣀⣀⣀⣀⣀⣶⣾⣿⠿⣄⠀⠙⢿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⡇⠀⠸⠇⠀⠀⠀⠈⢻⣋⣹⣏⣙⡏⠉⠀⠀⠀⠘⠇⠀⢸⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣿⣿⣿⡿⢿⣿⣿⣿⣿⣿⣶⣶⣶⣶⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣄⠀⠘⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠧⠀⠸⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠧⠀⠸⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("\n");
    delay(2);
    printf("Peculiar Flower: Hi.. I'm Flowey!\n");
    printf("\n");
    printf("You sense a peculiarity in it, and not long after...\n");
    delay(3);
    printf("\n");
    printf("\n");
    printf("\n");
    printf("D   I   E   !\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("Oh no, the flower is actually evil!  (꒪_/꒪)\n");
    printf("Luckily, not long after... a goat creature came to your rescue!\n");
    delay(2);
    printf("Toriel: Oh.. Hello!\n");
    delay(2);
    printf("Toriel: My name is Toriel, keeper of the Undergrounds!\n");
    delay(2);
    printf("Toriel: Please be careful, my child, as this place is not safe\n");
    printf("\n");
    delay(2);
    printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-");
    printf("\n");
    printf("Toriel then brings you to her home and cares for you. It seems like\n");
    delay(2);
    printf("She had lost her own child before, and so she is very protective of you...\n");
    delay(2);
    printf("But you must return to your world. You cannot remain.\n");
    delay(2);
    printf("To do so, one day, you went to the gate she explicitly told you to avoid...\n");
    printf("\n");
    delay(2);
    printf("Toriel arrives shortly afterwards with a dissapointed look on her face.\n");
    delay(2);
    printf("Toriel: My dear child.. I cannot let you through these gates...\n");
    delay(2);
    printf("However... must you insist, you'll need to face me first...\n");
    delay(2);
    printf("Prove to me, child, that you are strong enough to proceed.\n");
    delay(2);
    printf("\n");
    delay(3);
    printf("************************************************************\n");
    printf("      Y O U - H A V E - E N T E R E D - A - F I G H T\n");
    printf("************************************************************\n");
    printf("\n");

    torielfight(score,name);

    printf("You have succeeded in defeating Toriel. Would you like to Kill or Spare her? (K/S) \n");
    boolean lanjut = false;
    while (!lanjut)
    {
        STARTCMD();
        if (wordStringEq(CURRENTCOMMAND,"K"))
        {
            lanjut = true;
            printf("Toriel: Why.. would.. you do this..?\n");
            printf("Toriel perished. You open the gate in front of you to proceed in your journey.\n");
            printf("\n");
            *p = Left(*p);
        } else if (wordStringEq(CURRENTCOMMAND,"S")) {
            lanjut = true;
            printf("Toriel: My child.. you have a kind heart.\n");
            printf("Toriel: Proceed as you wish. May you always be protected.\n");
            printf("You hugged Toriel, and stepped onto the gate to proceed with your Journey.\n");
            *p = Right(*p);
        } else {
            printf("Please input K or S in capital.\n");
        }

    }
}

void papyrus(BinTree* p , char*name , int *score)
{   printf("\n");
    printf("              C H A P T E R - 2 , P A P Y R U S           \n");
    printf("************************************************************\n");
    delay(2);
    printf("You have just emerged outside of the Ruins (Undergrounds)...\n");
    delay(2);
    printf("You have reached an area filled with snow...\n");
    printf("❄ ❄ ❄ ❄ ❄ ❄ ❄\n");
    printf("      ❄ ❄ ❄ ❄ ❄ ❄ ❄\n");
    printf("              ❄ ❄ ❄ ❄ ❄ ❄ ❄\n");
    printf("                     ❄ ❄ ❄ ❄ ❄ ❄ ❄\n");
    printf("                             ❄ ❄ ❄ ❄ ❄ ❄ ❄\n");
    printf("\n");
    delay(2);
    printf("Behind all the trees and snow.. you discovered what looks like.. a skull?!\n");
    delay(2);
    printf("Sans: Hey, human!\n");
    delay(2);
    printf("Sans: Quick, hide behind that lamp!\n");
    delay(2);
    printf("Sans points to a nearby lamp. You notice a taller, more slender skeleton approaching\n");
    delay(2);
    printf("You quickly hid behind the lamp.\n");
    delay(2);
    printf("\n");
    printf("Papyrus: Hey, don't you smell a human nearby?\n");
    delay(2);
    printf("Sans: Oh hey, bro! Ahh, it's probably just you and your mind.\n");
    delay(2);
    printf("Papyrus: Hmm... is that so..\n");
    delay(2);
    printf("Papyrus: Oh well, I'm off then!\n");
    delay(2);
    printf("\n");
    printf("Papyrus leaves the scene.\n");
    delay(2);
    printf("\n");
    printf("Sans: He's gone, Kid\n");
    delay(2);
    printf("You emerge out of the lamp to thank him. Sans left afterwards.\n");
    delay(2);
    printf("You continue to walk...\n");
    delay(2);
    printf("To your surprise, Papyrus was still nearby and ambushed you.\n");
    delay(2);
    printf("Papyrus: ALL HUMANS SHALL PERISH!\n");

    delay(2);
    printf("\n");
    printf("************************************************************\n");
    printf("      Y O U - H A V E - E N T E R E D - A - F I G H T\n");
    printf("************************************************************\n");

    printf("\n");
    papyrusfight(score,name);
    printf("\n");

    printf("You have succeeded in defeating Papyrus. Would you like to Kill or Spare him? (K/S) \n");
    boolean lanjut = false;
    while (!lanjut)
    {
        STARTCMD();
        if (wordStringEq(CURRENTCOMMAND,"K"))
        {
            lanjut = true;
            delay(2);
            printf("Papyrus: I knew it.. humans are nothing but trash...\n");
            delay(2);
            printf("Papyrus perished. You aim for King Asriel's palace, the only way out from the Undergrounds..\n");
            printf("\n");
            *p = Left(*p);
        } else if (wordStringEq(CURRENTCOMMAND,"S")) {
            lanjut = true;
            delay(2);
            printf("Papyrus: But.. but I thought humans were bad..\n");
            printf("Papyrus: Seems that I have misjudged you.. I apologize..\n");
            delay(2);
            printf("Papyrus: From now on, Papyrus will always be by your side!\n");
            printf("You shook hands with Papyrus, and he led you towards King Asriel's palace, the only way out from the Undergrounds..\n");
            *p = Right(*p);
        } else {
            printf("Please input K or S in capital.\n");
        }
    } 
}

void lastcorridor()
{
    printf("        C H A P T E R - 3 , L A S T - C O R R I D O R       \n");
    printf("************************************************************\n");
    delay(2);
    printf("\n");
    printf("You have reached King Asriel's palace.\n");
    delay(2);
    printf("Using the elevators inside, you went straight to the top level.\n");
    delay(2);
    printf("It's the corrdior before King Asriel's throne.\n");
    delay(2);
    printf("On the edge of the palace, you see a familiar sight.\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("░░░░░░░░██████████████████\n");
    printf("░░░░████░░░░░░░░░░░░░░░░░░████\n");
    printf("░░██░░░░░░░░░░░░░░░░░░░░░░░░░░██\n");
    printf("░░██░░░░░░░░░░░░░░░░░░░░░░░░░░██\n");
    printf("██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██\n");
    printf("██░░░░░░░░░░░░░░░░░░░░██████░░░░██\n");
    printf("██░░░░░░░░░░░░░░░░░░░░██████░░░░██\n");
    printf("██░░░░██████░░░░██░░░░██████░░░░██\n");
    printf("░░██░░░░░░░░░░██████░░░░░░░░░░██\n");
    printf("████░░██░░░░░░░░░░░░░░░░░░██░░████\n");
    printf("██░░░░██████████████████████░░░░██\n");
    printf("██░░░░░░██░░██░░██░░██░░██░░░░░░██\n");
    printf("░░████░░░░██████████████░░░░████\n");
    printf("░░░░░░████░░░░░░░░░░░░░░████\n");
    printf("░░░░░░░░░░██████████████\n");
}

void megalovania(BinTree* p , char*name , int*score)
{
    lastcorridor();

    printf("\n");
    printf("Sans: Heya, Kid.\n");
    delay(2);
    printf("Sans: You've been busy, Huh?\n");
    delay(2);
    printf("Sans: Just going around, killing everyone you see\n");
    delay(3);
    printf("Sans: So, i've got a question for ya.");
    delay(2);
    printf("Sans: Do you think even the worst person can change?\n");
    delay(2);
    printf("\n");
    printf("Despite his dialogue, you step forward, bringing out your knife.\n");
    delay(2);
    printf("\n");
    printf("Sans: Heh.. here's a better question.\n");
    delay(2);
    printf("Sans: Do you wanna have a bad time? Cause if you step forward...\n");
    delay(2);
    printf("Sans: You're REALLY not going to like what happens next.\n");
    delay(2);
    printf("\n");
    delay(3);
    printf("You take one more step forward.\n");
    printf("\n");
    delay(2);
    printf("Sans: Welp, here we go.\n");

    delay(2);
    printf("\n");
    printf("************************************************************\n");
    printf("      Y O U - H A V E - E N T E R E D - A - F I G H T\n");
    printf("************************************************************\n");
    printf("\n");

    sansfight(score,name);
    printf("\n");

    printf("You have succeeded in defeating Sans. Would you like to Kill or Spare him? (K/S) \n");
    boolean lanjut = false;
    while (!lanjut)
    {
        STARTCMD();
        if (wordStringEq(CURRENTCOMMAND,"K"))
        {
            lanjut = true;
            printf("Sans: Heh.. heh...\n");
            delay(2);
            printf("Sans: At least.. I get to be with my brother now..\n");
            delay(2);
            printf("\n");
            printf("You proceed to Asriel's throne.\n");
            printf("\n");
            *p = Left(*p);
        } else if (wordStringEq(CURRENTCOMMAND,"S")) {
            lanjut = true;
            delay(2);
            printf("Sans: You should've just killed me.. kid.\n");
            delay(2);
            printf("Sans: Just like you did with everyone else, right?\n");
            delay(2);
            printf("Sans: Just like you did.. with my brother.\n");
            printf("\n");
            delay(2);
            printf("You proceed to Asriel's throne.\n");
            printf("\n");
            *p = Right(*p);
        } else {
            printf("Please input Y or N in capital.\n");
        }
    }

}

void sansneutral(BinTree* p , char*name , int *score)
{
    lastcorridor();
    printf("\n");
    delay(2);
    printf("Sans: Heya, Kid.\n");
    delay(2);
    printf("Sans: How does it feel? You're finally at the end of your journey...\n");
    delay(2);
    printf("Sans: Beyond these gates, is the throne of King Asriel\n");
    delay(2);
    printf("Sans: There, you will be at the pinnacle of life and death...\n");
    delay(3);
    printf("Sans: Take a moment to reflect upon your actions in the past...\n");
    delay(2);
    printf("Sans: Those people that you've murdered.. and those you've spared\n");
    delay(2);
    printf("Sans: Well.. at least you were honest with yourself..\n");
    delay(3);
    *p = Left(*p);
}

void sanspacifist(BinTree* p ,char*name , int *score)
{
    lastcorridor();
    printf("\n");
    printf("Sans: Heya, Kid.\n");
    delay(2);
    printf("Sans: How does it feel? You're finally at the end of your journey...\n");
    delay(2);
    printf("Sans: Beyond these gates, is the throne of King Asriel\n");
    delay(2);
    printf("Sans: There, you will be at the pinnacle of life and death...\n");
    delay(2);
    printf("Sans: Take a moment to reflect upon your actions in the past...\n");
    delay(3);
    printf("Sans: ...\n");
    delay(2);
    printf("Sans: But you've always been a kind soul, haven't you?\n");
    delay(2);
    printf("Sans: Even if you're thrown in situations that you didn't want to face\n");
    delay(2);
    printf("Sans: Even if you ran away.. you ran away with a smile\n");
    delay(2);
    printf("Sans: You gained love from all of us.\n");
    delay(2);
    printf("Sans: We're all rooting for ya, Kid.\n");
    *p = Left(*p);
}

void asriel(BinTree p , char*name , int *score)
{
    printf("              C H A P T E R - 4 , T H E  E N D   \n");
    printf("************************************************************\n");
    printf("\n");
    printf("                              {} {}\n");
    printf("                        !  !  II II  !  !\n");
    printf("                     !  I__I__II II__I__I  !\n");
    printf("                     !  I__I__II II__I__I  !\n");
    printf("                     I_/|--|--||   ||--|____I\n");
    printf("                     |_____|           |____|\n");
    printf("                     |_____|           |____|\n");
    printf("                     |_____|           |____|\n");
    printf("                     |_____|           |____|\n");
    printf("                     |_____|           |____|\n");
    printf("                     |_____|           |____|\n");
    printf("                     |_____|           |____|\n");
    printf("                     |_____|           |____|\n");
    printf("                     |_____|           |____|\n");
    printf("                     I_/|--|--||   ||--|____I\n");
    printf("                     !   I__I__II II__I__I  !\n");
    printf("                    ||I      ---------      I||\n");
    printf("                    ||I      ---------      I||\n");
    printf("                    //      ---------       I__\n");
    printf("\n");
    printf("You finally reached Asriel's Throne.\n");
    delay(3);
    printf("Asriel: Welcome, Human.\n");
    delay(3);
    printf("Asriel: You know what must happen... right?\n");
    delay(3);
    printf("Asriel: You know what I must do.. to protect the creatures in the Underground...\n");
    
    if (p->Info=='H')
    {
        delay(3);
        printf("Asriel: But I guess you do not have the heart... to understand that\n");
        delay(2);
        printf("Asriel gets off his throne.\n");
        delay(2);
        printf("Asriel: Whenever you're ready, human.\n");
    } else if (p->Info=='O') {
        delay(2);
        printf("Asriel: Even though I do not want to.. since you have the kindest heart.\n");
        delay(3);
        printf("Asriel: Forgive me, human.\n");
        delay(2);
        printf("Asriel gets off his throne.\n");
        delay(2);
        printf("Asriel: Whenever you're ready, human.\n");
    } else {
        delay(2);
        printf("Asriel gets off his throne.\n");
        delay(2);
        printf("Asriel: Whenever you're ready, human.\n");
    }

    printf("\n");
    printf("Are you read to fight Asriel? (Y/N)\n");
    boolean ready = false;
    while (!ready)
    {
        STARTCMD();
        if (wordStringEq(CURRENTCOMMAND,"Y"))
        {
            ready = true;
        } else if (wordStringEq(CURRENTCOMMAND,"N")) {
            printf("Take your time.\n");
            printf("Type in 'Y' whenever you are ready.\n");
        } else {
            printf("Please input Y or N in capital\n");
        }
    }

    printf("\n");
    printf("************************************************************\n");
    printf("      Y O U - H A V E - E N T E R E D - A - F I G H T\n");
    printf("************************************************************\n");
    printf("\n");

    asrielfight(score,name);
}

boolean end(char a)
{
    return a == 'H' || a == 'I' || a == 'J' || a == 'K' || a == 'L' || a == 'M' || a == 'N' || a == 'O';
}

void beginning()
{
    printf("                 T H E - B E G I N N I N G                  \n");
    printf("************************************************************\n");
    printf("Long ago, two races ruled over Earth: HUMANS and MONSTERS\n");
    printf("One day, war broke out between the two races.\n");
    printf("After a long battle, the humans were victorious\n");
    printf("They sealed the monsters underground with a magic spell.\n");
    printf("Many years later...a human fell into the depths of Mt. Ebbot\n");
    printf("************************************************************\n");
    printf("\n");
}
void createRoute(BinTree* route, BinTree* l, BinTree* r)
{
    MakeTree('A',*l,*r,route);
    AddDaun (route,'A','B', true);
    AddDaun (route,'A','C', false);
    AddDaun (route,'B','D', true);
    AddDaun (route,'B','E', false);
    AddDaun (route,'C','F', true);
    AddDaun (route,'C','G', false);
    AddDaun (route,'D','H', true);
    AddDaun (route,'D','I', false);
    AddDaun (route,'E','J', true);
    AddDaun (route,'E','K', false);
    AddDaun (route,'F','L', true);
    AddDaun (route,'F','M', false);
    AddDaun (route,'G','N', true);
    AddDaun (route,'G','O', false);
}

void undertale(char*game , ArrayDin ListGames , ArrayOfMap *GameMap , int nilai)
{
    printf(" _______ _______ _____  _______ ______ _______ _______ _____   _______ \n");
    printf("|   |   |    |  |     \\    ___|   __ \\_    _|   _   |     |_|    ___|\n");
    printf("|   |   |       |  --  |    ___|      < |   | |       |       |    ___|\n");
    printf("|_______|__|____|_____/|_______|___|__| |___| |___|___|_______|_______|\n");

    printf("\n");    
    printf("\n"); 
    printf("\n");                                               

    printf("░░░░░░░░░░░▄▀▄▀▀▀▀▄▀▄░░░░░░░░░░░░░░░░░░\n");
    printf("░░░░░░░░░░░█░░░░░░░░▀▄░░░░░░▄░░░░░░░░░░\n");
    printf("░░░░░░░░░░█░░▀░░▀░░░░░▀▄▄░░█░█░░░░░░░░░\n");
    printf("░░░░░░░░░░█░▄░█▀░▄░░░░░░░▀▀░░█░░░░░░░░░\n");
    printf("░░░░░░░░░░█░░▀▀▀▀░░░░░░░░░░░░█░░░░░░░░░\n");
    printf("░░░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░░\n");
    printf("░░░░░░░░░░█░░░░░░░░░░░░░░░░░░█░░░░░░░░░\n");
    printf("░░░░░░░░░░░█░░▄▄░░▄▄▄▄░░▄▄░░█░░░░░░░░░░\n");
    printf("░░░░░░░░░░░█░▄▀█░▄▀░░█░▄▀█░▄▀░░░░░░░░░░\n");
    printf("░░░░░░░░░░░░▀░░░▀░░░░░▀░░░▀░░░░░░░░░░░░\n");

    printf("\n");  
    printf("\n");  

    printf("Type 'START' in all capitals to start! ");

    STARTCMD();

    while (!wordStringEq(CURRENTCOMMAND,"START"))
    {
        printf("Invalid command! (꒪‸/꒪)\n");
        printf("Type 'START' in all capitals to start!");
        STARTCMD();
    }

    printf("\n");  

    BinTree route,l,r;
    createRoute(&route,&l,&r);
    
    BinTree pointer = route;

    int score = 0;

    beginning();

    // Giving the character a name
    printf("\n");
    printf("(。╹‿ ╹ 。)\n");
    printf("Name the fallen Human\n");
    STARTCMD();
    char* name;
    /*Ini aku ijin ganti funsginya*/
    name = KATATOSTRING(CURRENTCOMMAND);
    boolean correct = false;
    while (!correct)
    {
        printf("Is this name correct? (Y/N)\n");
        printf("%s\n", name);
        printf("\n");
        STARTCMD();
        printf("\n");
        if (wordStringEq(CURRENTCOMMAND,"Y"))
        {
            correct = true;
        } else if (wordStringEq(CURRENTCOMMAND,"N")) {
            printf("Name the fallen Human\n");
            STARTCMD();
        } else {
            printf("Please input Y or N in capital\n");
        }
    }

    printf("Dear %s, WELCOME TO UNDERTALE.\n", name);
    printf("In undertale, your every choice determines how your story ends.\n");
    printf("Choose wisely. Follow your heart.\n");
    printf("\n");

    while (!end(pointer->Info))
    {
        if (pointer->Info == 'A')
        {
            toriel(&pointer , name , &score);
        } else if (pointer->Info == 'B' || pointer->Info == 'C') {
            papyrus(&pointer , name , &score);
        } else {
            if (pointer->Info == 'D')
            {
                megalovania(&pointer , name , &score);
            } else if (pointer->Info == 'G') {
                sanspacifist(&pointer , name , &score);
            } else {
                sansneutral(&pointer , name , &score);
            }
        }
    }

    asriel(pointer , name , &score);

    printf("\n");
    printf("***************************************************************************\n");
    printf("      Y O U - H A V E - E S C A P E D - T H E - U N D E R G R O U N D\n");
    printf("***************************************************************************\n");
    printf("\n");

    printf("Thank you for playing\n");
    printf(" _______ _______ _____  _______ ______ _______ _______ _____   _______ \n");
    printf("|   |   |    |  |     \\    ___|   __ \\_    _|   _   |     |_|    ___|\n");
    printf("|   |   |       |  --  |    ___|      < |   | |       |       |    ___|\n");
    printf("|_______|__|____|_____/|_______|___|__| |___| |___|___|_______|_______|\n");
    printf("\n");
    printf("Remember that every choice you make in life Matters.\n");
    printf("\n");

    Username(game , ListGames , GameMap , nilai);
}

// void WelcomingTorielFight(){
//     printf("\n");
// }
void torielfight(int *score , char*Username)
/*Melakukan permainan Rock , Paper , Scissors dimana user akan menginput Rock , Paper , atau scissors*/
{
    int skor = 100;
    int langkah = 0;
    Map RPS;
    CreateEmptyMap(&RPS);
    Insert(&RPS, "rock", 1);
    Insert(&RPS, "paper", 2);
    Insert(&RPS, "scissors", 3);
    // for (int i = 0;i < RPS.Count ; i++){
    //     printf("%s %d\n", RPS.Elements[i].Nama, RPS.Elements[i].Skor);
    // }
    boolean win = false;
    boolean valid = false;
    int random;
    char *input;
    while(!valid && !win){
        langkah++;
        srand(time(0));
        random = randint(1, 3);
        //printf("random integer = %d\n",random);
        //char *RPSopponet = copystr(RPS.Elements[random - 1].Nama);
        printf("RPSOpponet = %s\n",RPS.Elements[random - 1].Nama);
            
            printf("rock / paper / scissors \n");
            printf("Enter your choice:");
            STARTCOMMANDGAME();
            input = WORDTOSTRING(currentCMD);
            //printf("input = %s\n", input);
            if(IsUsernameEqual(input, "rock") || IsUsernameEqual(input, "paper") || IsUsernameEqual(input, "scissors")){
                valid = true;
                //printf("masuk\n");
                //printf("value input = %d\n" , Skor(RPS, input));
                if (IsUsernameEqual(input, "rock")){
                    if (random == 3){
                        printf("Draw\n");
                    } else if (random == 2){
                        printf("You lose\n");
                    } else if (random == 1){
                        printf("You win\n");
                        win = true;
                    }
                } else if (IsUsernameEqual(input, "paper")){
                    if (random == 3){
                        printf("You win\n");
                        win = true;
                    } else if (random == 2){
                        printf("Draw\n");
                    } else if (random == 1){
                        printf("You lose\n");
                    }
                } else if (IsUsernameEqual(input , "scissors")){
                    if (random == 3){
                        printf("You lose\n");
                    } else if (random == 2){
                        printf("You win\n");
                        win = true;
                    } else if (random == 1){
                        printf("Draw\n");
                    }
                } 
                //EndWord = true;
                if(!win){
                    valid = false;
                }
            }
            else{
                printf("Inputan Salah! Silahkan Input kembali berupa rock / paper / scissor\n");
            }
        
    }
    skor = (skor - (langkah * 1)) + 1;
    printf("skor RPS %d\n", skor);
    (*score) += skor;
} 
void WelcomingGamePapyrus(){
printf("     __________ \n");
printf("    | ________ |\n");
printf("    ||12345678||\n");
printf("    |~~~~~~~~~~|\n");
printf("    |[M|#|C][-]|\n");
printf("    |[7|8|9][+]|\n");
printf("    |[4|5|6][x]|\n");
printf("    |[1|2|3][%]|\n");
printf("    |[.|O|:][=]|\n");
printf("    ------------\n");
printf("\n");
printf(" :::::::::::::::::::::\n");
printf(" ::  !! WARNING !!  ::\n");
printf(" :::::::::::::::::::::\n");
printf("\n");
int rs = 175;
int ls = 174;
printf("%c Prepare Your Calculator %c\n",rs , ls);
printf("%c To win this game, you must maintain your health so that it is not below 70 %c\n",rs , ls);
printf("%c Every Mistake will reduce your health by 10 , so make sure there are no mistakes %c\n",rs , ls);
}
int mainpapyrus()
/*Basic nya mirip mathquiz cuman bedanya semua mode pertambahan , perkalian , dan pengurangan di jadiin satu 
dan dipisahkan dengan 3 stage berbeda*/
{
    /*FASE 1 - PERTAMBAHAN*/
    WelcomingGamePapyrus();
    printf("\n");
    int health = 100;
    int  a , b , c;
    int i = 0;
    int looping = 3;
    printf("Your Health = %d\n", health);
    boolean ulang1 = true;
    while(ulang1){
        printf("\nSTAGE 1\n");
        printf("GET READY ...\n\n");
        while(i < looping ){
                a = randint(0,20);
                b = randint(0,20);
                c = a + b;
                int masukan;
                //printf("hasil adalah %d\n" , c);
                printf("%d + %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    //printf("masuk\n");
                    masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        printf("Your Answer Is Correct\n");
                    }
                    else{
                        printf("Your Ansewr Is Wrong \n\n");
                        printf("The Answer Should Be %d\n",c);
                        health = health - 10;
                    }
                }
                else{
                    printf("Invalid Input !\n");
                }
                //printf("Skor kuis kamu sekarang adalah %d\n" , skor);
                IgnoreBlanksCMD();
                i++;   
                printf("\n");
            }
            boolean valid = false;
            printf("Your Health =  %d\n", health);
            while(!valid){
                printf("Do You Want To Repeat Stage 1 ? (yes/no)\n");
                STARTCOMMANDGAME();
                if(IsUsernameEqual(WORDTOSTRING(currentCMD), "yes")){
                    i = 0;
                    //looping = 3;
                    valid = true;
                    ulang1 = true;
                    health = 100;
                } else if (IsUsernameEqual(WORDTOSTRING(currentCMD), "no")){
                    ulang1 = false;
                    valid = true;  
                }
                else{
                    printf("Invalid Input !\n\n");
                }
            }
            
        }
    /*FASE 2 - PERKALIAN*/
    i = 0;
    int health1 = health;
    boolean ulang2 = true;
    while(ulang2){
        printf("\nSTAGE 2\n");
        printf("GET READY ...\n\n");
        while(i < looping ){
                a = randint(0,10);
                b = randint(0,10);
                c = a * b;
                int masukan;
                //printf("hasil adalah %d\n" , c);
                printf("%d x %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    //printf("masuk\n");
                    masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        printf("Your Answer Is Correct\n");
                    }
                    else{
                        printf("Your Answer Is Wrong \n\n");
                        printf("The Answer Should Be %d\n",c);
                        health = health - 10;
                    }
                }
                else{
                    printf("Invalid Input\n");
                }
                //printf("Skor kuis kamu sekarang adalah %d\n" , skor);
                IgnoreBlanksCMD();
                i++;   
                printf("\n");
            }
            boolean valid = false;
            printf("Your Health =  %d\n", health);
            while(!valid){
                printf("Do You Want To Repeat Stage 2 ? (yes/no)\n");
                STARTCOMMANDGAME();
                if(IsUsernameEqual(WORDTOSTRING(currentCMD), "yes")){
                    i = 0;
                    //looping = 3;
                    valid = true;
                    ulang2 = true;
                    health = health1;
                } else if (IsUsernameEqual(WORDTOSTRING(currentCMD), "no")){
                    ulang2 = false;
                    valid = true;  
                }
                else{
                    printf("Invalid Input !\n\n");
                }
            }
            
        }

    i = 0;
    int health2 = health;
    boolean ulang3 = true;
    while(ulang3){
        printf("\nSTAGE 3\n");
        printf("GET READY ...\n\n");
        while(i < looping ){
                a = randint(0,50);
                // while(a == 0){
                //     a = randint(0,50);
                // }
                b = randint(0,50);
                // while(b < a){
                //      b = randint(0,50);
                // }
                if (a >= b){
                    c = a - b;
                    //printf("hasil adalah %d\n" , c);
                    printf("%d - %d = ", a , b);
                }
                else{
                    c = b - a;
                    printf("%d - %d = ", b , a);
                }
                int masukan;
                //printf("hasil adalah %d\n" , c);
                //printf("%d x %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    //printf("masuk\n");
                    masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        printf("Your Answer Is Correct\n");
                    }
                    else{
                        printf("Your Answer Is Wrong \n\n");
                        printf("The Answer Should Be %d\n",c);
                        health = health - 10;
                    }
                }
                else{
                    printf("Invalid Input\n");
                }
                //printf("Skor kuis kamu sekarang adalah %d\n" , skor);
                IgnoreBlanksCMD();
                i++;   
                printf("\n");
            }
            boolean valid = false;
            printf("Your Health =  %d\n", health);
            while(!valid){
                printf("Do You Want To Repeat Stage 3 ? (yes/no)\n");
                STARTCOMMANDGAME();
                if(IsUsernameEqual(WORDTOSTRING(currentCMD), "yes")){
                    i = 0;
                    //looping = 3;
                    valid = true;
                    ulang3 = true;
                    health = health2;
                } else if (IsUsernameEqual(WORDTOSTRING(currentCMD), "no")){
                    ulang3 = false;
                    valid = true;  
                }
                else{
                    printf("Invalid Input !\n\n");
                }
            }
            
        }
        printf("Your Current Health = %d\n", health);
    
    return health;
}

void papyrusfight(int *score , char*Username)
/*Melakukan looping hingga health papyrus harus diatas 70*/
{
    int papyrus = mainpapyrus();
    while (papyrus < 70){
        printf("You Failed This Game\n");
        printf("You have to repeat this game again to continue to the next story !\n");
        papyrus = mainpapyrus();
    }
    //printf("Skor math quiz %d\n",papyrus);
    (*score) += papyrus;
}

void sansfight(int *score , char *Username)
/*Menyusun beberapa jenis uang dengan jumlah tertentu agar sesuai dengan jumlah uang yang harus dibayarkan*/
{
    int skor = 100;
    int langkah = 0;
    printf("\n");
    printf("%s want to cook his favorite food %s So he has to buy some groceries in the market for a certain amount. \n" , Username , Username);
    printf("Help %s to prepare the money she needs to pay for her groceries while at the market . \n" , Username , Username);
    printf("\n");
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    srand(time(0));
    int random = randint(1,200);
    printf("the amount of money %s have to pay is  %d\n",Username ,  random);
    printf("Description : \n");
    printf ("quarters = 25 \n");
    printf ("dimes = 10 \n");
    printf ("nickels = 5 \n");
    printf ("pennies = 1 \n");
    printf("\n");
    int masukanquarters , masukandimes , masukannickels , masukanpennies;
    boolean valid = false;
    boolean win = false;
    int total;
    while (!win){
        while(!valid){
        printf("enter the number of quarters : \n");
        STARTCOMMANDGAME();
        if(isInteger(currentCMD)){
            masukanquarters = WordToInt(currentCMD);
            valid = true;
            }
        
        else{
            printf("Invalid Input !\n");
        }
    }

        valid = false;
        while(!valid){
            printf("enter the number of dimes : \n");
            STARTCOMMANDGAME();
            if(isInteger(currentCMD)){
                masukandimes = WordToInt(currentCMD);
                valid = true;
                }
            
            else{
                printf("Invalid Input\n");
            }
        }

        valid = false;
        while(!valid){
            printf("enter the number of nickels : \n");
            STARTCOMMANDGAME();
            if(isInteger(currentCMD)){
                masukannickels = WordToInt(currentCMD);
                valid = true;
                }
            
            else{
                printf("Invalid Input !\n");
            }
        }

        valid = false;
        while(!valid){
            printf("enter the number of pennies : \n");
            STARTCOMMANDGAME();
            if(isInteger(currentCMD)){
                masukanpennies = WordToInt(currentCMD);
                valid = true;
                }
            
            else{
                printf("Invalid Input \n");
            }
        }

        total = (quarters * masukanquarters) + (dimes * masukandimes) + (nickels * masukannickels) + (pennies * masukanpennies);
        if (total == random){
            printf("Congratulations, you made it!\n");
            win = true;
        }
        else if (total > random){
            printf("Your amount of money is more than needed\n");
            printf("Please try again\n");
        }
        else{
            printf("Your amount of money is less than needed\n");
            printf("Please try again\n");
        }
        printf("\n");
    }
    skor = (skor - (langkah * 10)) + 10;
    //printf("Skor Hitung Duit %d\n",skor);
    (*score) += skor;
}
void CreateRandomPointAsriel(Point *P){
    int x = randint(0, 4);
    int y = randint(0, 4);
    CreatePoint(P , x, y);
}

void PrintAlphabet(Map MiniGames , int index , char*input)
/*Melakukan print alphabet sesuai value yang dimilikinya*/
{ 
    int value;
    value = MiniGames.Elements[index].Skor;
    if(value == 1 || value == 0 || value == -999){
        printf("  %s  ",input);
    }
    else if(value == -1){
        printf("     ");
    }
    else if(value == 100){
        printf(" WIN ");
    }
    else if(value == -100){
        printf(" BOM ");
    }
}

void Axe(){
    printf(" _,-,\n");
    printf("T_  |\n");
    printf("||`-'\n");
    printf("||   \n");
    printf("||   \n");
    printf("~~ \n");                                                  
}



void WelcomingAsrielGames(){
printf("\n");
printf("           *O*                                                   \n");
printf("           |X|_                                                  \n");
printf("           |X||-------________________________________________   \n");
printf(",O---------+X| \\___   `=------------------------------- _____ \\*\n");
printf("`O---------+X| /      ,=-------------------------------'      /* \n");
printf("           |X||-------~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   \n");
printf("           |X|~                                                  \n");
printf("           *0*                                                   \n");
printf("\n");

printf("\n");
printf("==================================================================\n");
printf("=                  WELCOME TO THE FINAL STAGE                    =\n");
printf("==================================================================\n");
printf ("\n");
}

void AsrielGameRule(){
printf("******************************************************************\n");
printf("*                       RULES OF THE GAME                        *\n");
printf("******************************************************************\n");
printf("*             DO NOT USING WHITESPACE WHEN INPUT COMMAND!        *\n");
printf("*               DO NOT OPEN THE BOX THAT CONTAIN BOMB            *\n");
printf("*           THERE IS ONLY ONE TREASURE THAT U SHOUL FIND IT      *\n");
printf("******************************************************************\n");

printf("\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~ GOOD LUCK ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("\n");
}
void PrintPetaAsriel(Map MiniGames){
    printf("Here is the game map\n");
    int i,j;
    int alphabet = 0;
    int value;
    for(i = 0; i < 11; i++)
    {
        for(j = 0; j < 11; j++)
        {
            
            if(i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    printf(" ");
                }
                else 
                {
                    printf("-----");
                }
            }
            
            else 
            {
                if(j % 2 == 0)
                {
                    printf("|");
                }
                
                else 
                {
                    if(i == 1 && j == 1)
                    {
                        // value = MiniGames.Elements[0].Skor;
                        // if(value == 1 || value == 0 || value == -999){
                        //     printf("  A  ");
                        // }
                        // else if(value == -1){
                        //     printf("  X  ");
                        // }
                        // else if(value == 100){
                        //     printf(" WIN ");
                        // }
                        // else if(value == -100){
                        //     printf(" BOM ");
                        // }
                    PrintAlphabet(MiniGames , alphabet , "A");
                    }
                    else if(i == 1 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "B");
                    }
                    else if(i == 1 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "C");
                    }
                    else if(i == 1 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "D");
                    }
                    else if(i == 1 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "E");
                    }
                    else if(i == 3 && j == 1)
                    {
                        PrintAlphabet(MiniGames , alphabet , "F");
                    }
                    else if(i == 3 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "G");
                    }
                    else if(i == 3 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "H");
                    }
                    else if(i == 3 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "I");
                    }
                    else if(i == 3 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "J");
                    }
                    else if(i == 5 && j == 1)
                    {
                        PrintAlphabet(MiniGames , alphabet , "K");
                    }
                    else if(i == 5 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "L");
                    }
                    else if(i == 5 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "M");
                    }
                    else if(i == 5 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "N");
                    }
                    else if(i == 5 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "O");
                    }
                    else if(i == 7 && j == 1)
                    {
                        PrintAlphabet(MiniGames , alphabet , "P");
                    }
                    else if(i == 7 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "Q");
                    }
                    else if(i == 7 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "R");
                    }
                    else if(i == 7 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "S");
                    }
                    else if(i == 7 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "T");
                    }
                    else if(i == 9 && j == 1)
                    {
                        PrintAlphabet(MiniGames , alphabet , "U");
                    }
                    else if(i == 9 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "V");
                    }
                    else if(i == 9 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "W");
                    }
                    else if(i == 9 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "X");
                    }
                    else if(i == 9 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "Y");
                    }
                    alphabet++;
            }
        }
        
    }
    printf("\n");
}
}

void InsertMapMiniGames(Map *M, keytype k, valuetype v)
{
	if(IsEmptyMap(*M)){
		(*M).Elements[(*M).Count].Nama = k;
		(*M).Elements[(*M).Count].Skor = v;
		(*M).Count++;
	}
	else{
		if(!IsMemberMap(*M , k)){
			(*M).Elements[(*M).Count].Nama = k;
			(*M).Elements[(*M).Count].Skor = v;
			(*M).Count++;
		}
	}
}

int mainasriel(char*Username){
    WelcomingAsrielGames();
    AsrielGameRule();
    int skor = 100;
    int langkah = 0;
    Point bomb1, bomb2, bomb3, bomb4, bomb5 , treasure;
    Map asriel_map;
    CreateEmptyMap(&asriel_map);
    CreateRandomPointAsriel(&bomb1);
    CreateRandomPointAsriel(&bomb2);
    CreateRandomPointAsriel(&bomb3);
    CreateRandomPointAsriel(&bomb4);
    CreateRandomPointAsriel(&bomb5);
    CreateRandomPointAsriel(&treasure);
    /*Memastikan setiap bomb dan treasure menghasilkan Point Value yang berbeda beda*/
    while(IsPointSama(bomb1, bomb2) || IsPointSama(bomb1, bomb3) || IsPointSama(bomb1, bomb4) || IsPointSama(bomb1, bomb5) || IsPointSama(bomb1,treasure)){
        CreateRandomPointAsriel(&bomb1);
    }
    while(IsPointSama(bomb2 , bomb1) || IsPointSama(bomb2,bomb3) || IsPointSama(bomb2,bomb4) || IsPointSama(bomb2,bomb5) || IsPointSama(bomb2,treasure)){
        CreateRandomPointAsriel(&bomb2);
    }
    while(IsPointSama(bomb3 , bomb1) || IsPointSama(bomb3,bomb2) || IsPointSama(bomb3,bomb4) || IsPointSama(bomb3,bomb5) || IsPointSama(bomb3,treasure)){
        CreateRandomPointAsriel(&bomb3);
    }
    while(IsPointSama(bomb4 , bomb1) || IsPointSama(bomb4,bomb2) || IsPointSama(bomb4,bomb3) || IsPointSama(bomb4,bomb5) || IsPointSama(bomb4,treasure)){
        CreateRandomPointAsriel(&bomb4);
    }
    while(IsPointSama(bomb5 , bomb1) || IsPointSama(bomb5,bomb2) || IsPointSama(bomb5,bomb3) || IsPointSama(bomb5,bomb4) || IsPointSama(bomb5,treasure)){
        CreateRandomPointAsriel(&bomb5);
    }
    
    /*Inisiasi Map*/
    int TreasureMap[5][5];
    int x,y;
    for(x = 0; x < 5; x++){
        for(y = 0; y < 5; y++){
            /*Melakukan assign matrix value sebesar -999 ke lokasi yang merupakan bomb*/
            if((x == Absis(bomb1) && y == Ordinat(bomb1)) || (x == Absis(bomb2) && y == Ordinat(bomb2)) || (x == Absis(bomb3) && y == Ordinat(bomb3)) || (x == Absis(bomb4) && y == Ordinat(bomb4)) || (x == Absis(bomb5) && y == Ordinat(bomb5))){
                TreasureMap[x][y] = -999;
            }
            /*Melakukan assign matrix value sebesar 0 ke lokasi yang merupakan treasure*/
            else if(x == Absis(treasure) && y == Ordinat(treasure)){
                TreasureMap[x][y] = 0;
            }
            /*Melakukan assign matrix value sebesar 1 ke lokasi yang bukan merupakan bomb / treasure*/
            else{
                TreasureMap[x][y] = 1;
            }
        }
    }
    
    InsertMapMiniGames(&asriel_map , "A" , TreasureMap[0][0]);
    InsertMapMiniGames(&asriel_map , "B" , TreasureMap[0][1]);
    InsertMapMiniGames(&asriel_map , "C" , TreasureMap[0][2]);
    InsertMapMiniGames(&asriel_map , "D" , TreasureMap[0][3]);
    InsertMapMiniGames(&asriel_map , "E" , TreasureMap[0][4]);
    InsertMapMiniGames(&asriel_map , "F" , TreasureMap[1][0]);
    InsertMapMiniGames(&asriel_map , "G" , TreasureMap[1][1]);
    InsertMapMiniGames(&asriel_map , "H" , TreasureMap[1][2]);
    InsertMapMiniGames(&asriel_map , "I" , TreasureMap[1][3]);
    InsertMapMiniGames(&asriel_map , "J" , TreasureMap[1][4]);
    InsertMapMiniGames(&asriel_map , "K" , TreasureMap[2][0]);
    InsertMapMiniGames(&asriel_map , "L" , TreasureMap[2][1]);
    InsertMapMiniGames(&asriel_map , "M" , TreasureMap[2][2]);
    InsertMapMiniGames(&asriel_map , "N" , TreasureMap[2][3]);
    InsertMapMiniGames(&asriel_map , "O" , TreasureMap[2][4]);
    InsertMapMiniGames(&asriel_map , "P" , TreasureMap[3][0]);
    InsertMapMiniGames(&asriel_map , "Q" , TreasureMap[3][1]);
    InsertMapMiniGames(&asriel_map , "R" , TreasureMap[3][2]);
    InsertMapMiniGames(&asriel_map , "S" , TreasureMap[3][3]);
    InsertMapMiniGames(&asriel_map , "T" , TreasureMap[3][4]);
    InsertMapMiniGames(&asriel_map , "U" , TreasureMap[4][0]);
    InsertMapMiniGames(&asriel_map , "V" , TreasureMap[4][1]);
    InsertMapMiniGames(&asriel_map , "W" , TreasureMap[4][2]);
    InsertMapMiniGames(&asriel_map , "X" , TreasureMap[4][3]);
    InsertMapMiniGames(&asriel_map , "Y" , TreasureMap[4][4]);
    PrintPetaAsriel(asriel_map);
    int TM = 0;
    for(x = 0; x < 5; x++){
        for(y = 0; y < 5; y++){
            printf("%d " , asriel_map.Elements[TM].Skor);
            TM++;
        }
        printf("\n");
    }
    // PrintMap(asriel_map);
    // printf("\n");
    /*Melakukan Print Map */
    //PrintPetaAsriel();
    
    boolean win = false;
    boolean bomb = false;

    /*Selama dia gakena bomb atau treasure terus diiterasi*/
    while(!bomb && !win){
            langkah++;
            printf("Select a box by selecting the available letters : \n");
            STARTCOMMANDGAME();
            char *input = WORDTOSTRING(currentCMD);
            valuetype value = Skor(asriel_map , input);
            //printf("value : %d\n",value);
            
            /*Jika Inputan Valid maka cek setiap kondisi*/
            if(IsMemberMap(asriel_map , input)){
                if(value == 1){
                    //printf("TEST1\n");
                    for(int index = 0;index < asriel_map.Count ; index++){
                        if(IsUsernameEqual(asriel_map.Elements[index].Nama , input)){
                            //printf("masuk1\n");
                            asriel_map.Elements[index].Skor = -1;
                        }
                    }
                    PrintPetaAsriel(asriel_map);
                }
                else if(value == 0){
                    //printf("TEST2\n");
                    for(int index = 0;index < asriel_map.Count ; index++){
                        if(IsUsernameEqual(asriel_map.Elements[index].Nama , input)){
                            //printf("masuk2\n");
                            asriel_map.Elements[index].Skor = 100;
                        }
                    }
                    PrintPetaAsriel(asriel_map);
                    //printf("nemu harta karun\n");
                    win = true;
                }
                else if(value == -999){
                    //printf("TEST3\n");
                        for(int index = 0;index < asriel_map.Count ; index++){
                            if(IsUsernameEqual(asriel_map.Elements[index].Nama , input)){
                                //printf("masuk3\n");
                                asriel_map.Elements[index].Skor = -100;
                            }
                        }
                        PrintPetaAsriel(asriel_map);
                        //printf("Kena Bom\n");
                        bomb = true;
                    }
                else if(value == -1){
                    printf("The box is already open\n");
                }
            }
            else{
                printf("Invalid input, please enter the valid input!\n");
            }
            int TM = 0;
            for(x = 0; x < 5; x++){
                for(y = 0; y < 5; y++){
                    printf("%d " , asriel_map.Elements[TM].Skor);
                    TM++;
                }
            printf("\n");
        }
    }
    if(bomb){
        skor = 0;
    }
    else if (win){
        skor = (skor - (langkah * 5)) + 5;
    }
    return skor;
}

void asrielfight(int *score , char *Username){
    int skor = mainasriel(Username);
    while (skor == 0){
        printf("\n You lost, please try again !\n");
        delay(3);
        skor = mainasriel(Username);
    }
    //printf("Skor final game %d\n",skor);
    (*score) += skor;
}


//int main()
//{
//    undertale();
//    return 0;
//}


// int main()
// {
//     towerofhanoi();
//     return 0;
// }
/*int main()
{
    
    
    List L;
    CreateEmpty(&L);
    int X = randint(0,4);
    int Y = randint(0,4);

    Point P1;
    CreatePoint(&P1, X, Y);
    Point P2 = CreateNextPoint(P1);
    Point P3 = CreateNextPoint(P2);

    printf("P1: %d %d\n", Absis(P1), Ordinat(P1));
    printf("P2: %d %d\n", Absis(P2), Ordinat(P2));
    printf("P3: %d %d\n", Absis(P3), Ordinat(P3));

    
    CreateList3Elemen(&L, P1, P2, P3);

    
    printf("Isi list: \n");
    printList(L);
    printf("%i\n", NbElmt(L));

    printf("info head: %d %d\n", Absis(Info(Head(L))), Ordinat(Info(Head(L))));
    

    //SnakeOnMeteor();
    return 0;
}*/

// int main(){
//     SnakeOnMeteor();
//     return 0;
// }


/*int main()
{
    Point P1, P2;
    CreatePoint(&P1, 1, 1);
    CreatePoint(&P2, 1, 1);
    if (IsMeteor(P1, P2))
    {
        printf("mati\n");
    }
    else
    {
        printf("idup\n");
    }
    return 0;
}*/
// int main(){
//     Stack GameHistory;
//     ArrayOfMap GameMap;
//     Queue QueueGame;
//     CreateQueue(&QueueGame);
//     ArrayDin ListGames = CreateDynArray() ;
//     MakeEmptyArrayOfMap(&GameMap);
//     CreateEmptyStack(&GameHistory);
//     LOADFILE(&ListGames , &GameHistory , "savefile2.txt", &GameMap);
//     CREATEGAME(&ListGames , &GameMap);
//     int lastidx = NbElmtArrayOfMap(GameMap);
//     printf("lastidx = %d\n", lastidx);
//     char*name = "Marvel";
//     int score = 100;
//     Map Temp = GetElmtArrayOfMap(GameMap , lastidx); 
//     Insert(&GameMap.ArrMap[lastidx] , name , score);
//     // GameMap.ArrMap[lastidx].Elements[0].Nama = name;
//     // GameMap.ArrMap[lastidx].Elements[0].Skor = score;
//     printf("%s %d\n", GetElmtArrayOfMap(GameMap , lastidx).Elements[0].Nama , GetElmtArrayOfMap(GameMap , lastidx).Elements[0].Skor);
//     printf("%d\n",GameMap.ArrMap[lastidx].Count);
//     DELETE(&ListGames , QueueGame , &GameMap);
//     //Scoreboard(ListGames , GameMap);
//     //SAVEBNMO(&ListGames , &GameHistory , "savefile4.txt",&GameMap);
//     // printf("List Games : \n");

//     return 0;
// }