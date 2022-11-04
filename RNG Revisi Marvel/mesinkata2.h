#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
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

int charToInt(char c);

int kataToInt(Word kata);

#endif