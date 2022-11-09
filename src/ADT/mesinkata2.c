#include <stdio.h>
#include <stdlib.h>
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
    if (GetCC() == MARK || GetCC() == feof(pita)){
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
        //printf("%c", currentChar);
        i++;
    }
    
    currentWord.Length = i;

    if (i >= NMax){
        currentWord.Length = NMax;
    } 
    else {
        currentWord.Length = i;}
}

void PrintWord(Word K){
    for (int i = 0; i < K.Length; i ++) {
        printf("%c", K.TabWord[i]);
    }
    printf("\n");
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
        //printf("%c", currentChar);
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
    if (i >= NMax) 
    {currentCMD.Length = NMax;}
    else 
    {currentCMD.Length = i;}
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
/***** ADT UNTUK MANIPULASI INPUT COMMAND *****/
Word kataPertama(Word w)
{
    Word first;
    int i = 0;
    while ((i<w.Length) && (w.TabWord[i] != ' '))
    {
        first.TabWord[i] = w.TabWord[i];
        i++;
    }
    first.Length = i; 
    return first;
}

Word kataKedua(Word w)
{
    Word second;
    int i=0;
    while ((i<w.Length) && (w.TabWord[i] != ' '))
    {
        i++;
    }
    //posisi i berada di spasi
    
    int j = i+1; //j mulai dari kata kedua
    int tab = 0;
    while (j<w.Length)
    {
        second.TabWord[tab] = w.TabWord[j];
        j++;
        tab++;
    }
    

    second.Length = w.Length-i+1;
    return second;
}

/***** ADT UNTUK KONVERSI TYPE DATA *****/
char *akusisi(Word kata)
{
    CopyWord();
    char *akusisiKata = NULL;

    akusisiKata = malloc(kata.Length * sizeof(char));
    int i = 0;
    while (i < kata.Length)
    {
        *(akusisiKata + i) = kata.TabWord[i];
        i++;
    }
    return akusisiKata;
}

int charToInt(char c)
{
    return c - '0';
}

char intToChar(int c){
    return (c + '0');//Cuman bisa convert dari angka 0-9 
}

int WordToInt(Word kata)
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

void wordToString(Word currentWord, char *string)
{
    int i = 0;
    while (i < currentWord.Length)
    {
        string[i] = currentWord.TabWord[i];
        i++;
    }
    string[i] = '\0';
}

Word stringToWord(char* command) 
/* Mengirimkan kata yang elemen of arraynya berasal dari command */
{
    int i;
    Word output;
    for (i = 0; i < string_length(command); i++) {
        output.TabWord[i] = command[i];
    }
    output.Length = string_length(command);
    return output;
}

int string_length(char *str)
{
    char *ptrstr;
    int result;

    ptrstr = str;
    for (result = 0; *ptrstr; ++result)
        ++ptrstr;
    return result;
}
void stringConcat(char str1[] , char str2[] , char *output)
{
  int i=0,j=0;
  while(str1[i]!='\0'){
    output[i] = str1[i];
    i++;
  }

  while(str2[j]!='\0')
  {
    output[i]=str2[j];
    j++;
    i++;
  }
  output[i]='\0';
  //printf("\nConcatenated String is %s",output);
}
/**** ADT UNTUK MEMBANGKAN KATA****/
boolean wordAndCharSama(Word kata, char command[]) {
    /* Mengirimkan true apabila kedua kata sama */
    boolean sama = true;
    for (int i = 0; i < kata.Length; i++) {
        if (kata.TabWord[i] != command[i]) {
            sama = false;
        }
    }
    return sama;
}

boolean wordAndWordSama(Word InputCommand, Word Command) 
/* Mengirimkan true jika K1 = K2 : Length dan elemen tiap arraynya sama */
{
    boolean sama = true;
    if (InputCommand.Length != Command.Length) {
        return !sama;
    } else {
        int i = 0;
        while (sama && (i < Command.Length)) {
            if (InputCommand.TabWord[i] != Command.TabWord[i]) {
                sama = false;
            }
            i++;
        }
        return sama;
    }
}

/*
int main(){
    //char path[NMax];
    //int masukan;
    //STARTCOMMAND();
    //masukan = kataToInt(currentCMD);
    //if(masukan == 55){
        //printf("Berhasil");
    //}
    //else{
        //printf("Gagal");
    //}
    //stringConcat("./data/" , "savefile.txt" , path);
    //printf("%s", path);
    //return 0;
    int a = 0 ;
    char b = intToChar(a);
    printf("%c",b);
}
*/
