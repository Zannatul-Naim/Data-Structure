#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data; 
   struct Node * next;
} *head;

typedef struct Node node;

void display() {
    node * temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void insertFirst(int item) {
    node * newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode->data = item;
    newNode->next = head;
    head = newNode;
}

void insertLast(int item) {
    node * newNode;
    newNode = (node*) malloc(sizeof(node));
    newNode-> data = item;
    newNode->next = NULL;

    if(head == NULL) head = newNode;
    else {
        node * temp = head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }

}

int main()
{
    insertLast(565);
    insertLast(566);
    insertLast(567);
    insertFirst(564);
    insertFirst(563);
    display();
   
    return 0;
}
