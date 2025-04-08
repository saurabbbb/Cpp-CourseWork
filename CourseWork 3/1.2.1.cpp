#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

using namespace std;

class Vehicle {
protected:
    string registrationNumber;
    string color;

public:
    Vehicle(string regNo, string col) : registrationNumber(regNo), color(col) {}

    virtual void writeDetailsToFile() {
        ofstream file("vehicle_details.txt", ios::app);
        if (!file) {
            throw runtime_error("Error opening file!");
        }
        file << "Vehicle Registration Number: " << registrationNumber << endl;
        file << "Vehicle Color: " << color << endl;
        file.close();
    }

    virtual ~Vehicle() {}
};

class Car : public Vehicle {
private:
    int seats;

public:
    Car(string regNo, string col, int s) : Vehicle(regNo, col), seats(s) {}

    void writeDetailsToFile() override {
        ofstream file("vehicle_details.txt", ios::app);
        if (!file) {
            throw runtime_error("Error opening file!");
        }
        file << "Car Registration Number: " << registrationNumber << endl;
        file << "Car Color: " << color << endl;
        file << "Seats: " << seats << endl;
        file.close();
    }
};

class Bike : public Vehicle {
private:
    int engineCapacity;

public:
    Bike(string regNo, string col, int engCap) : Vehicle(regNo, col), engineCapacity(engCap) {}

    void writeDetailsToFile() override {
        ofstream file("vehicle_details.txt", ios::app);
        if (!file) {
            throw runtime_error("Error opening file!");
        }
        file << "Bike Registration Number: " << registrationNumber << endl;
        file << "Bike Color: " << color << endl;
        file << "Engine Capacity: " << engineCapacity << "cc" << endl;
        file.close();
    }
};

int main() {
    try {
        Vehicle *vehicle1 = new Car("Ba 12 Pa 1234", "Red", 4);
        vehicle1->writeDetailsToFile();

        Vehicle *vehicle2 = new Bike("Ga 34 Pa 5678", "Black", 150);
        vehicle2->writeDetailsToFile();

        Vehicle *vehicle3 = new Car("Ba 23 Pa 2345", "Blue", 5);
        vehicle3->writeDetailsToFile();

        Vehicle *vehicle4 = new Bike("Sa 56 Pa 6789", "White", 200);
        vehicle4->writeDetailsToFile();

        Vehicle *vehicle5 = new Car("Ka 78 Pa 3456", "Silver", 4);
        vehicle5->writeDetailsToFile();

        cout << "Details of vehicles have been written to the file successfully!" << endl;

        delete vehicle1;
        delete vehicle2;
        delete vehicle3;
        delete vehicle4;
        delete vehicle5;

    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
