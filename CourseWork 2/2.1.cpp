#include <iostream>
#include <fstream>
#include <cmath>  // for M_PI
using namespace std;

// Define M_PI if not available
#ifndef M_PI
    #define M_PI 3.14159265358979323846
#endif

// Circle class definition
class Circle {
private:
    float radius;  // private member for radius

public:
    // constructor to initialize the radius
    Circle(float r) : radius(r) {}

    // function to calculate area of the circle, marked as const
    float area() const {
        return M_PI * radius * radius;  // area formula
    }

    // friend function to compare two circles
    friend void compareTwoCircles(const Circle& c1, const Circle& c2, ofstream& outFile);
};

// friend function to compare two circles
void compareTwoCircles(const Circle& c1, const Circle& c2, ofstream& outFile) {
    float area1 = c1.area();  // area of first circle
    float area2 = c2.area();  // area of second circle

    // Compare areas and write the result to the output file
    if (area1 > area2) {
        outFile << "Circle 1 has a larger area." << endl;
    } else if (area1 < area2) {
        outFile << "Circle 2 has a larger area." << endl;
    } else {
        outFile << "Both circles have the same area." << endl;
    }
}

int main() {
    // Open the input file
    ifstream inFile("input.txt");

    // Check if the file was opened successfully
    if (!inFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    // Read the radii for the two circles from the input file
    float radius1, radius2;
    inFile >> radius1 >> radius2;

    // Close the input file after reading
    inFile.close();

    // Create two Circle objects with the given radii
    Circle circle1(radius1);
    Circle circle2(radius2);

    // Open the output file
    ofstream outFile("output.txt");

    // Check if the file was opened successfully
    if (!outFile) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    // Compare the two circles and write the result to the output file
    compareTwoCircles(circle1, circle2, outFile);

    // Close the output file after writing
    outFile.close();

    cout << "Comparison result has been written to 'output.txt'" << endl;

    return 0;
}
