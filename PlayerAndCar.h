#ifndef PLAYERANDCAR_H
#define PLAYERANDCAR_H

typedef struct{
    int playerRow;
    int playerCol;
    int carRow;
    int carCol;
    int goalRow;
    int goalCol;
    char direction;
} PlayerAndCar;

typedef struct LinkedListNode{
    PlayerAndCar data;
    struct LinkedListNode* next;
} LinkedListNode;

typedef struct {
    LinkedListNode* head; 
} LinkedList;

LinkedList* createLinkedList();
int isEmpty(LinkedList*);
void insertFirst(LinkedList*, PlayerAndCar);
PlayerAndCar removeFirst(LinkedList*);
void freeLinkedList(LinkedList*);
void freeNode(LinkedListNode*);

#endif
