#include <iostream>
using namespace std;
#include "Address.h"

Address::Address(string cty, string str, string ctry, string zip) {
        city = cty;
        street = str;
        country = ctry;
        zipCode = zip;
}
void Address::display(){
  cout<< street << ", " << city << ", " << country << " " << zipCode << endl;
}
