#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>
#include <string>
#include "Date.h"
#include "Address.h"
#include "Ticket.h"
using namespace std;

// Base class for Driver
class Driver{
protected:
    int driverID;
    string name;
    Date licenseDate;
    int experience;
    string workType;
    string medicalStatus;
    Date dob;
    Address address;
public:
    Driver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a);
    virtual void display();
    int getID();
    int calculateAge();
    Address getAddress() const;
};

//class for Student Driver
class StudentDriver: public Driver {
public:
    StudentDriver( int id, string n, Date licenseDate, int exp, string w_type, string m_status, Date b_date, Address a);
    void display();
};

//class for middle age driver
class MiddleAgeDriver: public Driver {
public:    MiddleAgeDriver(int id, string n, Date licenseDate, int exp, string w_type, string m_status, Date b_date, Address a);
    void display();
};

//class for senior driver
class SeniorDriver: public Driver {
public:    SeniorDriver(int id, string n, Date licenseDate, int exp, string w_type, string m_status, Date b_date, Address a);
    void display();
};

//function to create driver based on age
Driver* createDriver(int id, string n, Date licenseDate, int exp, string w_type, string m_status, Date b_date, Address a);

#endif

