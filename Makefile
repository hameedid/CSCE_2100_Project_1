CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = driverdb

OBJS = main.o Driver.o Date.o Address.o Ticket.o DriverDatabase.o CustomDataStructures.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Driver.o: Driver.cpp Driver.h
	$(CXX) $(CXXFLAGS) -c Driver.cpp

Date.o: Date.cpp Date.h
	$(CXX) $(CXXFLAGS) -c Date.cpp

Address.o: Address.cpp Address.h
	$(CXX) $(CXXFLAGS) -c Address.cpp

Ticket.o: Ticket.cpp Ticket.h
	$(CXX) $(CXXFLAGS) -c Ticket.cpp

DriverDatabase.o: DriverDatabase.cpp DriverDatabase.hpp
	$(CXX) $(CXXFLAGS) -c DriverDatabase.cpp

CustomDataStructures.o: CustomDataStructures.cpp Driver.h Ticket.h
	$(CXX) $(CXXFLAGS) -c CustomDataStructures.cpp

clean:
	rm -f *.o $(TARGET)

