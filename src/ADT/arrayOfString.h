#ifndef _ARRAY_OF_STRING_
#define _ARRAY_OF_STRING

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../boolean.h"

typedef int IdxType;
typedef char* ElType;
typedef struct {
    ElType *A;
    int Capacity;
    int Neff;
} ArrayDin;

ArrayDin CreateDynArray();

void DeallocateList(ArrayDin *array);

int Length(ArrayDin list);

void InsertIn(char*string , ArrayDin*ListGames ,  int idx);

void InsertAt(ArrayDin *array, ElType el, IdxType i);
  
void InsertLast(ArrayDin *array, ElType el);
  
void InsertFirst(ArrayDin *array, ElType el);

boolean IsEmpty (ArrayDin T);
#endif