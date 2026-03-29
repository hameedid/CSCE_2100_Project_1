#ifndef TICKET_H
#define TICKET_H

#include <string>
#include "Date.h"
using namespace std;

// Ticket class
class Ticket {
private:
    int ticketID;
    string location;
    Date issueDate;
    
public:
    Ticket(int id=0, string loc="", Date d=Date());
    void display();
};

#endif
