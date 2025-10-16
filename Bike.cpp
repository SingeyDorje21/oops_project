#include "Bike.h"
#include <algorithm>

Bike::Bike(string no) : Vehicle(no) {}

double Bike::calculateFee(time_t exitTime) {
    double hours = difftime(exitTime, entryTime) / 3600.0;
    return max(10.0, hours * 5);
}
