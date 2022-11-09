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
    printf("2. LOAD <nama file>\n"); // LOAD savefile1.txt
 

    while (IsEmpty(ListGames))
    {
    printf("ENTER COMMAND : ");
    STARTCOMMAND();
    if (wordAndCharSama(currentCMD, "START"))
    {
        STARTGAME(&ListGames);
        
    }
    else if(wordAndCharSama(currentCMD, "LOAD")) // asumsi nama file pasti benar dan file tidak kosong
    {
        ADVCOMMAND();
        char *namafile;
        wordToString(currentCMD, namafile);
        LOADFILE(&ListGames, namafile);
    }
    else{
        printf("Masukan command salah. Silahkan masukkan command kembali.\n ");
    }
    }

    HELP();
    //LISTGAME(&ListGames);
    printf("ENTER COMMAND: ");
    STARTCOMMAND();
    while (!wordAndCharSama(currentCMD, "QUIT"))
    {
        if (wordAndCharSama(currentCMD, "SAVE"))
        {
            ADVCOMMAND();
            char *namafile;
            wordToString(currentCMD, namafile);
            SAVEBNMO(&ListGames, namafile);
        }
        else if (wordAndCharSama(currentCMD, "CREATE"))
        {
            ADVCOMMAND();
            char *game;
            wordToString(currentCMD, game);
            printf("%s\n" , game);
            if(wordAndCharSama(currentCMD, "GAME"))
            {
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
            char *game;
            wordToString(currentCMD, game);
            if(wordAndCharSama(currentCMD, "GAME"))
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
            char *game;
            wordToString(currentCMD, game);
            if(wordAndCharSama(currentCMD, "GAME"))
            {
                DELETE(&ListGames);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(wordAndCharSama(currentCMD, "QUEUE"))
        {
            ADVCOMMAND();
            char *game;
            wordToString(currentCMD, game);
            if(wordAndCharSama(currentCMD, "GAME"))
            {
                QUEUEGAME(&QueueGame, &ListGames);
            }
            else
            {
                printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
            }
        }
        else if(wordAndCharSama(currentCMD, "PLAY"))
        {
            ADVCOMMAND();
            char *game;
            wordToString(currentCMD, game);
            if(wordAndCharSama(currentCMD, "GAME"))
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
            int skip = WordToInt(currentCMD) - 10 ;            
            SKIPGAME(&QueueGame, skip);
        }
        else if(wordAndCharSama(currentCMD, "HELP"))
        {
            HELP();
        }
        else
        {
            printf("Command tidak dikenali, silahkan masukkan command yang valid.\n");
        }
        printf("ENTER COMMAND: ");
        STARTCOMMAND();   
    }
    QUIT();

    return 0;

}
