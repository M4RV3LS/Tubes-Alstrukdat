#include <stdio.h>
#include <stdlib.h>
//#include "ADT/arrayOfString.h"
#include "ADT/mesinkata2.h"
#include "ADT/mesinkar2.h"
#include "LOAD.h"

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

 /*Test Case*/
 int main(){
    ArrayDin ListGames = CreateDynArray(); //= CreateDynArray();
    LOADFILE(&ListGames , "savefile.txt");
    SAVEBNMO(&ListGames , "savefile4.txt");
    /*
    ArrayDin arr;
    arr = CreateDynArray();
    char string[11];
    for (int i = 0;i <=9;i++){
        string[i] = intToChar(i);
        InsertLast(&arr , string);
        printf("%s\n" , arr.A[i]);
    }
    SAVEBNMO(&arr, "test.txt");
    return 0;
    */
   return 0;
 }