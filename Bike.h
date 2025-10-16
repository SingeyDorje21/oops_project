#ifndef BIKE_H
#define BIKE_H

#include "Vehicle.h"

class Bike : public Vehicle {
public:
    Bike(string no);
    double calculateFee(time_t exitTime) override;
};

#endif

