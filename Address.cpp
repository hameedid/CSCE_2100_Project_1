#include <iostream>
using namespace std;
#include "Address.h"

// Address class
Address::Address(string cty, string str, string ctry, string zip) {
        city = cty;
        street = str;
        country = ctry;
        zipCode = zip;
}

// displaying the address information
void Address::display(){
  cout<< street << ", " << city << ", " << country << " " << zipCode << endl;
}
