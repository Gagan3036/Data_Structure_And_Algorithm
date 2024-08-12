#include <stdio.h>
#define max 100

int queue[max];
int front = -1, rear = -1;

void insert(void);
int delete(void);
int peek(void);
int display(void);

int main()
{
    int op;

    do{
        printf("\nMenu");
        printf("\n1.Insert\n2.Delete\n3.Peek\n4.Display");
        printf("\nEnter your choice: ");
        scanf("%d",&op);

        switch(op){
            case 1:
            insert();
            break;

            case 2:
            delete();
            break;

            case 3:
            peek();
            break;

            case 4:
            display();
            break;

            default:
            printf("\nInvalid Input\n");
        }
    }
    while(op != 5);

    return 0;
}

void insert(){
    int val;

    if(rear == max - 1){
        printf("\nOverflow\n");
    }
    else if(front == - 1 && rear == -1){
        printf("\nEnter the element: ");
        scanf("%d",&val);
        front = 0;
        queue[++rear] = val;
    }
    else{
        printf("\nEnter the element: ");
        scanf("%d",&val);
        queue[++rear] = val;
    }
}

int delete(){
    int num;
    
    if(front == -1 || front > rear){
        printf("\nUnderflow\n");
        return -1;
    }
    else{
        num = queue[front];
        front++;
        printf("\nDeleted element: %d\n",num);
    }
    if(front > rear){
        front = rear = -1;
    }
}

int peek(){
    if(front == -1 || front > rear){
        printf("\nQueue is empty\n");
        return -1;
    }
    else{
        printf("\n%d\n",queue[front]);
    }
}

int display(){
    if(front == -1 && rear == -1){
        printf("\nQueue is empty\n");
        return -1;
    }
    for(int i=front; i<=rear; i++){
        printf("\n%d",queue[i]);
    }
    printf("\n");
}