#ifndef DATE_H
#define DATE_H

//Date class
class Date {
private:
    int day, month, year;
public:
    Date(int d=1, int m=1, int y=2000);
    int getAge();
    void display() const;
};
#endif
