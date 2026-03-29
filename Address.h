#ifndef ADDRESS_H
#define ADDRESS_H
#include <string>
using namespace std;

class Address {
private:
    string city;
    string street;
    string country;
    string zipCode;
public:
    Address(string cty="", string str="", string ctry="", string zip="");
    void display();
};
#endif
