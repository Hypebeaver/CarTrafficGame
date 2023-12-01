#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PlayerAndCar.h"
#include "fileIO.h"
#include "car.h"

/* Function that read the row and column value of the map array */
void readRowAndColumn(char *argv[], int *mRow, int *mCol)
{
    FILE* file;
    char line[10];
    char* ch;
    
    file = fopen(argv[1], "r");
    
    if (file == NULL)
    {
        printf("Error: could not open %s\n", argv[1]);
    }
    else
    {
        fgets(line, 10, file);
        ch = strtok(line, " ");
        *mRow = atoi(ch);

        ch = strtok(NULL, " ");
        *mCol = atoi(ch);
    }

    fclose(file);
}

/* Function that read thre map data and import into the map array and struct PlayerAndCar */
void readFile(char *argv[], PlayerAndCar *tempPAC, char **mArray)
{
    FILE* file;
    char line[100];
    char* ch;
    int i, j;

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        printf("Error: could not open %s\n", argv[1]);
    }
    else
    {
        /* Skip the first line */
        fgets(line, 100, file);
        
        for (i = 0; fgets(line, 100, file) != NULL; i++)
        {
            ch = strtok(line, " ");

            for (j = 0; ch != NULL; j++)
            {
                if (*ch == '0')
                {
                    mArray[i][j] = ' ';
                }
                else if (*ch == '1')
                {
                    mArray[i][j] = '.';
                }
                else if (*ch == '2')
                {
                    tempPAC->carRow = i;
                    tempPAC->carCol = j;
                    mArray[i][j] = '.';
                }
                else if (*ch == '3')
                {
                    tempPAC->playerRow = i;
                    tempPAC->playerCol = j;
                    mArray[i][j] = ' ';
                }
                else 
                {
                    tempPAC->goalRow = i;
                    tempPAC->goalCol = j;
                    mArray[i][j] = 'G';
                }
                
                ch = strtok(NULL, " ");
            }
        }

        tempPAC->direction = randomDirection(tempPAC, mArray);
    }

    fclose(file);
}
