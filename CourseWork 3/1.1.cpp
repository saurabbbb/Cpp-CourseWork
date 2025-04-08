#include <iostream>
#include <stdexcept>  // For exceptions

using namespace std;

// Custom exception class for invalid time
class InvalidTimeException : public exception {
public:
    const char* what() const noexcept override {
        return "Invalid time! Hours should be less than 24 and minutes less than 60.";
    }
};

class Time {
private:
    int hours;
    int minutes;

    // Validates time: hours < 24 and minutes < 60
    void validateTime() {
        if (hours >= 24 || minutes >= 60) {
            throw InvalidTimeException();  // Throw an exception for invalid time
        }
    }

public:
    // Constructor to initialize the time
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        validateTime();  // Validate time upon creation
    }

    // Overload the + operator to add two Time objects
    Time operator+(const Time& other) {
        int newMinutes = minutes + other.minutes;
        int newHours = hours + other.hours + (newMinutes / 60);  // Add hours from overflowed minutes
        newMinutes %= 60;  // Ensure minutes are within range

        if (newHours >= 24) {
            newHours = newHours % 24;  // Adjust hours if overflowed beyond 24
        }

        return Time(newHours, newMinutes);  // Return new time object
    }

    // Overload the > operator to compare two Time objects
    bool operator>(const Time& other) const {
        if (hours > other.hours) return true;
        if (hours == other.hours && minutes > other.minutes) return true;
        return false;
    }

    // Display the time in HH:MM format
    void display() const {
        cout << hours << ":" << (minutes < 10 ? "0" : "") << minutes << endl;
    }

    // Setters for time (to be used for reassigning time if needed)
    void setTime(int h, int m) {
        hours = h;
        minutes = m;
        validateTime();  // Validate time after setting new values
    }
};

int main() {
    int hour, minute;

    try {
        // Take user input for Time 1
        cout << "Enter Time 1 (hours minutes): ";
        cin >> hour >> minute;
        Time time1(hour, minute);  // Create Time object for Time 1

        // Take user input for Time 2
        cout << "Enter Time 2 (hours minutes): ";
        cin >> hour >> minute;
        Time time2(hour, minute);  // Create Time object for Time 2

        // Display both times
        cout << "Time 1: ";
        time1.display();
        cout << "Time 2: ";
        time2.display();

        // Add both times
        Time time3 = time1 + time2;
        cout << "Sum of Time 1 and Time 2: ";
        time3.display();

        // Compare times
        if (time1 > time2) {
            cout << "Time 1 is greater than Time 2.\n";
        } else {
            cout << "Time 2 is greater than or equal to Time 1.\n";
        }
    } catch (const InvalidTimeException& e) {
        // Catch invalid time exception
        cout << e.what() << endl;
    } catch (const exception& e) {
        // Catch any other unexpected exceptions
        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}
