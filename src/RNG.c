#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "boolean.h"

int gameRNG()  
/*I.S.Setiap permainan dimulai dengan program sudah menentukan sebuah angka acak X.
F.S.Permainan selesai jika pemain menebak angka X dengan benar.Skor pemain bergantung pada jumlah tebakan yang dilakukan oleh 
user , semakin banyak tebakan yang dilakukan , semakin sedikit skor yg didapat.
*/
{  
    srand(time(NULL)); // randomize seed
    int maxTry = 50; // Maksimal tebakan
    printf("RNG Telah dimulai. Uji keberuntungan Anda dengan menebak sebuah angka yang rentangnya berada diantara 1 - 50.\n");
    int random = rand() % 50 + 1; // biar angka berada di rentang 1 - 50
    //printf("%d\n",random); Buat mengetahui random integernya hehe
    int tebakan; // Nampung Variabel Tebakan
    int skor = 0; // Nampung Varaiabel Skor 
    printf("Tebakan : ");
    scanf("%d",&tebakan); //Input Tebakan
    int nTebakan = 1; // Inisiasi Jumlah Tebakan 
    while(tebakan != random && (nTebakan <= maxTry)){ //Looping Tebakan
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
    skor = maxTry - nTebakan; //Penilaian Skor adalah 50 - jumlah tebakan
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