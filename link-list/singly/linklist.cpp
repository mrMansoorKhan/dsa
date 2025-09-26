#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

class list {
    struct node {
        int data;
        node *link;
    } *p;

public:
    void inslast(int);
    void insbeg(int);
    void delelement(int);
    void delbeg();
    void dellast();
    void disp();
    int seek(int);

    list() { p = NULL; }
    ~list();
};

void list::inslast(int x) {
    node *q, *t;
    if (p == NULL) {
        p = new node;
        p->data = x;
        p->link = NULL;
    } else {
        q = p;
        while (q->link != NULL)
            q = q->link;
        t = new node;
        t->data = x;
        t->link = NULL;
        q->link = t;
    }

    cout << "\nInserted Successfully at the end...";
    disp();
}

void list::insbeg(int x) {
    node *q;
    q = p;
    p = new node;
    p->data = x;
    p->link = q;
    cout << "\nInserted successfully at the beginning...";
    disp();
}

void list::delelement(int x) {
    node *q, *r;
    q = p;
    if (q == NULL) {
        cout << "\nList is empty!";
        return;
    }

    if (q->data == x) {
        p = q->link;
        delete q;
        return;
    }
    r = q;
    while (q != NULL) {
        if (q->data == x) {
            r->link = q->link;
            delete q;
            return;
        }
        r = q;
        q = q->link;
    }
    cout << "\nElement you entered " << x << " is not found..";
}

void list::delbeg() {
    cout << "\nThe list before deletion:";
    disp();
    node *q;
    q = p;
    if (q == NULL) {
        cout << "\nNo data is present..";
        return;
    }
    p = q->link;
    delete q;
    return;
}

void list::dellast() {
    cout << "\nThe list before deletion: ";
    disp();
    node *q;
    q = p;
    if (q == NULL) {
        cout << "\nThere is no data in the list..";
        return;
    }
    if (q->link == NULL) {
        p = q->link;
        delete q;
        return;
    }

    while (q->link->link != NULL)
        q = q->link;
    delete q->link;
    q->link = NULL;
    return;
}

list::~list() {
    node *q;
    if (p == NULL)
        return;

    while (p != NULL) {
        q = p->link;
        delete p;
        p = q;
    }
}

void list::disp() {
    node *q;
    q = p;
    if (q == NULL) {
        cout << "\nNo data is in the list..";
        return;
    }
    cout << "\nThe items present in the list are :";
    while (q != NULL) {
        cout << " " << q->data;
        q = q->link;
    }
    cout << endl;
}

int list::seek(int value) {
    node *temp;
    temp = p;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == value)
            return position + 1;
        else {
            temp = temp->link;
            position = position + 1;
        }
    }
    cout << " Element " << value << " Not Found";
    return 0;
}

int main() {
    list l;
    int ch, v, ps;

    do {
        cout << "\nOperations on List.. \n";
        cout << "\n1. Insertion\n2. Deletion\n3. Display\n4. Seek\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "\n1. Insertion at the beginning\n2. Insertion at the end";
            cout << "\nEnter your choice: ";
            cin >> ps;
            cout << "\nEnter the value to insert: ";
            cin >> v;

            switch (ps) {
            case 1:
                l.insbeg(v);
                break;
            case 2:
                l.inslast(v);
                break;
            default:
                cout << "\nThe choice is invalid..";
                return 0;
            }
            break;

        case 2:
            cout << "\n1. Delete the first element\n2. Delete the last element";
            cout << "\n3. Delete by value";
            cout << "\nEnter your choice: ";
            cin >> ps;

            switch (ps) {
            case 1:
                l.delbeg();
                cout << "\nThe list after deletion: ";
                l.disp();
                break;

            case 2:
                l.dellast();
                cout << "\nThe list after deletion: ";
                l.disp();
                break;

            case 3:
                l.disp();
                cout << "\nEnter the element to delete: ";
                cin >> v;
                l.delelement(v);
                cout << "\nThe list after deletion: ";
                l.disp();
                break;

            default:
                cout << "\nThe option is invalid..";
                break;
            }
            break;

        case 3:
            l.disp();
            break;

        case 4:
            l.disp();
            cout << "\nEnter the element to search: ";
            cin >> v;
            cout << "\nThe position of the element " << v << " is " << l.seek(v);
            break;

        case 5:
            exit(1);

        default:
            cout << "\nThe option is invalid..";
            return 0;
        }

        system("pause");

    } while (ch != 5);

    return 0;
}
