#include "start.h"

void STARTGAME(ArrayDin *game){
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
        InsertLast(game , string);
        printf("%s\n" , (*game).A[i-1]);
    }
    if(!IsEmpty(*game)) 
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


int main(){
    ArrayDin ListGames;
    STARTGAME(&ListGames);
}


/*
void LOADBNMO(ArrayDin* GamesList, char* filename) 
 { 
     char path[50]; 
     stringConcat("./data/",filename,path); 
     // printf("%s",path); 
     STARTWORD(path); 
     int TotalGame = WordToInt(currentWord); 
     int i = 1; 
     // printf("%d\n",TotalGame); 
     ADVLine(); 
     while(i <= TotalGame) 
     { 
         // printf("%s\n",currentWord); 
         char *line; 
         line = WordToString(currentWord); 
         // printf("%s\n",line); 
         InsertLast(GamesList,line); 
         // PrintArrayDin(*GamesList); 
         ADVLine(); 
         // printf("%s\n",line); 
         i++; 
     } 
     if(!IsEmpty(*GamesList)) 
     { 
         printf("Save file berhasil dibaca. BNMO berhasil dijalankan.\n"); 
     } 
 }*/