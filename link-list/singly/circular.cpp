#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct node {
    int info;
    struct node *next;
} *p;

class circular_llist {
public:
    void create_node(int value);
    void add_after(int value, int position);
    void delete_element(int value);
    void display_list();
    circular_llist() {
        p = NULL;
    }
};

int main() {
    int choice, element, position;
    circular_llist cl;
    while (1) {
        cout << "1. Create Node" << endl;
        cout << "2. Add after" << endl;
        cout << "3. Delete" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the element: ";
            cin >> element;
            cl.create_node(element);
            cout << endl;
            break;
        case 2:
            cout << "Enter the element: ";
            cin >> element;
            cout << "Insert element after position: ";
            cin >> position;
            cl.add_after(element, position);
            cout << endl;
            break;
        case 3:
            if (p == NULL) {
                cout << "List is empty, nothing to delete" << endl;
                break;
            }
            cout << "Enter the element for deletion: ";
            cin >> element;
            cl.delete_element(element);
            cout << endl;
            break;
        case 4:
            cl.display_list();
            break;
        case 5:
            exit(0);
            break;
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}

// Insert Operation
void circular_llist::create_node(int value) {
    node *t;
    t = new node;
    t->info = value;
    if (p == NULL) {
        p = t;
        t->next = p;
    } else {
        t->next = p->next;
        p->next = t;
        p = t;
    }
}

void circular_llist::add_after(int value, int pos) {
    if (p == NULL) {
        cout << "First create the list." << endl;
        return;
    }
    node *t, *s;
    s = p->next;
    for (int i = 0; i < pos - 1; i++) {
        s = s->next;
        if (s == p->next) {
            cout << "There are less than " << pos << " elements in the list" << endl;
            return;
        }
    }
    t = new node;
    t->next = s->next;
    t->info = value;
    s->next = t;

    if (s == p) {
        p = t;
    }
}

// Delete Operation
void circular_llist::delete_element(int value) {
    node *t, *s;
    s = p->next;

    if (p->next == p && p->info == value) {
        t = p;
        p = NULL;
        delete t;
        return;
    }
    if (s->info == value) {
        t = s;
        p->next = s->next;
        delete t;
        return;
    }
    while (s->next != p) {
        if (s->next->info == value) {
            t = s->next;
            s->next = t->next;
            delete t;
            cout << "Element " << value << " deleted from the list" << endl;
            return;
        }
        s = s->next;
    }

    if (s->next->info == value) {
        t = s->next;
        s->next = p->next;
        delete t;
        p = s;
        return;
    }
    cout << "Element " << value << " not found in the list" << endl;
}

// Display List Operation
void circular_llist::display_list() {
    node *s;
    if (p == NULL) {
        cout << "List is empty" << endl;
        return;
    }
    s = p->next;
    cout << "Circular Link List: ";
    while (s != p) {
        cout << s->info << " -> ";
        s = s->next;
    }
    cout << s->info << endl;
    cout << endl;
}
