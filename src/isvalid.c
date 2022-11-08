#include "isvalid.h"

boolean isLoad(Word cmd)
{
    return wordAndCharSama(kataPertama(cmd),"LOAD");
}

boolean isSave(Word cmd)
{
    return wordAndCharSama(kataPertama(cmd),"SAVE");
}

boolean isCmdValid(Word cmd, ArrayDin validcmd)
{
    boolean valid = false;
    if (isLoad(cmd)||isSave(cmd))
    {
        valid = true;
    } else {
        int i = 0;
        while (!valid && i<Length(validcmd))
        {
            if (wordAndCharSama(cmd,validcmd[i]))
            {
                valid = true;
            } else {
                i++;
            }
        }
    } 
    return valid;
}