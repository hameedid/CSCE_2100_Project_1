#include <iostream>
using namespace std;
#include "Ticket.h"


Ticket::Ticket(int id, string loc, Date d) {
        ticketID = id;
        location = loc;
        issueDate = d;
}
void Ticket::display(){
  cout << "Ticket ID: " << ticketID << endl;
        cout << "Location: " << location << endl;
        cout << "Issue Date: ";
        issueDate.display();
        cout << endl;
}
