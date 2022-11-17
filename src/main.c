#include <stdio.h>
#include "console.h"

int main(){
    printf("    __   __   ______  ___     ___     ______   ___\n");
    printf("   / /_ /  / /  ___/ /  /    /  /    / __  /  /  /\n");
    printf("  /  __   / /  /__  /  /    /  /    / / / /  /  /\n");
    printf(" /  / /  / /  /__  /  /_   /  /__  / /_/ /  /__/\n");
    printf("/__/ /__/ /_____/ /_____/ /_____/ /_____/  /__/\n");

    ArrayDin ListGames = CreateDynArray();
    Queue QueueGame;
    CreateQueue(&QueueGame);
    printf("Silahkan pilih Command \n");
    printf("1. START\n");
    printf("2. LOAD <nama file>\n \n"); // LOAD savefile1.txt
 

    while (IsEmpty(ListGames))
    {
    printf("ENTER COMMAND : ");
    STARTCOMMAND();
    if (wordAndCharSama(currentCMD, "START"))
    {
        STARTGAME(&ListGames);
        
    }
    else if(wordAndCharSama(currentCMD, "LOAD")) // asumsi nama file pasti benar dan file tidak kosong
    {   //printf("%s\n", currentCMD);
        ADVCOMMAND();
        //printf("%s\n", currentCMD);
        char namafile[50];

        wordToString(currentCMD, namafile);
        //printf("%s\n",namafile);
        int j =0;
        char *filename = (char *)malloc(currentCMD.Length * sizeof(char));
        //printf("%d",currentCMD.Length);
        while (j <= currentCMD.Length)
        {
            filename[j] = namafile[j];
            j++;
        }
        //printf("%s\n",filename);
        LOADFILE(&ListGames, filename);
        
    }
    else{
        printf("Masukan command salah. Silahkan masukkan command kembali.\n ");
    }
    while(!EndWord){
        ADVCOMMAND();
    }
    }

    HELP();
    //LISTGAME(&ListGames);
    boolean berhenti = false;
    while (!berhenti)
    {
        char*GAME = "GAME";
        printf("ENTER COMMAND: ");
        STARTCOMMAND();
        if (wordAndCharSama(currentCMD, "SAVE"))
        {
            ADVCOMMAND();
            char namafile[50];
            wordToString(currentCMD, namafile);
            SAVEBNMO(&ListGames, namafile);
        }
        else if (wordAndCharSama(currentCMD, "CREATE"))
        {
            ADVCOMMAND();
            char game[50];
            wordToString(currentCMD, game);
            if(CompareString(game , GAME))
            {
            //printf("%s\n",currentCMD);
            CREATEGAME(&ListGames);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(wordAndCharSama(currentCMD, "LIST"))
        {   
            ADVCOMMAND();
            char game[50];
            wordToString(currentCMD, game);
        
            if(CompareString(game , GAME))
            {
                LISTGAME(&ListGames);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(wordAndCharSama(currentCMD, "DELETE"))
        {
            ADVCOMMAND();
            char game[50];
            wordToString(currentCMD, game);
            if(CompareString(game , "GAME"))
            {
                //printf("naon yak 2");
                DELETE(&ListGames, QueueGame);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(wordAndCharSama(currentCMD, "QUEUE"))
        {
            ADVCOMMAND();
            char game[50];
            wordToString(currentCMD, game);
            if(CompareString(game , "GAME"))
            {
                QUEUEGAME(&QueueGame, ListGames);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(wordAndCharSama(currentCMD, "PLAY"))
        {
            ADVCOMMAND();
            char game[50];
            wordToString(currentCMD, game);
            if(CompareString(game , "GAME"))
            {
                PLAYGAME(&QueueGame);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(wordAndCharSama(currentCMD, "SKIPGAME")) // setelah "SKIPGAME" wajib beed integer
        {
            ADVCOMMAND();
            if(isInteger(currentCMD) && !(EndWord)){
                int skip = WordToInt(currentCMD); //- 10 ;            
                SKIPGAME(&QueueGame, skip);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(wordAndCharSama(currentCMD, "HELP"))
        {
            HELP();
        }
        else if(wordAndCharSama(currentCMD, "QUIT")){
            berhenti = true;
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }   
    }
    QUIT();

    return 0;

}
