#ifndef __MESIN_KAR__
#define __MESIN_KAR__

#include "../boolean.h"
#include <stdio.h>
#define MARK '.'
#define ENTER '\n'

/* State Mesin */
extern char currentChar;
extern boolean EOP;
extern FILE *pita;


/* *** Membaca dari file *** */
void START(char *directory);

void ADV();

char GetCC();

boolean IsEOP();

/* *** Membaca dari terminal *** */
void COMMAND();

void ADVC();

#endif