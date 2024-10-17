#include<stdio.h>
#include<malloc.h>


// Node structure
struct Node{
    int data;
    struct Node *next;
};

// Function to create a new node 
struct Node *creatNode(int value){
    
    // Allocate memory 
    struct Node *newNode =
    (struct Node*)malloc(sizeof(struct Node));

    // Set the data
    newNode->data = value;

    // Initialize next to NULL 
    newNode->next = NULL;

    // Return the new node 
    return newNode;
}

// Allocate memory for nodes
struct Node *first =
(struct Node *)malloc(sizeof(struct Node));
struct Node *second = 
(struct Nide *)malloc(sizeof(struct Node));
struct Node *last = 
(struct Node *)malloc(sizof(struct Node));

// Initialize nodes
first->data = 2;
second->data = 3;
last->data =  4;

// Connect nodes
first->next = second;
second->next = last;
last->next = first;