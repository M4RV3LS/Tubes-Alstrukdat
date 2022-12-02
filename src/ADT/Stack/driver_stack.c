#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main(){
   
    Stack S;
    char *TOP;
    CreateEmptyStack(&S);
    PushStack(&S,"Marvel");
    PushStack(&S,"Tim");
    PushStack(&S,"Jodi");
    PushStack(&S,"lim");
    
    /*Mengecek apakah stack kosong*/
    printf("Mengecek apakah Stack Kosong ? :\n");
    if(IsEmptyStack(S)){
        printf("Stack kosong\n");
    }
    else{
        printf("Stack tidak kosong\n");
    }

    /*mengecek apakah stack penuh*/
    printf("Mengecek apakah Stack Penuh ? :\n");
    if(IsFullStack(S)){
        printf("Stack penuh\n");
    }
    else{
        printf("Stack tidak penuh\n");
    }
    
    printf("Berikut Stack yang telah dibuat : \n");
    DisplayStack(S , Top(S));
    printf("\n");
    printf("Berikut Stack yang telah dibuat setelah di reverse : \n");
    Stack out;
    out = ReverseStack(S);
    printf("Hasil Reverse ; \n");
    DisplayStack(out , Top(out));
    printf("\n");
    PopStack(&S,&TOP);
    printf("TOP Yang di Pop adalah : %s\n" , TOP);
    printf("Berikut Stack yang telah dibuat setelah di Pop : \n");
    DisplayStack(S , Top(S));
    printf("\n");
    PopStack(&S,&TOP);
    PopStack(&S,&TOP);
    PopSatck(&S,&TOP);
    DisplayStack(S , Top(S));
    return 0;
} 
