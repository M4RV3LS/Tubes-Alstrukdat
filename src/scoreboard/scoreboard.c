#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../ADT/SetMap/map.h"
#include "../ADT/arrayOfString.h"
#include "../ADT/boolean.h"
#include "../ADT/mesinkata2.h"

// void LISTGAME(ArrayDin *ListGames)
// {
//     printf("Berikut adalah daftar game yang tersedia\n");
//     for (int i = 0; i < (*ListGames).Neff; i++)
//     {
//         printf("%i. %s\n", i+1, (*ListGames).A[i]);
//     }
// }

boolean ya(){
    boolean value = false;
    boolean valid = false;
    while(!valid){
        STARTCOMMANDGAME();
        char*temp;
        wordToString(currentCMD , temp);
        if (CompareString(temp, "YA")){
            value = true;
            valid = true;}
        else if (CompareString(temp, "TIDAK")){
            value = false;
            valid = true;}
        else{
            printf("Masukan tidak valid, silahkan masukan kembali\n");
        }
    }
   return value; 
}

void ResetScoreboard(ArrayDin *ListGames , Map *RNG , Map *DinerDASH , Map *HANGMAN , Map *TOWEROFHANOI , Map *SNAKEOFMETEOR , Map *MATHQUIZ){
    printf("DAFTAR SCOREBOARD:\n");
    printf("0.ALL\n");
    printf("1.RNG\n");
    printf("2.Diner DASH\n");
    printf("3.HANGMAN\n");
    printf("4.TOWER OF HANOI\n");
    printf("5.SNAKE ON METEOR\n");
    boolean found = false;
    int i = 0;
    while(i < (*ListGames).Neff && !found)
    {
        if (strcmp((*ListGames).A[i], "MATH QUIZ") == 0)
        {
            found = true;
            //printf("Ketemu\n");
        }
        else{
            i++;
        }
    }
    if (found)
    {
        printf("6.MATH QUIZ\n");
    }
    
    boolean valid = false;
    while(!valid){
        printf("SCOREBOARD YANG INGIN DIHAPUS: ");
        STARTCOMMAND();
        int input = WordToInt(currentCMD);
        ADVCOMMAND();
        if(!EndWord){
            printf("Masukan tidak valid, silahkan masukan kembali\n");
        }
        else{
            if (input == 0){
            valid = true;
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD ALL (YA/TIDAK)?\n");
            if (ya()){
                CreateEmpty(RNG);
                CreateEmpty(DinerDASH);
                CreateEmpty(HANGMAN);
                CreateEmpty(TOWEROFHANOI);
                CreateEmpty(SNAKEOFMETEOR);
                printf("Scoreboard berhasil di-reset.\n");
                if (found)
                {
                    CreateEmpty(MATHQUIZ);
                }
            }
        }
        else if (input == 1){
            valid = true;
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD RNG (YA/TIDAK)?\n");
            if(ya()){
                CreateEmpty(RNG);
                printf("Scoreboard berhasil di-reset.\n");
            }
            else{
                printf("Scoreboard gagal di-reset.\n");
            }
        }
        else if (input == 2){
            valid = true;
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET Diner DASH ALL (YA/TIDAK)?\n");
            if(ya()){
                CreateEmpty(DinerDASH);
                printf("Scoreboard berhasil di-reset.\n");
            }
            else{
                printf("Scoreboard gagal di-reset.\n");
            }
        }
        else if (input == 3){
            valid = true;
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD HANGMAN (YA/TIDAK)?\n");
            if(ya()){
                CreateEmpty(HANGMAN);
                printf("Scoreboard berhasil di-reset.\n");
            }
            else{
                printf("Scoreboard gagal di-reset.\n");
            }
        }
        else if (input == 4){
            valid = true;
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD TOWER OF HANOI (YA/TIDAK)?\n");
            if(ya()){
                CreateEmpty(TOWEROFHANOI);
                printf("Scoreboard berhasil di-reset.\n");
            }
            else{
                printf("Scoreboard gagal di-reset.\n");
            }
        }
        else if (input == 5){
            valid = true;
            printf("APAKAH KAMU YAKIN INGIN MELAKUKAN RESET SCOREBOARD SNAKE OF METEOR (YA/TIDAK)?\n");
            if(ya()){
                CreateEmpty(SNAKEOFMETEOR);
                printf("Scoreboard berhasil di-reset.\n");
            }
            else{
                printf("Scoreboard gagal di-reset.\n");
            }
        }
        else if (input == 6){
            valid = true;
            if (found)
            {
                if(ya()){
                    CreateEmpty(MATHQUIZ);
                    printf("Scoreboard berhasil di-reset.\n");
                }
                else{
                    printf("Scoreboard gagal di-reset.\n");
                }
            }
            else{
                printf("Game tidak tersedia\n");
            }
        }
        else{
            printf("Masukan tidak valid, silahkan masukan kembali\n");
        }
        
    }
}
}


// int main(){
//     printf("Test");
//     ArrayDin ListGames;
//     CreateDynArray(&ListGames);
//     InsertLast(&ListGames , "RNG");
//     InsertLast(&ListGames , "Diner DASH");
//     InsertLast(&ListGames , "HANGMAN");
//     InsertLast(&ListGames , "TOWER OF HANOI");
//     InsertLast(&ListGames , "SNAKE ON METEOR");
//     InsertLast(&ListGames , "MATH QUIZ");
//     for (int i = 0; i < ListGames.Neff; i++)
//     {
//         printf("%s\n", ListGames.A[i]);
//     }
//     printf("Test");
//     Map RNG;
//     Map DinerDASH;
//     Map HANGMAN;
//     Map TOWEROFHANOI;
//     Map SNAKEOFMETEOR;
//     Map MATHQUIZ;
//     CreateEmpty(&RNG);
//     CreateEmpty(&DinerDASH);
//     CreateEmpty(&HANGMAN);
//     CreateEmpty(&TOWEROFHANOI);
//     CreateEmpty(&SNAKEOFMETEOR);
//     CreateEmpty(&MATHQUIZ);
//     Insert(&RNG , "MARVEL" , 250);
//     Insert(&RNG , "LIM" , 300);
//     Insert(&RNG , "TIM" , 200);
//     SortMap(&RNG);
//     for(int i = 0; i < RNG.Count - 1; i++){
// 		printf("[%s | %d] ,", RNG.Elements[i].Nama, RNG.Elements[i].Skor);
// 	}
// 	int i = RNG.Count - 1;
// 	printf("[%s | %d]\n", RNG.Elements[i].Nama, RNG.Elements[i].Skor);
//     //PrintMap(RNG);
//     ResetScoreboard(&ListGames , &RNG , &DinerDASH , &HANGMAN , &TOWEROFHANOI , &SNAKEOFMETEOR , &MATHQUIZ);
//     if (RNG.Count == 0)
//     {
//         printf("RNG Kosong\n");
//     }
//     else{
//         printf("RNG Tidak Kosong\n");
//     }
//     //PrintMap(RNG);
//     return 0;
// }