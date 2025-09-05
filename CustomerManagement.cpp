#include <iostream>
using namespace std;

class Customer {
public:
    int id;
    char name[50];
};

Customer customer[100];
int cus_count = 0;

void addCustomer() {
    cout << "Enter the Id of Customer: ";
    cin >> customer[cus_count].id;
    cout << "Enter the name of customer: ";
    cin >> customer[cus_count].name;
    cus_count++;
    cout << "Customer Added Successfully\n";
}

void display() {
    if (cus_count == 0) {
        cout << "No Customer found\n";
        return;
    }
    cout << "\n--------------- CUSTOMER LIST -------------------\n";
    for (int i = 0; i < cus_count; i++) {
        cout << "Id = " << customer[i].id << ", Name = " << customer[i].name << endl;
    }
}

void update() {
    int id;
    cout << "Enter the ID to Update the Name: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i < cus_count; i++) {
        if (customer[i].id == id) {
            cout << "Enter the new Name: ";
            cin >> customer[i].name;
            cout << "Updated record Successfully\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Customer with ID " << id << " not found!\n";
    }
}

void delete_cus() {
    int id;
    cout << "Enter the id of customer to delete: ";
    cin >> id;
    bool found = false;

    for (int i = 0; i < cus_count; i++) {
        if (customer[i].id == id) {
            // Shift elements to left
            for (int j = i; j < cus_count - 1; j++) {
                customer[j] = customer[j + 1];
            }
            cus_count--; // reduce count
            cout << "Deleted Customer successfully\n";
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Customer with ID " << id << " not found!\n";
    }
}

int main() {
    int choice = 0;

    do {
        cout << "\n------------ MENU ------------\n";
        cout << "1 - ADD NEW CUSTOMER\n";
        cout << "2 - DISPLAY CUSTOMER RECORDS\n";
        cout << "3 - UPDATE CUSTOMER RECORD\n";
        cout << "4 - DELETE CUSTOMER RECORD\n";
        cout << "5 - EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCustomer();
            break;
        case 2:
            display();
            break;
        case 3:
            update();
            break;
        case 4:
            delete_cus();
            break;
        case 5:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "WRONG CHOICE! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
