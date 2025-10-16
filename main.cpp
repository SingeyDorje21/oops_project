#include <iostream>
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "ParkingLot.h"
using namespace std;

int main() {
    ParkingLot lot(5);
    int choice;
    while (true) {
        cout << "\n1. Park Vehicle\n2. Unpark Vehicle\n3. Display Status\n4. Exit\nChoice: ";
        cin >> choice;
        if (choice == 1) {
            string no, type;
            cout << "Enter Vehicle No: "; cin >> no;
            cout << "Enter Type (Car/Bike/Truck): "; cin >> type;
            Vehicle* v = nullptr;
            if (type == "Car") v = new Car(no);
            else if (type == "Bike") v = new Bike(no);
            else if (type == "Truck") v = new Truck(no);
            else { cout << "Invalid type!\n"; continue; }

            try {
                lot.parkVehicle(v);
            } catch (exception &e) {
                cout << e.what() << endl;
                delete v;
            }
        } else if (choice == 2) {
            string no; cout << "Enter Vehicle No: "; cin >> no;
            lot.unparkVehicle(no);
        } else if (choice == 3) {
            lot.displayStatus();
            cout << "Total Vehicles till now: " << ParkingLot::getTotalVehicles() << endl;
        } else break;
    }
    return 0;
}
