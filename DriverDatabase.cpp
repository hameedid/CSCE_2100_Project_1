#include "DriverDatabase.hpp"

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <new>
#include <sstream>

DriverDatabase::Node::Node(const DriverRecord& driver) : data(driver), next(0) {}

DriverDatabase::DriverDatabase() : head(0), tail(0), size(0) {}

DriverDatabase::~DriverDatabase() {
    clear();
}

bool DriverDatabase::append(const DriverRecord& driver) {
    Node* node = new (std::nothrow) Node(driver);
    if (!node) {
        return false;
    }

    if (!head) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = node;
    }

    ++size;
    return true;
}

bool DriverDatabase::parseLine(const char* line, DriverRecord& driver) const {
    std::istringstream lineStream(line);
    char field[64];
    char* endPtr = 0;

    if (!lineStream.getline(driver.driverId, MAX_DRIVER_ID_LENGTH, ',')) {
        return false;
    }
    if (!lineStream.getline(driver.firstName, MAX_DRIVER_NAME_LENGTH, ',')) {
        return false;
    }
    if (!lineStream.getline(driver.lastName, MAX_DRIVER_NAME_LENGTH, ',')) {
        return false;
    }
    if (!lineStream.getline(driver.licenseNumber, MAX_LICENSE_NUMBER_LENGTH, ',')) {
        return false;
    }
    if (!lineStream.getline(driver.state, MAX_STATE_LENGTH, ',')) {
        return false;
    }

    if (!lineStream.getline(field, sizeof(field), ',')) {
        return false;
    }
    driver.dateOfBirth.day = static_cast<int>(std::strtol(field, &endPtr, 10));
    if (*endPtr != '\0') {
        return false;
    }

    if (!lineStream.getline(field, sizeof(field), ',')) {
        return false;
    }
    driver.dateOfBirth.month = static_cast<int>(std::strtol(field, &endPtr, 10));
    if (*endPtr != '\0') {
        return false;
    }

    if (!lineStream.getline(field, sizeof(field), ',')) {
        return false;
    }
    driver.dateOfBirth.year = static_cast<int>(std::strtol(field, &endPtr, 10));
    if (*endPtr != '\0') {
        return false;
    }

    if (!lineStream.getline(field, sizeof(field), ',')) {
        return false;
    }
    driver.licenseIssueDate.day = static_cast<int>(std::strtol(field, &endPtr, 10));
    if (*endPtr != '\0') {
        return false;
    }

    if (!lineStream.getline(field, sizeof(field), ',')) {
        return false;
    }
    driver.licenseIssueDate.month = static_cast<int>(std::strtol(field, &endPtr, 10));
    if (*endPtr != '\0') {
        return false;
    }

    if (!lineStream.getline(field, sizeof(field))) {
        return false;
    }
    driver.licenseIssueDate.year = static_cast<int>(std::strtol(field, &endPtr, 10));
    if (*endPtr != '\0') {
        return false;
    }

    return true;
}

int DriverDatabase::compareDates(const Date& left, const Date& right) const {
    if (left.year != right.year) {
        return left.year - right.year;
    }
    if (left.month != right.month) {
        return left.month - right.month;
    }
    return left.day - right.day;
}

void DriverDatabase::clear() {
    Node* current = head;
    while (current) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = 0;
    tail = 0;
    size = 0;
}

int DriverDatabase::getSize() const {
    return size;
}

bool DriverDatabase::loadFromFile(const char* filePath, int& loadedCount) {
    std::ifstream input(filePath);
    if (!input) {
        return false;
    }

    clear();
    loadedCount = 0;

    char line[256];

    if (!input.getline(line, sizeof(line))) {
        return false;
    }

    while (input.getline(line, sizeof(line))) {
        if (line[0] == '\0') {
            continue;
        }

        DriverRecord driver;
        if (!parseLine(line, driver)) {
            clear();
            loadedCount = 0;
            return false;
        }

        if (!append(driver)) {
            clear();
            loadedCount = 0;
            return false;
        }

        ++loadedCount;
    }

    return loadedCount > 0;
}

bool DriverDatabase::getMostRecentLicense(DriverRecord& outDriver) const {
    if (!head) {
        return false;
    }

    Node* best = head;
    for (Node* current = head->next; current; current = current->next) {
        if (compareDates(current->data.licenseIssueDate, best->data.licenseIssueDate) > 0) {
            best = current;
        }
    }

    outDriver = best->data;
    return true;
}

bool DriverDatabase::getOldestLicense(DriverRecord& outDriver) const {
    if (!head) {
        return false;
    }

    Node* best = head;
    for (Node* current = head->next; current; current = current->next) {
        if (compareDates(current->data.licenseIssueDate, best->data.licenseIssueDate) < 0) {
            best = current;
        }
    }

    outDriver = best->data;
    return true;
}

bool DriverDatabase::findByLicenseNumber(const char* licenseNumber, DriverRecord& outDriver) const {
    for (Node* current = head; current; current = current->next) {
        if (std::strcmp(current->data.licenseNumber, licenseNumber) == 0) {
            outDriver = current->data;
            return true;
        }
    }
    return false;
}

bool runMember3Tests(const char* filePath) {
    DriverDatabase database;
    int loadedCount = 0;
    if (!database.loadFromFile(filePath, loadedCount)) {
        return false;
    }

    if (loadedCount != 100 || database.getSize() != 100) {
        return false;
    }

    DriverRecord recentLicense;
    DriverRecord oldestLicense;
    DriverRecord lookupResult;

    if (!database.getMostRecentLicense(recentLicense)) {
        return false;
    }
    if (!database.getOldestLicense(oldestLicense)) {
        return false;
    }
    if (!database.findByLicenseNumber("LIC0100", lookupResult)) {
        return false;
    }

    return std::strcmp(recentLicense.licenseNumber, "LIC0100") == 0 &&
           std::strcmp(oldestLicense.licenseNumber, "LIC0001") == 0 &&
           std::strcmp(lookupResult.firstName, "Driver100") == 0;
}
