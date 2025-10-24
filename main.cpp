#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "ParkingLot.h"
using namespace std;

const string ADMIN_KEY = "admin123";//authentication for admin
#define MAX 100 //maximum accomodation slots provided
// Forward declarations for access functions
void adminAccess(ParkingLot& lot);
void userAccess(ParkingLot& lot);
int main() {
    // Initialize the parking lot
    ParkingLot lot(MAX); 
    int accessChoice;
    while (true) {
        cout << "\n--- Welcome to the Parking System ---\n";
        cout << "1. Admin Access\n2. User Access\n3. Exit System\nChoice: ";
        if (!(cin >> accessChoice)) {
            // Handle non-integer input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (accessChoice == 1) {
            // Admin Access
            string key;
            cout << "Enter Admin Key: ";
            cin >> key;
            if (key == ADMIN_KEY) {
                adminAccess(lot);
            } else {
                cout << " Incorrect Admin Key! Access Denied.\n";
            }
        } else if (accessChoice == 2) {
            // User Access
            userAccess(lot);
        } else if (accessChoice == 3) {
            cout << "Exiting the Parking System. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
void adminAccess(ParkingLot& lot) {
    int choice;
    cout << "\n Admin Access Granted.\n";
    while (true) {
        cout << "\n--- Admin Menu ---\n";
        cout << "1. Park Vehicle\n2. Unpark Vehicle\n3. Display Parking Status\n4. View Total Vehicles Count\n5. Logout\nChoice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            // Park Vehicle
            string no, type;
            cout << "Enter Vehicle No: ";
            getline(cin >> ws, no);
            cout << "Enter Type (Car/Bike/Truck): "; cin >> type;
            transform(type.begin(), type.end(), type.begin(), ::tolower);

            Vehicle* v = nullptr;
            if (type == "car") v = new Car(no);
            else if (type == "bike") v = new Bike(no);
            else if (type == "truck") v = new Truck(no);
            else { cout << "Invalid vehicle type!\n"; continue; }

            try {
                lot.parkVehicle(v);
                cout << " Vehicle " << no << " parked successfully.\n";
            } catch (exception &e) {
                cout << " Error: " << e.what() << endl;
                delete v; // Clean up memory if parking failed
            }
        } else if (choice == 2) {
            // Unpark Vehicle
            string no; cout << "Enter Vehicle No to unpark: ";
            getline(cin >> ws, no);
            lot.unparkVehicle(no);
        } else if (choice == 3) {
            // Display Status
            cout << "\n--- Current Parking Status ---\n";
            lot.displayStatus();
        } else if (choice == 4) {
            // View Total Vehicles
            cout<<"Current Vehicles that are present now: "<< lot.getCurrentVehicles()<<endl;
            cout << "Total Vehicles that have parked till now: " << ParkingLot::getTotalVehicles() << endl;
        } else if (choice == 5) {
            cout << " Logging out of Admin Access.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
void userAccess(ParkingLot& lot) {
    int choice;
    cout << "\n User Access Granted.\n";
    while (true) {
        cout << "\n--- User Menu ---\n";
        cout << "1. Park Vehicle\n2. Unpark Vehicle\n3. Check Availability (Simulated)\n4. Logout\nChoice: ";
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            // Park Vehicle
            string no, type;
            cout << "Enter Vehicle No: ";
            getline(cin >> ws, no);
            cout << "Enter Type (Car/Bike/Truck): "; cin >> type;
            transform(type.begin(), type.end(), type.begin(), ::tolower);

            Vehicle* v = nullptr;
            if (type == "car") v = new Car(no);
            else if (type == "bike") v = new Bike(no);
            else if (type == "truck") v = new Truck(no);
            else { cout << "Invalid vehicle type! Please try again.\n"; continue; }

            try {
                lot.parkVehicle(v);
                cout << "Vehicle " << no << " parked successfully. Remember your vehicle number for unparking.\n";
            } catch (exception &e) {
                cout << " Error: " << e.what() << endl;
                delete v;
            }
        } else if (choice == 2) {
            // Unpark Vehicle
            string no; cout << "Enter Vehicle No to unpark: ";
            getline(cin >> ws, no);
            lot.unparkVehicle(no);
        } else if (choice == 3) {
            // Simple check availability for user (Simulated)
            cout << "Parking lot is generally available. Please try parking to confirm or contact admin for precise details.\n";
        } else if (choice == 4) {
            cout << " Logging out of User Access.\n";
            break;
        } else {
            cout << "Invalid choice. Please try again.\n";
        }
    }
}
