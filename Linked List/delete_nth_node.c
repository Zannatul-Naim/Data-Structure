#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
}*head;
typedef struct Node node;

node * getNode() {
    node * temp;
    temp = (node*) malloc(sizeof(node));

    return temp;
}

void insert(int item) {
    node * temp = getNode();

    temp -> data = item;
    temp -> next = NULL;

    if(head == NULL) head = temp;
    
    else {
        node * curr_node = head;

        while(curr_node -> next != NULL) curr_node = curr_node -> next;
        curr_node -> next = temp;
    }
}

void delete_nth_node(int pos) {
    if(pos == 0 && head != NULL) {
        head = head -> next;
    }
    else {
        node * curr_node = head;
        node * prev;
        while(--pos) {
            prev = curr_node;
            curr_node = curr_node -> next;
        }
        int deleted = curr_node -> data;
        printf("%d node deleted...\n", deleted);
        prev -> next = curr_node -> next;
    }
}

void show() {
    node * temp = head;

    while(temp != NULL) {
        printf("%d ", temp -> data);
        temp = temp -> next;
    }
    printf("\n");
}

int getCurrentSize() {
    node * temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp -> next;
    }
    return count;
}

int main() 
{
    int size;

    for(int i = 1; i <= 10; i++) insert(i);
    show();
    
    size = getCurrentSize();
    printf("Current size: %d\n", size);

    delete_nth_node(5);
    show();

    size = getCurrentSize();
    printf("Current size: %d\n", size);

    return 0;
}
