#ifndef __MESIN_KAR__DD__
#define __MESIN_KAR__DD__

#include "boolean.h"
#include <stdio.h>
#define MARK '.'
#define ENTER '\n'

extern char karakter;

static FILE *command;
static int retval;

/* *** Membaca dari terminal *** */
void COMMAND();
/* Mesin siap dioperasikan. Pita command disiapkan ... */

void ADVC();
// Pita dimajukan satu karakter.

#endif