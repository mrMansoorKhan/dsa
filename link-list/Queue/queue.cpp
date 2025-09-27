#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    node *link;
};

node *p, *r; // front (p) and rear (r) pointers

class queue_list {
public:
    void insert(int);
    void del();
    void display();
    queue_list() {
        p = NULL;
        r = NULL;
    }
};

int main() {
    int choice, x;
    queue_list ql;

    while (1) {
        cout << "\n";
        cout << "1. Insert Element into the Queue" << endl;
        cout << "2. Delete Element from the Queue" << endl;
        cout << "3. Display the Queue" << endl;
        cout << "4. Quit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> x;
                ql.insert(x);
                break;
            case 2:
                ql.del();
                break;
            case 3:
                ql.display();
                break;
            case 4:
                exit(0);
            default:
                cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}

// Insert element into queue
void queue_list::insert(int x) {
    node *t = new node;
    t->data = x;
    t->link = NULL;

    if (p == NULL) { // first element
        p = t;
        r = t;
    } else {
        r->link = t;
        r = t;
    }
    cout << x << " inserted into queue" << endl;
}

// Delete element from queue
void queue_list::del() {
    if (p == NULL) {
        cout << "Queue Underflow (empty)" << endl;
        return;
    }

    node *q = p;
    cout << "Element Deleted: " << q->data << endl;
    p = p->link;
    delete q;

    if (p == NULL) // if queue becomes empty, reset rear
        r = NULL;
}

// Display queue
void queue_list::display() {
    if (p == NULL) {
        cout << "Queue is empty" << endl;
        return;
    }

    cout << "Queue elements: ";
    node *q = p;
    while (q != NULL) {
        cout << q->data << " ";
        q = q->link;
    }
    cout << endl;
}
