#include <stdio.h>
#include <stdlib.h>
#include "PlayerAndCar.h"
#include "car.h"
#include "macro.h"
#include "random.h"

/* Funtion that assign car direction in struct PlayerAndCar*/
char randomDirection(PlayerAndCar *temp, char **mArray)
{
    int randomNum;
    char direction;
    initRandom();

    /* While iteration is undergo until suitable random value is generated */
    do
    {
        randomNum = randomGenerator(1, 4);
    } while (checkRandomNum(temp, mArray, randomNum) == FALSE);

    /*  If the car direction is 1, direction will face north.
        If the car direction is 2, direction will face east.
        If the car direction is 3, direction will face south.
        If the car direction is 4, direction will face west.    */
    switch(randomNum)
    {
        case 1:
            direction = '^';
            break;
        case 2:
            direction = '>';
            break;
        case 3:
            direction = 'v';
            break;
        default:
            direction = '<';
            break;
    }

    return direction;
}

/* Funtion that check the random number of car direction is valid or not*/
int checkRandomNum(PlayerAndCar *temp, char **mArray, int randomNum)
{
    int validDirection, i, j;

    validDirection = TRUE;
    i = temp->carRow;
    j = temp->carCol;

    /*  If there is only one path in horizontal, the random number generated must be face east or west.
        If there is only one path in vertical, the random number generated must be face north or south.   */
    if (mArray[i-1][j] == '.' && mArray[i+1][j] == '.' && mArray[i][j-1] == ' ' && mArray[i][j+1] == ' ')
    {
        if (randomNum == 2 || randomNum == 4)
        {
            validDirection = FALSE;
        }
    }
    else if (mArray[i][j-1] == '.' && mArray[i][j+1] == '.' && mArray[i-1][j] == ' ' && mArray[i+1][j] == ' ')
    {
        if (randomNum == 1 || randomNum == 3)
        {
            validDirection = FALSE;
        }
    }
    
    return validDirection;
}

/* Function that update the car position and direction inside struct PlayerAndCar */
void updateCarDirection(PlayerAndCar *temp, char **mArray)
{
    char direction;
    int i, j;

    direction = temp->direction;
    i = temp->carRow;
    j = temp->carCol;

    if (direction == '^')
    {
        if (mArray[i-1][j] == '.')
        {
            temp->carRow = i - 1;
        }
        else if (mArray[i][j+1] == '.')
        {
            temp->carCol = j + 1;
            temp->direction = '>';
        }
        else if (mArray[i][j-1] == '.')
        {
            temp->carCol = j - 1;
            temp->direction = '<';
        }
    }
    else if (direction == '>')
    {
        if (mArray[i][j+1] == '.')
        {
            temp->carCol = j + 1;
        }
        else if (mArray[i-1][j] == '.')
        {
            temp->carRow = i - 1;
            temp->direction = '^';
        }
        else if (mArray[i+1][j] == '.')
        {
            temp->carRow = i + 1;
            temp->direction = 'v';
        }
    }
    else if (direction == 'v')
    {
        if (mArray[i+1][j] == '.')
        {
            temp->carRow = i + 1;
        }
        else if (mArray[i][j+1] == '.')
        {
            temp->carCol = j + 1;
            temp->direction = '>';
        }
        else if (mArray[i][j-1] == '.')
        {
            temp->carCol = j - 1;
            temp->direction = '<';
        }
    }
    else if (direction == '<')
    {
        if (mArray[i][j-1] == '.')
        {
            temp->carCol = j - 1;
        }
        else if (mArray[i+1][j] == '.')
        {
            temp->carRow = i + 1;
            temp->direction = 'v';
        }
        else if (mArray[i-1][j] == '.')
        {
            temp->carRow = i - 1;
            temp->direction = '^';
        }
    }
}

/* Function that check whether there is clash between player and car */
int checkAccident(PlayerAndCar *temp)
{
    int accident = FALSE;

    if (ISEQUAL(temp->playerRow, temp->playerCol, temp->carRow, temp->carCol))
    {
        accident = TRUE;
    }

    return accident;
}
