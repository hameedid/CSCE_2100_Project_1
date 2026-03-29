#include <iostream>
using namespace std;

Date::Date(int d, int m, int y){
  day=d; month=m, year=y;
}

int Date::getAge() {
        int currentYear = 2026;
        return currentYear - year;
}
void display() const {
        cout << day << "/" << month << "/" << year << endl;
}
