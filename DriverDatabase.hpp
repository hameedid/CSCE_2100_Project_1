#ifndef DRIVER_DATABASE_HPP
#define DRIVER_DATABASE_HPP

#include "Client.hpp"

const int MAX_DRIVER_ID_LENGTH = 16;
const int MAX_DRIVER_NAME_LENGTH = 32;
const int MAX_LICENSE_NUMBER_LENGTH = 20;
const int MAX_STATE_LENGTH = 3;

struct DriverRecord {
    char driverId[MAX_DRIVER_ID_LENGTH];
    char firstName[MAX_DRIVER_NAME_LENGTH];
    char lastName[MAX_DRIVER_NAME_LENGTH];
    char licenseNumber[MAX_LICENSE_NUMBER_LENGTH];
    char state[MAX_STATE_LENGTH];
    Date dateOfBirth;
    Date licenseIssueDate;
};

class DriverDatabase {
private:
    struct Node {
        DriverRecord data;
        Node* next;

        Node(const DriverRecord& driver);
    };

    Node* head;
    Node* tail;
    int size;

    bool append(const DriverRecord& driver);
    bool parseLine(const char* line, DriverRecord& driver) const;
    int compareDates(const Date& left, const Date& right) const;

public:
    DriverDatabase();
    ~DriverDatabase();

    DriverDatabase(const DriverDatabase&) = delete;
    DriverDatabase& operator=(const DriverDatabase&) = delete;

    void clear();
    int getSize() const;

    bool loadFromFile(const char* filePath, int& loadedCount);
    bool getMostRecentLicense(DriverRecord& outDriver) const;
    bool getOldestLicense(DriverRecord& outDriver) const;
    bool findByLicenseNumber(const char* licenseNumber, DriverRecord& outDriver) const;
};

bool runMember3Tests(const char* filePath);

#endif
