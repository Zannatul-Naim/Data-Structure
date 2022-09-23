#include<iostream>

using namespace std;

class Stack {
    public:
        int MAX = 100;
        int top = -1;
        int stack[100];

    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX-1;
    }

    void pop() {
        if(isEmpty()) cout << "Stack UnderFlow!" << endl;
        else {
            cout << "Poped : " << stack[top] << endl;
            --top;
        }
    }

    void push(int item) {
        if(isFull()) cout << "Stack Overflow!" << endl;
        else {
            stack[++top] = item;
        }
    }

    void display() {
        cout << "Elements of Stacks : ";
        for(int i = top; i >= 0; i--) cout << stack[i] << " ";
        cout << endl;
    }

    int getSize() {
        return top;
    }
};

int main() {
    Stack stack;

    for(int i = 10; i >= 1; i--) stack.push(i);

    stack.display();

    stack.pop();

    stack.display();

    cout << "Size of Stack : " << stack.getSize() << endl;

    return 0;
}
