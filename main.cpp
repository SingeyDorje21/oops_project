#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <limits>
#include "Car.h"
#include "Bike.h"
#include "Truck.h"
#include "ParkingLot.h"
using namespace std;

const string ADMIN_KEY = "admin123";
#define MAX 100

// Forward declarations
void adminAccess(ParkingLot& lot);
void userAccess(ParkingLot& lot);

void printHeader(const string &title) {
    cout << "\n" << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
    cout << setw(30 + title.length() / 2) << right << title << endl;
    cout << setfill('=') << setw(60) << "=" << setfill(' ') << endl;
}

void printLine() {
    cout << setfill('-') << setw(60) << "-" << setfill(' ') << endl;
}

int main() {
    ParkingLot lot(MAX);
    int accessChoice;

    while (true) {
        printHeader("WELCOME TO THE PARKING SYSTEM");
        printLine();
        cout << left << setw(25) << "1." << "Admin Access" << endl;
        cout << left << setw(25) << "2." << "User Access" << endl;
        cout << left << setw(25) << "3." << "Exit System" << endl;
        printLine();
        cout << "Enter your choice: ";

        if (!(cin >> accessChoice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        if (accessChoice == 1) {
            string key;
            cout << "\nEnter Admin Key: ";
            cin >> key;
            if (key == ADMIN_KEY) {
                adminAccess(lot);
            } else {
                cout << "\nIncorrect Admin Key! Access Denied.\n";
            }
        } else if (accessChoice == 2) {
            userAccess(lot);
        } else if (accessChoice == 3) {
            cout << "\nExiting the Parking System. Goodbye!\n";
            break;
        } else {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
    return 0;
}

void adminAccess(ParkingLot& lot) {
    int choice;
    printHeader("ADMIN ACCESS GRANTED");

    while (true) {
        printLine();
        cout << left << setw(25) << "1." << "Park Vehicle" << endl;
        cout << left << setw(25) << "2." << "Unpark Vehicle" << endl;
        cout << left << setw(25) << "3." << "Display Parking Status" << endl;
        cout << left << setw(25) << "4." << "View Vehicle Counts" << endl;
        cout << left << setw(25) << "5." << "Logout" << endl;
        printLine();
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            string no, type;
            cout << "\nEnter Vehicle No: ";
            getline(cin >> ws, no);
            cout << "Enter Type (Car/Bike/Truck): ";
            cin >> type;
            transform(type.begin(), type.end(), type.begin(), ::tolower);

            Vehicle* v = nullptr;
            if (type == "car") v = new Car(no);
            else if (type == "bike") v = new Bike(no);
            else if (type == "truck") v = new Truck(no);
            else { cout << "\nInvalid vehicle type!\n"; continue; }

            try {
                lot.parkVehicle(v);
                cout << "\nVehicle " << no << " parked successfully.\n";
            } catch (exception &e) {
                cout << "\nError: " << e.what() << endl;
                delete v;
            }

        } else if (choice == 2) {
            string no;
            cout << "\nEnter Vehicle No to unpark: ";
            getline(cin >> ws, no);
            lot.unparkVehicle(no);

        } else if (choice == 3) {
            cout << "\nCURRENT PARKING STATUS\n";
            printLine();
            lot.displayStatus();

        } else if (choice == 4) {
            cout << "\nVEHICLE STATISTICS\n";
            printLine();
            cout << left << setw(40) << "Current Vehicles in Lot:" 
                 << lot.getCurrentVehicles() << endl;
            cout << left << setw(40) << "Total Vehicles Parked Till Now:" 
                 << ParkingLot::getTotalVehicles() << endl;

        } else if (choice == 5) {
            cout << "\nLogging out of Admin Access.\n";
            break;
        } else {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
}

void userAccess(ParkingLot& lot) {
    int choice;
    printHeader("USER ACCESS GRANTED");

    while (true) {
        printLine();
        cout << left << setw(25) << "1." << "Park Vehicle" << endl;
        cout << left << setw(25) << "2." << "Unpark Vehicle" << endl;
        cout << left << setw(25) << "3." << "Check Availability" << endl;
        cout << left << setw(25) << "4." << "Logout" << endl;
        printLine();
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input. Please enter a number.\n";
            continue;
        }

        if (choice == 1) {
            string no, type;
            cout << "\nEnter Vehicle No: ";
            getline(cin >> ws, no);
            cout << "Enter Type (Car/Bike/Truck): ";
            cin >> type;
            transform(type.begin(), type.end(), type.begin(), ::tolower);

            Vehicle* v = nullptr;
            if (type == "car") v = new Car(no);
            else if (type == "bike") v = new Bike(no);
            else if (type == "truck") v = new Truck(no);
            else { cout << "\nInvalid vehicle type!\n"; continue; }

            try {
                lot.parkVehicle(v);
                cout << "\nVehicle " << no 
                     << " parked successfully. Remember your number for unparking.\n";
            } catch (exception &e) {
                cout << "\nError: " << e.what() << endl;
                delete v;
            }

        } else if (choice == 2) {
            string no;
            cout << "\nEnter Vehicle No to unpark: ";
            getline(cin >> ws, no);
            lot.unparkVehicle(no);

        } else if (choice == 3) {
            cout << "\nPARKING AVAILABILITY\n";
            printLine();
            cout << "Parking lot is generally available.\n"
                 << "Try parking or contact admin for details.\n";

        } else if (choice == 4) {
            cout << "\nLogging out of User Access.\n";
            break;

        } else {
            cout << "\nInvalid choice. Please try again.\n";
        }
    }
}
