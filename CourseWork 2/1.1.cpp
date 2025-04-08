#include <iostream>
#include <vector>
#include <string>

// class to handle student info and grades
class Student {
private:
    std::string name; // student name
    std::vector<int> marks; // marks for subjects

public:
    Student(std::string studentName, std::vector<int> subjectMarks)
        : name(studentName), marks(subjectMarks) {}

    int calculateTotal() {
        int total = 0;
        for (int mark : marks) total += mark; // sum marks
        return total;
    }

    double calculateAverage() {
        return static_cast<double>(calculateTotal()) / marks.size(); // average
    }

    char calculateGrade() {
        double average = calculateAverage();
        if (average >= 90) return 'A';
        if (average >= 80) return 'B';
        if (average >= 70) return 'C';
        if (average >= 60) return 'D';
        return 'F'; // failing grade
    }

    void displayDetails() {
        // display student info and results
        std::cout << "\nstudent name: " << name << std::endl;
        std::cout << "total marks: " << calculateTotal() << std::endl;
        std::cout << "average marks: " << calculateAverage() << std::endl;
        std::cout << "grade: " << calculateGrade() << std::endl;
    }
};

// check if a mark is valid
bool isValidMark(int mark) { return mark >= 0 && mark <= 100; }

int main() {
    std::string name;
    std::vector<int> marks(3); // store three marks

    // get student name
    std::cout << "enter student name: ";
    std::getline(std::cin, name);

    // loop to enter marks
    for (int i = 0; i < 3; i++) {
        while (true) {
            std::cout << "enter mark for subject " << (i + 1) << " (0-100): ";
            int mark;
            std::cin >> mark;

            if (isValidMark(mark)) { // check validity
                marks[i] = mark; // store valid mark
                break; // exit loop
            } else {
                std::cout << "invalid mark! please enter between 0 and 100." << std::endl;
            }
        }
    }

    Student student(name, marks); // create student object
    student.displayDetails(); // show results

    return 0; // end program
}
