#include "map.h"

/* MODUL Map
Deklarasi stack yang dengan implementasi array eksplisit-statik rata kiri
*/

// #define false 0
// #define true 1
/*
#define Nil 0
#define MaxEl 10
#define Undefined -999

// typedef int bool;
typedef int keytype;
typedef int valuetype;
typedef int address;

typedef struct {
	keytype Nama;
	valuetype Skor;
} infotype;

typedef struct {
	infotype Elements[MaxEl];
	address Count;
} Map;
*/
/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

/* ********* Prototype ********* */

/* *** Konstruktor/Kreator *** */
void CreateEmpty(Map *M){
	(*M).Count = Nil;
}
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxEl */
/* Ciri Map kosong : count bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
boolean IsEmptyMap(Map M){
	return (M.Count == Nil);
}
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsFull(Map M){
	return (M.Count == MaxEl);
}
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxEl */

/* ********** Operator Dasar Map ********* */
valuetype Skor(Map M, keytype k){
	valuetype Skor;
	if(IsMember(M , k)){
		boolean found = false;
		int i = 0;
		while(!found && (i < M.Count)){
			if(M.Elements[i].Nama == k){
				Skor = M.Elements[i].Skor;
				found = true;
			}
			else {
				i++;
			}
		}
		
	}
	
	else {
		Skor = Undefined;
	}
	return Skor;
}
/* Mengembalikan nilai Skor dengan Nama k dari M */
/* Jika tidak ada Nama k pada M, akan mengembalikan Undefined */

void Insert(Map *M, keytype k, valuetype v){
	if(IsEmptyMap(*M)){
		(*M).Elements[(*M).Count].Nama = k;
		(*M).Elements[(*M).Count].Skor = v;
		(*M).Count++;
	}
	else{
		if(!IsMember(*M , k)){
			(*M).Elements[(*M).Count].Nama = k;
			(*M).Elements[(*M).Count].Skor = v;
			(*M).Count++;
		}
	}
}
/* Menambahkan Elmt sebagai elemen Map M. */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan Nama k */
/* F.S. v menjadi anggota dari M dengan Nama k. Jika k sudah ada, operasi tidak dilakukan */

void Delete(Map *M, keytype k){
	if(IsMember(*M , k)){
        boolean found = false;
        int idx = 0;
        while (!found && (idx < ((*M).Count))){
            if((*M).Elements[idx].Nama == k){
                found = true;
            }
            else {
                idx++;
            }
        
        for(int i = idx ; i < ((*M).Count - 1);i++){
            (*M).Elements[i] = (*M).Elements[i+1];
			
        }
        
        (*M).Count--;
        }
    }
}

/* Menghapus Elmt dari Map M. */
/* I.S. M tidak kosong
        element dengan Nama k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan Nama k bukan anggota dari M */

boolean IsMember(Map M, keytype k){
	boolean found = false;
	int i = 0;
	while(!found && (i < M.Count)){
		if(M.Elements[i].Nama == k){
			found = true;
		}
		else {
			i++;
		}
	}
	return found;
}

/* Mengembalikan true jika k adalah member dari M */
void PrintMap(Map M){
	for(int i = 0; i < M.Count - 1; i++){
		printf("[%s | %d] ,", M.Elements[i].Nama, M.Elements[i].Skor);
	}
	int i = M.Count - 1;
	printf("[%s | %d]", M.Elements[i].Nama, M.Elements[i].Skor);
}

// void PrintMapToFile(Map M, FILE *f){
	
// }

void SortMap(Map *M){
	printf("test1\n");
	int i, j;
	infotype temp;
	for(i = 0; i < (*M).Count - 1; i++){
		for(j = i + 1; j < (*M).Count; j++){
			if((*M).Elements[i].Skor > (*M).Elements[j].Skor){
				temp = M->Elements[i];
				M->Elements[i] = M->Elements[j];
				M->Elements[j] = temp;
			}
		}
	}
}

// int main()
// {
//     Map M;
//     CreateEmpty(&M);
// 	printf("oi\n");
//     Insert(&M, "Akk", 2);
//     Insert(&M, "Bkk", 1);
//     Insert(&M, "Ckk", 4);
//     Insert(&M, "Dkk", 3);
//     Insert(&M, "Ekk", 8);
//     Insert(&M, "Fkk", 7);
//     Insert(&M, "Gkk", 6);
//     Insert(&M, "Hkk", 5);
//     Insert(&M, "Ikk", 5);
// 	SortMap(&M);
// 	printf("\n");
// 	printf("%d\n",M.Elements[0].Skor);
//     printf("Isi Map M:\n");
//     PrintMap(M);
//     return 0;
// }