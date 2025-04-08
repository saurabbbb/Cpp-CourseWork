#include <iostream>
using namespace std;

int main() {
    int startnum;    // Initial number that is used for starting
    int choice;     // out of the level choose one in this
    int max;        // highest number possible for the context
    int secret;     // number to be guessed by the program
    int guess;      // our guesses
    int tries = 0;  // number of tries it took to reach the final result of the found number


       do {
        cout << "Type any number to start (1-50): ";
        cin >> startnum;

        if (startnum < 1 || startnum > 50) {
            cout << "Invalid! The number must be between 1 and 50. Try again.\n";
        }
    } while (startnum < 1 || startnum > 50);  // Repeat until valid input


    // Show the game choices
    cout << "Pick a game:\n";
    cout << "1. Easy (1-8)\n";
    cout << "2. Medium (1-30)\n";
    cout << "3. Hard (1-50)\n";
    cout << "Type 1, 2, or 3: ";
    cin >> choice;


    if (choice == 1) {
        max = 8;
        secret = (startnum % 8) + 1;  // Leftover after dividing by 8, plus 1
    }
    else if (choice == 2) {
        max = 30;
        secret = (startnum % 30) + 1; // Leftover after dividing by 30, plus 1
    }
    else {
        max = 50;
        secret = (startnum % 50) + 1; // Leftover after dividing by 50, plus 1
    }

    // Start guessing
    cout << "Guess a number from 1 to " << max << ": ";
    do {
        cin >> guess;
        tries = tries + 1;

        if (guess < secret) {
            cout << "Too low! Guess again: ";
        }
        else if (guess > secret) {
            cout << "Too high! Guess again: ";
        }
    } while (guess != secret);

    // Tell you that you won
    cout << "You got it! The number was " << secret << "\n";
    cout << "It took you " << tries << " guesses\n";

    return 0;
}
