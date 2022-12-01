#include "ADT/mesinkar2.h"
#include "ADT/mesinkata2.h"
#include "ADT/arrayOfString.h"
#include "boolean.h"
#include "ADT/queue.h"
#include "ADT/SetMap/map.h"
#include "ADT/Stack/stack.h"
#include "ADT/SnakeOnMeteor/snakeonmeteor.h"


void torielfight(int *score , char*Username);;
/* Permainan Rock Paper Scissor*/

int mainpapyrus();
/*Basic nya mirip mathquiz cuman bedanya semua mode pertambahan , perkalian , dan pengurangan di jadiin satu 
dan dipisahkan dengan 3 stage berbeda*/


void papyrusfight(int *score , char*Username);
/*Melakukan looping hingga health papyrus harus diatas 70*/


void sansfight(int *score , char *Username);
/*Permainan game hitung duit */

void CreateRandomPointAsriel(Point *P);
/*Membuat Random point buat generate bomb dan treasure*/

void PrintAlphabet(Map MiniGames , int index , char*input);
/*Melakukan print alphabet sesuai value yang dimilikinya*/


void Axe();
/*Axe Ascii Art*/

// void Maze(){
//     printf("88888888888888888888888888888888888888888888888888888888888888888888888\n");
//     printf("88.._|      | `-.  | `.  -_-_ _-_  _-  _- -_ -  .'|   |.'|     |  _..88\n");
//     printf("88   `-.._  |    |`!  |`.  -_ -__ -_ _- _-_-  .'  |.;'   |   _.!-'|  88\n");
//     printf("88      | `-!._  |  `;!  ;. _______________ ,'| .-' |   _!.i'     |  88\n");
//     printf("88..__  |     |`-!._ | `.| |_______________||.''|  _!.;'   |     _|..88\n");
//     printf("88   |``'..__ |    |`';.| i|_|MMMMMMMMMMM|_|'| _!-|   |   _|..-|'    88\n");
//     printf("88   |      |``--..|_ | `;!|l|MMoMMMMoMMM|1|.'j   |_..!-'|     |     88\n");
//     printf("88   |      |    |   |`-,!_|_|MMMMP'YMMMM|_||.!-;'  |    |     |     88\n");
//     printf("88___|______|____!.,.!,.!,!|d|MMMo * loMM|p|,!,.!.,.!..__|_____|_____88\n");
//     printf("88      |     |    |  |  | |_|MMMMb,dMMMM|_|| |   |   |    |      |  88\n");
//     printf("88      |     |    |..!-;'i|r|MPYMoMMMMoM|r| |`-..|   |    |      |  88\n");
//     printf("88      |    _!.-j'  | _!,'|_|MMMMMMoMMM|_||!._|  `i-!.._  |      |  88\n");
//     printf("88     _!.-'|    | _.'|  ! |1|MbdMMoMMMMM|l|`.| `-._|    |``-.._  |  88\n");
//     printf("88..-i'     |  _.''|  !-| !|_|MMMoMMMMoMM|_|.|`-. | ``._ |     |``'..88\n");
//     printf("88   |      |.|    |.|  !| |u|MoMMMMoMMMM|n||`. |`!   | `;.    |     88\n");
//     printf("88   |  _.-'  |  .'  |.' |/|_|MMMMoMMMMoM|_|! |`!  `,.|    |-._|     88\n");
//     printf("88  _!`'|     !.'|  .'| .'|[@]MMMMMMMMMMM[@] \|  `. | `._  |   `-._  88\n");
//     printf("88-'    |   .'   |.|  |/| /                 \|`.  |`!    |.|      |`-88\n");
//     printf("88      |_.'|   .' | .' |/                   \  \ |  `.  | `._-   |  88\n");
//     printf("88     .'   | .'   |/|  /                     \ |`!   |`.|    `.  |  88\n");
//     printf("88  _.'     !'|   .' | /                       \|  `  |  `.    |`.|  88\n");
//     printf("88 vanishing point 888888888888888888888888888888888888888888888(FL)888\n");
// }

void WelcomingAsrielGames();
/*Welcoming game Treasure Hunt*/

void AsrielGameRule();
/*print game rule buat treasure Hunt*/

void PrintPetaAsriel(Map MiniGames);
/*Print Peta permainan untuk game Treasure Hunt*/

void InsertMapMiniGames(Map *M, keytype k, valuetype v);
/*Insert atribut ke Map buat TreasureHunt*/

int mainasriel(char*Username);
/*Main Program Treasure Hunt*/

void asrielfight(int *score , char *Username);
/*Main Game Treasure Hunt*/