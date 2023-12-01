#include <stdio.h>
#include <stdlib.h>
#include "PlayerAndCar.h"
#include "macro.h"

/* Create and initialise linked list. */
LinkedList* createLinkedList()
{
    LinkedList* theList;
    
    theList = (LinkedList*)malloc(sizeof(LinkedList));
    theList->head = NULL;

    return theList;
}

/* Function that check whether the linked list is empty or not */
int isEmpty(LinkedList *tempList)
{
    int isEmpty;
    isEmpty = TRUE;

    if (tempList->head != NULL)
    {
        isEmpty = FALSE;
    }

    return isEmpty;
}

/* Function that insert new node inside the linked list */
void insertFirst(LinkedList *tempList, PlayerAndCar newData)
{
    LinkedListNode *newNode = (LinkedListNode*)malloc(sizeof(LinkedListNode));
    newNode->data = newData;
    newNode->next = tempList->head;
    tempList->head = newNode;
}

/* Function that remove the 1st node of the linked list */
PlayerAndCar removeFirst(LinkedList *tempList)
{
    LinkedListNode* temp;
    PlayerAndCar previousData;

    if ( isEmpty(tempList) == FALSE )
    {
        temp = tempList->head;
        previousData = temp->data;
        tempList->head = tempList->head->next;
        free(temp);
    }

    return previousData;
}

/* Frees the whole list. */
void freeLinkedList(LinkedList* thelist)
{
    freeNode(thelist->head);
    free(thelist);
}

/* Frees a given node and everything after it. */
void freeNode(LinkedListNode *node)
{
    if(node != NULL) {
        freeNode(node->next); /* Recursive call. */
        free(node);
    }
}
