#include "Truck.h"
#include <algorithm>

Truck::Truck(string no) : Vehicle(no) {}

double Truck::calculateFee(time_t exitTime) {
    double hours = difftime(exitTime, entryTime) / 3600.0;
    return max(30.0, hours * 15);
}
