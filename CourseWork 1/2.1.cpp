#include <iostream>
using namespace std;

bool isBouncy(int num) {
    if (num < 100) return false;  // Not bouncy if less than 100

    bool increasing = false, decreasing = false;
    int lastDigit = num % 10;
    num /= 10;

    while (num > 0) {
        int currentDigit = num % 10;

        // Determine if the number is increasing or decreasing
        if (currentDigit < lastDigit) increasing = true;
        if (currentDigit > lastDigit) decreasing = true;

        if (increasing && decreasing) return true;

        lastDigit = currentDigit;
        num /= 10;
    }

    return false;  // Not bouncy
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (isBouncy(num)) {
        cout << num << " is a bouncy number!" << endl;
    } else {
        cout << num << " is NOT a bouncy number." << endl;
    }

    return 0;
}
