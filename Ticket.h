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
    
    // Prevent copying to avoid double-delete
    Ticket(const Ticket&) = delete;
    Ticket& operator=(const Ticket&) = delete;
    
    // Allow moving
    Ticket(Ticket&& other) noexcept : v(other.v), slotNo(other.slotNo) {
        other.v = nullptr;
    }
    Ticket& operator=(Ticket&& other) noexcept {
        if (this != &other) {
            v = other.v;
            slotNo = other.slotNo;
            other.v = nullptr;
        }
        return *this;
    }
    
    Vehicle* getVehicle() const;
    int getSlot() const;
    friend ostream& operator<<(ostream& out, const Ticket& t);
};

#endif