#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(string no);
    double calculateFee(time_t exitTime) override;
    string getType() const override;
};

#endif
