#include<stdio.h>
# define max 10

int queue[max];
int front = -1, rear = -1;

void insert();
int delete();
int peek();
void display();

int main(){
    int ch, val;

    do{
        printf("\nMenu\n1.Insert\n2.Delete\n3.peek\n4.Display\n5.Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch(ch){
            case 1: insert();
                    break;

            case 2: val = delete();
                    if(val != -1)
                        printf("\nThe deleted element is %d", val);
                    break;
            
            case 3: val = peek();
                    if(val != -1)
                        printf("\nThe topmost element is %d", val);
                    break;
            
            case 4: display();
                    break;
            
            case 5: return 0;
        }
    }
    while(ch != 5);

    return 0;
}

void insert(){
    int num;
    printf("\nEnter any number to be inserted in queue: ");
    scanf("%d", &num);

    if((front == 0 && rear == max-1) || (rear + 1 == front)){  // Check for circular overflow
        printf("\nOverflow");
    } 
    else if(front == -1 && rear == -1){  // First element case
        front = rear = 0;
        queue[rear] = num;
    }
    else if(rear == max-1 && front != 0){  // Wrap-around case
        rear = 0;
        queue[rear] = num;
    }
    else{  // Normal insertion
        rear++;
        queue[rear] = num;
    }
}

int delete(){
    int val;

    if(front == -1){  // Queue empty
        printf("\nUnderflow");
        return -1;
    }

    val = queue[front];

    if(front == rear){  // Only one element in queue
        front = rear = -1;
    }
    else if(front == max-1){  // Wrap-around case
        front = 0;
    }
    else{
        front++;
    }

    return val;
}

int peek(){
    if(front == -1){
        printf("\nQueue is empty");
        return -1;
    }
    return queue[front];
}

void display(){
    if(front == -1){
        printf("\nQueue is empty");
    }
    else{
        printf("\nQueue elements: ");
        if(front <= rear){  // Normal case
            for(int i = front; i <= rear; i++){
                printf("%d ", queue[i]);
            }
        }
        else{  // Wrap-around case
            for(int i = front; i < max; i++){
                printf("%d ", queue[i]);
            }
            for(int i = 0; i <= rear; i++){
                printf("%d ", queue[i]);
            }
        }
        printf("\n");
    }
}