#include "stackofdisks.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    STACKSS s;
    CreateEmptySS(&s);

    //Test isempty
    if (IsEmptySS(s))
    {
        printf("Awalnya, s kosong\n");
        if (!IsFullSS(s))
        {
            printf("s juga tidak penuh\n");
        }
    }

    Disk tempdii;
    tempdii.size = 8;
    tempdii.sym = "ini temp";

    PushSS(&s,tempdii.sym,tempdii.size);
    PushSS(&s,tempdii.sym,tempdii.size);
    PushSS(&s,tempdii.sym,tempdii.size);
    PushSS(&s,tempdii.sym,tempdii.size);
    PushSS(&s,tempdii.sym,tempdii.size);

    Disk tempdiii;
    char* tempp1 = (char *) malloc (MaxEl*sizeof(char));
    PopSS(&s,&tempdiii,5,tempp1);
    
    if (diskComp(tempdii,tempdiii))
    {
        printf("Diskcomp berhasil\n");
    }

    free(tempp1);
}
