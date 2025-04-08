#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int size;


    cout << "How many numbers do you want to enter? ";
    cin >> size;


    int numbers[size];


    cout << "Enter " << size << " numbers:\n";
    for (int i = 0; i < size; i++) {
        cin >> numbers[i];
    }


    sort(numbers, numbers + size);


    cout << "Sorted numbers in ascending order:\n";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";

    return 0;
}
