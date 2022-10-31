#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "boolean.h"

int gameRNG()  
{  
    srand(time(NULL));
    int maxTry = 50;
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak sebuah angka yang rentangnya berada diantara 1 - 50.\n");
    int random = rand() % 50 + 1;
    //printf("%d\n",random); Buat mengetahui random integernya hehe
    int tebakan;
    int skor = 0;
    printf("Tebakan : ");
    scanf("%d",&tebakan);
    int nTebakan = 1;
    while(tebakan != random && (nTebakan <= maxTry)){
        if(tebakan < random){
            printf("Lebih Besar\n");
        }
        else if(tebakan > random){
            printf("Lebih Kecil\n");
        }
        printf("Tebakan : ");
        scanf("%d",&tebakan);
        nTebakan++;
    }
    skor = maxTry - nTebakan;
    printf("skor = %d" , skor);
    return skor;
}

/*TEST CASE*/
/*
int main(){
    gameRNG();
    return 0;
}
*/