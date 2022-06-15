#include<stdio.h>
#include<stdlib.h>

#define size 5
int queue[size];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1 && rear == -1);
}

int isFull() {
    return ((rear+1)%size == front);
}

void enqueue(int item) {
    if(isEmpty()) {
        front = rear = 0;
        queue[rear] = item;
    }
    else if(isFull()) printf("Queue is Full!\n");
    else {
        rear = (rear+1)%size;
        queue[rear] = item;
    }
}

void dequeue() {
    if(isEmpty()) printf("Nothing to dequeue...\n");
    else {
        int temp = front;
        printf("Dequeued Element is : %d\n", queue[temp]);
        ++front;
    }
}

void display() {
    if(isEmpty()) printf("Nothing in the queue\n");
    else {
        int i = front;
        printf("Queue is : ");
        while(i != rear) {
            printf("%d ", queue[i]);
            i = (i+1)%size;
        }
        printf("%d", queue[rear]);
        printf("\n");
    }
}

void peek() {
    if(isEmpty()) printf("Nothing in the queue\n");
    else printf("Front value of the queue : %d\n", queue[front]);
}

int main() {
    
    enqueue(5);
    enqueue(4);
    enqueue(3);
    enqueue(2);
    enqueue(1);
    display();
    dequeue();
    display();
    enqueue(6);
    dequeue();
    enqueue(7);
    display();
    peek();

    return 0;
}

/*

Output:

Queue is : 5 4 3 2 1
Dequeued Element is : 5
Queue is : 4 3 2 1
Dequeued Element is : 4
Queue is : 3 2 1 6 7
Front value of the queue : 3

*/

