#ifndef __MESINKATA_H__DD__
#define __MESINKATA_H__DD__

#include "boolean.h"
#include "mesinkar.h"

#define NMax 100
#define BLANK ' '

typedef struct {
	char TabWord[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentCmd;

/* Pembacaan Pita */
void CopyWord();

void STARTCOMMAND();

/* Operasi pada Word */
int WordToInt(Word w);

Word getCommand(Word w);

Word getLabel(Word w);

int stringLength(char *str);

boolean wordStringEq(Word w1, char *w2);
//Cek apakah Kata sama dengan input yang dimasukkan

boolean wordWordEq(Word w1, Word w2);

Word IntToWord(int n);
//ubah INT menjadi WORD

void joinWord(Word *w1, Word w2);

//Menggabungkan dua kata dan menyimpannya dalam W1

void salinWord(Word *w1, Word w2);

void printWord(Word W);

#endif