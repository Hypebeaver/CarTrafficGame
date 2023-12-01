#include <stdio.h>
#include "PlayerAndCar.h"
#include "move.h"

/* Function that update the position of player within the map array and struct PlayerAndCar */
void move(PlayerAndCar *tempPAC, char* wasd, int* mRow, int* mCol)
{
    if (*wasd == 'w')
    {
        if (tempPAC->playerRow > 0)
        {
            tempPAC->playerRow = tempPAC->playerRow - 1;
        }
    }
    else if (*wasd == 'a')
    {
        if (tempPAC->playerCol > 0)
        {
            tempPAC->playerCol = tempPAC->playerCol - 1;
        }
    }
    else if (*wasd == 's')
    {
        if (tempPAC->playerRow < *mRow - 1)
        {
            tempPAC->playerRow = tempPAC->playerRow + 1;
        }
    }
    else if (*wasd == 'd')
    {
        if (tempPAC->playerCol < *mCol - 1)
        {
            tempPAC->playerCol = tempPAC->playerCol + 1;
        }
    }
}
