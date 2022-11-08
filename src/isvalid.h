#include "boolean.h"
#include "mesinkata2.h"
#include "arrayOfString.h"
#include <stdio.h>

boolean isLoad(Word cmd);
// Mengembalikan true apabila command yang dimasukkan = Load

boolean isSave(Word cmd);
// Mengembalikan true apabila command yang dimasukkan = Save

boolean isCmdValid(Word cmd);
// Mengembalikan true apabila command yang dimasukkan valid