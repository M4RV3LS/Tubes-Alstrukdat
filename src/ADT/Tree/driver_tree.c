#include <stdio.h>
#include "tree.h"

int main()
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
}