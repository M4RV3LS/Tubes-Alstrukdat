#include "hangmanprint.h"

void landingPage(){
    printf("SELAMAT DATANG DI PERMAINAN HANGMAN!\n");
    printf("\n\n\t 1. PLAY");
    printf("\n\t 2. HELP");
    printf("\n\t 3. TAMBAHKATA");
    printf("\n\t 4. QUIT\n\n");
    printf("\nSilakan pilih menu di atas: ");
}

void exitPage()
{

}

void themePage()
{
    printf("\n\t 1. KOTA");
    printf("\n\t 2. NEGARA");
    printf("\n\nSilakan pilih tema di atas: ");
}

void helpHangman()
{
    printf("Cara bermain: ");
    printf("\n 1. Masukkan huruf tebakan dari kata yang sudah ditetapkan");
    printf("\n 2. Input hanya berupa satu huruf kapital");
    printf("\n 3. Input huruf kecil akan dinyatakan salah");
    printf("\n 4. Input lebih dari satu huruf akan dinyatakan salah");
    printf("\n 5. Setiap tebakan kata yang berhasil, pemain akan mendapatkan 25 poin");
    printf("\n 6. Jika kesempatan habis, permainan berhenti");
}

void printInputNotValid()
{
    printf("\nInput salah! Ulangi!\n");
}

void hangedMan(int kesempatan){
    switch(kesempatan)
    {
        case 9:
            printf("\n\n\n\n\n\n");
            printf("_ _ _ _ _\n");
            break;
        case 8:
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_ _ _ _ _\n");
            break;
        case 7:
            printf(" _ _ _ _\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_ _ _ _ _\n");
            break;
        case 6:
            printf(" _ _ _ _\n");
            printf(" |     |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_ _ _ _ _\n");
            break;
        case 5:
            printf(" _ _ _ _\n");
            printf(" |     |\n");
            printf(" |     O\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_ _ _ _ _\n");
            break;
        case 4:
            printf(" _ _ _ _\n");
            printf(" |     |\n");
            printf(" |     O\n");
            printf(" |     |\n");
            printf(" |     |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_ _ _ _ _\n");
            break;
        case 3:
            printf(" _ _ _ _\n");
            printf(" |     |\n");
            printf(" |     O\n");
            printf(" |    /|\n");
            printf(" |     |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_ _ _ _ _\n");
            break;
        case 2:
            printf(" _ _ _ _\n");
            printf(" |     |\n");
            printf(" |     O\n");
            printf(" |    /|\\ \n");
            printf(" |     |\n");
            printf(" |\n");
            printf(" |\n");
            printf("_ _ _ _ _\n");
            break;
        case 1:
            printf(" _ _ _ _\n");
            printf(" |     |\n");
            printf(" |     O\n");
            printf(" |    /|\\ \n");
            printf(" |     |\n");
            printf(" |    /\n");
            printf(" |\n");
            printf("_ _ _ _ _\n");
            break;
        case 0:
            printf(" _ _ _ _\n");
            printf(" |     |\n");
            printf(" |     O\n");
            printf(" |    /|\\ \n");
            printf(" |     |\n");
            printf(" |    / \\ \n");
            printf(" |\n");
            printf("_ _ _ _ _\n");
            break;
    }
}