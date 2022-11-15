#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentCmd;

/* Pembacaan Pita */
void CopyCommandGame(){
    int i = 0;
    while ((karakter != ENTER) && i != NMax) {
        currentCmd.TabWord[i] = karakter;
        ADVC();
        i++;
    }
    currentCmd.Length = i;
}

void STARTCOMMAND()
{
    COMMAND();
    if (karakter == '\n')
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyCommandGame();
    }
}

/* Operasi pada Word */
int WordToInt(Word w)
{
    int result = 0;
    result += w.TabWord[0] - 48;
    if (w.Length > 1)
    {
        int i;
        for (i=1; i < w.Length; i++)
        {
            result = result*10;
            result += w.TabWord[i] - 48;
        }
    }
    return result;
}

Word getCommand(Word w)
{
    Word temp;
    int i = 0;
    while ((i<w.Length) && (w.TabWord[i] != ' ')){
        if (i < NMax){
            temp.TabWord[i] = w.TabWord[i];
            i++;
        }
    }
    temp.Length = i; 
    return temp;
}

Word getLabel(Word w)
{
    Word temp;
    int i=0;

    while ((i<w.Length) && (w.TabWord[i] != ' '))
    {
        i++;
    }

    int j = i+1;
    int x = 0;
    temp.Length=0; 
    while (j<w.Length){
        if (i < NMax){
            temp.TabWord[x] = w.TabWord[j];
            temp.Length++;
            j++;
            x++;
        }
    }
    return temp;
}

int stringLength(char *str)
{
    int i,length;
    i = 0;
    length = 0;
    while (str[i] != '\0'){
        i++;
        length++;
    }
    return length;
}

boolean wordStringEq(Word w1, char *w2)
{ 
    if (w1.Length != stringLength(w2)){
        return false;
    } else {
        boolean sama = true;
        int i;
        for (i=0;i<w1.Length;i++)
        {
            if (w1.TabWord[i] != w2[i])
            {
                sama = false;
            }
        }
        return sama;
    }
}
//Cek apakah Kata sama dengan input yang dimasukkan

boolean wordWordEq(Word w1, Word w2)
{
    boolean sama = true;
    if (w1.Length != w2.Length) {
        return !sama;
    } else {
        int i = 0;
        while (sama && (i < w1.Length)) {
            if (w1.TabWord[i] != w2.TabWord[i]) {
                sama = false;
            }
            i++;
        }
        return sama;
    }
}

Word IntToWord(int n)
{
    Word temp;
    int i,j;
    i=0;
    j=n;
    temp.Length=0;  

    while (n >= 10){
        temp.TabWord[i] = (n/10) + '0';
        temp.Length++;
        n = n%10; 
        i++;
    }
    temp.Length++;
    temp.TabWord[i] = n + '0';

    return temp;
}
//ubah INT menjadi WORD

void joinWord(Word *w1, Word w2)
{
    int i;
    int sum = w1->Length + w2.Length;
    for (i=w1->Length;i<sum;i++){
        w1->TabWord[i] = w2.TabWord[i-(w1->Length)];
    }
    w1->Length += w2.Length;
}

//Menggabungkan dua kata dan menyimpannya dalam W1

void salinWord(Word *w1, Word w2)
{
    int i;
    for(i=0;i<w2.Length;i++){
        w1->TabWord[i] = w2.TabWord[i];
    }
    w1->Length = w2.Length;
    //w2 disalin ke w1
}

void printWord(Word w)
{
    int i;
    for (i=0;i<w.Length;i++){
        printf("%c", w.TabWord[i]);
    }
}
