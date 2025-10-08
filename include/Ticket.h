#ifndef TICKET_H
#define TICKET_H

#include "Vehicle.h"
#include <iostream>
using namespace std;

class Ticket {
    Vehicle* v;
    int slotNo;
public:
    Ticket(Vehicle* v, int s);
    Vehicle* getVehicle() const;
    int getSlot() const;
    friend ostream& operator<<(ostream& out, const Ticket& t);
};

#endif
