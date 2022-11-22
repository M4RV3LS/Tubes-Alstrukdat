/*
NIM             : 18221068
Nama            : Oncar Awwalu Rozaqy
Tanggal         : 31 Oktober 2022
Topik praktikum : Set dan Map
Deskripsi       : implementasi duplicate.h
*/

#include <stdio.h>
#include "duplicate.h"

/*
    Masukkan semua elemen array arr ke suatu Set, kemudian kembalikan Set tersebut
        Contoh:
            arrToSet
                <- arr = [1, 1, 3]
                <- arrSize = 3
            -> [1, 3]
*/
Set arrToSet(int* arr, int arrSize){
	Set S;
	CreateEmpty(&S);
	for (int i=0; i<arrSize ; i++){
		Insert(&S, arr[i]);
	}
	return S;
}

/*
    Dengan memanfaatkan fungsi arrToSet, hapuslah elemen duplikat pada array arr
    kemudian kembalikan isinya secara menurun

    Penjelasan Parameter:
    Parameter 1: arr, merupakan array masukan yang perlu dihapus elemen duplikatnya
    Parameter 2: arrSize, merupakan panjang arr
    Parameter 3: arrRes, merupakan array keluaran, hasil pengapusan elemen duplikat
        dan elemen-elemennya terurut menurun
    Parameter 4: arrResSize, merupakan panjang arrRes

    Contoh: 
        removeDuplicate
            <- arr = [1, 1, 2, 3]
            <- arrSize = 4
            -> arrRes = [3, 2, 1]
            -> arrResSize = 3
        removeDuplicate
            <- arr = [3, 1, 1]
            <- arrSize = 3
            -> arrRes = [3, 1]
            -> arrResSize = 2
*/
void removeDuplicateDesc(int* arr, int arrSize, int* arrRes, int* arrResSize){
	Set S1;
	S1 = arrToSet(arr, arrSize);
	for (int i=0; i<S1.Count-1 ; i++){
		for (int j=i+1; j<S1.Count ; j++){	
			if (S1.Elements[i]<S1.Elements[j]){
				infotype temp;
				temp=S1.Elements[i];
				S1.Elements[i]=S1.Elements[j];
				S1.Elements[j]=temp;
			}
		}
	}
	*arrResSize=S1.Count;
	for (int k=0; k<S1.Count; k++){
		arrRes[k]=S1.Elements[k];
	}	
}
