#include <iostream>
using namespace std;


void displaySeats(char seats[5][5]) {
    cout << "Current seating arrangement:\n";
    cout << "  1 2 3 4 5\n";
    for (int row = 0; row < 5; row++) {
        cout << row + 1 << " ";
        for (int col = 0; col < 5; col++) {
            cout << seats[row][col] << " ";
        }
        cout << endl;
    }
}


bool bookSeat(char seats[5][5], int row, int col) {
    if (seats[row][col] == 'X') {
        return false;
    }
    seats[row][col] = 'X';
    return true;
}

int main() {
    char seats[5][5] = {
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'},
        {'O', 'O', 'O', 'O', 'O'}
    };

    int totalBookings = 0;
    while (true) {
        displaySeats(seats);

        cout << "Let's book a seat! Please tell me the row (1-5): ";
        int row, col;

        cin >> row;
        if (row == 0) break;

        cout << "Which column (1-5)? ";
        cin >> col;
        if (col == 0) break;

        if (row < 1 || row > 5 || col < 1 || col > 5) {
            cout << "Oops! That seat selection is out of range. Please enter values between 1 and 5.\n";
            continue;
        }


        row--; // adjustment for array
        col--;

        if (!bookSeat(seats, row, col)) {
            cout << "Sorry, that seat is already taken. Please try another one.\n";
            continue; // will try again if the seat is taken
        }

        totalBookings++; // Increment the total bookings
        cout << "Great! Your seat has been booked successfully!\n";

        char choice;
        cout << "Would you like to book more seats? (y/n): ";
        cin >> choice;

        if (choice == 'n' || choice == 'N') {
            cout << "Thank you for using our cinema ticket booking system. You've booked a total of " << totalBookings << " seats.\n";
            cout << "Exiting the system...\n";
            break;
        }
    }

    return 0;
}
