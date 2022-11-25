#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "../boolean.h"
#include "mesinkar2.h"

#define NMax 100
#define BLANK ' '

typedef struct {
	char TabWord[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;
extern Word currentCMD;


/* *** Membaca dari file *** */
void IgnoreBlanks();

void IgnoreEnter();

void STARTWORD(char *filename);

void ADVWORD();

void CopyWord();

void PrintWord(Word K);

void ADVLine();

void CopyLine();

/* *** Membaca command dari terminal *** */
void IgnoreBlanksCMD();

void STARTCOMMAND();

void STARTCOMMANDGAME();

void ADVCOMMAND();

void CopyCommand();

void CopyCommandGame();

/***** ADT UNTUK MANIPULASI INPUT COMMAND *****/
Word kataPertama(Word w);

Word kataKedua(Word w);

/***** ADT UNTUK KONVERSI TYPE DATA *****/
char *WORDTOSTRING(Word kata);

int charToInt(char c);

char intToChar(int c);

int WordToInt(Word kata);

void wordToString(Word currentWord, char *string);

Word stringToWord(char* command);

int string_length(char *str);

void stringConcat(char str1[] , char str2[] , char *output);

Word splitwordDD(Word kata);
	
/**** ADT UNTUK MEMBANDINGKAN KATA****/
boolean wordAndCharSama(Word kata, char command[]);

boolean wordAndWordSama(Word InputCommand, Word Command);

boolean CompareString(char *string1 , char *string2);

boolean IsUsernameEqual(char*string1 , char*string2);

boolean isInteger(Word Kata);

char *copystr(char *str);

int LengthKalimat(char *kalimat);

void delay(int number_of_seconds);

int randint(int lower , int upper);

char* getCurrentWord(Word string);
#endif
