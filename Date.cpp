#include <iostream>
#include <string>
using namespace std;
#include "Date.h"

//Date class
Date::Date(int d, int m, int y){
  day=d; month=m, year=y;
}

// calculating the age of the driver
int Date::getAge() {
        int currentYear = 2026;
        return currentYear - year;
}

// displaying the date information
void Date::display() const {
        cout << day << "/" << month << "/" << year << endl;
}

