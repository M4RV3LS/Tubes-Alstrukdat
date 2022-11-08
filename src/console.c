#include "console.h"

void CREATEGAME(ArrayDin *ListGames)
{
    printf("Masukkan nama game yang akan ditambahkan : ");
    STARTCOMMANDGAME();
    InsertLast(ListGames, currentCMD.TabWord);
    printf("Game berhasil ditambahkan\n");
}

void DELETE(ArrayDin *ListGames)
{
    int nomor_game;
    printf("Masukkan nomor game yang akan dihapus: ");
    STARTCOMMAND();
    nomor_game = WordToInt(currentCMD);

    if (nomor_game > 5)
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
    printf("1. START \n2. LOAD \n3. SAVE \n4. CREATE GAME \n5. LIST GAME \n6. DELETE GAME \n7. QUEUE GAME \n8. PLAY GAME \n9. SKIP GAME \n10. QUIT \n11. HELP");
}

void LISTGAME(ArrayDin *ListGames)
{
    printf("Berikut adalah daftar game yang tersedia\n");
    for (int i=0; i < ListGames->Neff; i++)
    {
        printf("%i. %s\n", i+1, ListGames->A[i]);
    }
}

void LOADFILE(ArrayDin *ListGames , char* filename){
    char path[NMax];
    stringConcat("../data/",filename,path);
    printf("%s\n",path);
    STARTWORD(path);
    int nGame = WordToInt(currentWord);
    printf("%d\n" , nGame);
    char string[NMax];
    for (int i = 1; i <= nGame; i++){
        ADVLine();
        wordToString(currentWord , string);
        //InsertIn(string , ListGames , i);
        InsertLast(ListGames , string);
        printf("%s\n" , (*ListGames).A[i-1]);
    }
    if(!IsEmpty(*ListGames)) 
    { 
        printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n"); 
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
}

void PLAYGAME(Queue *q1)
{
    ElType A;
    char *rng, *dinner;
    rng = "RNG";
    dinner = "Dinner DASH";

    if (isEmpty(*q1))
    {
        printf("Antrian game kosong.\n");
    }

    else
    {
        if (HEAD(*q1) == rng)
        {
            printf("Loading %s ...", rng);
            dequeue(q1, &A);
            gameRNG();
        } 

        else if(HEAD(*q1) == "DINOSAUR IN EARTH")
        {
            printf("Game DINOSAUR IN EARTH masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");
        }

        else if(HEAD(*q1) == "RISEWOMAN")
        {
            printf("Game RISEWOMAN masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");

        }

        else if(HEAD(*q1) == "EIFFEL TOWER")
        {
            printf("Game EIFFEL TOWER masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.");

        }
        



        /*else if (HEAD(*q1) == dinner)
        {
            printf("Loading %s ...", dinner);
            dequeue(q1, &A);
            dinnerdash(); //nunggu fungsi game dinner dash
        }*/

        /*else if(HEAD(*q1) == )
        {

        } */

        else
        {
            printf("Game %s masih dalam maintenance, belum dapat dimainkan. Silahkan pilih game lain.", HEAD(*q1));
        }

    }
}

void QUEUEGAME(Queue *q1, ArrayDin *game){
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
    LISTGAME(game);


    Queue q;
    printf("Nomor Game yang mau ditambahkan ke antrian : ");
    int nomor_game;
    CreateQueue(&q);
    STARTCOMMANDGAME();
    nomor_game = WordToInt(currentCMD);
    if (nomor_game > game->Neff){
         printf("Nomor permainan tidak valid\n");
    } else {
        char *val = game->A[nomor_game - 1];
        for (int i = 0; i< game->Neff; i++){
            enqueue(&q, game->A[i]);
        }
    enqueue(q1, val);
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
    printf("skor = %d" , skor);
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
        displayQueue(*q);
        //PLAYGAME(q);
    } 
    else { // 
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
    printf("%d\n" , nGame);
    nGame -= 10;
    char string[NMax];
    for (int i = 1; i <= nGame; i++){
        ADVLine();
        wordToString(currentWord , string);
        //InsertIn(string , ListGames , i);
        InsertLast(ListGames , string);
        printf("%s\n" , (*ListGames).A[i-1]);
    }
    if(!IsEmpty(*ListGames)) 
    { 
        printf("File konfigurasi sistem berhasil dibaca. BNMO berhasil dijalankan.\n"); 
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
}

