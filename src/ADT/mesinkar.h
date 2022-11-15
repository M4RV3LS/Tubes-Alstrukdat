#ifndef __MESIN_KAR__
#define __MESIN_KAR__

#include "boolean.h"
#include <stdio.h>
#define MARK '.'
#define ENTER '\n'

char currentChar;

static FILE *command;
static int retval;

/* *** Membaca dari terminal *** */
void COMMAND();
/* Mesin siap dioperasikan. Pita command disiapkan ... */

void ADVC();
// Pita dimajukan satu karakter.

#endif