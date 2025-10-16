#include "Ticket.h"

Ticket::Ticket(Vehicle* v, int s) : v(v), slotNo(s) {}

Vehicle* Ticket::getVehicle() const { return v; }
int Ticket::getSlot() const { return slotNo; }

ostream& operator<<(ostream& out, const Ticket& t) {
    if (t.v != nullptr) {
        out << "Ticket: Vehicle " << t.v->getVehicleNo() << " at slot " << t.slotNo;
    }
    return out;
}