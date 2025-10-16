#include "Vehicle.h"

Vehicle::Vehicle(string no) : vehicleNo(no) {
    entryTime = time(0);
}

Vehicle::~Vehicle() {}

string Vehicle::getVehicleNo() const { return vehicleNo; }
time_t Vehicle::getEntryTime() const { return entryTime; }
