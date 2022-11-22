/* File : stack.h */
/* deklarasi stack yang diimplementasi dengan tabel kontigu dan ukuran sama */
/* TOP adalah alamat elemen puncak */
/* Implementasi dalam bahasa C dengan alokasi statik */

#include "stack.h"
#include <stdio.h>
#include <stdio.h>
/*
#define Nil -1
#define MaxEl 100
 Nil adalah stack dengan elemen kosong . */

  /*
typedef int infotype;
typedef int address;  indeks tabel */

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
/*typedef struct { 
  infotype T[MaxEl];  tabel penyimpan elemen */
  /*address TOP;   alamat TOP: elemen puncak 
} Stack;*/
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[0]..T[MaxEl-1] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get 
#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
*/
/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptyStack(Stack *S){
    Top(*S) = NILSTACK;
}
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S){
    return (Top(S) == NILSTACK);
}
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullStack(Stack S){
    return (Top(S) == (MaxEl -1));
}
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void PushStack(Stack * S, INFOTYPE X){
    if(IsEmptyStack(*S)){
        Top(*S) = 0;
        InfoTop(*S) = X;
    }
    else
        Top(*S) ++;
        InfoTop(*S) = X;
}
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void PopStack(Stack * S, INFOTYPE* X){
    *X = InfoTop(*S);
    Top(*S) --;
}
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
void DisplayStack(Stack S , int index){
    if(IsEmptyStack(S)){
        printf("Stack Kosong\n");
    }
    else {
        int i;
        int nomor = 0;
        for(i=index;i>=0;i--){
        nomor = nomor + 1;
        printf("%d. %s\n", nomor , S.T[i] );
    }
    }
    
}

Stack ReverseStack(Stack in){
    Stack out;
    CreateEmptyStack(&out);
    INFOTYPE element;
    while(!IsEmptyStack(in)){
        PopStack(&in, &element);
        PushStack(&out, element);
    }
    return out;
}
    

// int main(){
//     Stack S;
//     char *TOP;
//     CreateEmptyStack(&S);
//     Push(&S,"Marvel");
//     Push(&S,"Tim");
//     Push(&S,"Jodi");
//     Push(&S,"lim");
//     DisplayStack(S , Top(S));
//     printf("\n");
//     Stack out;
//     out = ReverseStack(S);
//     printf("Hasil Reverse ; \n");
//     DisplayStack(out , Top(out));
//     printf("\n");
//     // Pop(&S,&TOP);
//     // printf("TOP Yang di Pop adalah : %s\n" , TOP);
//     // DisplayStack(S , Top(S));
//     // printf("\n");
//     // Pop(&S,&TOP);
//     // Pop(&S,&TOP);
//     // Pop(&S,&TOP);
//     // DisplayStack(S , Top(S));
//     return 0;
// }