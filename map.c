#include <stdio.h>
#include <stdlib.h>
#include "PlayerAndCar.h"
#include "map.h"

/* Function pointer that return 2D mapArray */
char** createMapArray(int *mRow, int *mCol)
{
    int i;
    char** mArray;

    mArray = (char**)malloc(*mRow * sizeof(char*));
    
    for (i = 0; i < *mRow; i++)
    {
        mArray[i] = (char*)malloc(*mCol * sizeof(char));
    }

    return mArray;
}

/* Function that free 2D mapArray */
void freeMapArray(char **mArray, int *mRow)
{
    int i;

    for (i = 0; i < *mRow; i++)
    {
        free(mArray[i]);
    }

    free(mArray);
}

/* Function that update change of player and car position in map array */
void updateMap(PlayerAndCar *temp, char **mArray, int *mRow, int *mCol)
{
    int i, j;

    for (i = 0; i < *mRow; i++)
    {
        for (j = 0; j < *mCol; j++)
        {
            if (mArray[i][j] == '^' || mArray[i][j] == '>' || mArray[i][j] == 'v' || mArray[i][j] == '<' )
            {
                mArray[i][j] = '.';
            }
            else
            {
                mArray[i][j] = ' ';
            }
        }
    }

    for (i = 0; i < *mRow; i++)
    {
        for (j = 0; j < *mCol; j++)
        {
            if (i == temp->playerRow && j == temp->playerCol)
            {
                mArray[i][j] = 'P';
            }
            else if (i == temp->goalRow && j == temp->goalCol)
            {
                mArray[i][j] = 'G';
            }
            else if (i == temp->carRow && j == temp->carCol)
            {
                mArray[i][j] = temp->direction;
            }
            else if (mArray[i][j] == 'P' || mArray[i][j] == 'G' || mArray[i][j] == '^' 
                || mArray[i][j] == '>' || mArray[i][j] == 'v' || mArray[i][j] == '<' )
            {
                mArray[i][j] = '.';
            }
            else
            {
                mArray[i][j] = ' ';
            }
        }
    }
}

/* Function that print map array to terminal */
void printMap(PlayerAndCar *temp, char **mArray, int *mRow, int *mCol)
{
    int i, j;

    for (i = -1; i <= *mRow; i++)
    {
        for (j = -1; j <= *mCol; j++)
        {
            if ( (i == -1 || i == *mRow) || (j == -1 || j == *mCol) )
            {
                printf("*");
            }
            else if (i == temp->playerRow && j == temp->playerCol)
            {
                printf("P");
            }
            else if (i == temp->carRow && j == temp->carCol)
            {
                printf("%c", temp->direction);
            }
            
            else
            {
                printf("%c", mArray[i][j]);
            }
        }

        printf("\n");
    }

    printf("Press w to move up\n");
    printf("Press s to move down\n");
    printf("Press a to move left\n");
    printf("Press d to move right\n");
    printf("Press u to undo\n");
}
