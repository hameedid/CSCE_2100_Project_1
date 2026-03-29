#include <iostream>
#include <string>
using namespace std;

class Date { 
private:
    int day;
    int month;
    int year;

public:
    Date(int d=1, int m=1, int y=2000) {
         day=d, month = m, year =y;
    }

    // getters
    int getDay() {
        return day;
    }
    int getMonth() {
        return month;
    }
    int getYear() {
        return year;
    }

    //Setters
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }

    int getAge() {
        int currentYear = 2026;
        return currentYear - year;
    }
    void display() const {
        cout << day << "/" << month << "/" << year << endl;
    }
};

class Address {
private:
    string city;
    string street;
    string country;
    string zipCode;

public:
    Address(string cty="", string str="", string ctry="", string zip="") {
        city = cty;
        street = str;
        country = ctry;
        zipCode = zip;
    }
    void setAddress(string cty, string str, string ctry, string zip) {
        city = cty;
        street = str;
        country = ctry;
        zipCode = zip;
    }
    void display() const {
        cout << street << ", " << city << ", " << country << " " << zipCode << endl;
    }
};

class Ticket {
private:
    int ticketID;
    string location;
    Date issueDate;
    
public:
    Ticket(int id=0, string loc="", Date d=Date()) {
        ticketID = id;
        location = loc;
        issueDate = d;
    }
    void setTicket(int id, string loc, Date d) {
        ticketID = id;
        location = loc;
        issueDate = d;
    }
    void display() {
        cout << "Ticket ID: " << ticketID << endl;
        cout << "Location: " << location << endl;
        cout << "Issue Date: ";
        issueDate.display();
        cout << endl;
    }
};


class Driver {
private:
    int driverID;
    string name;
    string licenseDate;
    int experience;
    string workType;
    string medicalStatus;
    Date dob;
    Address address;

    Ticket tickets[10];
    int ticketCount;

public:
    Driver(int id=0, string n="", Date l_date=Date(), int exp=0, string w_type="", string m_status="", Date b_date=Date() Address a=Address()) {
        driverID = id;
        name = n;
        licenseDate = l_date;
        experience = exp;
        workType = w_type;
        medicalStatus = m_status;
        dob = b_date;
        address = a;
        ticketCount = 0;
    }

    //Getters
    int getDriverID() {
        return driverID;
    }

    string getName() const {
        return name;
    }

    //Setters
    void setName(string n) {
        name = n;
    }
    void setworkType(string w_type) {
        workType = w_type;
    }

    void addTicket(Ticket t) {
        if (ticketCount < 10) {
            tickets[ticketCount++] = t;
        }
    }

    //to calculate age of driver
    int calculateAge() {
        return dob.getAge();
    }

    // use for display the driver information
    void displayDriver() {
        cout << "Driver ID: " << driverID << endl;
        cout << "Name: " << name << endl;
       
        cout << "Date of Birth: ";
        dob.display();
        cout << "(Age: " << calculateAge() << ")" << endl;
    
        cout << "License Date: " << licenseDate << endl;
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
};



    // For student Driver

    class StudentDriver: public Driver {
    public:
        StudentDriver( int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a)
            : Driver(id, n, l_date, exp, w_type, m_status, b_date, a), school(sch) {}


        void displayDriver() override {
            Driver::displayDriver();
            cout << " Category: Student Driver (Age 16-28)\n";
        }
    };


    // For middle Age Driver
    class MiddleAgeDriver: public Driver {
    public:
        MiddleAgeDriver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a)
            : Driver(id, n, l_date, exp, w_type, m_status, b_date, a) {}

        void displayDriver() override {
            Driver::displayDriver();
            cout << " Category: Middle Age Driver (Age 29-50)\n";
        }
    };

    // For senior driver
    class SeniorDriver: public Driver {
    public:
        SeniorDriver(int id, string n, Date l_date, int exp, string w_type, string m_status, Date b_date, Address a)
            : Driver(id, n, l_date, exp, w_type, m_status, b_date, a) {}

        void displayDriver() override {
            Driver::displayDriver();
            cout << " Category: Senior Driver (Age 51+)\n";
        }
    }; 
