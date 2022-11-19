#include <stdio.h>
#include "snakeonmeteor.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

int SnakeOnMeteor(){
    List L;
    CreateEmpty(L);
    int X = randint(0,4);
    int Y = randint(0,4);
    
    CreatePoint(Point P1, X, Y);
    Point P2 = CreateNextPoint(P1);
    Point P3 = CreateNextPoint(P2);

    

}