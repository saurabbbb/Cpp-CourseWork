#include <iostream>
using namespace std;

int main() {
    int day;


    do {
        cout << "Enter a number (1-7) to find the day of the week: ";
        cin >> day;

        // Check the number and print the day
        if (day == 1) {
            cout << "Sunday\n";
        }
        else if (day == 2) {
            cout << "Monday\n";
        }
        else if (day == 3) {
            cout << "Tuesday\n";
        }
        else if (day == 4) {
            cout << "Wednesday\n";
        }
        else if (day == 5) {
            cout << "Thursday\n";
        }
        else if (day == 6) {
            cout << "Friday\n";
        }
        else if (day == 7) {
            cout << "Saturday\n";
        }
        else {
            cout << "Invalid number! Please enter a number between 1 and 7.\n";
        }
    } while (day < 1 || day > 7);
    return 0;
}
