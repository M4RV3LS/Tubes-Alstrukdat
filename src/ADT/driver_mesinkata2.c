#include "mesinkata2.h"

/*
int main(){
    //char path[NMax];
    //int masukan;
    //STARTCOMMAND();
    //masukan = kataToInt(currentCMD);
    //if(masukan == 55){
        //printf("Berhasil");
    //}
    //else{
        //printf("Gagal");
    //}
    //stringConcat("./data/" , "savefile.txt" , path);
    //printf("%s", path);
    //return 0;
    int a = 0 ;
    char b = intToChar(a);
    printf("%c",b);
    int random = randint(1,5);
    printf("%d" , random);
}
*/

/*
int main(){
    char string[100];
    int i = 20;
    sprintf(string , "%d" , i);
    printf("%s\n",string);
}
*/

int main(){
    printf("ENTER COMMAND: ");
    STARTCOMMAND();
    if(EndWord){
        printf("Masukan kosong\n");
    }
    else if(isInteger(currentCMD)){
        printf("CMD ADALAH INTEGER\n");
    }
    else{
        printf("CMD BUKAN INTEGER\n");
    }
    return 0;
}
