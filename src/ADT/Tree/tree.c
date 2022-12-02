#include "tree.h"

//KONSTRUKTOR
BinTree Tree (Infotype Akar, BinTree L, BinTree R) 
/* Menghasilkan sebuah pohon biner dari Akar, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
	//Alokasi Pohon
	BinTree T;
	T= (AddressTree) malloc (sizeof(Node));

	if (T != Nil) 
	{
		Akar(T)= Akar;
		Left(T)= L;
		Right(T)= R;
	} 

	return T;
}


void MakeTree (Infotype Akar, BinTree L, BinTree R, BinTree *P) 
// I.S. Sembarang
// F.S. Menghasilkan sebuah pohon P
// Menghasilkan sebuah pohon biner P dari Akar , L, dan R, jika alokasi berhasil
// Menghasilkan pohon P yang kosong (Nil) jika alokasi gagal
{
	*P= Tree(Akar,L,R);
}

//PREDIKAT
boolean IsTreeEmpty (BinTree P)
// Mengirimkan true jika P adalah pohon biner kosong
{
	return P == Nil;
}

boolean IsOneElmt (BinTree P)
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1
elemen */
{
	if (!IsTreeEmpty(P)) 
	{
		return (Left(P) == Nil && Right(P) == Nil);
	} else {
		return false;
	}
}

boolean IsUnerRight (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P hanya
mempunyai subpohon kanan */
{
	if (!IsTreeEmpty(P)) 
	{
		return (IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P)));
	} else {
		return false;
	}
}

boolean IsUnerLeft (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P hanya
mempunyai subpohon kiri */
{
	if (!IsTreeEmpty(P)) 
	{
		return (!IsTreeEmpty(Left(P)) && IsTreeEmpty(Right(P)));
	} else {
		return false;
	}
}

boolean IsBiner (BinTree P)
/* Mengirimkan true jika pohon biner tidak kosong P mempunyai
subpohon kiri dan subpohon kanan */
{
	if (!IsTreeEmpty(P)) 
	{
		return (!IsTreeEmpty(Left(P)) && !IsTreeEmpty(Right(P)));
	} else {
		return false;
	}
}

//SEARCHING
boolean SearchTree (BinTree P, Infotype X)
/* Mengirimkan true jika ada node dari P yang bernilai X */
{
	if (IsTreeEmpty(P)) 
	{
		return false;
	} else {
		if (Akar(P) == X) {
			return true;
		} else {
			return (SearchTree(Left(P),X) || SearchTree(Right(P),X));
		}
	}
}

//OPERASI ADDITION DAN DELETION
void AddDaunLeft (BinTree *P, Infotype X)
/* I.S. P boleh kosong */
/* F.S. P bertambah simpulnya, dengan X sebagai simpul daun terkiri */
{
	if (IsTreeEmpty(*P)) 
	{
		*P= Tree(X,Nil,Nil);
	} else if (IsUnerLeft(*P)||IsBiner(*P)||IsOneElmt(*P)) {
		AddDaunLeft(&Left(*P),X);
	} else {
		AddDaunLeft(&Right(*P),X);
	}
}

void AddDaun (BinTree *P, Infotype X, Infotype Y, boolean Kiri)
/* I.S. P tidak kosong, X adalah salah satu daun Pohon Biner P */
/* F.S. P bertambah simpulnya, dengan Y sebagai anak kiri X jika Kiri=True, atau
sebagai anak kanan X jika Kiri=False */
{
	if (!IsTreeEmpty(*P)) 
	{
		if (Akar(*P) == X) 
		{
			if (Kiri) {
				Left(*P)= Tree(Y,Nil,Nil);
			} else {
				Right(*P)= Tree(Y,Nil,Nil);
			}
		} else {
			AddDaun(&Left(*P), X, Y, Kiri);
			AddDaun(&Right(*P), X, Y, Kiri);
		}
	}
}


void DelDaunLeft (BinTree *P, Infotype *X)
/* I.S. P tidak kosong */
/* F.S. P dihapus daun terkirinya, dan didealokasi, dengan X adalah info yang semula
disimpan pada daun terkiri yang dihapus */
{
	if (IsOneElmt(*P)) 
	{
		*X= Akar(*P);
		free(*P);
		*P = Nil;
	} else {
		if (IsUnerRight(*P)) 
		{
			DelDaunLeft(&Right(*P),X);
		} else { 
			DelDaunLeft(&Left(*P),X);
		}
	}
}

void DelDaun (BinTree *P, Infotype X)
/* I.S. P tidak kosong, X adalah salah satu daun */
/* F.S. Semua daun bernilai X dihapus dari P */
{
	if (!IsTreeEmpty(*P)) 
	{
		if (Akar(*P) == X) 
		{
			free(*P);
			*P = Nil;
		} else {
			DelDaun(&Left(*P),X);
			DelDaun(&Right(*P),X);
		}
	}
}

//FUNGSI TAMBAHAN
int NbElmt (BinTree P)
/* Mengirimkan banyaknya elemen (node) pohon biner P */
{
	if (!IsTreeEmpty(P)) 
	{
		return (1 + NbElmt(Left(P)) + NbElmt(Right(P)));
	} else {
		return 0;
	} 
}

int NbLeaf (BinTree P)
/* Mengirimkan banyaknya daun (node) pohon biner P */
{
	if (IsTreeEmpty(P))
	{
		return 0;
	} else if (IsOneElmt(P)) {
		return 1;
	} else {
		return (NbLeaf(Left(P)) + NbLeaf(Right(P)));
	}
}

void printTree (BinTree P)
/* Mencetak elemen Tree ke layar */
{
	if (!IsTreeEmpty(P)) // Tidak kosong
	{
		printf("%c\n", P->Info);
		printTree(P->Left);
		printTree(P->Right);
	}
}

/*int main()
{
	BinTree test,l,r;
	MakeTree('A',l,r,&test);

	//Test info tree
	printf("Ini Info Tree : %c\n", test->Info);

	//Test is oneelmt
	if (IsOneElmt(test))
	{
		printf("Pohon test one element!\n");
	}

	//Test empty tree
	if (IsTreeEmpty(Left(test)))
	{
		printf("Cabang kiri pohon test kosong!\n");
	}

	//Tambah cabang kiri
	AddDaunLeft(&test,'B');

	//Test uner left
	if (IsUnerLeft(test))
	{
		printf("Setelah tambah daun kiri, pohon kini uner left!\n");
	}

	Infotype temp;
	DelDaunLeft(&test,&temp);
	printf("Ini info daun yang di delete: %c\n", temp);

	AddDaun(&test,'A','C',false);

	//Test uner right
	if (IsUnerRight(test))
	{
		printf("Setelah delete daun kiri dan tambah daun kanan, pohon kini uner right!\n");
	}

	//Tambah daun di kiri
	AddDaun(&test,'A','B',true);

	//Test nbelmt dan nbdaun, wanted answer: 3 dan 2
	printf("Jumlah elemen pohon adalah: %d\n", NbElmt(test));
	printf("Jumlah daun adalah: %d\n", NbLeaf(test));

	//Test search
	if (SearchTree(test,'C'))
	{
		printf("Ya, terdapat huruf C di pohon.\n");
	}

	//Test pohon biner
	if (IsBiner(test))
	{
		printf("Ya, pohon adalah pohon biner.\n");
	}

	//Test delete
	DelDaun(&test,'C');
	if (!SearchTree(test,'C'))
	{
		printf("Daun mengandung huruf C sudah di delete.\n");
	}

	//Test print
	printf("Untuk test print, daun C akan ditambah lagi.\n");
	AddDaun(&test,'A','C',false);
	printTree(test);
}*/
