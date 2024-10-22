#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to traverse and print the circular linked list
void traverse(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    printf("Inserting %d at the beginning.\n", data);
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;  // Point to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
    printf("Current List: ");
    traverse(*head);
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    printf("Inserting %d at the end.\n", data);
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;  // Point to itself
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Current List: ");
    traverse(*head);
}

// Function to insert a node at a specific position
void insertAtPosition(struct Node** head, int data, int position) {
    printf("Inserting %d at position %d.\n", data, position);
    if (position == 0) {
        insertAtBeginning(head, data);
        return;
    }

    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct Node* temp = *head;
        int i = 0;
        while (i < position - 1 && temp->next != *head) {
            temp = temp->next;
            i++;
        }
        if (i != position - 1) {
            printf("Position out of bounds. Node will be inserted at the end.\n");
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    printf("Current List: ");
    traverse(*head);
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    printf("Deleting node from the beginning.\n");
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    if ((*head)->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        struct Node* last = *head;
        while (last->next != *head) {
            last = last->next;
        }
        last->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
    }
    printf("Current List: ");
    traverse(*head);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    printf("Deleting node from the end.\n");
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    if ((*head)->next == *head) {
        free(temp);
        *head = NULL;
    } else {
        struct Node* prev = NULL;
        while (temp->next != *head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = *head;
        free(temp);
    }
    printf("Current List: ");
    traverse(*head);
}

// Function to delete a node from a specific position
void deleteAtPosition(struct Node** head, int position) {
    printf("Deleting node at position %d.\n", position);
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (position == 0) {
        deleteFromBeginning(head);
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;
    int i = 0;

    while (i < position && temp->next != *head) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    if (i != position) {
        printf("Position out of bounds. No node deleted.\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Current List: ");
    traverse(*head);
}

// Function to search for a node with a given key
int search(struct Node* head, int key) {
    if (head == NULL) {
        return 0;
    }
    struct Node* temp = head;
    do {
        if (temp->data == key) {
            return 1;  // Key found
        }
        temp = temp->next;
    } while (temp != head);
    return 0;  // Key not found
}

// Driver program
int main() {
    struct Node* head = NULL;

    // Insertion
    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtBeginning(&head, 5);
    insertAtPosition(&head, 15, 2);

    // Deletion
    deleteFromEnd(&head);
    deleteAtPosition(&head, 1);

    // Searching
    int key = 10;
    printf("Searching for %d.\n", key);
    if (search(head, key)) {
        printf("Element %d is found in the linked list.\n", key);
    } else {
        printf("Element %d is not found in the linked list.\n", key);
    }

    return 0;
}
/*
Output: 
PS C:\Users\gagan\Documents\Data_Structure_And_Algorithm\Experiments> cd "c:\Users\gagan\Documents\Data_Structure_And_Algorithm\Experiments\" ; if ($?) { gcc circular-linked-list.c -o circular-linked-list } ; if ($?) { .\circular-linked-list }
Inserting 10 at the end.
Current List: 10 -> HEAD
Inserting 20 at the end.
Current List: 10 -> 20 -> HEAD
Inserting 5 at the beginning.
Current List: 5 -> 10 -> 20 -> HEAD
Inserting 15 at position 2.
Current List: 5 -> 10 -> 15 -> 20 -> HEAD
Deleting node from the end.
Current List: 5 -> 10 -> 15 -> HEAD
Deleting node at position 1.
Current List: 5 -> 15 -> HEAD
Searching for 10.
Element 10 is not found in the linked list.
*/