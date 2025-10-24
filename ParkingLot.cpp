#include "ParkingLot.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int ParkingLot::totalVehicles = 0;

ParkingLot::ParkingLot(int cap) : capacity(cap) ,currentVehicles(0){}

bool ParkingLot::parkVehicle(Vehicle* v) {
    if ((int)tickets.size() >= capacity) {
        throw runtime_error("Parking Full!");
    }
    for (auto &ticket : tickets) {
        Vehicle* parkedVehicle = ticket.getVehicle();
        if (parkedVehicle && parkedVehicle->getType() == v->getType() &&
            parkedVehicle->getVehicleNo() == v->getVehicleNo()) {
            throw runtime_error("Vehicle with same type and number already parked!");
        }
    }
    tickets.push_back(Ticket(v, tickets.size()+1));
    currentVehicles++;
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
            currentVehicles--;
            // Store pointer before erasing
            Vehicle* vehicleToDelete = it->getVehicle();
            tickets.erase(it);
            delete vehicleToDelete;
            
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
int ParkingLot::getCurrentVehicles() { return currentVehicles; }
