# Smartly

Smartly is a simple, menu-driven parking lot manager written in modern C++. It keeps track of cars, bikes, and trucks, issues tickets on entry, calculates parking fees on exit, and enforces basic admin authentication – all from a single terminal application.

## Key Features
- Admin and user access modes with distinct capabilities
- Ticketing system backed by dynamic storage (`std::vector`) to track occupied slots
- Vehicle-type polymorphism for fee calculation (bike, car, truck)
- Automatic duplicate-vehicle guard to avoid double parking
- On-demand occupancy summary and running totals of vehicles served

## Code Layout
| File | Role |
| ---- | ---- |
| `main.cpp` | Entry point; handles menus, input validation, and dispatches to the parking lot API |
| `ParkingLot.h/.cpp` | Owns tickets, enforces capacity, issues and revokes parking slots |
| `Ticket.h/.cpp` | Wraps a `Vehicle*` with a slot number and stream output support |
| `Vehicle.h/.cpp` | Abstract base class capturing shared state (vehicle number, entry time) |
| `Bike.h/.cpp`, `Car.h/.cpp`, `Truck.h/.cpp` | Concrete vehicle types with specific hourly fee rules |

The menu flow is straightforward:
1. Choose admin or user access.
2. Provide the admin key (`admin123`) when prompted for privileged operations.
3. Park or unpark vehicles by number and type; Smartly normalizes the type to lowercase internally.

## Building Smartly
### Prerequisites
- A C++17-compatible compiler (tested with `g++` and `clang++`).

### Compile
```bash
g++ -std=c++17 -Wall -Wextra -O2 -o Smartly \
	main.cpp ParkingLot.cpp Ticket.cpp Vehicle.cpp Car.cpp Bike.cpp Truck.cpp
```

On Windows using `bash.exe` (Git Bash), run the same command from the project root.

### Run
```bash
./Smartly   # on Windows Git Bash or Linux/macOS
Smartly.exe # from cmd/PowerShell if you built with MSVC
```

## Using the Application
### Admin Mode
1. Select option `1` at the main menu.
2. Enter the admin key `admin123`.
3. Choose from: park, unpark, display status, or view vehicle counts.

### User Mode
1. Select option `2` at the main menu.
2. Park or unpark by providing the vehicle number and type (case-insensitive).
3. View the simulated availability message if you only need a quick capacity check.

When parking, Smartly issues a ticket and notes the entry timestamp. On exit, the system computes a fee using the vehicle’s rate card:
- Bikes: min ₹10, otherwise ₹5/hour
- Cars:  min ₹20, otherwise ₹10/hour
- Trucks: min ₹30, otherwise ₹15/hour

## Memory & Safety Notes
- Tickets are non-copyable to avoid double-deletion of vehicle pointers.
- Vehicles are deleted when you unpark them, so there is no manual cleanup needed beyond normal use.

## Extending Smartly
Potential enhancements include persistent storage, a richer CLI with argument parsing, unit tests, or a GUI/REST front end. Contributions are welcome.
