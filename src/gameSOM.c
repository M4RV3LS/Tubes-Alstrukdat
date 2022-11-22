#include <stdio.h>
#include "ADT/SnakeOnMeteor/snakeonmeteor.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int SnakeOnMeteor(){
    printf("Selamat datang di Snake on Meteor!\n\n");
    printf("Mengenerate peta, snake, dan makanan . . .\n\n");
    delay(2);

    List L;
    CreateEmpty(&L);
    int X = randint(0,4);
    int Y = randint(0,4);

    Point P1;
    CreatePoint(&P1, X, Y);
    Point P2 = CreateNextPoint(P1);
    Point P3 = CreateNextPoint(P2);

    CreateList3Elemen(&L, P1, P2, P3);

    Point Obstacle = GenerateObstacle(L);
    Point Food = GenerateFoodPertama(Obstacle, L);
    // di titik ini sudah terbentuk 3 elemen sesuai aturan dan 1 buah obstacle

//                  INTERFACE                   //

    printf("Berhasil digenerate!\n\n");
    // Print peta

    // selanjutnya adalah pergerakan snake dan summon meteor

    int turn = 1;
    boolean gerak = false;
    boolean input = false;
    Point Meteor;
    CreatePoint(&Meteor, 5 ,5);
    do {

    printf("TURN %d:\n", turn);
    printf("Silahkan masukkan command anda:");
    STARTCOMMANDGAME();
    printf("\n");

    Point Geser;
    Geser = Info(Head(L));

    if (wordAndCharSama(currentCMD, "a"))
    {
        Absis(Geser) = Absis(Geser) - 1;
        while (Absis(Geser) < 0)
        {
            Absis(Geser) = Absis(Geser) + 5;
        }
        input = true;
    }
    else if (wordAndCharSama(currentCMD, "d"))
    {
        Absis(Geser) = Absis(Geser) + 1;
        while(Absis(Geser) > 4)
        {
            Absis(Geser) = Absis(Geser) - 5;
        }
        input = true;
    }
    else if (wordAndCharSama(currentCMD, "w"))
    {
        Ordinat(Geser) = Ordinat(Geser) - 1;
        while(Ordinat(Geser) < 0)
        {
            Ordinat(Geser) = Ordinat(Geser) + 5;
        }
        input = true;
    }
    else if (wordAndCharSama(currentCMD, "w"))
    {
        Ordinat(Geser) = Ordinat(Geser) + 1;
        while(Ordinat(Geser) > 4)
        {
            Ordinat(Geser) = Ordinat(Geser) - 5;
        }
        input = true;
    }
    else
    {
        printf("Command tidak valid! Silahkan input command menggunakan huruf w/a/s/d\n");
        input = false;
    }

    if (IsObstacle(Obstacle, Geser) && input)
    {
        printf("Ada obstacle itu lho, yo jangan mbok tabrak to mas\n");
        gerak = false;
        input = false;
    }
    else if (turn > 1 && input )
    {
        if  (IsMeteor(Meteor, Geser))
        {
            printf("Meteor masih panas! Anda belum dapat kembali ke titik tersebut.\n");
            printf("Silahkan masukkan command lainnya\n");
            gerak = false;
            input = false;
        }
        
    }
    else if (input) // berhasil bergerak
    {
        if (IsFood(Food, Geser)) // dapet makanan
        {
            InsertLast(&L);
            MoveList(&L, Geser);
            Food = GenerateFood(Obstacle, Meteor, L);
        }
        else // ga dapet makanan
        {
            MoveList2(&L, Geser);
        }
        printf("Berhasil bergerak!\n");
        gerak = true;
        turn++;
    }

    if (gerak)
    {
        Point Meteor = GenerateMeteor(Obstacle);
        printPeta(Obstacle, Meteor, Food, L);
        if (IsBadanKenaMeteor(L, Meteor) && gerak)
        {
            DeleteAt(L, Meteor);
            printf("\nAnda terkena meteor!\n");
            // Print peta
            gerak = false;
            printf("Silahkan lanjutkan permainan\n");
        }
        else if (gerak && !IsHeadKenaMeteor(L, Meteor))
        {
            printf("Anda beruntung tidak terkena meteor! Silahkan lanjutkan permainan\n");
            gerak = false;
        }
    }
    
    

    }
    while (IsGameOver(L, Meteor));

    // INTERFACE GAMEOVER //

    if (IsHeadKenaMeteor(L, Meteor))
    {
        printf("Kepala snake terkena meteor!\n");
    }
    else if (IsHeadNabrakBadan(L))
    {
        printf("Kepala snake nabrak badan!\n");
    }
    else if (IsEmpty(L))
    {
        printf("Snake mati karena tubuh snake terkena meteor semua!\n");
    }

    int skor = NbElmt(L)*2;
    printf("Game berakhir. Skor: %d\n", skor);


    return 0;
}

int main()
{
    SnakeOnMeteor();
    return 0;
}


/* Urutan bermain :
A. Inisialisasi
1. buat list kosong
2. buat 3 point random
3. alokasi 3 point
4. insert 3 point ke list
6. Buat obstacle
7. print ke layar

B. Permainan (loop sampai mati)
1. input
2. gerakkan snake
3. summon meteor
4. print ke layar

C. Penutup
1. print alasan mati
2. print score


*/
