#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../boolean.h"
#include "../ADT/arrayOfString.h"
#include "../ADT/boolean.h"
#include "../ADT/mesinkata2.h"

boolean yes(){
    boolean value = false;
    boolean valid = false;
    while(!valid){
        printf("\nAPAKAH KAMU YAKIN INGIN MELAKUKAN RESET HISTORY? (YA/TIDAK)\n");
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

void History(ArrayDin Game , int n){
    if(IsEmpty(Game)){
        printf("Belum ada game yang dimainkan\n");
    }
    else {
        if(n <= Game.Neff && n > 0){
            printf("Berikut adalah daftar Game yang telah dimainkan \n");
            for (int i = 0; i < n; i++)
            {
                printf("%d. %s\n", i+1, Game.A[i]);
            }
        }
        else if (n > Game.Neff) {
            printf("Berikut adalah daftar Game yang telah dimainkan \n");
            for (int i = 0; i < Game.Neff; i++)
            {
                printf("%d. %s\n", i+1, Game.A[i]);
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

void ResetHistory (ArrayDin * Game){
    
    if(yes()){
        DeallocateList(Game);
        //Buat Test Case
        // int n = (*Game).Neff;
        // for (int i = 0; i < n; i++)
        // {
        //     printf("%d. %s\n", i+1, (*Game).A[i]);
        // }
        if(IsEmpty(*Game)){
            printf("History berhasil direset\n");
        }
        else {
            printf("History gagal direset\n");
        }
        // printf("History berhasil di-reset.\n");
    }
    else{
        printf("History tidak jadi di-reset. Berikut adalah daftar Game yang telah dimainkan\n");
        int n = (*Game).Neff;
        for (int i = 0; i < n; i++)
        {
            printf("%d. %s\n", i+1, (*Game).A[i]);
        }
    }
}

int main(){
    ArrayDin Game = CreateDynArray();
    InsertFirst(&Game, "RNG");
    InsertFirst(&Game, "Diner DASH");
    InsertFirst(&Game, "HANGMAN");
    InsertFirst(&Game, "TOWER OF HANOI");
    InsertFirst(&Game, "SNAKE ON METEOR");
    InsertFirst(&Game, "MATH QUIZ");
    History(Game, 6);
    ResetHistory(&Game);
    return 0;
}