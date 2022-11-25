#include "../mesinkar2.h"
#include "../mesinkata2.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include "../boolean.h"

#define NilSOM NULL
typedef struct tElmtList *address;
typedef struct {
    int X;
    int Y;
} Point;

typedef struct {
    address head;
    address tail;
} List;

typedef struct tElmtList {
    address prev;
    Point info;
    address next;
} ElmtList;

#define Info(E) (E)->info
#define Prev(E) (E)->prev
#define Next(E) (E)->next

#define Head(L) (L).head
#define Tail(L) (L).tail

#define Absis(P) (P).X
#define Ordinat(P) (P).Y

boolean IsEmptySOM (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreatePoint (Point *P, int X, int Y);
/* I.S. sembarang             */
/* F.S. Terbentuk Point dengan Absis X dan Ordinat Y */

void CreateList3Elemen (List *L, Point P1, Point P2, Point P3);
/* I.S. sembarang             */
/* F.S. Terbentuk list dengan 3 elemen */

Point CreateNextPoint(Point P);

Point CreateNextNextPoint(Point P, Point P1);
/* I.S. sembarang             */
/* F.S. Terbentuk Point dengan Absis X dan Ordinat Y */

/****************** Manajemen Memori ******************/
address Alokasi (Point X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak NilSOM, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=NilSOM */
/* Jika alokasi gagal, mengirimkan NilSOM */

void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

void printList(List L);
/* I.S. L terdefinisi */
/* F.S. L dicetak ke layar */

int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

boolean IsPointSama(Point P1, Point P2);
/* Mengirimkan true jika P1 dan P2 sama */

Point GenerateMeteor(Point Food, Point Obstacle);
/* Menghasilkan Point Meteor di tempat selain obstacle dan Food*/

Point GenerateFoodPertama(Point Obstacle, List L);
/* Menghasilkan Point Food di tempat selain obstacle dan list-nya */

Point GenerateFood(Point Obstacle, Point Meteor, List L);
/* Menghasilkan Point Food di tempat selain obstacle, Meteor dan list-nya */

Point GenerateObstacle(List L);
/* Menghasilkan Point Obstacle di tempat selain list-nya */

void SalinPoint(Point P1, Point *P2);
/* I.S. P1 terdefinisi */
/* F.S. P2 terdefinisi */

void InsertAkhirSOM (List *L);
/* I.S. Sembarang */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru dengan X adalah point elemen
sebelumnya */

void DeleteDi (List *L, Point P);
/* I.S. List tidak kosong */
/* F.S. Elemen list ber-Point P dihapus dari list karena kena meteor*/

boolean IsMember (List L, Point P);
/* Mengirimkan true jika P adalah anggota list, false jika tidak */

/*      IN GAME         */
boolean IsObstacle (Point Obstacle, Point P);
/* Mengirimkan true jika P adalah obstacle, false jika tidak */

boolean IsBadanKenaMeteor(List L, Point P);
/* Mengirimkan true jika L kena meteor di P, false jika tidak */

boolean IsMeteor(Point Meteor, Point P);
/* Mengirimkan true jika P adalah meteor, false jika tidak */
/* Bekas meteor masih panas, ga bisa dilewatin mase */

boolean IsHeadKenaMeteor(List L, Point Meteor);
/* Mengirim true jika kepala snake kena meteor */

boolean IsHeadNabrakBadan(List L);
/* Mengirim true jika kepala snake nabrak badan */

boolean IsFood(Point Food, Point Geser);
/* Mengirim true jika Food berada di tempat yang dituju */

boolean IsGameOver(List L, Point Meteor, Point Obstacle);
/* Mengirim true jika game over */
/* Aturan game over :
1. nabrak obstacle
2. pala kena meteor
3. nabrak badan sndiri
4. ulernya abis (kosong)
5. dan mati konyol lainnya
*/

void MoveList(List *L, Point P);
/* I.S. List tidak kosong */
/* F.S. List bergerak ke arah P */

void MoveList2(List *L, Point P);
/* I.S. List tidak kosong */
/* F.S. List bergerak ke arah P */

void printmap(List L, Point M, Point F, Point O);
/* I.S. sembarang */
/* F.S. Map ditampilkan */

int indexOf(List L, Point P);
/* Mengirimkan index dari elemen list yang ber-Point P */


#endif
