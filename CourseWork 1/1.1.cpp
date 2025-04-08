#include <iostream>
using namespace std;

int main() {
double Temperature;
char unit;

cout << "Please enter a temperature value: ";
cin >> Temperature;
cout << "Choose conversion:\n";
cout << "  [C] for Celsius\n";
cout << "  [F] for Fahrenheit\n";
cout << "Your choice: ";
cin >> unit;
if (unit == 'C' || unit == 'c') //case sensitive approach might trigger an error//
{
double result = (Temperature- 32) * 5 / 9; //calculations
cout << Temperature << "F = " << result << "C" << endl; //Fahrenheit conversion output
}
else if (unit == 'F' || unit == 'f')
{
double result = (Temperature * 9 / 5) + 32;  //calculations
cout << Temperature<< "C = " << result << "F" << endl; //Celsius conversion output
}
else
{
cout << "Unacceptable please consider selecting 'C' or 'F' only" << endl;
}
return 0;
}

