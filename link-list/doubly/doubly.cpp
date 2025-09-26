#include <iostream>
#include <cstdlib>
using namespace std;

struct node {
    int data;
    node *next;
    node *prev;
} *p;

class double_llist {
public:
    void create_list(int value);
    void add_begin(int value);
    void add_after(int value, int position);
    void delete_element(int value);
    void display_dlist();
    double_llist() {
        p = NULL;
    }
};

int main() {
    int choice, element, position;
    double_llist dl;
    while (1) {
        cout << endl;
        cout << "1. Insert" << endl;
        cout << "2. Add after" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "6. Add beginning" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
        case 1:
            cout << "Enter the element: ";
            cin >> element;
            dl.create_list(element);
            cout << endl;
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> element;
            cout << "Insert element after position: ";
            cin >> position;
            dl.add_after(element, position);
            cout << endl;
            break;
        case 3:
            if (p == NULL) {
                cout << "List empty, nothing to delete" << endl;
                break;
            }
            cout << "Enter the element for deletion: ";
            cin >> element;
            dl.delete_element(element);
            cout << endl;
            break;
        case 4:
            dl.display_dlist();
            cout << endl;
            break;
        case 5:
            exit(0);
        case 6:
            cout << "Enter the element: ";
            cin >> element;
            dl.add_begin(element);
            cout << endl;
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

// Create new node at end
void double_llist::create_list(int value) {
    node *q, *t;
    t = new node;
    t->data = value;
    t->next = NULL;
    if (p == NULL) {
        t->prev = NULL;
        p = t;
    } else {
        q = p;
        while (q->next != NULL) {
            q = q->next;
        }
        q->next = t;
        t->prev = q;
    }
}

// Add node at beginning
void double_llist::add_begin(int value) {
    node *t = new node;
    t->data = value;
    t->prev = NULL;
    t->next = p;
    if (p != NULL) {
        p->prev = t;
    }
    p = t;
    cout << "Element Inserted at beginning" << endl;
}

// Add node after given position
void double_llist::add_after(int value, int pos) {
    if (p == NULL) {
        cout << "List is empty. First create the list." << endl;
        return;
    }
    node *q = p;
    for (int i = 0; i < pos - 1 && q != NULL; i++) {
        q = q->next;
    }
    if (q == NULL) {
        cout << "There are less than " << pos << " elements." << endl;
        return;
    }
    node *tmp = new node;
    tmp->data = value;
    tmp->next = q->next;
    tmp->prev = q;
    if (q->next != NULL) {
        q->next->prev = tmp;
    }
    q->next = tmp;
    cout << "Element Inserted" << endl;
}

// Delete node by value
void double_llist::delete_element(int value) {
    node *q = p;
    while (q != NULL && q->data != value) {
        q = q->next;
    }
    if (q == NULL) {
        cout << "Element " << value << " not found" << endl;
        return;
    }
    if (q->prev != NULL) {
        q->prev->next = q->next;
    } else {
        p = q->next;
    }
    if (q->next != NULL) {
        q->next->prev = q->prev;
    }
    delete q;
    cout << "Element Deleted" << endl;
}

// Display list
void double_llist::display_dlist() {
    node *q = p;
    if (p == NULL) {
        cout << "List empty" << endl;
        return;
    }
    cout << "The Doubly Linked List is: ";
    while (q != NULL) {
        cout << q->data << " <-> ";
        q = q->next;
    }
    cout << "NULL" << endl;
}
