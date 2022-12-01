#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "ADT/mesinkar2.h"
#include "ADT/mesinkata2.h"
#include "ADT/arrayOfString.h"
#include "boolean.h"
#include "ADT/queue.h"
#include "ADT/SetMap/map.h"
#include "ADT/Stack/stack.h"
#include "ADT/SnakeOnMeteor/snakeonmeteor.h"


void torielfight(int *score , char*Username)
/*Melakukan permainan Rock , Paper , Scissors dimana user akan menginput Rock , Paper , atau scissors*/
{
    int skor = 100;
    int langkah = 0;
    Map RPS;
    CreateEmptyMap(&RPS);
    Insert(&RPS, "rock", 1);
    Insert(&RPS, "paper", 2);
    Insert(&RPS, "scissors", 3);
    // for (int i = 0;i < RPS.Count ; i++){
    //     printf("%s %d\n", RPS.Elements[i].Nama, RPS.Elements[i].Skor);
    // }
    boolean win = false;
    boolean valid = false;
    int random;
    char *input;
    while(!valid && !win){
        langkah++;
        srand(time(0));
        random = randint(1, 3);
        //printf("random integer = %d\n",random);
        //char *RPSopponet = copystr(RPS.Elements[random - 1].Nama);
        printf("RPSOpponet = %s\n",RPS.Elements[random - 1].Nama);
            
            printf("rock / paper / scissors \n");
            printf("Masukan pilihanmu:");
            STARTCOMMANDGAME();
            input = WORDTOSTRING(currentCMD);
            //printf("input = %s\n", input);
            if(IsUsernameEqual(input, "rock") || IsUsernameEqual(input, "paper") || IsUsernameEqual(input, "scissors")){
                valid = true;
                printf("masuk\n");
                //printf("value input = %d\n" , Skor(RPS, input));
                if (IsUsernameEqual(input, "rock")){
                    if (random == 3){
                        printf("Draw\n");
                    } else if (random == 2){
                        printf("You lose\n");
                    } else if (random == 1){
                        printf("You win\n");
                        win = true;
                    }
                } else if (IsUsernameEqual(input, "paper")){
                    if (random == 3){
                        printf("You win\n");
                        win = true;
                    } else if (random == 2){
                        printf("Draw\n");
                    } else if (random == 1){
                        printf("You lose\n");
                    }
                } else if (IsUsernameEqual(input , "scissors")){
                    if (random == 3){
                        printf("You lose\n");
                    } else if (random == 2){
                        printf("You win\n");
                        win = true;
                    } else if (random == 1){
                        printf("Draw\n");
                    }
                } 
                //EndWord = true;
                if(!win){
                    valid = false;
                }
            }
            else{
                printf("Inputan Salah! Silahkan Input kembali berupa rock / paper / scissor\n");
            }
        
    }
    skor = (skor - (langkah * 1)) + 1;
    (*score) += skor;
} 

int mainsans()
/*Basic nya mirip mathquiz cuman bedanya semua mode pertambahan , perkalian , dan pengurangan di jadiin satu 
dan dipisahkan dengan 3 stage berbeda*/
{
    /*FASE 1 - PERTAMBAHAN*/
    printf("\n! WARNING !\n");
    printf("Untuk Memenangkan Game ini , Anda Harus mempertahankan health ... agar tidak dibawah 70\n");
    printf("Setiap Kesalahan akan mengurangi health anda sebesar 10 , jadi pastikan tidak ada kesalahan\n");
    int health = 100;
    int  a , b , c;
    int i = 0;
    int looping = 3;
    printf("health anda saat ini = %d\n", health);
    boolean ulang1 = true;
    while(ulang1){
        printf("\nSTAGE 1\n");
        printf("GET READY ...\n\n");
        while(i < looping ){
                a = randint(0,20);
                b = randint(0,20);
                c = a + b;
                int masukan;
                //printf("hasil adalah %d\n" , c);
                printf("%d + %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    //printf("masuk\n");
                    masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        printf("Jawaban Anda Benar\n");
                    }
                    else{
                        printf("Jawaban Anda Salah \n\n");
                        printf("Jawabannya seharusnya adalah %d\n",c);
                        health = health - 10;
                    }
                }
                else{
                    printf("Input tidak valid\n");
                }
                //printf("Skor kuis kamu sekarang adalah %d\n" , skor);
                IgnoreBlanksCMD();
                i++;   
                printf("\n");
            }
            boolean valid = false;
            printf("health anda saat ini = %d\n", health);
            while(!valid){
                printf("Apakah anda ingin mengulang stage 1 ? (yes/no)\n");
                STARTCOMMANDGAME();
                if(IsUsernameEqual(WORDTOSTRING(currentCMD), "yes")){
                    i = 0;
                    //looping = 3;
                    valid = true;
                    ulang1 = true;
                    health = 100;
                } else if (IsUsernameEqual(WORDTOSTRING(currentCMD), "no")){
                    ulang1 = false;
                    valid = true;  
                }
                else{
                    printf("Input Tidak Valid\n\n");
                }
            }
            
        }
    /*FASE 2 - PERKALIAN*/
    i = 0;
    int health1 = health;
    boolean ulang2 = true;
    while(ulang2){
        printf("\nSTAGE 2\n");
        printf("GET READY ...\n\n");
        while(i < looping ){
                a = randint(0,10);
                b = randint(0,10);
                c = a * b;
                int masukan;
                //printf("hasil adalah %d\n" , c);
                printf("%d x %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    //printf("masuk\n");
                    masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        printf("Jawaban Anda Benar\n");
                    }
                    else{
                        printf("Jawaban Anda Salah \n\n");
                        printf("Jawabannya seharusnya adalah %d\n",c);
                        health = health - 10;
                    }
                }
                else{
                    printf("Input tidak valid\n");
                }
                //printf("Skor kuis kamu sekarang adalah %d\n" , skor);
                IgnoreBlanksCMD();
                i++;   
                printf("\n");
            }
            boolean valid = false;
            printf("health anda saat ini = %d\n", health);
            while(!valid){
                printf("Apakah anda ingin mengulang stage 1 ? (yes/no)\n");
                STARTCOMMANDGAME();
                if(IsUsernameEqual(WORDTOSTRING(currentCMD), "yes")){
                    i = 0;
                    //looping = 3;
                    valid = true;
                    ulang2 = true;
                    health = health1;
                } else if (IsUsernameEqual(WORDTOSTRING(currentCMD), "no")){
                    ulang2 = false;
                    valid = true;  
                }
                else{
                    printf("Input Tidak Valid\n\n");
                }
            }
            
        }

    i = 0;
    int health2 = health;
    boolean ulang3 = true;
    while(ulang3){
        printf("\nSTAGE 3\n");
        printf("GET READY ...\n\n");
        while(i < looping ){
                a = randint(0,50);
                // while(a == 0){
                //     a = randint(0,50);
                // }
                b = randint(0,50);
                // while(b < a){
                //      b = randint(0,50);
                // }
                if (a >= b){
                    c = a - b;
                    //printf("hasil adalah %d\n" , c);
                    printf("%d - %d = ", a , b);
                }
                else{
                    c = b - a;
                    printf("%d - %d = ", b , a);
                }
                int masukan;
                //printf("hasil adalah %d\n" , c);
                //printf("%d x %d = ", a , b);
                STARTCOMMANDGAME();
                if(isInteger(currentCMD)){
                    //printf("masuk\n");
                    masukan = WordToInt(currentCMD);
                    //printf("Masukan kamu adalah %d\n",masukan);
                    
                    if (masukan == c){
                        printf("Jawaban Anda Benar\n");
                    }
                    else{
                        printf("Jawaban Anda Salah \n\n");
                        printf("Jawabannya seharusnya adalah %d\n",c);
                        health = health - 10;
                    }
                }
                else{
                    printf("Input tidak valid\n");
                }
                //printf("Skor kuis kamu sekarang adalah %d\n" , skor);
                IgnoreBlanksCMD();
                i++;   
                printf("\n");
            }
            boolean valid = false;
            printf("health anda saat ini = %d\n", health);
            while(!valid){
                printf("Apakah anda ingin mengulang stage 1 ? (yes/no)\n");
                STARTCOMMANDGAME();
                if(IsUsernameEqual(WORDTOSTRING(currentCMD), "yes")){
                    i = 0;
                    //looping = 3;
                    valid = true;
                    ulang3 = true;
                    health = health2;
                } else if (IsUsernameEqual(WORDTOSTRING(currentCMD), "no")){
                    ulang3 = false;
                    valid = true;  
                }
                else{
                    printf("Input Tidak Valid\n\n");
                }
            }
            
        }
        printf("health anda saat ini = %d\n", health);
    
    return health;
}

void sansfight(int *score , char*Username)
/*Melakukan looping hingga health papyrus harus diatas 70*/
{
    int sans = mainsans();
    while (papyrus < 70){
        printf("Anda gagal dalam permainan ini\n");
        printf("Anda harus mengulangi game ini kembali untuk melanjutkan ke cerita selanjutnya\n");
        sans = mainsans();
    }
    (*score) += sans;
}

void papyrusfight(int *score , char *Username)
/*Menyusun beberapa jenis uang dengan jumlah tertentu agar sesuai dengan jumlah uang yang harus dibayarkan*/
{
    int skor = 100;
    int langkah = 0;
    printf("\n");
    printf("%s ingin membeli makanan di restoran Papyrus dengan suatu harga tertentu . \n" , Username);
    printf("Bantulah %s untuk menyiapkan uangnya agar sesuai dengan jumlah uang yang harus dibayar . \n" , Username , Username);
    printf("\n");
    int quarters = 25;
    int dimes = 10;
    int nickels = 5;
    int pennies = 1;
    srand(time(0));
    int random = randint(1,200);
    printf("Jumlah uang yang harus %s bayar adalah %d\n",Username ,  random);
    printf("Keterangan : \n");
    printf ("quarters = 25 \n");
    printf ("dimes = 10 \n");
    printf ("nickels = 5 \n");
    printf ("pennies = 1 \n");
    printf("\n");
    int masukanquarters , masukandimes , masukannickels , masukanpennies;
    boolean valid = false;
    boolean win = false;
    int total;
    while (!win){
        while(!valid){
        printf("Masukkan jumlah quarters : \n");
        STARTCOMMANDGAME();
        if(isInteger(currentCMD)){
            masukanquarters = WordToInt(currentCMD);
            valid = true;
            }
        
        else{
            printf("Input tidak valid\n");
        }
    }

        valid = false;
        while(!valid){
            printf("Masukkan jumlah dimes : \n");
            STARTCOMMANDGAME();
            if(isInteger(currentCMD)){
                masukandimes = WordToInt(currentCMD);
                valid = true;
                }
            
            else{
                printf("Input tidak valid\n");
            }
        }

        valid = false;
        while(!valid){
            printf("Masukkan jumlah nickels : \n");
            STARTCOMMANDGAME();
            if(isInteger(currentCMD)){
                masukannickels = WordToInt(currentCMD);
                valid = true;
                }
            
            else{
                printf("Input tidak valid\n");
            }
        }

        valid = false;
        while(!valid){
            printf("Masukkan jumlah pennies : \n");
            STARTCOMMANDGAME();
            if(isInteger(currentCMD)){
                masukanpennies = WordToInt(currentCMD);
                valid = true;
                }
            
            else{
                printf("Input tidak valid\n");
            }
        }

        total = (quarters * masukanquarters) + (dimes * masukandimes) + (nickels * masukannickels) + (pennies * masukanpennies);
        if (total == random){
            printf("Selamat anda berhasil\n");
            win = true;
        }
        else if (total > random){
            printf("Jumlah uang anda lebih banyak dari yang dibutuhkan\n");
            printf("Silahkan coba lagi\n");
        }
        else{
            printf("Jumlah uang anda kurang dari yang dibutuhkan\n");
            printf("Silahkan coba lagi\n");
        }
        printf("\n");
    }
    skor = (skor - (langkah * 10)) + 10;
    (*score) += skor;
}
void CreateRandomPointAsriel(Point *P){
    int x = randint(0, 4);
    int y = randint(0, 4);
    CreatePoint(P , x, y);
}

void PrintAlphabet(Map MiniGames , int index , char*input)
/*Melakukan print alphabet sesuai value yang dimilikinya*/
{ 
    int value;
    value = MiniGames.Elements[index].Skor;
    if(value == 1 || value == 0 || value == -999){
        printf("  %s  ",input);
    }
    else if(value == -1){
        printf("  0  ");
    }
    else if(value == 100){
        printf(" WIN ");
    }
    else if(value == -100){
        printf(" BOM ");
    }
}

void Axe(){
    printf(" _,-,\n");
    printf("T_  |\n");
    printf("||`-'\n");
    printf("||   \n");
    printf("||   \n");
    printf("~~ \n");                                                  
}

// void Maze(){
//     printf("88888888888888888888888888888888888888888888888888888888888888888888888\n");
//     printf("88.._|      | `-.  | `.  -_-_ _-_  _-  _- -_ -  .'|   |.'|     |  _..88\n");
//     printf("88   `-.._  |    |`!  |`.  -_ -__ -_ _- _-_-  .'  |.;'   |   _.!-'|  88\n");
//     printf("88      | `-!._  |  `;!  ;. _______________ ,'| .-' |   _!.i'     |  88\n");
//     printf("88..__  |     |`-!._ | `.| |_______________||.''|  _!.;'   |     _|..88\n");
//     printf("88   |``'..__ |    |`';.| i|_|MMMMMMMMMMM|_|'| _!-|   |   _|..-|'    88\n");
//     printf("88   |      |``--..|_ | `;!|l|MMoMMMMoMMM|1|.'j   |_..!-'|     |     88\n");
//     printf("88   |      |    |   |`-,!_|_|MMMMP'YMMMM|_||.!-;'  |    |     |     88\n");
//     printf("88___|______|____!.,.!,.!,!|d|MMMo * loMM|p|,!,.!.,.!..__|_____|_____88\n");
//     printf("88      |     |    |  |  | |_|MMMMb,dMMMM|_|| |   |   |    |      |  88\n");
//     printf("88      |     |    |..!-;'i|r|MPYMoMMMMoM|r| |`-..|   |    |      |  88\n");
//     printf("88      |    _!.-j'  | _!,'|_|MMMMMMoMMM|_||!._|  `i-!.._  |      |  88\n");
//     printf("88     _!.-'|    | _.'|  ! |1|MbdMMoMMMMM|l|`.| `-._|    |``-.._  |  88\n");
//     printf("88..-i'     |  _.''|  !-| !|_|MMMoMMMMoMM|_|.|`-. | ``._ |     |``'..88\n");
//     printf("88   |      |.|    |.|  !| |u|MoMMMMoMMMM|n||`. |`!   | `;.    |     88\n");
//     printf("88   |  _.-'  |  .'  |.' |/|_|MMMMoMMMMoM|_|! |`!  `,.|    |-._|     88\n");
//     printf("88  _!`'|     !.'|  .'| .'|[@]MMMMMMMMMMM[@] \|  `. | `._  |   `-._  88\n");
//     printf("88-'    |   .'   |.|  |/| /                 \|`.  |`!    |.|      |`-88\n");
//     printf("88      |_.'|   .' | .' |/                   \  \ |  `.  | `._-   |  88\n");
//     printf("88     .'   | .'   |/|  /                     \ |`!   |`.|    `.  |  88\n");
//     printf("88  _.'     !'|   .' | /                       \|  `  |  `.    |`.|  88\n");
//     printf("88 vanishing point 888888888888888888888888888888888888888888888(FL)888\n");
// }

void WelcomingAsrielGames(){
printf("\n");
printf("           *O*                                                   \n");
printf("           |X|_                                                  \n");
printf("           |X||-------________________________________________   \n");
printf(",O---------+X| \\___   `=------------------------------- _____ \\*\n");
printf("`O---------+X| /      ,=-------------------------------'      /* \n");
printf("           |X||-------~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~   \n");
printf("           |X|~                                                  \n");
printf("           *0*                                                   \n");
printf("\n");

printf("\n");
printf("==================================================================\n");
printf("=                  WELCOME TO THE FINAL STAGE                    =\n");
printf("==================================================================\n");
printf ("\n");
}

void AsrielGameRule(){
printf("******************************************************************\n");
printf("*                       RULES OF THE GAME                        *\n");
printf("******************************************************************\n");
printf("*             DO NOT USING WHITESPACE WHEN INPUT COMMAND!        *\n");
printf("*               DO NOT OPEN THE BOX THAT CONTAIN BOMB            *\n");
printf("*           THERE IS ONLY ONE TREASURE THAT U SHOUL FIND IT      *\n");
printf("******************************************************************\n");

printf("\n");
printf("~~~~~~~~~~~~~~~~~~~~~~~~~~ GOOD LUCK ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
printf("\n");
}
void PrintPetaAsriel(Map MiniGames){
    printf("Berikut merupakan peta permainan\n");
    int i,j;
    int alphabet = 0;
    int value;
    for(i = 0; i < 11; i++)
    {
        for(j = 0; j < 11; j++)
        {
            
            if(i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    printf(" ");
                }
                else 
                {
                    printf("-----");
                }
            }
            
            else 
            {
                if(j % 2 == 0)
                {
                    printf("|");
                }
                
                else 
                {
                    if(i == 1 && j == 1)
                    {
                        // value = MiniGames.Elements[0].Skor;
                        // if(value == 1 || value == 0 || value == -999){
                        //     printf("  A  ");
                        // }
                        // else if(value == -1){
                        //     printf("  X  ");
                        // }
                        // else if(value == 100){
                        //     printf(" WIN ");
                        // }
                        // else if(value == -100){
                        //     printf(" BOM ");
                        // }
                    PrintAlphabet(MiniGames , alphabet , "A");
                    }
                    else if(i == 1 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "B");
                    }
                    else if(i == 1 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "C");
                    }
                    else if(i == 1 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "D");
                    }
                    else if(i == 1 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "E");
                    }
                    else if(i == 3 && j == 1)
                    {
                        PrintAlphabet(MiniGames , alphabet , "F");
                    }
                    else if(i == 3 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "G");
                    }
                    else if(i == 3 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "H");
                    }
                    else if(i == 3 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "I");
                    }
                    else if(i == 3 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "J");
                    }
                    else if(i == 5 && j == 1)
                    {
                        PrintAlphabet(MiniGames , alphabet , "K");
                    }
                    else if(i == 5 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "L");
                    }
                    else if(i == 5 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "M");
                    }
                    else if(i == 5 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "N");
                    }
                    else if(i == 5 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "O");
                    }
                    else if(i == 7 && j == 1)
                    {
                        PrintAlphabet(MiniGames , alphabet , "P");
                    }
                    else if(i == 7 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "Q");
                    }
                    else if(i == 7 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "R");
                    }
                    else if(i == 7 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "S");
                    }
                    else if(i == 7 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "T");
                    }
                    else if(i == 9 && j == 1)
                    {
                        PrintAlphabet(MiniGames , alphabet , "U");
                    }
                    else if(i == 9 && j == 3)
                    {
                        PrintAlphabet(MiniGames , alphabet , "V");
                    }
                    else if(i == 9 && j == 5)
                    {
                        PrintAlphabet(MiniGames , alphabet , "W");
                    }
                    else if(i == 9 && j == 7)
                    {
                        PrintAlphabet(MiniGames , alphabet , "X");
                    }
                    else if(i == 9 && j == 9)
                    {
                        PrintAlphabet(MiniGames , alphabet , "Y");
                    }
                    alphabet++;
            }
        }
        
    }
    printf("\n");
}
}

void InsertMapMiniGames(Map *M, keytype k, valuetype v)
{
	if(IsEmptyMap(*M)){
		(*M).Elements[(*M).Count].Nama = k;
		(*M).Elements[(*M).Count].Skor = v;
		(*M).Count++;
	}
	else{
		if(!IsMemberMap(*M , k)){
			(*M).Elements[(*M).Count].Nama = k;
			(*M).Elements[(*M).Count].Skor = v;
			(*M).Count++;
		}
	}
}

int mainasriel(char*Username){
    WelcomingAsrielGames();
    AsrielGameRule();
    int skor = 100;
    int langkah = 0;
    Point bomb1, bomb2, bomb3, bomb4, bomb5 , treasure;
    Map asriel_map;
    CreateEmptyMap(&asriel_map);
    CreateRandomPointAsriel(&bomb1);
    CreateRandomPointAsriel(&bomb2);
    CreateRandomPointAsriel(&bomb3);
    CreateRandomPointAsriel(&bomb4);
    CreateRandomPointAsriel(&bomb5);
    CreateRandomPointAsriel(&treasure);
    /*Memastikan setiap bomb dan treasure menghasilkan Point Value yang berbeda beda*/
    while(IsPointSama(bomb1, bomb2) || IsPointSama(bomb1, bomb3) || IsPointSama(bomb1, bomb4) || IsPointSama(bomb1, bomb5) || IsPointSama(bomb1,treasure)){
        CreateRandomPointAsriel(&bomb1);
    }
    while(IsPointSama(bomb2 , bomb1) || IsPointSama(bomb2,bomb3) || IsPointSama(bomb2,bomb4) || IsPointSama(bomb2,bomb5) || IsPointSama(bomb2,treasure)){
        CreateRandomPointAsriel(&bomb2);
    }
    while(IsPointSama(bomb3 , bomb1) || IsPointSama(bomb3,bomb2) || IsPointSama(bomb3,bomb4) || IsPointSama(bomb3,bomb5) || IsPointSama(bomb3,treasure)){
        CreateRandomPointAsriel(&bomb3);
    }
    while(IsPointSama(bomb4 , bomb1) || IsPointSama(bomb4,bomb2) || IsPointSama(bomb4,bomb3) || IsPointSama(bomb4,bomb5) || IsPointSama(bomb4,treasure)){
        CreateRandomPointAsriel(&bomb4);
    }
    while(IsPointSama(bomb5 , bomb1) || IsPointSama(bomb5,bomb2) || IsPointSama(bomb5,bomb3) || IsPointSama(bomb5,bomb4) || IsPointSama(bomb5,treasure)){
        CreateRandomPointAsriel(&bomb5);
    }
    
    /*Inisiasi Map*/
    int TreasureMap[5][5];
    int x,y;
    for(x = 0; x < 5; x++){
        for(y = 0; y < 5; y++){
            /*Melakukan assign matrix value sebesar -999 ke lokasi yang merupakan bomb*/
            if((x == Absis(bomb1) && y == Ordinat(bomb1)) || (x == Absis(bomb2) && y == Ordinat(bomb2)) || (x == Absis(bomb3) && y == Ordinat(bomb3)) || (x == Absis(bomb4) && y == Ordinat(bomb4)) || (x == Absis(bomb5) && y == Ordinat(bomb5))){
                TreasureMap[x][y] = -999;
            }
            /*Melakukan assign matrix value sebesar 0 ke lokasi yang merupakan treasure*/
            else if(x == Absis(treasure) && y == Ordinat(treasure)){
                TreasureMap[x][y] = 0;
            }
            /*Melakukan assign matrix value sebesar 1 ke lokasi yang bukan merupakan bomb / treasure*/
            else{
                TreasureMap[x][y] = 1;
            }
        }
    }
    
    InsertMapMiniGames(&asriel_map , "A" , TreasureMap[0][0]);
    InsertMapMiniGames(&asriel_map , "B" , TreasureMap[0][1]);
    InsertMapMiniGames(&asriel_map , "C" , TreasureMap[0][2]);
    InsertMapMiniGames(&asriel_map , "D" , TreasureMap[0][3]);
    InsertMapMiniGames(&asriel_map , "E" , TreasureMap[0][4]);
    InsertMapMiniGames(&asriel_map , "F" , TreasureMap[1][0]);
    InsertMapMiniGames(&asriel_map , "G" , TreasureMap[1][1]);
    InsertMapMiniGames(&asriel_map , "H" , TreasureMap[1][2]);
    InsertMapMiniGames(&asriel_map , "I" , TreasureMap[1][3]);
    InsertMapMiniGames(&asriel_map , "J" , TreasureMap[1][4]);
    InsertMapMiniGames(&asriel_map , "K" , TreasureMap[2][0]);
    InsertMapMiniGames(&asriel_map , "L" , TreasureMap[2][1]);
    InsertMapMiniGames(&asriel_map , "M" , TreasureMap[2][2]);
    InsertMapMiniGames(&asriel_map , "N" , TreasureMap[2][3]);
    InsertMapMiniGames(&asriel_map , "O" , TreasureMap[2][4]);
    InsertMapMiniGames(&asriel_map , "P" , TreasureMap[3][0]);
    InsertMapMiniGames(&asriel_map , "Q" , TreasureMap[3][1]);
    InsertMapMiniGames(&asriel_map , "R" , TreasureMap[3][2]);
    InsertMapMiniGames(&asriel_map , "S" , TreasureMap[3][3]);
    InsertMapMiniGames(&asriel_map , "T" , TreasureMap[3][4]);
    InsertMapMiniGames(&asriel_map , "U" , TreasureMap[4][0]);
    InsertMapMiniGames(&asriel_map , "V" , TreasureMap[4][1]);
    InsertMapMiniGames(&asriel_map , "W" , TreasureMap[4][2]);
    InsertMapMiniGames(&asriel_map , "X" , TreasureMap[4][3]);
    InsertMapMiniGames(&asriel_map , "Y" , TreasureMap[4][4]);
    PrintPetaAsriel(asriel_map);
    int TM = 0;
    for(x = 0; x < 5; x++){
        for(y = 0; y < 5; y++){
            printf("%d " , asriel_map.Elements[TM].Skor);
            TM++;
        }
        printf("\n");
    }
    // PrintMap(asriel_map);
    // printf("\n");
    /*Melakukan Print Map */
    //PrintPetaAsriel();
    
    boolean win = false;
    boolean bomb = false;

    /*Selama dia gakena bomb atau treasure terus diiterasi*/
    while(!bomb && !win){
            langkah++;
            printf("Pilih kotak dengan memilih huruf yang tersedia : \n");
            STARTCOMMANDGAME();
            char *input = WORDTOSTRING(currentCMD);
            valuetype value = Skor(asriel_map , input);
            //printf("value : %d\n",value);
            
            /*Jika Inputan Valid maka cek setiap kondisi*/
            if(IsMemberMap(asriel_map , input)){
                if(value == 1){
                    //printf("TEST1\n");
                    for(int index = 0;index < asriel_map.Count ; index++){
                        if(IsUsernameEqual(asriel_map.Elements[index].Nama , input)){
                            //printf("masuk1\n");
                            asriel_map.Elements[index].Skor = -1;
                        }
                    }
                    PrintPetaAsriel(asriel_map);
                }
                else if(value == 0){
                    //printf("TEST2\n");
                    for(int index = 0;index < asriel_map.Count ; index++){
                        if(IsUsernameEqual(asriel_map.Elements[index].Nama , input)){
                            //printf("masuk2\n");
                            asriel_map.Elements[index].Skor = 100;
                        }
                    }
                    PrintPetaAsriel(asriel_map);
                    //printf("nemu harta karun\n");
                    win = true;
                }
                else if(value == -999){
                    //printf("TEST3\n");
                        for(int index = 0;index < asriel_map.Count ; index++){
                            if(IsUsernameEqual(asriel_map.Elements[index].Nama , input)){
                                //printf("masuk3\n");
                                asriel_map.Elements[index].Skor = -100;
                            }
                        }
                        PrintPetaAsriel(asriel_map);
                        //printf("Kena Bom\n");
                        bomb = true;
                    }
                else if(value == -1){
                    printf("Kotak sudah terbuka\n");
                }
            }
            else{
                printf("Input tidak valid, silahkan masukkan input yang valid\n");
            }
            int TM = 0;
            for(x = 0; x < 5; x++){
                for(y = 0; y < 5; y++){
                    printf("%d " , asriel_map.Elements[TM].Skor);
                    TM++;
                }
            printf("\n");
        }
    }
    if(bomb){
        skor = 0;
    }
    else if (win){
        skor = (skor - (langkah * 5)) + 5;
    }
    return skor;
}

void asrielfight(int *score , char *Username){
    int skor = mainasriel(Username);
    while (skor == 0){
        printf("\nKamu kalah, silahkan coba lagi !\n");
        skor = mainasriel(Username);
    }
    (*score) += skor;
}

// int main(){
//     int score;
//     asriel(&score , "Marvel");
//     printf("Score anda %d\n" , score);
//     return 0;
// }