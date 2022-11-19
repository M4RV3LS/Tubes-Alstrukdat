#ifndef snakeonmeteor_H
#define snakeonmeteor_H
#include "../boolean.h"

#define Nil NULL

typedef struct {
    int X;
    int Y;
} Point;

typedef struct {
    address Head;
    address Tail;
} List;

typedef struct {
    address Prev;
    Point Info;
    address Next;
} ElmtList;

#define Prev(L) (L).Prev
#define Next(L) (L).Next
#define Info(L) (L).Info

#define Head(L) (L).Head
#define Tail(L) (L).Tail

#define Absis(L) (L).Info.X
#define Ordinat(L) (L).Info.Y

boolean IsEmpty (List L);
/* Mengirim true jika list kosong */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

void CreatePoint (Point P, int X, int Y);
/* I.S. sembarang             */
/* F.S. Terbentuk Point dengan Absis X dan Ordinat Y */

Point CreateNextPoint(Point P);
/* I.S. sembarang             */
/* F.S. Terbentuk Point dengan Absis X dan Ordinat Y */

/****************** Manajemen Memori ******************/
address Alokasi (infotype X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (address *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

int NbElmt (List L);
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

Point GenerateMeteor();
/* Menghasilkan Point Meteor di tempat selain obstacle dan list-nya */

void InsertLast (List L);
/* I.S. Sembarang */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru dengan X adalah point elemen
sebelumnya */

void DeleteAt (List L, Point P);
/* I.S. List tidak kosong */
/* F.S. Elemen list ber-Point P dihapus dari list karena kena meteor*/

boolean IsMember (List L, Point P);
/* Mengirimkan true jika P adalah anggota list, false jika tidak */

/*      IN GAME         */
boolean IsObstacle (Point P);
/* Mengirimkan true jika P adalah obstacle, false jika tidak */

boolean IsKenaMeteor(List L, Point P);
/* Mengirimkan true jika L kena meteor di P, false jika tidak */

boolean IsMeteor(Point P);
/* Mengirimkan true jika P adalah meteor, false jika tidak */
/* Bekas meteor masih panas, ga bisa dilewatin mase */

boolean IsEmpty(List L);
/* Mengirim true jika list kosong */
/*  Kalah */

boolean IsHeadKenaMeteor(List L);
/* Mengirim true jika kepala snake kena meteor */

boolean IsHeadNabrakBadan(List L);
/* Mengirim true jika kepala snake nabrak badan */

boolean IsGameOver(List L);
/* Mengirim true jika game over */
/* Aturan game over :
1. nabrak obstacle
2. pala kena meteor
3. nabrak badan sndiri
4. ulernya abis (kosong)
5. dan mati konyol lainnya
*/

#endif
