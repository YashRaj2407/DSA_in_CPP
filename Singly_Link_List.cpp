#include <iostream>
using namespace std;

// Node class for linked list
class Node {
public:
    int Data;
    Node *next;

    Node(int val) {
        Data = val;
        next = NULL;
    }
};

// Singly Linked List class
class SLL {
public:
    Node *head;
    Node *tail;

    SLL() {
        head = NULL;
        tail = NULL;
    }

    // Insert at beginning
    void insert_begin(int val) {
        Node *newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
            return;
        }
        newnode->next = head;
        head = newnode;
    }

    // Insert at end
    void insert_end(int val) {
        Node *newnode = new Node(val);
        if (head == NULL) {
            head = tail = newnode;
            return;
        }
        tail->next = newnode;
        tail = newnode;
    }

    // Insert at a given position (0-based index)
    void insert_mid(int val, int pos) {
        if (pos < 0) {
            cout << "Invalid position!" << endl;
            return;
        }
        if (pos == 0) {
            insert_begin(val);
            return;
        }

        Node *temp = head;
        for (int i = 0; i < pos - 1 && temp != NULL; i++) {
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        Node *newnode = new Node(val);
        newnode->next = temp->next;
        temp->next = newnode;
        if (newnode->next == NULL) tail = newnode;
    }

    // Delete from beginning
    void delete_begin() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        delete temp;
        if (head == NULL) tail = NULL;
    }

    // Delete from end
    void delete_end() {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == NULL) { // only one node
            delete head;
            head = tail = NULL;
            return;
        }
        Node *temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        delete tail;
        temp->next = NULL;
        tail = temp;
    }

    // Delete from given position (0-based index)
    void delete_mid(int pos) {
        if (head == NULL) {
            cout << "List is empty!" << endl;
            return;
        }
        if (pos == 0) {
            delete_begin();
            return;
        }

        Node *temp = head;
        Node *prev = NULL;
        for (int i = 0; i < pos && temp != NULL; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }

        prev->next = temp->next;
        if (temp == tail) tail = prev;
        delete temp;
    }

    // Update node value at position
    void update(int pos, int val) {
        Node *temp = head;
        for (int i = 0; i < pos && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            cout << "Position out of range!" << endl;
            return;
        }
        temp->Data = val;
    }

    // Search for a value
    void search(int val) {
        Node *temp = head;
        int pos = 0;
        while (temp != NULL) {
            if (temp->Data == val) {
                cout << "Value " << val << " found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Value " << val << " not found!" << endl;
    }

    // Sort the linked list (Bubble Sort)
    void sort() {
        for (Node *i = head; i != NULL; i = i->next) {
            for (Node *j = i->next; j != NULL; j = j->next) {
                if (i->Data > j->Data) {
                    swap(i->Data, j->Data);
                }
            }
        }
    }

    // Display the linked list
    void display() {
        Node *temp = head;
        while (temp != NULL) {
            cout << temp->Data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// Main Program - Menu Driven
int main() {
    SLL s;
    int choice, val, pos;

    do {
        cout << "\n====== Singly Linked List Menu ======\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete from Beginning\n";
        cout << "5. Delete from End\n";
        cout << "6. Delete from Position\n";
        cout << "7. Update Node\n";
        cout << "8. Search Node\n";
        cout << "9. Sort List\n";
        cout << "10. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                s.insert_begin(val);
                break;
            case 2:
                cout << "Enter value: ";
                cin >> val;
                s.insert_end(val);
                break;
            case 3:
                cout << "Enter value and position: ";
                cin >> val >> pos;
                s.insert_mid(val, pos);
                break;
            case 4:
                s.delete_begin();
                break;
            case 5:
                s.delete_end();
                break;
            case 6:
                cout << "Enter position: ";
                cin >> pos;
                s.delete_mid(pos);
                break;
            case 7:
                cout << "Enter position and new value: ";
                cin >> pos >> val;
                s.update(pos, val);
                break;
            case 8:
                cout << "Enter value to search: ";
                cin >> val;
                s.search(val);
                break;
            case 9:
                s.sort();
                cout << "List sorted!" << endl;
                break;
            case 10:
                s.display();
                break;
            case 0:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
