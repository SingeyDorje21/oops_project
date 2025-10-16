#ifndef PARKINGLOT_H
#define PARKINGLOT_H

#include "Ticket.h"
#include <vector>
using namespace std;

class ParkingLot {
    vector<Ticket> tickets;
    int capacity;
    static int totalVehicles;
public:
    ParkingLot(int cap);
    bool parkVehicle(Vehicle* v);
    void unparkVehicle(string no);
    void displayStatus();
    static int getTotalVehicles();
};

#endif
