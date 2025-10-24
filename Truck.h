#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
public:
    Truck(string no);
    double calculateFee(time_t exitTime) override;
    string getType() const override;
};

#endif
