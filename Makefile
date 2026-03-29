CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = driverdb

OBJS = main.o Driver.o Date.o Address.o Ticket.o DriverDatabase.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

clean:
	rm -f *.o $(TARGET)
