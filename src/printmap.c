#include <stdio.h>
#include "ADT/SnakeOnMeteor/snakeonmeteor.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

void printmap(List L, POINT M, POINT F)
{
    int i,j;
    POINT S;
    for(i = 0; i < 11; i++)
    {
        for(j = 0; j < 11; j++)
        {
            
            if(i % 2 == 0)
            {
                if (j % 2 == 0)
                {
                    printf(" ");
                }
                else 
                {
                    printf("---");
                }
            }
            
            else 
            {
                if(j % 2 == 0)
                {
                    printf("|");
                }
                
                else 
                {
                    S.x = j/2;
                    S.y = i/2;
                    if(Search(L,S)!=Nil)
                    {
                        if(M.x == S.x && M.y == S.y){
                            printf(" m ");
                        }
                        else {
                            printf(" %c ", Search(L,S)->info);
                        }
                        
                    }
                    
                    else 
                    {
                        if(F.x == S.x && F.y == S.y)
                        {
                            printf(" o ");
                        }
                        else if(M.x == S.x && M.y == S.y)
                        {
                            printf(" m ");
                        }
                        else 
                        {
                            printf("   ");
                        }
                    }
                    
                    
                }
            }
        }
        printf("\n");
    }
}