#include "ParkingLot.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int ParkingLot::totalVehicles = 0;

ParkingLot::ParkingLot(int cap) : capacity(cap) {}

bool ParkingLot::parkVehicle(Vehicle* v) {
    if ((int)tickets.size() >= capacity) {
        throw runtime_error("Parking Full!");
    }
    tickets.push_back(Ticket(v, tickets.size()+1));
    totalVehicles++;
    cout << "Vehicle Parked. " << tickets.back() << endl;
    return true;
}

void ParkingLot::unparkVehicle(string no) {
    for (auto it = tickets.begin(); it != tickets.end(); ++it) {
        if (it->getVehicle()->getVehicleNo() == no) {
            time_t exitTime = time(0);
            double fee = it->getVehicle()->calculateFee(exitTime);
            cout << "Vehicle " << no << " removed. Fee: Rs." << fee << endl;
            delete it->getVehicle();
            tickets.erase(it);
            return;
        }
    }
    cout << "Vehicle not found!" << endl;
}

void ParkingLot::displayStatus() {
    cout << "--- Parking Status ---" << endl;
    for (auto &t : tickets) {
        cout << t << endl;
    }
}

int ParkingLot::getTotalVehicles() { return totalVehicles; }
