#include "console.h"


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
    InsertLast(ListGames , gamename);
    printf("Game berhasil ditambahkan\n");
}

void DELETE(ArrayDin *ListGames, Queue *q1)
{
    int nomor_game;
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();
    nomor_game = WordToInt(currentCMD);
    //printf("%s\n",ListGames->A[nomor_game-1]);
    //printf("%c\n",ListGames->A[nomor_game-1][0]);
    int panjang = LengthKalimat(ListGames->A[nomor_game-1]);
    //printf("%d\n",panjang);
    char *nama_game = (char*) malloc ( panjang * sizeof(char)); 
    
    int i = 0;
    while (i <= panjang)
    {
        nama_game[i] = ListGames->A[nomor_game-1][i];
        //printf("%c\n" , nama_game[i]);
        i++;
        
    }
    /*
    printf("%s\n" , nama_game);
    if (CompareString(nama_game  , "MARV")){
        printf("Udah string\n");
    }
    else{
        printf("Bukan string\n");
    }
    */
    /*char string[1000];
    char *gamename = (char*) malloc (currentCMD.Length * sizeof(char));
    // char * gamename;
    int j = 0;
    ADVLine();
    wordToString(currentCMD , string);
    //printf("%s\n",string);
    while (j <= currentCMD.Length)
    {
        gamename[j] = string[j];
        j++;
    }
        //gamename[j] = '\0';
        //InsertIn(string , ListGames , i);
    InsertLast(ListGames , gamename);
    printf("Game berhasil ditambahkan\n");*/


    if (nomor_game > 5 && !isMember(*q1,nama_game))
    {
        int j = ListGames->Neff;
        int i = nomor_game-1;
        
        while (i < j)
        {
            ListGames->A[i] = ListGames->A[i+1];
            i++;
        }
        free(ListGames->A[j]);
        
        ListGames->Neff -= 1;
        printf("Game berhasil dihapus\n");

    }
    else
    {
        printf("Game gagal dihapus\n");
    }



}

void HELP()
{
    printf("Berikut command-command yang dapat anda gunakan: \n");
    printf("1. SAVE <nama_file> \n2. CREATE GAME \n3. LIST GAME \n4. DELETE GAME \n5. QUEUE GAME \n6. PLAY GAME \n7. SKIP GAME \n8. QUIT \n9. HELP\n");
}

void LISTGAME(ArrayDin *ListGames)
{
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int i = 0; i < (*ListGames).Neff; i++)
    {
        printf("%i. %s\n", i+1, (*ListGames).A[i]);
    }
}

void LOADFILE(ArrayDin *ListGames , char* filename){
    char path[NMax];
    stringConcat("../data/",filename,path);
    printf("%s\n",path);
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
        if(!IsEmpty(*ListGames)) 
        { 
            printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n"); 
        } 
    }
    else
    {
        printf("%s tidak dikenali.\n",filename);
    }
    //LISTGAME(ListGames);
    /*
    ADVWORD();
    int j;
    int idx2 = currentWord.TabWord[0] - 48;
    for (j=0; j < idx2; j++){
        ADVWORD();
        insertLast(ListHistory, currentWord);
    }
    
    */
}

void PLAYGAME(Queue *q1)
{
    ElType A;
    char *rng, *dinner , *dino ,*risewoman ,*eiffel, *MTK;
    
    rng = "RNG";
    dinner = "Dinner DASH";
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
        //wordToString()
        //printf("%s\n",game);
        //printf("%s\n",rng);
        if (CompareString(game , rng))
        {
            printf("Loading RNG ...\n");
            delay(2);
            //dequeue(q1, &A);
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
<<<<<<< Updated upstream
            printf("Loading MATH QUIZ ...");
=======
            delay(2);
>>>>>>> Stashed changes
            mathquiz();
        }
        
        

        else if (CompareString(game , dinner))
        {
            //printf("Loading Dinner DASH ...");
            //delay(2);
            //dequeue(q1, &A);
            //dinnerdash(); //nunggu fungsi game dinner dash
        }


        else
        {
            srand(time(NULL));
            int random = rand();
            printf("%d\n",random);
        }

    }
}   

void QUEUEGAME(Queue *q1, ArrayDin game){
    //List *game;
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
    STARTCOMMANDGAME();
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

void gameRNG()  
{  
    srand(time(NULL));
    int maxTry = 50;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak sebuah angka X yang rentangnya berada diantara 1 - 50.\n");
    int random = rand() % 50 + 1;
    printf("%d\n",random); //Buat mengetahui random integernya hehe
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
    for (int i = IDX_HEAD(*q); i < IDX_HEAD(*q) + length(*q); i++){
        printf("%d. %s\n",i+1, q->buffer[i]);
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
    char *filename = "savefile.txt";
    stringConcat("../data/",filename,path);
    printf("%s\n",path);
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
        else
        {
            printf("Masukan Command Anda Salah , Silahkan Ulangi\n");
        }
    }
    
    printf("Loading Mode pertambahan...\n");
    delay(2);
        for (int i = 0;i < 10;i++){
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
    
    printf("GAME TELAH SELESAI , SKOR KAMU ADALAH %d\n" , skormath);
    return skormath;
}
    /*
    ADVWORD();
    int j;
    int idx2 = currentWord.TabWord[0] - 48;
    for (j=0; j < idx2; j++){
        ADVWORD();
        insertLast(ListHistory, currentWord);
    }
    
    */
    //LISTGAME(ListGames);


/*
int main()
{
    ArrayDin listgame = CreateDynArray();
    listgame.A[0] = "Asih";
    listgame.A[1] = "Marvel";
    listgame.A[2] = "Amjad";
    listgame.A[3] = "Raka" ;
    listgame.A[4] = "Carissa";
    listgame.Neff = 5;

    LISTGAME(&listgame);
    return 0;
}
*/
/*
int main()
{
    ArrayDin array = CreateDynArray();
    LOADFILE(&array, "savefile.txt");
    //STARTGAME(&array);

    return 0;

}
*/
/*
int main(){
    ArrayDin game = CreateDynArray();
    LOADFILE(&game , "savefile.txt");
    SAVEBNMO(&game , "savefile3.txt");
}*/