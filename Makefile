CXX = g++
CXXFLAGS = -std=c++17 -Wall

SRC = main.cpp Bike.cpp Car.cpp Truck.cpp Vehicle.cpp ParkingLot.cpp Ticket.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = parking_system

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(TARGET)
