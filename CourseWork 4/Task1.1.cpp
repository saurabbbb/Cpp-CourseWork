#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <limits>  // For numeric_limits

using namespace std;

// Function to check if input is a valid integer
bool isValidInteger(int& input) {
    if (cin.fail()) {
        cin.clear();  // Clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
        return false;
    }
    return true;
}

// Add name and age
void addNameAgePair(vector<string>& names, map<string, int>& ageMap) {
    string name;
    int age;

    cout << "\nEnter name: ";
    cin >> name;

    // Check for empty name input
    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        return;
    }

    cout << "Enter age: ";
    cin >> age;

    // Validate age input
    while (!isValidInteger(age) || age <= 0) {
        cout << "Please enter a valid positive integer for age: ";
        cin >> age;
    }

    names.push_back(name);
    ageMap[name] = age;

    cout << "Added successfully.\n";
}

// Show people older than a certain age
void findPeopleAboveAge(const map<string, int>& ageMap) {
    int threshold;
    cout << "\nShow people older than: ";
    cin >> threshold;

    // Validate threshold
    while (!isValidInteger(threshold) || threshold <= 0) {
        cout << "Please enter a valid positive integer for age: ";
        cin >> threshold;
    }

    cout << "\nPeople older than " << threshold << ":\n";
    for (const auto& person : ageMap) {
        if (person.second > threshold) {
            cout << person.first << " - " << person.second << " years\n";
        }
    }
}

// Show all names in alphabetical order
void sortAndDisplayNames(const vector<string>& names) {
    vector<string> sorted = names;
    sort(sorted.begin(), sorted.end());

    cout << "\nNames (sorted):\n";
    for (const auto& name : sorted) {
        cout << name << endl;
    }
}

// Input validation function
int getValidChoice() {
    int choice;
    while (true) {
        cout << "Select an option: ";
        cin >> choice;

        if (isValidInteger(choice) && (choice >= 0 && choice <= 3)) {
            return choice;  // Return the valid input
        } else {
            cout << "Invalid choice. Please enter a number between 0 and 3.\n";
        }
    }
}

int main() {
    vector<string> names;
    map<string, int> ageMap;
    int choice;

    while (true) {
        cout << "\n=== MENU ===\n";
        cout << "1. Add name and age\n";
        cout << "2. Show people above a certain age\n";
        cout << "3. Show all names (sorted)\n";
        cout << "0. Exit\n";

        choice = getValidChoice();

        switch (choice) {
            case 1:
                addNameAgePair(names, ageMap);
                break;
            case 2:
                findPeopleAboveAge(ageMap);
                break;
            case 3:
                sortAndDisplayNames(names);
                break;
            case 0:
                cout << "\nExiting program.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
