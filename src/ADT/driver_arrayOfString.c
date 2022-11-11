#include "arrayOfString.h"

int main()
{
    ArrayDin arr;
    arr = CreateDynArray();
    char temp[8] = "Timothy";
    arr.A[0] = temp;
    int i = 0;
    int j = 0;
    while (arr.A[0][i] != '\0')
    {
        printf("%c",arr.A[0][i]);
        i++;
    }
}