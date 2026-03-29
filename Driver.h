#ifndef DRIVER_H
#define DRIVER_H

#include <string>
#include "Date.h"
#include "Address.h"
#include "Ticket.h"
using namespace std;

class Driver{
protected:
    int driverID;
    string name;
    string licenseDate;
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
};
class StudentDriver: public Driver {
public:
    StudentDriver( int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a);
    void display();
};
class MiddleAgeDriver: public Driver {
public:    MiddleAgeDriver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a);
    void display();
};
class SeniorDriver: public Driver {
public:    SeniorDriver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a);
    void display();
};

Driver* createDriver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a);
#endif

