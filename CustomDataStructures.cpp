// Member 2 - Data Structures & Database Logic
// GOAL: Build active & inactive driver databases, implement custom data structures,
// handle insertion, deletion, and search operations

#include <iostream>
#include <string>
#include "Driver.h"
#include "Ticket.h"

using namespace std;

struct Node {
    Driver* data;
    Node* next;
    Node* prev;
};

class doublyLinkedList {
public:
    Node* head;
    Node* tail;

    doublyLinkedList() : head(nullptr), tail(nullptr) {}

    void insertAtBeginning(Driver* d) {
        Node* newNode = new Node{d, head, nullptr};
        if (head != nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }

    void insertAtEnd(Driver* d) {
        Node* newNode = new Node{d, nullptr, tail};
        if (tail != nullptr) {
            tail->next = newNode;
        } else {
            head = newNode;
        }
        tail = newNode;
    }

    void insertAtMiddle(Driver* d, string targetCity) {
    Node* curr = head;

    // find node with matching city
    while (curr != nullptr && curr->data->getAddress().getCity() != targetCity) {
        curr = curr->next;
    }

    // if not found OR at end → insert at end
    if (curr == nullptr || curr == tail) {
        insertAtEnd(d);
        return;
    }

    // insert AFTER the found node
    Node* newNode = new Node{d, curr->next, curr};
    curr->next->prev = newNode;
    curr->next = newNode;
    }

    Driver* removeNode(int id) {
        Node* curr = head;

        while (curr != nullptr) {
            if (curr->data->getID() == id) {
                if (curr->prev != nullptr) {
                    curr->prev->next = curr->next;
                } else {
                    head = curr->next;
                }

                if (curr->next != nullptr) {
                    curr->next->prev = curr->prev;
                } else {
                    tail = curr->prev;
                }

                Driver* detachedData = curr->data;
                delete curr;
                return detachedData;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    Driver* searchNode(int id) {
        Node* curr = head;
        while (curr != nullptr) {
            if (curr->data->getID() == id) {
                return curr->data;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    void displayForward() {
        Node* curr = head;
        while (curr != nullptr) {
            curr->data->display();
            cout << endl;
            curr = curr->next;
        }
    }

    void displayBackward() {
        Node* curr = tail;
        while (curr != nullptr) {
            curr->data->display();
            cout << endl;
            curr = curr->prev;
        }
    }
};

class hashTable {
private:
    static const int SIZE = 127;

    struct hashNode {
        Driver* data;
        hashNode* next;
    };

    hashNode* table[SIZE];

public:
    hashTable() {
        for (int i = 0; i < SIZE; i++) {
            table[i] = nullptr;
        }
    }

    void insert(Driver* d) {
        int idx = d->getID() % SIZE;
        hashNode* newNode = new hashNode{d, table[idx]};
        table[idx] = newNode;
    }

    Driver* search(int id) {
        int idx = id % SIZE;
        hashNode* curr = table[idx];

        while (curr != nullptr) {
            if (curr->data->getID() == id) {
                return curr->data;
            }
            curr = curr->next;
        }
        return nullptr;
    }

    void remove(int id) {
        int idx = id % SIZE;
        hashNode* curr = table[idx];
        hashNode* prev = nullptr;

        while (curr != nullptr) {
            if (curr->data->getID() == id) {
                if (prev != nullptr) {
                    prev->next = curr->next;
                } else {
                    table[idx] = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }
};

class inactiveDriverDatabase {
private:
    doublyLinkedList list;

public:
    void addInactiveDriver(Driver* d) {
        list.insertAtEnd(d);
    }

    Driver* search(int id) {
        return list.searchNode(id);
    }

    void displayInactiveDrivers() {
        list.displayForward();
    }
};

class driverDatabase {
private:
    hashTable HASHTABLE;
    doublyLinkedList activeList;
    inactiveDriverDatabase inactiveList;

public:
    void insertDriverAtBeginning(Driver* d) {
        activeList.insertAtBeginning(d);
        HASHTABLE.insert(d);
    }

    void insertDriverAtMiddle(Driver* d, string targetCity) {
        activeList.insertAtMiddle(d, targetCity);
        HASHTABLE.insert(d);
    }

    void insertDriverAtEnd(Driver* d) {
        activeList.insertAtEnd(d);
        HASHTABLE.insert(d);
    }

    Driver* searchDriver(int id) {
        return HASHTABLE.search(id);
    }

    void moveToInactiveDriverDatabase(int id) {
        Driver* d = activeList.removeNode(id);
        if (d != nullptr) {
            HASHTABLE.remove(id);
            inactiveList.addInactiveDriver(d);
            cout << "The Driver " << id
                 << " has been successfully moved to the inactive database."
                 << endl;
        } else {
            cout << "Driver not found." << endl;
        }
    }

    void getRecentlyIssuedLicense(int n) {
        Node* curr = activeList.tail;
        for (int i = 0; i < n && curr != nullptr; i++) {
            curr->data->display();
            cout << endl;
            curr = curr->prev;
        }
    }

    void getOldestIssuedLicenses(int n) {
        Node* curr = activeList.head;
        for (int i = 0; i < n && curr != nullptr; i++) {
            curr->data->display();
            cout << endl;
            curr = curr->next;
        }
    }

    void displayActiveDrivers() {
        activeList.displayForward();
    }

    void displayInactiveDrivers() {
        inactiveList.displayInactiveDrivers();
    }
};
