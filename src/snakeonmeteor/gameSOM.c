#include <stdio.h>
#include "gameSOM.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

void SnakeOnMeteor(char* game , ArrayDin ListGames , ArrayOfMap *GameMap , int score){
    printf("Selamat datang di Snake on Meteor!\n\n");
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
        // printf("Geser: %d %d\n", Absis(Geser), Ordinat(Geser));
        input = true;
    }
    else if (wordAndCharSama(currentCMD, "s"))
    {
        Ordinat(Geser) = Ordinat(Geser) + 1;
        while(Ordinat(Geser) > 4)
        {
            Ordinat(Geser) = Ordinat(Geser) - 5;
        }
        input = true;
    }
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

    }while (!IsGameOver(L, Meteor, Obstacle));

    // INTERFACE GAMEOVER //
    int skor;
    if (IsHeadKenaMeteor(L, Meteor))
    {
        printf("Kepala snake terkena meteor!\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n", skor-2);
    }
    else if (IsHeadNabrakBadan(L))
    {
        printf("Kepala snake nabrak badan!\n");
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n", skor-2);
    }
    else if (IsEmptySOM(L))
    {
        printf("Snake mati karena tubuh snake terkena meteor semua!\n");
    }
    else if (IsObstacle(Obstacle, Info(Head(L)))) // nabrak obstacle
    {
        printf("Ada obstacle itu lho, yo jangan mbok tabrak to mas\n");
        gerak = false;
        input = false;
        skor = NbElmt(L)*2;
        printf("Game berakhir. Skor: %d\n", skor-2);
    }

    score = skor;
    Username(game , ListGames , GameMap , score);
}

/*int main()
{
    
    
    List L;
    CreateEmpty(&L);
    int X = randint(0,4);
    int Y = randint(0,4);

    Point P1;
    CreatePoint(&P1, X, Y);
    Point P2 = CreateNextPoint(P1);
    Point P3 = CreateNextPoint(P2);

    printf("P1: %d %d\n", Absis(P1), Ordinat(P1));
    printf("P2: %d %d\n", Absis(P2), Ordinat(P2));
    printf("P3: %d %d\n", Absis(P3), Ordinat(P3));

    
    CreateList3Elemen(&L, P1, P2, P3);

    
    printf("Isi list: \n");
    printList(L);
    printf("%i\n", NbElmt(L));

    printf("info head: %d %d\n", Absis(Info(Head(L))), Ordinat(Info(Head(L))));
    

    //SnakeOnMeteor();
    return 0;
}*/

// int main(){
//     SnakeOnMeteor();
//     return 0;
// }


/*int main()
{
    Point P1, P2;
    CreatePoint(&P1, 1, 1);
    CreatePoint(&P2, 1, 1);
    if (IsMeteor(P1, P2))
    {
        printf("mati\n");
    }
    else
    {
        printf("idup\n");
    }
    return 0;
}*/