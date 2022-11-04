#include <stdio.h>
#include "mesinkata2.h"

Word currentWord;
boolean EndWord;
Word currentCMD;

/* *** Membaca dari file *** */
void IgnoreBlanks(){
    while (GetCC() == BLANK || GetCC() == ENTER){
        ADV();
    }
}

void IgnoreEnter(){
    while (GetCC() == ENTER){
        ADV();
    }
}

void STARTWORD(char *filename){
    START(filename);
    IgnoreBlanks();
    if (GetCC() == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyWord();
    }
}

void ADVWORD(){
    IgnoreBlanks();
    if (GetCC() == MARK){
        EndWord = true;
    } else {
        CopyWord();
    }
    IgnoreBlanks();
}

void CopyWord(){
    int i = 0;
    currentChar = GetCC();
    while (currentChar != MARK && currentChar != BLANK && currentChar != ENTER){
        currentWord.TabWord[i] = currentChar;
        ADV();
        currentChar = GetCC();
        printf("%c", currentChar);
        i++;
    }
    
    currentWord.Length = i;

    if (i >= NMax) currentWord.Length = NMax;
    else currentWord.Length = i;
}

void PrintWord(Word K){
    for (int i = 0; i < K.Length; i ++) {
        printf("%c", K.TabWord[i]);
    }
}

void ADVLine(){
    IgnoreEnter();
    if (GetCC() == ENTER){
        EndWord = true;
    } else {
        CopyLine();
    }
}

void CopyLine(){
    int i = 0;
    currentChar = GetCC();
    while (currentChar != MARK && currentChar != ENTER && !feof(pita)){
        currentWord.TabWord[i] = currentChar;
        ADV();
        currentChar = GetCC();
        printf("%c", currentChar);
        i++;
    }
    
    currentWord.Length = i;

    if (i >= NMax) currentWord.Length = NMax;
    else currentWord.Length = i;
}

/* *** Membaca command dari terminal *** */
void IgnoreBlanksCMD(){
    while (GetCC() == BLANK){
        ADVC();
    }
}

void STARTCOMMAND(){
    COMMAND();
    IgnoreBlanksCMD();
    if (currentChar == ENTER){
        EndWord = true;
    } else {
        EndWord = false;
        CopyCommand();
    }
}

void STARTCOMMANDGAME(){
    COMMAND();
    IgnoreBlanksCMD();
    if(currentChar == ENTER){
        EndWord = true;
    } else {
        EndWord = false;
        CopyCommandGame();
    }
}

void ADVCOMMAND(){
    IgnoreBlanksCMD();
    if (currentChar == ENTER && !EndWord){
        EndWord = true;
    } else{
        CopyCommand();
        IgnoreBlanksCMD();
    }
}

void CopyCommand(){
    int i = 0;
    while ((currentChar != BLANK) && (currentChar != ENTER) && i != NMax) {
        currentCMD.TabWord[i] = currentChar;
        ADVC();
        i++;
    }
    if (i >= NMax) currentCMD.Length = NMax;
    else currentCMD.Length = i;
}

void CopyCommandGame(){
    int i = 0;
    while ((currentChar != ENTER) && i != NMax) {
        currentCMD.TabWord[i] = currentChar;
        ADVC();
        i++;
    }
    if (i >= NMax) currentCMD.Length = NMax;
    else currentCMD.Length = i;
}

int charToInt(char c)
{
    return c - '0';
}

int kataToInt(Word kata)
{
    int i, hasil;
    i = 0;
    hasil = 0;
    while (i < kata.Length)
    {
        hasil = hasil * 10 + charToInt(kata.TabWord[i]);
        i++;
    }
    return hasil;
}
/*
int main(){
    int masukan;
    STARTCOMMAND();
    masukan = kataToInt(currentCMD);
    if(masukan == 55){
        printf("Berhasil");
    }
    else{
        printf("Gagal");
    }
    return 0;
}
*/