#ifndef __MESIN_KAR__
#define __MESIN_KAR__

#include "../boolean.h"
#include <stdio.h>
#define MARK '.'
#define ENTER '\n'

/* State Mesin */
extern char CC;
extern boolean EOP;
extern FILE *pita;



/*
  pada implementasi (mesin_kar.c), perlu ditambahkan variabel static 
  global yang menyimpan pembacaan file pita.
*/

/* *** Membaca dari File *** */
void START(char* filename);
/* Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
Karakter pertama yang ada pada pita posisinya adalah pada jendela.
filename merupakan nama file yang berisi pita karakter
I.S. : sembarang
F.S. : CC adalah karakter pertama pada pita
Jika CC != MARK maka EOP akan padam (false)
Jika CC = MARK maka EOP akan menyala (true) */


void ADV();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != MARK
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = MARK
Jika CC = MARK maka EOP akan menyala (true) */

/* *** Membaca dari terminal *** */
void COMMAND();
/*  Mesin siap dioperasikan. Pita disiapkan untuk dibaca.
    Karakter pertama yang ada pada pita posisinya adalah pada jendela.
    filename merupakan nama file yang berisi pita karakter
    I.S. : sembarang
    F.S. : CC adalah karakter pertama pada pita
    Jika CC != ENTER maka EOP akan padam (false)
    Jika CC = ENTER maka EOP akan menyala (true) */

void ADVC();
/* Pita dimajukan satu karakter.
I.S. : Karakter pada jendela = CC, CC != ENTER
F.S. : CC adalah karakter berikutnya dari CC yang lama,
CC mungkin = ENTER
Jika CC = ENTER maka EOP akan menyala (true) */

int STRINGTOINT(char c);
/*Mengubah string menjadi Integer
I.S. : Karakter merupakan tipe string
F.S : Karakter bertipa integer*/

char GetCC();

boolean IsEOP();

#endif