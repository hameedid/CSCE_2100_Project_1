#include <iostream>
#include "Driver.h"
using namespace std;

// Driver class 
Driver::Driver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a) {
        driverID = id;
        name = n;
        licenseDate = l_date;
        experience = exp;
        workType = w_type;
        medicalStatus = m_status;
        dob = b_date;
        address = a;
}

// displaying the driver information
int Driver::getID() {
        return driverID;
}
int Driver::calculateAge() {
        return dob.getAge();
}
void Driver::display() {
        cout << "Driver ID: " << driverID << endl;
        cout << "Name: " << name << endl;
       
        cout << "Date of Birth: ";
        dob.display();
        cout << "(Age: " << calculateAge() << ")" << endl;
    
        cout << "License Date: ";
        licenseDate.display();
        cout << endl;

        cout << "Experience: " << experience << " years" << endl;
        cout << "Work Type: " << workType << endl;
        cout << "Medical Status: " << medicalStatus << endl;

        cout << "Address: ";
        address.display();
        cout << endl;

        cout << "Tickets:\n" ;
        for (int i = 0; i < ticketCount; i++) {
            tickets[i].display();
            cout << endl;
        }
    }

// StudentDriver class
StudentDriver::StudentDriver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a)
    : Driver(id, n, l_date, exp, w_type, m_status, b_date, a) {}

void StudentDriver::display() {
    Driver::display();
    cout<< "Category: Student Driver(16-28)" << endl;
}

// MiddleAgeDriver class
MiddleAgeDriver::MiddleAgeDriver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a)
    : Driver(id, n, l_date, exp, w_type, m_status, b_date, a) {}

void MiddleAgeDriver::display() {
    Driver::display();
    cout<< "Category: Middle Age Driver(29-50)" << endl;
}

// SeniorDriver class
SeniorDriver::SeniorDriver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a)
    : Driver(id, n, l_date, exp, w_type, m_status, b_date, a) {}

void SeniorDriver::display() {
    Driver::display();
    cout<< "Category: Senior Driver(51+)" << endl;
}

// function to create driver based on age
Driver* createDriver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a) {
    int age = b_date.getAge();
    if (age >= 16 && age <= 28) {
        return new StudentDriver(id, n, l_date, exp, w_type, m_status, b_date, a);
    } else if (age >= 29 && age <= 50) {
        return new MiddleAgeDriver(id, n, l_date, exp, w_type, m_status, b_date, a);
    } else {
        return new SeniorDriver(id, n, l_date, exp, w_type, m_status, b_date, a);
    }
}

