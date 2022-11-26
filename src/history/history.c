#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"

boolean yes(){
    //printf("Test\n");
    boolean value = false;
    boolean valid = false;
    while(!valid){
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK)\n");
        STARTCOMMANDGAME();
        char*temp = (char*) malloc (currentCMD.Length* sizeof(char));
        wordToString(currentCMD , temp);

        //printf("Test2\n");
        //printf("%s\n" , temp);
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
    //printf("woi\n");
   return value; 
}

// void History(ArrayDin Game , int n){
//     if(IsEmpty(Game)){
//         printf("Belum ada game yang dimainkan\n");
//     }
//     else {
//         if(n <= Game.Neff && n > 0){
//             printf("Berikut adalah daftar Game yang telah dimainkan \n");
//             for (int i = 0; i < n; i++)
//             {
//                 printf("%d. %s\n", i+1, Game.A[i]);
//             }
//         }
//         else if (n > Game.Neff) {
//             printf("Berikut adalah daftar Game yang telah dimainkan \n");
//             for (int i = 0; i < Game.Neff; i++)
//             {
//                 printf("%d. %s\n", i+1, Game.A[i]);
//             }
//         }
//         else if(n <= 0){
//             printf("Masukan tidak valid , harap masukan angka dengan besar minimal 1\n");
//         }
//         else {
//             printf("Masukan tidak valid , harap masukan angka dengan besar minimal 1\n");
//         }
//     }
// }
void History(Stack Game , int n){
    if(IsEmptyStack(Game)){
        printf("Belum ada game yang dimainkan\n");
    }
    else {
        if(n <= Top(Game) + 1 && n > 0){
            // printf("Top Game = %d\n",Top(Game));
            // printf("Masuk ke kasus1 : \n");
            printf("Berikut adalah daftar Game yang telah dimainkan \n");
            int nomor = 0;
            // char *TOP;
            for(int i=n-1;i>=0;i--){
                nomor = nomor + 1;
                printf("%d. %s\n", nomor , Game.T[i] );
                }
            // while(n && !IsEmptyStack(Game)){
            //     Pop(&Game , &TOP);
            //     nomor = nomor + 1;
            //     printf("%d. %s\n", nomor , TOP);
            //     n--;
            // }
        }
        else if (n > Top(Game) + 1) {
            // printf("Masuk ke kasus2 : \n");
            printf("Berikut adalah daftar Game yang telah dimainkan \n");
            int nomor = 0;
            for(int i=Top(Game);i>=0;i--){
                nomor = nomor + 1;
                printf("%d. %s\n", nomor , Game.T[i] );
                }
        }
        else if(n <= 0){
            printf("Masukan tidak valid , harap masukan angka dengan besar minimal 1\n");
        }
        else {
            printf("Masukan tidak valid , harap masukan angka dengan besar minimal 1\n");
        }
    }
}
// void ResetHistory (ArrayDin * Game){
    
//     if(yes()){
//         DeallocateList(Game);
//         //Buat Test Case
//         // int n = (*Game).Neff;
//         // for (int i = 0; i < n; i++)
//         // {
//         //     printf("%d. %s\n", i+1, (*Game).A[i]);
//         // }
//         if(IsEmpty(*Game)){
//             printf("History berhasil direset\n");
//         }
//         else {
//             printf("History gagal direset\n");
//         }
//         // printf("History berhasil di-reset.\n");
//     }
//     else{
//         printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
//         int n = (*Game).Neff;
//         for (int i = 0; i < n; i++)
//         {
//             printf("%d. %s\n", i+1, (*Game).A[i]);
//         }
//     }
// }
void ResetHistory (Stack * Game){
    
    if(yes()){
        CreateEmptyStack(Game);
        //Buat Test Case
        // int n = (*Game).Neff;
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%d. %s\n", i+1, (*Game).A[i]);
        // }
        if(IsEmptyStack(*Game)){
            printf("History berhasil direset\n");
        }
        else {
            printf("History gagal direset\n");
        }
        // printf("History berhasil di-reset.\n");
    }
    else{
        printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        int n = Top(*Game);
        int nomor = 0;
            for(int i=n;i>=0;i--){
                nomor = nomor + 1;
                printf("%d. %s\n", nomor , (*Game).T[i] );
                }
        // int nomor = 0;
        // char *TOP;
        // while(n && !IsEmptyStack(*Game)){
        //     Pop(Game , &TOP);
        //     nomor = nomor + 1;
        //     printf("%d. %s\n", nomor , TOP);
        //     n--;
        // }
    }
}

// int main(){
//     ArrayDin Game = CreateDynArray();
//     InsertFirst(&Game, "RNG");
//     InsertFirst(&Game, "Diner DASH");
//     InsertFirst(&Game, "HANGMAN");
//     InsertFirst(&Game, "TOWER OF HANOI");
//     InsertFirst(&Game, "SNAKE ON METEOR");
//     InsertFirst(&Game, "MATH QUIZ");
//     History(Game, 6);
//     ResetHistory(&Game);
//     return 0;
// }

// int main(){
//     Stack Game;
//     CreateEmptyStack(&Game);
//     PushStack(&Game, "RNG");
//     PushStack(&Game, "Diner DASH");
//     PushStack(&Game, "HANGMAN");
//     PushStack(&Game, "TOWER OF HANOI");
//     PushStack(&Game, "SNAKE ON METEOR");
//     PushStack(&Game, "MATH QUIZ");
//     //DisplayStack(Game , Top(Game));
//     History(Game , Top(Game));
//     ResetHistory(&Game);
//     //yes();
//     return 0;
// }