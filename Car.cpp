#include "Car.h"
#include <algorithm>

Car::Car(string no) : Vehicle(no) {}

double Car::calculateFee(time_t exitTime) {
    double hours = difftime(exitTime, entryTime) / 3600.0;
    return max(20.0, hours * 10);
}
