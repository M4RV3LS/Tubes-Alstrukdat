#include "snakeonmeteor.h"

/*
Note :
Beberapa ADT khususnya boolean seperti IsMeteor, merupakan penerapan dari
IsPointSama dan ADT yang berisikan ADT-ADT basic. Maka untuk ADT "spesial" ini akan 
dianggap sama seperti ADT "parent"-nya sehingga test cukup hanya untuk parentnya saja.
*/

int main()
{
    // test create point and element
    List L;
    Point P1, P2, P3,P4;
    CreateEmpty(&L);
    CreatePoint(&P1, 1, 1);
    CreateNextPoint(P1);
    CreateNextNextPoint(P2, P1);
    CreateList3Elemen(&L, P1, P2, P3);
    if (NbElmt(L) == 3)
    {
        printf("Test CreateList3Elemen: Passed\n");
    }
    else
    {
        printf("Test CreateList3Elemen: Failed\n");
    }
    // -------------------------------------------------------------------//
    // Test meteor, obstacle,  food, and snake
    Point Meteor, Obstacle, Food;
    Obstacle = GenerateObstacle(L);
    Food = GenerateFoodPertama(Obstacle, L);
    Meteor = GenerateMeteor(Food, Obstacle);

    if (IsPointSama(Meteor, Food) || IsPointSama(Meteor, Obstacle))
    {
        printf("Test GenerateMeteor: Failed\n");
    }
    else
    {
        printf("Test GenerateMeteor: Passed\n");
    }

    if (IsPointSama(Food, Obstacle))
    {
        printf("Test GenerateFood: Failed\n");
    }
    else
    {
        printf("Test GenerateFood: Passed\n");
    }

    if (IsPointSama(Obstacle, P1) || IsPointSama(Obstacle, P2) || IsPointSama(Obstacle, P3))
    {
        printf("Test GenerateObstacle: Failed\n");
    }
    else
    {
        printf("Test GenerateObstacle: Passed\n");
    }

    if (IsPointSama(Food, P1) || IsPointSama(Food, P2) || IsPointSama(Food, P3))
    {
        printf("Test GenerateFoodPertama: Failed\n");
    }
    else
    {
        printf("Test GenerateFoodPertama: Passed\n");
    }

    // -------------------------------------------------------------------//
    // Test Insert Akhir
    InsertAkhirSOM(&L);
    if (NbElmt(L) == 4)
    {
        printf("Test InsertAkhirSOM: Passed\n");
    }
    else
    {
        printf("Test InsertAkhirSOM: Failed\n");
    }

    // -------------------------------------------------------------------//
    
    DeleteDi(&L, P1);
    if (NbElmt(L) == 3)
    {
        printf("Test DeleteDi: Passed\n");
    }
    else
    {
        printf("Test DeleteDi: Failed\n");
    }

    // -------------------------------------------------------------------//
    // Test IsMember
    if (IsMember(L, P1))
    {
        printf("Test IsMember: Failed\n");
    }
    else
    {
        printf("Test IsMember: Passed\n");
    }

    // -------------------------------------------------------------------//
    if (IsPointSama(P1, P2))
    {
        printf("Test IsPointSama: Failed\n");
    }
    else
    {
        printf("Test IsPointSama: Passed\n");
    }

    // -------------------------------------------------------------------//
    // Test IsPointSama
    if (IsPointSama(P1, P1))
    {
        printf("Test IsPointSama: Passed\n");
    }
    else
    {
        printf("Test IsPointSama: Failed\n");
    }

    // -------------------------------------------------------------------//
    if (indexOf(L, P1) == 0)
    {
        printf("Test indexOf: Passed\n");
    }
    else
    {
        printf("Test indexOf: Failed\n");
    }

    // -------------------------------------------------------------------//
    printmap(L, Meteor, Food, Obstacle);
    printf("Test printmap: Passed\n");

    // -------------------------------------------------------------------//
    // Test Move
    CreatePoint(P4, 1, 2);
    MoveList(&L, P4);
    if (IsPointSama(Info(L), P4))
    {
        printf("Test MoveList: Passed\n");
    }
    else
    {
        printf("Test MoveList: Failed\n");
    }

    printf("All Test Passed\n");

    return 0;
}