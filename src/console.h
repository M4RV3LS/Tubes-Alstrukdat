#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
#include "creategame.h"
#include "deletegame.h"
// #include "dinerdash.h"
#include "help.h"
#include "listgame.h"
#include "LOAD.h"
#include "playgame.h"
#include "queuegame.h"
#include "quit.h"
// #include "save.h"
#include "RNG.h"
#include "skipgame.h"
#include "start.h"
*/ 

#include "ADT/mesinkar2.h"
#include "ADT/mesinkata2.h"
#include "ADT/arrayOfString.h"
#include "boolean.h"
#include "ADT/queue.h"


void CREATEGAME(ArrayDin *ListGames);

void DELETE(ArrayDin *ListGames);

void HELP();

void LISTGAME(ArrayDin *ListGames);

void LOADFILE(ArrayDin *ListGames , char* filename);

void PLAYGAME(Queue *q1);

void QUEUEGAME(Queue *q1, ArrayDin *game);

void QUIT(); 

void gameRNG(); 

void SAVEBNMO(ArrayDin* GamesList, char* filename);

void SKIPGAME(Queue *q, int n);

void STARTGAME(ArrayDin *ListGames);

