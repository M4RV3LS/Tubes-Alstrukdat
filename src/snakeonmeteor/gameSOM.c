#include <stdio.h>
#include "gameSOM.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

void SnakeOnMeteor(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score){
    printf("Selamat datang di Snake on Meteor!\n\n");
    // aturan permainan 
    printf("Peraturan permainan Snake on Meteor:\n");
    printf("1. Snake dapat bergerak ke atas, kiri, bawah, atau kanan dengan meng-input w/a/s/d TANPA SPASI!\n");
    printf("2. Tujuan permainan : Dapatkan skor tertinggi dengan menghindari obstacle dan meteor yang jatuh dari langit!\n");
    printf("3. Snake akan mati jika terkena meteor, obstacle, atau badan sendiri.\n\n");

    printf("Selamat bermain!\n\n");
    delay(5);
    printf("Mengenerate peta, snake, dan makanan . . .\n\n");
    delay(1);

    List L;
    CreateEmpty(&L);
    int X = randint(0,4);
    int Y = randint(0,4);

    Point P1;
    CreatePoint(&P1, X, Y);
    Point P2 = CreateNextPoint(P1);
    Point P3 = CreateNextNextPoint(P2,P1);

    CreateList3Elemen(&L, P1, P2, P3);

    Point Obstacle = GenerateObstacle(L);
    Point Food = GenerateFoodPertama(Obstacle, L);
    // di titik ini sudah terbentuk 3 elemen sesuai aturan dan 1 buah obstacle

//                  INTERFACE                   //

    printf("Berhasil digenerate!\n\n");

    printf("________________________________\n\n\n");

    // selanjutnya adalah pergerakan snake dan summon meteor

    int turn = 1;
    boolean turnPertama = true;
    boolean gerak = false; // kalo gerak = true, snake bergerak
    boolean input = false; // kalo input = true, lakukan operasi (belum tentu gerak, bisa aja nabrak obstacle)
    Point Meteor;
    CreatePoint(&Meteor, -1, -1);
    printmap(L, Meteor, Food, Obstacle);
    printf("\n");
    // CreatePoint(&Meteor, 5 ,5);
    do {

    printf("TURN %d\n", turn);
    printf("Silahkan masukkan command anda:");
    STARTCOMMANDGAME();
    IgnoreBlanksCMD(); // kalo ada blank
    printf("\n");

    Point Geser;
    Geser = Info(Head(L));

    if (currentCMD.Length == 1 )
    {
    if (wordAndCharSama(currentCMD,"a") || wordAndCharSama(currentCMD,"A"))
    {
        Absis(Geser) = Absis(Geser) - 1;
        while (Absis(Geser) < 0)
        {
            Absis(Geser) = Absis(Geser) + 5;
        }
        if (IsHeadBakalNabrakBadan(L, Geser))
        {
            input = false;
            printf("Input tidak valid. Dilarang bunuh diri!\n");
        }
        else
        {
            input = true;
        }
    }
    else if (wordAndCharSama(currentCMD, "d") || wordAndCharSama(currentCMD,"D"))
    {
        Absis(Geser) = Absis(Geser) + 1;
        while(Absis(Geser) > 4)
        {
            Absis(Geser) = Absis(Geser) - 5;
        }
        if (IsHeadBakalNabrakBadan(L, Geser))
        {
            input = false;
            printf("Input tidak valid. Dilarang bunuh diri!\n");
        }
        else
        {
            input = true;
        }
    }
    else if (wordAndCharSama(currentCMD, "w") || wordAndCharSama(currentCMD,"W"))
    {
        Ordinat(Geser) = Ordinat(Geser) - 1;
        while(Ordinat(Geser) < 0)
        {
            Ordinat(Geser) = Ordinat(Geser) + 5;
        }
        // printf("Geser: %d %d\n", Absis(Geser), Ordinat(Geser));
        if (IsHeadBakalNabrakBadan(L, Geser))
        {
            input = false;
            printf("Input tidak valid. Dilarang bunuh diri!\n");
        }
        else
        {
            input = true;
        }
    }
    else if (wordAndCharSama(currentCMD, "s") || wordAndCharSama(currentCMD,"S"))
    {
        Ordinat(Geser) = Ordinat(Geser) + 1;
        while(Ordinat(Geser) > 4)
        {
            Ordinat(Geser) = Ordinat(Geser) - 5;
        }
        if (IsHeadBakalNabrakBadan(L, Geser))
        {
            input = false;
            printf("Input tidak valid. Dilarang bunuh diri!\n");
        }
        else
        {
            input = true;
        }
    }
    else // input salah
    {
        printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        input = false;
    }}
    else // input salah
    {
        printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        input = false;
    }
 
    if (input) // input benar
    {
        if(IsMeteor(Geser, Meteor))
        {
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            printf("Silahkan masukkan command lainnya\n\n");
            gerak = false;
            input = false;
        }
        else 
        {
        if (IsFood(Food, Geser)) // dapet makanan
        {
            MoveList(&L, Geser);
            Food = GenerateFood(Obstacle, Meteor, L); // food auto muncul di next turn
            turn++;
            turnPertama = false;
            printf("Berhasil bergerak!\n");
            gerak = true;
        }
        else // ga dapet makanan
        {
            MoveList2(&L, Geser);
            turn++;
            turnPertama = false;
            printf("Berhasil bergerak!\n");
            gerak = true;
        } 
        }          
        
    }

    if (gerak) // fix move (gerak)
    {
        Meteor = GenerateMeteor(Obstacle, Food);
        printmap(L, Meteor, Food, Obstacle);
        if (IsBadanKenaMeteor(L, Meteor) && gerak)
        {
            DeleteDi(&L, Meteor);
            printf("\nAnda terkena meteor!\n");
            printmap(L, Meteor, Food, Obstacle);
            printf("\n");
            gerak = false;
            printf("Silahkan lanjutkan permainan\n");
        }
        else if (gerak && !IsHeadKenaMeteor(L, Meteor))
        {
            printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n\n");
            gerak = false;
        }
    }

    }while (!IsGameOver(L, Meteor, Obstacle) || (NbElmt(L) == 24));

    // INTERFACE GAMEOVER //
    int skor;
    if (IsHeadKenaMeteor(L, Meteor))
    {
        printf("Kepala snake terkena meteor!\n\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n\n", skor-2);
    }
    else if (IsEmptySOM(L))
    {
        printf("Snake mati karena tubuh snake terkena meteor semua!\n\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: 0.\n\n");
    }
    else if (IsObstacle(Obstacle, Info(Head(L)))) // nabrak obstacle
    {
        printf("Ada obstacle itu lho, yo jangan mbok tabrak to mas\n\n");
        gerak = false;
        input = false;
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n\n", skor-2);
    }
    else if (NbElmt(L) == 24)
    {
        printf("Selamat! Anda berhasil menyelesaikan permainan!\n\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n\n", skor);
    }
    else if (!IsMasihBisaGerak(L, Obstacle, Meteor))
    {
        printf("Snake mati karena tidak bisa bergerak lagi!\n\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n\n", skor-2);
    }
    score = skor;
    Username(game , ListGames , GameMap , score);
}


