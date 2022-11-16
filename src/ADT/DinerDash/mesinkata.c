#include <stdio.h>
#include "mesinkata.h"

boolean EndKata;
Kata CURRENTCOMMAND;

/* Pembacaan Pita */
void COPYCOMMANDGAMEDD(){
    int i = 0;
    while ((karakter != ENTER) && i != NMax) {
        CURRENTCOMMAND.TabKata[i] = karakter;
        advcharacter();
        i++;
    }
    CURRENTCOMMAND.Length = i;
}

void STARTCMD()
{
    CMD();
    if (karakter == '\n')
    {
        EndKata = true;
    }
    else
    {
        EndKata = false;
        COPYCOMMANDGAMEDD();
    }
}

/* Operasi pada Kata */
int KataToInt(Kata w)
{
    int result = 0;
    result += w.TabKata[0] - 48;
    if (w.Length > 1)
    {
        int i;
        for (i=1; i < w.Length; i++)
        {
            result = result*10;
            result += w.TabKata[i] - 48;
        }
    }
    return result;
}

Kata getCommand(Kata w)
{
    Kata temp;
    int i = 0;
    while ((i<w.Length) && (w.TabKata[i] != ' ')){
        if (i < NMax){
            temp.TabKata[i] = w.TabKata[i];
            i++;
        }
    }
    temp.Length = i; 
    return temp;
}

Kata getLabel(Kata w)
{
    Kata temp;
    int i=0;

    while ((i<w.Length) && (w.TabKata[i] != ' '))
    {
        i++;
    }

    int j = i+1;
    int x = 0;
    temp.Length=0; 
    while (j<w.Length){
        if (i < NMax){
            temp.TabKata[x] = w.TabKata[j];
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

boolean wordStringEq(Kata w1, char *w2)
{ 
    if (w1.Length != stringLength(w2)){
        return false;
    } else {
        boolean sama = true;
        int i;
        for (i=0;i<w1.Length;i++)
        {
            if (w1.TabKata[i] != w2[i])
            {
                sama = false;
            }
        }
        return sama;
    }
}
//Cek apakah Kata sama dengan input yang dimasukkan

boolean wordKataEq(Kata w1, Kata w2)
{
    boolean sama = true;
    if (w1.Length != w2.Length) {
        return !sama;
    } else {
        int i = 0;
        while (sama && (i < w1.Length)) {
            if (w1.TabKata[i] != w2.TabKata[i]) {
                sama = false;
            }
            i++;
        }
        return sama;
    }
}

Kata IntToKata(int n)
{
    Kata temp;
    int i,j;
    i=0;
    j=n;
    temp.Length=0;  

    while (n >= 10){
        temp.TabKata[i] = (n/10) + '0';
        temp.Length++;
        n = n%10; 
        i++;
    }
    temp.Length++;
    temp.TabKata[i] = n + '0';

    return temp;
}
//ubah INT menjadi WORD

void joinKata(Kata *w1, Kata w2)
{
    int i;
    int sum = w1->Length + w2.Length;
    for (i=w1->Length;i<sum;i++){
        w1->TabKata[i] = w2.TabKata[i-(w1->Length)];
    }
    w1->Length += w2.Length;
}

//Menggabungkan dua kata dan menyimpannya dalam W1

void salinKata(Kata *w1, Kata w2)
{
    int i;
    for(i=0;i<w2.Length;i++){
        w1->TabKata[i] = w2.TabKata[i];
    }
    w1->Length = w2.Length;
    //w2 disalin ke w1
}

void printKata(Kata w)
{
    int i;
    for (i=0;i<w.Length;i++){
        printf("%c", w.TabKata[i]);
    }
}
