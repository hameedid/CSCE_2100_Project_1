#ifndef ADDRESS_H
#define ADDRESS_H

#include <string>
using namespace std;

// Address class
class Address {
private:
    string city;
    string street;
    string country;
    string zipCode;

public:
    Address(string cty = "", string str = "", string ctry = "", string zip = "");
    void display();
    string getCity() const;
};

#endif
