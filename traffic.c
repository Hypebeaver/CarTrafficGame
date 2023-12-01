#include <stdio.h>
#include <stdlib.h>
#include "PlayerAndCar.h"
#include "car.h"
#include "fileIO.h"
#include "map.h"
#include "macro.h"
#include "terminal.h"
#include "move.h" 

int main(int argc, char* argv[])
{
    PlayerAndCar playerAndCar;
    LinkedList* list;
    int mapRow, mapCol, accident;
    char** mapArray;
    char enter;

    /* Read and get row and column of the map from a file */
    readRowAndColumn(argv, &mapRow, &mapCol);

    /* Create mapArray */
    mapArray = createMapArray(&mapRow, &mapCol);

    /* Read and import map data from a file into mapArray */
    readFile(argv, &playerAndCar, mapArray);

    /* Create linkedlist */
    list = createLinkedList();

    /* Assign and initialise accident as FALSE before traffic game program start */
    accident = FALSE;

    system("clear");

    /* Display and print the map to the user */
    printMap(&playerAndCar, mapArray, &mapRow, &mapCol);

    /* While iteration undergo unitl player and goal position is equal or accident is TRUE */
    while ( ISEQUAL(playerAndCar.playerRow, playerAndCar.playerCol, playerAndCar.goalRow, playerAndCar.goalCol) == FALSE 
            && accident == FALSE )
    {
        disableBuffer();
        scanf(" %c", &enter);
        enableBuffer();

        /* Player and cars postion will be updated by the user enter inside the map */
        if (enter == 'w' || enter == 'a' || enter == 's' || enter == 'd')
        {
            insertFirst(list, playerAndCar);
            move(&playerAndCar, &enter, &mapRow, &mapCol);
            updateCarDirection(&playerAndCar, mapArray);
        }
        else if (enter == 'u') 
        {
            /* If statement is used if the linkedlist is empty insetFirst() function will call to save the initial progress of the traffic */
            if (isEmpty(list) == FALSE)
            {
                playerAndCar = removeFirst(list);
            }
            else
            {
                insertFirst(list, playerAndCar);
            }
        }

        /* If statements used to undergo checkAccident() function to check whether there is clash of player and car*/
        if (checkAccident(&playerAndCar))
        {
            accident = TRUE;
        }

        system("clear");

        /* Display and print the map to the user */
        printMap(&playerAndCar, mapArray, &mapRow, &mapCol);
    }
    
    /* If statments are used to differentiate whether the player win or lose */
    if (accident == TRUE)
    {
        printf("You lose!\n");
    }
    else if (ISEQUAL(playerAndCar.playerRow, playerAndCar.playerCol, playerAndCar.goalRow, playerAndCar.goalCol))
    {
        printf("You win!\n");
    }

    /* free memory of mapArray */
    freeMapArray(mapArray, &mapRow);

    /* Frees the whole list. */
    freeLinkedList(list);

    return 0;
}
