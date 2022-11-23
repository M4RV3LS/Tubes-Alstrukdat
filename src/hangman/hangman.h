#ifndef _HANGMAN_
#define _HANGMAN_

#include "boolean.h"
#include "mesinkata2.h"
#include "mesinkar2.h"
#include "arrayhangman.h"

#include <stdio.h>
#include <stdlib.h>

void hangman();

void mainHangman(int*kesempatan, char*Kata);

void loadkata(ListKata *ListKata, char*filename);

void saveListKata(ListKata ListKata, char*filename);

boolean isTebakanValid(Word word);

boolean isHurufAda(char huruf, char* kata);

void underscoreToHuruf(char huruf, char* GuessedKata, char*kata);

void PrintCharWithSpace(char*kata, int len);

void PrintCharNoSpace(char*kata, int len);

int panjang_kata(char*s);

void InsertKataLast(char huruf, char*kata);

char* wordToStr(Word word);

#endif