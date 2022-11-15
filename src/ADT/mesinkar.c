#include <stdio.h>
#include "mesinkar.h"

char karakter;

static FILE *command;
static int retval;

/* *** Membaca dari terminal *** */
void COMMAND() {
    /* Mesin siap dioperasikan. Pita command disiapkan ... */
    command = stdin;
    ADVC();
}

void ADVC()
// Pita dimajukan satu karakter.
{
    retval = fscanf(command,"%c",&karakter);
    // Pita command tidak diclose agar dapat terus terbaca oleh mesin
}