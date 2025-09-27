#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    int priority;
    node *next;
};

node *front = NULL;

class PriorityQueue {
public:
    void insert(int d, int p);
    void del();
    void display();
};

// Insert element into priority queue
void PriorityQueue::insert(int d, int p) {
    node *t = new node;
    t->data = d;
    t->priority = p;
    t->next = NULL;

    if (front == NULL || p < front->priority) {
        // insert at beginning if higher priority
        t->next = front;
        front = t;
    } else {
        node *q = front;
        while (q->next != NULL && q->next->priority <= p) {
            q = q->next;
        }
        t->next = q->next;
        q->next = t;
    }

    cout << "Inserted " << d << " with priority " << p << endl;
}

// Delete element (highest priority first)
void PriorityQueue::del() {
    if (front == NULL) {
        cout << "Priority Queue Underflow (empty)" << endl;
        return;
    }
    node *t = front;
    cout << "Deleted element: " << t->data << " with priority " << t->priority << endl;
    front = front->next;
    delete t;
}

// Display priority queue
void PriorityQueue::display() {
    if (front == NULL) {
        cout << "Priority Queue is empty" << endl;
        return;
    }
    node *q = front;
    cout << "Priority Queue: " << endl;
    while (q != NULL) {
        cout << "[Value: " << q->data << ", Priority: " << q->priority << "] ";
        q = q->next;
    }
    cout << endl;
}

int main() {
    PriorityQueue pq;
    int choice, value, pr;

    while (1) {
        cout << "\n1. Insert\n2. Delete\n3. Display\n4. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                cout << "Enter priority (lower number = higher priority): ";
                cin >> pr;
                pq.insert(value, pr);
                break;
            case 2:
                pq.del();
                break;
            case 3:
                pq.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong choice!" << endl;
        }
    }

    return 0;
}
