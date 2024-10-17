#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void deleteAfterNode(struct Node* prev_node){
    // chack the next node existence 
    if(prev_node == NULL || prev_node->next == NULL){
        printf("Next node not exist");
        return;
    }
    else{
        struct Node* temp = prev_node->next;
        
        prev_node->next = temp->next;

        free(temp);
    }

}