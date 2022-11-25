#include "hangman.h"
#include "ADT/Hangman/hangmanprint.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void hangman()
{
    // pilihan menu
    ListKata ListKata;
    boolean on = true;
    while (on)
    {
        landingPage();
        STARTCOMMAND();
        if (wordAndCharSama(currentCMD, "1") || wordAndCharSama(currentCMD, "PLAY"))
        {
            themePage();
            STARTCOMMAND();
            boolean valid = false;
            while (!valid)
            {
                if (wordAndCharSama(currentCMD, "1") || wordAndCharSama(currentCMD, "KOTA"))
                {
                    loadkata(&ListKata, "KataKota.txt"); valid = true;
                }
                else if(wordAndCharSama(currentCMD, "2") || wordAndCharSama(currentCMD, "NEGARA"))
                {
                    loadkata(&ListKata, "KataNegara.txt"); valid = true;
                }
                else
                {
                    printInputNotValid();
                }
            }
            int kesempatan = 10;
            int skor = 0;
            while (kesempatan > 0)
            {
                srand(time(NULL));
                int random = rand() % (ListKata.Neff) + 1;   
                char*Kata = wordToStr(ListKata.TI[random]);

                mainHangman(&kesempatan, Kata);
                if (kesempatan != 0) skor += 25;
            }
            printf("\nGAME OVER.");
            printf("\n\nSkor kamu adalah %d", skor); 
            
            on = false; 
        } 
        else if (wordAndCharSama(currentCMD, "2") || wordAndCharSama(currentCMD, "HELP"))
        {
            helpHangman();
            printf("\n\nPress any key to continue..\n");
            STARTCOMMAND();
        }
        else if (wordAndCharSama(currentCMD, "3") || wordAndCharSama(currentCMD, "TAMBAHKATA"))
        {
            themePage();
            STARTCOMMAND();
            boolean valid = false;
            char*file; char* tema;
            while (!valid)
            {
                if (wordAndCharSama(currentCMD, "1") || wordAndCharSama(currentCMD, "KOTA"))
                {
                    file = "KataKota.txt"; tema = "KOTA";
                    loadkata(&ListKata, file); valid = true;
                }
                else if(wordAndCharSama(currentCMD, "2") || wordAndCharSama(currentCMD, "NEGARA"))
                {
                    file = "KataNegara.txt"; tema = "NEGARA";
                    loadkata(&ListKata, file); valid = true;
                }
                else
                {
                    printInputNotValid();
                }
            }
            printf("\nSilakan memasukkan ");
            printf("%s", tema);
            printf(" yang ingin kamu tambahkan");
            printf("\n(DALAM HURUF KAPITAL) :");
            STARTCOMMAND();
            int n = ListKata.Neff;
            SetEl(&ListKata, n+1, currentCMD);
            saveListKata(ListKata, file);
        }
        else if (wordAndCharSama(currentCMD, "4") || wordAndCharSama(currentCMD, "QUIT"))
        {
            printf("\nSad to say goodbye to you! :(((\n");
            on = false;
        }
        else
        {
            printInputNotValid();
        }
    }
}

void mainHangman(int*kesempatan, char*Kata)
{
    Kata[string_length(Kata)] = '\0';

    char huruf;
    char GuessedHuruf[10]; GuessedHuruf[0] = '\0';

    char GuessedKata[20];
    for (int i = 0; i < string_length(Kata); i++){
        GuessedKata[i] = '_';
    }
    GuessedKata[panjang_kata(Kata)] = '\0';

    printf("\n%s", GuessedHuruf);
    
    int n;
    boolean win = false;
    while (!win && *kesempatan > 0){
        printf("\nTebakan Sebelumnya: ");
        n = panjang_kata(GuessedHuruf);
        PrintCharWithSpace(GuessedHuruf, n);

            // print progress tebakan kata pemain
        printf("\nKata: ");
        n = panjang_kata(GuessedKata);
        PrintCharWithSpace(GuessedKata, n);

            // print kesempatan yang tersisa
        printf("\nKesempatan: %d", *kesempatan);

            // memasukkan tebakkan
        printf("\nMasukkan tebakan: ");
        STARTCOMMAND();

        wordToString(currentCMD, &huruf);

        if (currentCMD.Length == 1){

            if (isHurufAda(huruf, GuessedHuruf)){

                printf("\nKamu sudah menebak huruf %c!\n", huruf);
                (*kesempatan)-=1;

            } else {

                if (isHurufAda(huruf, Kata) == false){

                    printf("\nTebakan kamu salah!\n\n");
                    (*kesempatan)-=1;

                } else {

                    printf("\nSelamat, tebakan kamu benar!\n");
                    underscoreToHuruf(huruf, GuessedKata, Kata);

                    if (!isHurufAda('_', GuessedKata)){
                        win = true;
                    } else {
                        win = false;
                    }

                }
                InsertKataLast(huruf, GuessedHuruf);
            }
            hangedMan(*kesempatan);
        } else 
        {
            printf("\nMasukkan hanya satu huruf!\n");
            (*kesempatan)--;
        }
    }
    if (win == true){
        printf("\nBerhasil menebak "); PrintCharNoSpace(Kata, panjang_kata(Kata));
        printf("! Kamu mendapatkan 25 poin!");
    }
    if ((*kesempatan) == 0) printf("\nKesempatan habis! Total poin yang kamu dapatkan adalah ");
}

void loadkata(ListKata *ListKata, char*filename)
{
    char path[NMax];
    stringConcat("data/",filename,path);
    STARTWORD(path);
    int nGame = WordToInt(currentWord);
    for (int i = 1; i <= nGame; i++){
        ADVLine();
        SetEl(ListKata, i, currentWord);
    }
}

void saveListKata(ListKata ListKata, char*filename)
{
    FILE* fp; 
    char path[50]; 
  
    stringConcat("data/",filename,path); 
    fp = fopen(path,"w"); 

    fprintf(fp,"%d",ListKata.Neff); 
    for(int i = 1; i <= ListKata.Neff;i++) 
    {
        char*string = wordToStr(ListKata.TI[i]);
        fprintf(fp,"\n%s", string); 
    } 
    fclose(fp); 
  
    fp = fopen(path, "r"); 
    if (fp != NULL) 
    { 
        printf("Kata berhasil ditambahkan!\n");
        fclose(fp); 
    } else printf("Kata gagal ditambahkan!\n");
}

boolean isTebakanValid(Word word)
{
    if (word.Length =! 1) return false;
    else true;
}

boolean isHurufAda(char huruf, char* kata)
{
    int i = 0;
    boolean found = false;
	while(!found && i < panjang_kata(kata))
    {
        if (kata[i] == huruf) found = true;
        i++;
    }
    return found;
}

void underscoreToHuruf(char huruf, char* GuessedKata, char* kata)
{
    for (int i = 0; i < string_length(kata); i++)
    {
        if (huruf == kata[i]){
            *(GuessedKata+i) = huruf;
        }
    }
}

void PrintCharWithSpace(char* kata, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%c ", kata[i]);
	}
	printf("\n");
}

void PrintCharNoSpace(char* kata, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%c", kata[i]);
	}
}

int panjang_kata(char*s){
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}

void InsertKataLast(char huruf, char*kata)
{
    int n = panjang_kata(kata);
    kata[n] = huruf;
    kata[n+1] = '\0';
}

char* wordToStr(Word word)
{
    char*str = (char *)malloc(sizeof(char) * word.Length);

    int i = 0;
    while (i < word.Length)
    {
        str[i] = word.TabWord[i];
        i++;
    }
    str[i] = '\0';  

    return str;  
}