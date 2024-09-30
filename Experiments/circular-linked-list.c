#include<stdio.h>
#include<malloc.h>

struct Node{
    int data;
    struct Node *next;
};

void insertAtBeginning(struct Node **start, int data re)

void insertAtEnd(struct Node **start, int data){
    struct Node *newNode = createNode(data);
    if(*start == NULL){
        *start = newNode;
        newNode->next = *start;
    }
    else{
        struct Node *lastNode = *start;
        while (lastNode->next != *start){
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->next = *start;
    }
};


int main(){
    struct Node *start = NULL;

    //Insertion
    insertAtEnd(&start, 10);
    insertAtEnd(&start, 20);
    insertAtBeginning(&start, 5);
    insertAtPosition(&start, 15, 2);
}