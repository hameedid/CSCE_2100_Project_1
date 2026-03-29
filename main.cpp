#include <iostream>
#include "DriverDatabase.hpp"
using namespace std;

void displayMenu() {
    cout << "Driver Database System" << endl;
    cout << "1. Load driver data" << endl;
    cout << "2. Add a new driver" << endl;
    cout << "3. Search for a driver" << endl;
    cout << "4. Delete a driver or move them to the inactive data bases" << endl;
    cout << "5. Show N most recently issued licenses" << endl;
    cout << "6. Show N oldest issued licenses" << endl;
    cout << "7. Display active drivers" << endl;
    cout << "8. Display inactive drivers" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;
    DriverDatabase db;
    int loaded = 0;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                if (db.loadFromFile("data.txt", loaded)) {
                    cout << "Loaded " << loaded << " drivers" << endl;
                } else {
                    cout << "Failed to load file" << endl;
                }
                break;

            case 2:
                cout << "Insert driver" << endl;
                break;

            case 3:
                cout << "Search driver" << endl;
                break;

            case 4:
                cout << "Delete/move driver" << endl;
                break;

            case 5:
                cout << "Recent licenses feature will be connected here." << endl;
                break;

            case 6:
                cout << "Oldest licenses feature will be connected here." << endl;
                break;

            case 7:
                cout << "Display active drivers " << endl;
                break;

            case 8:
                cout << "Display inactive drivers " << endl;
                break;

            case 9:
                cout << "Exiting the program" << endl;
                break;

            default:
                cout << "Wrong choice, Try again." << endl;
        }

    } while (choice != 9);

    return 0;
}
