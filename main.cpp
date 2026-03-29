#include <iostream>
using namespace std;

void displayMenu() {
    cout << "\n========== Driver Database System ==========" << endl;
    cout << "1. Load driver data from file" << endl;
    cout << "2. Insert a new driver" << endl;
    cout << "3. Search for a driver" << endl;
    cout << "4. Delete a driver / move to inactive database" << endl;
    cout << "5. Show N most recently issued licenses" << endl;
    cout << "6. Show N oldest issued licenses" << endl;
    cout << "7. Display active drivers" << endl;
    cout << "8. Display inactive drivers" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Load file feature will be connected here." << endl;
                break;

            case 2:
                cout << "Insert driver feature will be connected here." << endl;
                break;

            case 3:
                cout << "Search driver feature will be connected here." << endl;
                break;

            case 4:
                cout << "Delete/move to inactive feature will be connected here." << endl;
                break;

            case 5:
                cout << "Recent licenses feature will be connected here." << endl;
                break;

            case 6:
                cout << "Oldest licenses feature will be connected here." << endl;
                break;

            case 7:
                cout << "Display active drivers feature will be connected here." << endl;
                break;

            case 8:
                cout << "Display inactive drivers feature will be connected here." << endl;
                break;

            case 9:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 9);

    return 0;
}
