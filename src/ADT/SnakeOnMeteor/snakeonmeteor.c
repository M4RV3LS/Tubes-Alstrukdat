#include "snakeonmeteor.h"

boolean IsEmpty (List L)
/* Mengirim true jika list kosong */
{
    return (Head(L) == Nil && Tail(L) == Nil);
}

void CreateEmpty (List *L)
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */
{
    Head(*L) = Nil;
    Tail(*L) = Nil;
}

void CreatePoint (Point *P, int X, int Y)
{
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void CreateList3Elemen(List *L, Point P1, Point P2, Point P3)
{
    address P;
    P = (address) malloc (sizeof(ElmtList));
    Info(P) = P1;
    Prev(P) = Nil;
    Next(P) = Nil;
    Head(*L) = P;
    Tail(*L) = P;

    P = (address) malloc (sizeof(ElmtList));
    Info(P) = P2;
    Prev(P) = Tail(*L);
    Next(P) = Nil;
    Next(Tail(*L)) = P;
    Tail(*L) = P;

    P = (address) malloc (sizeof(ElmtList));
    Info(P) = P3;
    Prev(P) = Tail(*L);
    Next(P) = Nil;
    Next(Tail(*L)) = P;
    Tail(*L) = P;
}

Point CreateNextPoint(Point P)
{
    Point Pnew;
    if (Absis(P) > 0)
    {
        Absis(Pnew) = Absis(P) - 1;
        Ordinat(Pnew) = Ordinat(P);
        return Pnew;
    }
    else if (Ordinat(P) > 0)
    {
        Absis(Pnew) = Absis(P);
        Ordinat(Pnew) = Ordinat(P) - 1;
        return Pnew;
    }
    else
    {
        Absis(Pnew) = Absis(P) + 1;
        Ordinat(Pnew) = Ordinat(P);
    }
    return Pnew;
}

address Alokasi (Point X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address) malloc(sizeof(ElmtList));
    Info(P) = X;
    Next(P) = Nil;
    Prev(P) = Nil;
    
    return P;
}

void Dealokasi (address *P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(*P);
}

void printList(List L)
{
    address P = Head(L);
    while (P != Nil)
    {
        printf("(%d,%d)\n", Absis(Info(P)), Ordinat(Info(P)));
        P = Next(P);
    }
}

int NbElmt (List L)
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */
{
    int count = 0;
    if (IsEmpty(L))
    {
        return 0;
    }
    else
    {
        address P = Head(L);
        while (P != Nil)
        {
            count++;
            P = Next(P);
        }
        return count;
    }
}

boolean IsPointSama(Point P1, Point P2)
{
    return (Absis(P1) == Absis(P2) && Ordinat(P1) == Ordinat(P2));
}

Point GenerateMeteor(Point Food, Point Obstacle)
/* Menghasilkan Point Meteor di tempat selain obstacle dan list-nya */
{
    int X = randint(0,4);
    int Y = randint(0,4);
    Point Meteor;
    CreatePoint(&Meteor, X, Y);
    while (IsPointSama(Obstacle, Meteor) || IsPointSama(Food, Meteor))
    {
        X = randint(0,4);
        Y = randint(0,4);
        CreatePoint(&Meteor, X, Y);
    }
    return Meteor;
}

Point GenerateFoodPertama(Point Obstacle, List L)
{
    int X = randint(0,4);
    int Y = randint(0,4);
    Point Food;
    CreatePoint(&Food, X, Y);
    while (IsPointSama(Obstacle, Food) || IsMember(L, Food))
    {
        X = randint(0,4);
        Y = randint(0,4);
        CreatePoint(&Food, X, Y);
    }
    return Food;
}

Point GenerateFood(Point Obstacle, Point Meteor, List L)
{
    int X = randint(0,4);
    int Y = randint(0,4);
    Point Food;
    CreatePoint(&Food, X, Y);
    while (IsPointSama(Obstacle, Food) || IsPointSama(Meteor, Food) || IsMember(L, Food))
    {
        X = randint(0,4);
        Y = randint(0,4);
        CreatePoint(&Food, X, Y);
    }
    return Food;
}

Point GenerateObstacle(List L)
{
    int X = randint(0,4);
    int Y = randint(0,4);
    Point Obstacle;
    CreatePoint(&Obstacle, X, Y);
    while (IsMember(L, Obstacle))
    {
        X = randint(0,4);
        Y = randint(0,4);
        CreatePoint(&Obstacle, X, Y);
    }
    return Obstacle;
}

void SalinPoint(Point P1, Point *P2)
{
    Absis(*P2) = Absis(P1);
    Ordinat(*P2) = Ordinat(P1);
}

void InsertLast (List *L)
/* I.S. Sembarang */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru dengan X adalah point elemen
sebelumnya */
{
    Point X = Info(Tail(*L));
    address P = Alokasi(X);
    Prev(P) = Tail(*L);
    Next(Tail(*L)) = P;
    Tail(*L) = P;

}

void DeleteAt (List *L, Point P)
/* I.S. List tidak kosong */
/* F.S. Elemen list ber-Point P dihapus dari list karena kena meteor*/
{
    address X = Head(*L);
    while (!IsPointSama(Info(X), P))
    {
        X = Next(X);
    }
    if (X == Tail(*L)) // di ekor or sama kayak delete last
    {
        Tail(*L) = Prev(X);
        Next(Tail(*L)) = Nil;
    }
    else // selain pala sama ekor
    {
        Next(Prev(X)) = Next(X);
        Prev(Next(X)) = Prev(X);
    }
}

boolean IsMember (List L, Point P)
/* Mengirimkan true jika P adalah anggota list, false jika tidak */
{
    address X = Head(L);
    while (X != Nil)
    {
        if (IsPointSama(Info(X), P))
        {
            return true;
        }
        X = Next(X);
    }
    return false;
}

/*      IN GAME         */
boolean IsObstacle(Point Obstacle, Point P)
{
    return (IsPointSama(Obstacle, P));
}

boolean IsBadanKenaMeteor(List L, Point P)
/* Mengirimkan true jika L kena meteor di P, false jika tidak */
{
    address X = Next(Head(L));
    while (X != Nil)
    {
        if (IsPointSama(Info(X), P))
        {
            return true;
        }
        X = Next(X);
    }
    return false;
}

boolean IsMeteor(Point Meteor, Point P)
/* Mengirimkan true jika P adalah meteor, false jika tidak */
/* Bekas meteor masih panas, ga bisa dilewatin mase */
{
    return (IsPointSama(Meteor, P));
}

boolean IsHeadKenaMeteor(List L, Point Meteor)
/* Mengirim true jika kepala snake kena meteor */
{
    return (IsPointSama(Info(Head(L)), Meteor));
}

boolean IsHeadNabrakBadan(List L)
/* Mengirim true jika kepala snake nabrak badan */
{
    Point P = Info(Head(L));
    address X = Next(Head(L));
    while (X != Nil)
    {
        if (IsPointSama(Info(X), P))
        {
            return true;
        }
        X = Next(X);
    }
    return false;
}

boolean IsFood(Point Food, Point Geser)
{
    return (IsPointSama(Food, Geser));
}

boolean IsGameOver(List L, Point Meteor, Point Obstacle)
/* Mengirim true jika game over */
/* Aturan game over :
2. pala kena meteor
3. nabrak badan sndiri
4. ulernya abis (kosong)
*/
{
    return (IsHeadKenaMeteor(L, Meteor) || IsHeadNabrakBadan(L) || IsEmpty(L)) || IsObstacle(Obstacle, Info(Head(L)));
}

void MoveList(List *L, Point Geser) // kalo dia abis makan
{
    InsertLast(L);
    address P = Prev(Tail(*L));
    while (P != Head(*L))
    {
        Info(P) = Info(Prev(P));
        P = Prev(P);
    }
    Info(Head(*L)) = Geser;
}

void MoveList2(List *L, Point Geser) // kalo dia ga makan
{
    address P = Tail(*L);
    while (P != Head(*L))
    {
        Info(P) = Info(Prev(P));
        P = Prev(P);
    }
    Info(Head(*L)) = Geser;
}

int indexOf(List L, Point P)
{
    int i = 0;
    address X = Head(L);
    while (X != Nil)
    {
        if (IsPointSama(Info(X), P))
        {
            return i;
        }
        X = Next(X);
        i++;
    }
    return -1;
}

void printmap(List L, Point M, Point F, Point O)
{
    printf("Berikut merupakan peta permainan\n");
    int i,j;
    Point S;
    for(i = 0; i < 11; i++)
    {
        for(j = 0; j < 11; j++)
        {
            
            if(i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    printf(" ");
                }
                else 
                {
                    printf("-----");
                }
            }
            
            else 
            {
                if(j % 2 == 0)
                {
                    printf("|");
                }
                
                else 
                {
                    S.X = j/2;
                    S.Y = i/2;
                    if(IsMember(L,S)) // kalo ketemu bagian dari list
                    {
                        if(M.X == S.X && M.Y == S.Y){ // kalo ketemu meteor
                            printf("  m  ");
                        }
                        else { // kalo ga ktemu meteor
                            // printf(" %c ", Search(L,S)->info);
                            if (indexOf(L,S) == 0)
                            {
                                printf("  H  ");
                            }
                            else{
                                printf("  %i  ", indexOf(L,S));
                            }
                        }
                        
                    }
                    
                    else  // kalo di luar dari list
                    {
                        if(F.X == S.X && F.Y == S.Y) // makanan
                        {
                            printf("  o  ");
                        }
                        else if(M.X == S.X && M.Y == S.Y) // meteor
                        {
                            printf("  m  ");
                        }
                        else if(O.X == S.X && O.Y == S.Y) // obstacle
                        {
                            printf("  +  "); 
                        }
                        else 
                        {
                            printf("     ");
                        }
                    }
                    
                    
                }
            }
        }
        printf("\n");
    }
}

/*
// test case
int main()
{
  List L;
  CreateEmpty(&L);

  int X = randint(0,4);
  int Y = randint(0,4);

  Point P1;
  CreatePoint(&P1, X, Y);

  printf("%d %d", P1.X, P1.Y);

  return 0;
}
*/
