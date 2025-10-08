#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <ctime>
using namespace std;

class Vehicle {
protected:
    string vehicleNo;
    time_t entryTime;
public:
    Vehicle(string no);
    virtual ~Vehicle();
    string getVehicleNo() const;
    time_t getEntryTime() const;
    virtual double calculateFee(time_t exitTime) = 0; // Abstract
};

#endif
