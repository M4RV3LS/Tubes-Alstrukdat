/* MODUL CIRCULAR QUEUE */
/* Definisi ADT Queue dengan representasi array secara eksplisit dan alokasi dinamik */
/* Implementasi Queue menggunakan circular buffer (Alternatif III) 


#include "boolean.h"
*/
/* Nilai untuk indeks yang tidak terdefinisi 
#define NIL -999
*/
/* Definisi tipe elemen dan indeks pada Queue 
typedef int ElType;
typedef int IdxType;
*/
/*
typedef struct { ElType * Tab;   tabel penyimpan elemen */
                /* IdxType HEAD;  indeks elemen paling awal (terdepan) */
                 /*  IdxType TAIL;  indeks tempat menambah elemen baru */
                 /*  int MaxEl;     kapasitas jumlah elemen */
              /*   } Queue; Definisi Queue kosong: HEAD=NIL; TAIL=NIL. */
#include <stdio.h>
#include <stdlib.h>
#include "circular_queue.h"
/* ********* Prototype ********* */
boolean IsEmpty (Queue Q){
    return (Q.HEAD == NIL && Q.TAIL == NIL);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (Queue Q){
    return (Length(Q) == MaxLength(Q));
}
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int Length (Queue Q){
    int count ;
    if (IsEmpty(Q)){
        count = 0;
    }
    else if (Q.TAIL > Q.HEAD){
        count = (Q.TAIL - Q.HEAD) + 1;
    }
    else if(Q.HEAD > Q.TAIL){
        count = (MaxLength(Q) - Q.HEAD) + (Q.TAIL + 1);
    }
    return count;
    }
/* Mengirimkan banyaknya elemen Q, 0 jika kosong */
int MaxLength (Queue Q){
    return Q.MaxEl;
}
/* Mengirimkan kapasitas jumlah elemen Q */

/* *** Kreator *** */
Queue CreateQueue (int Max){
    Queue Q;
    Q.Tab = (ElType *)malloc(sizeof(ElType)*Max);
    if(Q.Tab != NULL){
        Q.MaxEl = Max;
        Q.HEAD = NIL ;
        Q.TAIL = NIL ;
        //printf("Berhasil");
    }
    else {
        Q.MaxEl = 0;
        //printf("Ngga Berhasil");
    }
    return Q;
}
/* Proses : Melakukan alokasi memori, membuat sebuah Q kosong */
/* I.S. sembarang */
/* F.S. mengembalikan Q kosong dengan kondisi sbb: */
/*   Jika alokasi berhasil, Tab dialokasi berukuran Max */
/*   Jika alokasi gagal, Q kosong dengan MaxEl=0 */

/* *** Destruktor *** */
void DeleteQueue (Queue * Q){
    Q->MaxEl = 0;
    free(Q->Tab);
    
}
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. membebaskan memori Tab, Q.MaxEl di-set 0 */

/* *** Primitif Add/Delete *** */
void Push (Queue * Q, ElType X){
    if(IsEmpty(*Q)){
        Q->HEAD = 0;
        Q->TAIL = 0;
        Q->Tab[Q->TAIL] = X;
    }
    else{
        Q->TAIL = (Q->TAIL + 1) % MaxLength(*Q);
        Q->Tab[Q->TAIL] = X;
    }
}
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru,
        TAIL "maju" dengan mekanisme circular buffer
        Jika Q kosong, HEAD dimulai dari 0 */
ElType Pop (Queue * Q){
    ElType Head = Front(*Q);
    if(Q->HEAD == Q->TAIL){
        Q->HEAD = NIL ;
        Q->TAIL = NIL ;
    }
    else{
        Q->HEAD = (Q->HEAD + 1) % MaxLength(*Q);
    }
    
    return Head;
}
/* Proses: Menghapus indeks HEAD pada Q dengan aturan FIFO, lalu mengembalikan nilainya */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */
ElType Front (Queue Q){
    return(Q.Tab[Q.HEAD]);
}
/* Proses: Mengembalikan nilai Q pada indeks HEAD tanpa penghapusan */
/* I.S. Q tidak mungkin kosong */
/* F.S. mengembalikan nilai Q pada indeks HEAD;
        Q pasti tetap tidak kosong */
/*
int main(){
    Queue Q = CreateQueue(10);
    for(int i = 0; i < Q.MaxEl ; i++){
        Q.Tab[i] = i;
        printf("%d" , Q.Tab[i]);
    }

}*/