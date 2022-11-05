#include <stdio.h>
#include <stdlib.h>
#include "LOAD.h"

void LOADFILE(ArrayDin *ListGames , char* filename){
    char path[NMax];
    stringConcat("./data/",filename,path);
    // printf("%s",path);
    STARTWORD(filename);
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

/*
int main(){
    ArrayDin ListGames;
    LOADFILE(&ListGames , "savefile.txt");
}
*/

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