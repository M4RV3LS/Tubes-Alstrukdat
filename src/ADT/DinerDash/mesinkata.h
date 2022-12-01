#ifndef __MESINKATA_H__DD__
#define __MESINKATA_H__DD__

#include "../../boolean.h"
#include "mesinkar.h"

#define NMax 100
#define BLANK ' '

typedef struct {
	char TabKata[NMax+1]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CURRENTCOMMAND;

/* Pembacaan Pita */
void COPYCOMMANDGAMEDD();

void STARTCMD();

char *KATATOSTRING(Kata kata);

/* Operasi pada Kata */
int KataToInt(Kata w);

Kata getCommand(Kata w);

Kata getLabel(Kata w);

int stringLength(char *str);

boolean wordStringEq(Kata w1, char *w2);
//Cek apakah Kata sama dengan input yang dimasukkan

boolean wordKataEq(Kata w1, Kata w2);

Kata IntToKata(int n);
//ubah INT menjadi WORD

void joinKata(Kata *w1, Kata w2);

//Menggabungkan dua kata dan menyimpannya dalam W1

void salinKata(Kata *w1, Kata w2);

void printKata(Kata W);

#endif