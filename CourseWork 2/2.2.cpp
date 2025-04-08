
#include <iostream>

// function to find maximum between two integers
int findMax(int a, int b) {
    return (a > b) ? a : b;
}

// function to find maximum between two floating-point numbers
float findMax(float a, float b) {
    return (a > b) ? a : b;
}

// function to find maximum among three integers
int findMax(int a, int b, int c) {
    return findMax(findMax(a, b), c); // use existing function for two integers
}

// function to find maximum between an integer and a float
float findMax(int a, float b) {
    return (static_cast<float>(a) > b) ? static_cast<float>(a) : b; // compare and return as float
}

int main() {
    // testing the function overloads
    std::cout << "Max of 10 and 20: " << findMax(10, 20) << std::endl; // integer max
    std::cout << "Max of 10.5 and 20.2: " << findMax(10.5f, 20.2f) << std::endl; // float max
    std::cout << "Max of 10, 20, 30: " << findMax(10, 20, 30) << std::endl; // max of three integers
    std::cout << "Max of 15 and 10.5: " << findMax(15, 10.5f) << std::endl; // integer and float max

    return 0; // end of program
}
