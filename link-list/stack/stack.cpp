#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

node *top = NULL;  // stack top pointer

// push operation
void push(int x) {
    node *t = new node;
    t->data = x;
    t->next = top;
    top = t;
    cout << x << " pushed onto stack" << endl;
}

// pop operation
int pop() {
    if (top == NULL) {
        cout << "Stack is empty!" << endl;
        return -1;  // special value
    }
    int x = top->data;
    node *temp = top;
    top = top->next;
    delete temp;
    return x;
}

// display stack
void display() {
    if (top == NULL) {
        cout << "Stack is empty!" << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    node *q = top;
    while (q != NULL) {
        cout << q->data << " ";
        q = q->next;
    }
    cout << endl;
}

int main() {
    int choice, value;
    while (true) {
        cout << "\n1. Push\n2. Pop\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> value;
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1)
                    cout << "Popped: " << value << endl;
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}