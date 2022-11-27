#include "console.h"
#include <stdio.h>
void CREATEGAME(ArrayDin *ListGames , ArrayOfMap *GameMap)
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
{
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int i = 0; i < (*ListGames).Neff; i++)
    {
        printf("%i. %s\n", i+1, (*ListGames).A[i]);
    }
}

void LOADFILE(ArrayDin *ListGames , Stack *GameHistory , char* filename ,ArrayOfMap *GameMap){
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
            printf("%s\n" , (*ListGames).A[i-1]);
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
            //printf("%s\n",kata);
            // while (j <= currentWord.Length)
            // {
            //     gamename[j] = kata[j];
            //     j++;
            // }
            //gamename[j] = '\0';  
            //InsertIn(string , ListGames , i);
            PushStack(GameHistory, kata); 
            printf("%s\n" , InfoTop(*GameHistory));
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
                //printf("panjang currentWord score = %d\n" , currentWord.Length);
                //printf("%d\n",score);
                // while (j <= currentWord.Length)
                // {
                //     gamename[j] = kata[j];
                //     j++;
                // }
                //gamename[j] = '\0';  
                Insert(&Temp, kata, score);
                printf("%s %d\n" , (Temp).Elements[idxMap].Nama , (Temp).Elements[idxMap].Skor);
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
{
    ElType A;
    char *rng, *dinerDash , *hangman ,*towerofhanoi ,*snakeonmeteor ,*MTK;
    int score;
    rng = "RNG";
    dinerDash = "Diner DASH";
    hangman = "HANGMAN";
    towerofhanoi = "TOWER OF HANOI";
    snakeonmeteor = "SNAKE ON METEOR";
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
            gameRNG(game , ListGames ,GameMap , score); 
            //printf("Skor: %d\n", score);
            PushStack(GameHistory , game);
            
        } 

        else if(CompareString(game , hangman))
        {
            printf("Loading %s ...\n", hangman);
            delay(2);
            Hangman(game , ListGames , GameMap , score);
            PushStack(GameHistory , game);
        }

        else if(CompareString(game , towerofhanoi))
        {
            printf("Loading %s ...\n", towerofhanoi);
            delay(2);
            TowerOfHanoi(game , ListGames , GameMap , score);
            PushStack(GameHistory , game);

        }

        else if(CompareString(game , snakeonmeteor))
        {
            printf("Loading %s ...\n", snakeonmeteor);
            delay(2);
            SnakeOnMeteor(game , ListGames , GameMap , score);
            PushStack(GameHistory , game);

        }
        else if(CompareString(game , MTK))
        {
            printf("Loading MATH QUIZ ...\n");
            delay(2);
            mathquiz(game ,ListGames , GameMap , score);
            PushStack(GameHistory , game);
            
        }

        else if (CompareString(game , dinerDash))
        {
            printf("Loading %s ...\n", dinerDash);
            delay(2);
            dinerdash(game , ListGames , GameMap , score);
            PushStack(GameHistory , game);
            
        }


        else
        {   
                printf("Loading %s ...\n", game);
                delay(2);
                score = randint(1 , 100);
                printf("Game Over.Skor Anda adalah %d\n", score);
                Username(game , ListGames , GameMap , score);
                PushStack(GameHistory , game);
            }

            // srand(time(NULL));
            // int random = rand();
            // printf("Skor Kamu Adalah %d\n",random);
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

void gameRNG(char*game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)  
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

void SAVEBNMO(ArrayDin *ListGames , Stack *GameHistory , char* filename ,ArrayOfMap *GameMap) 
 { 
    FILE* fp; 
    char path[50]; 
  
    stringConcat("../data/",filename,path); 
    printf("%s\n",path);
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
    printf("Top = %d\n",Top(*GameHistory));
    INFOTYPE Game;
    while(!IsEmptyStack(*GameHistory))
    {   PopStack(GameHistory , &Game);
        //printf("Game = %s\n",Game);
        fprintf(fp , "\n%s" , Game);
        
    }
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

void mathquiz(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score){      
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
    
    score = skormath;
    Username(game , ListGames , GameMap , score);
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

void dinerdash(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)
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

boolean foundmathquiz(ArrayDin ListGames){
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

void Scoreboard(ArrayDin ListGames , ArrayOfMap GameMap){
    int idxlistgame;
    for(idxlistgame = 0 ; idxlistgame < ListGames.Neff ; idxlistgame++){
        printf("**** SCOREBOARD GAME %s ****\n", ListGames.A[idxlistgame]);
        PrintScoreBoard(GameMap.ArrMap[idxlistgame]);
        printf("\n");
    }
}

void Username(char*game ,ArrayDin ListGames , ArrayOfMap *GameMap , int score){
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




boolean ya(){
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



void ResetScoreboard(ArrayOfMap *M , ArrayDin *ListGames ){
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
                printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)?\n");
                if (ya()){
                    for(int i = 0; i < (*ListGames).Neff; i++){
                        CreateEmptyMap(&(M->ArrMap[i]));
                        if(IsEmptyMap(M->ArrMap[i])){
                            printf("Scoreboard ke-%d berhasil di-reset.\n",i+1);
                        }
                        else{
                            printf("Scoreboard gagal di-reset.\n");
                        }
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

int KataTerpanjang(Map Game){
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

boolean yes(){

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


void History(Stack Game , int n){
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

void ResetHistory (Stack * Game){
    
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

void SnakeOnMeteor(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score){
    printf("Selamat datang di Snake on Meteor!\n\n");
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
    printf("\n");

    Point Geser;
    Geser = Info(Head(L));

    if (wordAndCharSama(currentCMD, "a"))
    {
        Absis(Geser) = Absis(Geser) - 1;
        while (Absis(Geser) < 0)
        {
            Absis(Geser) = Absis(Geser) + 5;
        }
        input = true;
    }
    else if (wordAndCharSama(currentCMD, "d"))
    {
        Absis(Geser) = Absis(Geser) + 1;
        while(Absis(Geser) > 4)
        {
            Absis(Geser) = Absis(Geser) - 5;
        }
        input = true;
    }
    else if (wordAndCharSama(currentCMD, "w"))
    {
        Ordinat(Geser) = Ordinat(Geser) - 1;
        while(Ordinat(Geser) < 0)
        {
            Ordinat(Geser) = Ordinat(Geser) + 5;
        }
        // printf("Geser: %d %d\n", Absis(Geser), Ordinat(Geser));
        input = true;
    }
    else if (wordAndCharSama(currentCMD, "s"))
    {
        Ordinat(Geser) = Ordinat(Geser) + 1;
        while(Ordinat(Geser) > 4)
        {
            Ordinat(Geser) = Ordinat(Geser) - 5;
        }
        input = true;
    }
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

    }while (!IsGameOver(L, Meteor, Obstacle));

    // INTERFACE GAMEOVER //
    int skor;
    if (IsHeadKenaMeteor(L, Meteor))
    {
        printf("Kepala snake terkena meteor!\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n", skor-2);
    }
    else if (IsHeadNabrakBadan(L))
    {
        printf("Kepala snake nabrak badan!\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n", skor-2);
    }
    else if (IsEmptySOM(L))
    {
        printf("Snake mati karena tubuh snake terkena meteor semua!\n");
    }
    else if (IsObstacle(Obstacle, Info(Head(L)))) // nabrak obstacle
    {
        printf("Ada obstacle itu lho, yo jangan mbok tabrak to mas\n");
        gerak = false;
        input = false;
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n", skor-2);
    }

    score = skor;
    Username(game , ListGames , GameMap , score);
}


void Hangman(char*game ,ArrayDin ListGames , ArrayOfMap *GameMap , int score)
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
        if (wordAndCharSama(currentCMD, "1") || wordAndCharSama(currentCMD, "PLAY"))
        {
            themePage();
            STARTCOMMANDGAME();
            boolean valid = false;
            while (!valid)
            {
                if (wordAndCharSama(currentCMD, "1") || wordAndCharSama(currentCMD, "KOTA"))
                {
                    loadkata(&ListKata, "KataKota.txt"); valid = true;
                    //printf("MasukPakEko\n");

                }
                else if(wordAndCharSama(currentCMD, "2") || wordAndCharSama(currentCMD, "NEGARA"))
                {
                    loadkata(&ListKata, "KataNegara.txt"); valid = true;
                }
                else
                {
                    printInputNotValid();
                }
            }
            int kesempatan = 10;
            //int skor =0;
            // if(IsEmptyArrayHangman(ListKata)){
            //     printf("Array kosong\n");
            // }
            // else{
            //     printf("Array tidak kosong\n");
            //     printf("%s\n",ListKata.TI[1]);
            //     printf("%d\n",ListKata.EFEKTIF);
            // }
            while (kesempatan > 0)
            {
                //printf("Masuk1\n");
                srand(time(NULL));
                int random = randint(1,ListKata.EFEKTIF);
                // printf("%d\n",ListKata.EFEKTIF);
                // printf("%d\n",random);  
                char*Kata;
                Kata = WORDTOSTRING(ListKata.TI[random]);
                //printf("Masuk2\n");
                mainHangman(&kesempatan, Kata);
                if (kesempatan != 0) skor += 25;
            }
            printf("\nGAME OVER.");
            printf("\n\nSkor kamu adalah %d\n", skor); 
            
            on = false; 
        } 
        else if (wordAndCharSama(currentCMD, "2") || wordAndCharSama(currentCMD, "HELP"))
        {
            helpHangman();
            printf("\n\nPress any key to continue..\n");
            STARTCOMMAND();
        }
        else if (wordAndCharSama(currentCMD, "3") || wordAndCharSama(currentCMD, "TAMBAHKATA"))
        {
            themePage();
            STARTCOMMAND();
            boolean valid = false;
            char*file; char* tema;
            while (!valid)
            {
                if (wordAndCharSama(currentCMD, "1") || wordAndCharSama(currentCMD, "KOTA"))
                {
                    file = "KataKota.txt"; tema = "KOTA";
                    loadkata(&ListKata, file); valid = true;
                }
                else if(wordAndCharSama(currentCMD, "2") || wordAndCharSama(currentCMD, "NEGARA"))
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
            STARTCOMMAND();
            int n = ListKata.EFEKTIF;
            SetElListKata(&ListKata, n+1, currentCMD);
            saveListKata(ListKata, file);
        }
        else if (wordAndCharSama(currentCMD, "4") || wordAndCharSama(currentCMD, "QUIT"))
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
        printf("! Kamu mendapatkan 25 poin!");
    }
    if ((*kesempatan) == 0)
        printf("\nKesempatan habis!\n");
    
        
    }

void loadkata(ListKata *ListKata, char*filename)
{
    char path[NMax];
    stringConcat("ADT/Hangman/",filename,path);
    //printf("\n%s", path);
    FILE *fp = fopen(path, "r");
    STARTWORD(path);
    int nGame = WordToInt(currentWord);
    //char*temp;
    for (int i = 1; i <= nGame; i++){
        ADVLine();
        SetElListKata(ListKata, i, currentWord);
        //temp = WORDTOSTRING(currentWord);
        //printf("%d. %s\n",i , temp);
    }
    printf("%d\n",(*ListKata).EFEKTIF);
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

boolean win(STACKSS c)
{
    // Create winning tower
    STACKSS w;
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

void displaystacks(STACKSS a, STACKSS b, STACKSS c)
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

void TowerOfHanoi(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score)
{
    // Kamus
    int countsteps = 0;
    int skor = 0;

    // Menciptakan "towers"
    STACKSS a;
    STACKSS b;
    STACKSS c;
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
    while (i<Maksimal)
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