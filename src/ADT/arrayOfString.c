#include <stdio.h>
#include<stdlib.h>
#include "arrayOfString.h"


ArrayDin CreateDynArray() {
 ArrayDin array;
 // Alokasi elemen array secara dinamik menggunakan malloc
 array.A = (ElType*) malloc (50 * sizeof(ElType));
 array.Capacity = 50; // Kapasitas array diset sebesar StartSize
 array.Neff = 0; // Karena masih kosong, elemen efektif array bernilai 0
 return array;
}

void DeallocateList(ArrayDin *array) {
    free(array->A);
}

int Length(ArrayDin array) {
    return array.Neff;
}

void InsertIn(char*string , ArrayDin*ListGames ,  int idx){
    int j = idx - 1;
    (*ListGames).A[j] = string;
    //int i = 0;
    /*while ((*ListGames).A[j][i] != '\0'){
        (*ListGames).A[j][i] = string[i];
        i++;
    }*/
}

void InsertAt(ArrayDin *array, ElType el, IdxType i) 
 { 
    if((*array).Neff == (*array).Capacity) 
    { 
        (*array).Capacity *= 2; //Kalau penuh perbesar kapasitasnya
        (*array).A = (ElType *) realloc ((*array).A, (*array).Capacity * sizeof(ElType)); //Perbarui besar kapasitasnya
    } 
    IdxType temp = array->Neff; 
    while (temp > i) 
    { 
    (*array).A[temp]=(*array).A[temp-1]; //GESER geser 
    temp--; 
    } 
    (*array).A[i]=el; 
    (*array).Neff++; 
 } 
  
 void InsertLast(ArrayDin *array, ElType el) 
 { 
    (*array).A[(*array).Neff] = el; 
    (*array).Neff++; 
 } 
  
 void InsertFirst(ArrayDin *array, ElType el) 
 { 
    InsertAt(array, el, 0); 
 }

boolean IsEmpty (ArrayDin array)
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
{
    return (array.Neff == 0);
}
/*
int main()
{
    ArrayDin arr;
    arr = CreateDynArray();
    char temp[8] = "Timothy";
    arr.A[0] = temp;
    int i = 0;
    int j = 0;
    while (arr.A[0][i] != '\0')
    {
        printf("%c",arr.A[0][i]);
        i++;
    }
}
*/