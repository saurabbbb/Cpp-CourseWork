#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>
#include <vector>
#include <iomanip>

using namespace std;

class Student {
public:
    int rollNo;
    string name;
    int marks;

    Student(int roll, string n, int m) : rollNo(roll), name(n), marks(m) {}
};

class StudentRecords {
private:
    vector<Student> students;

    void validateMarks(int marks) {
        if (marks < 0 || marks >= 100) {
            throw invalid_argument("Marks should be between 0 and 99.");
        }
    }

public:
    void addStudent(int roll, string name, int marks) {
        validateMarks(marks);
        students.push_back(Student(roll, name, marks));
    }

    void saveToFile(const string& fileName) {
        ofstream file(fileName);
        if (!file) {
            throw runtime_error("Error opening file!");
        }

        for (const auto& student : students) {
            file << student.rollNo << " " << student.name << " " << student.marks << endl;
        }

        file.close();
    }

    void displayRecords() {
        cout << left << setw(10) << "Roll No" << setw(20) << "Name" << setw(10) << "Marks" << endl;
        for (const auto& student : students) {
            cout << left << setw(10) << student.rollNo << setw(20) << student.name << setw(10) << student.marks << endl;
        }
    }
};

int main() {
    StudentRecords recordSystem;

    try {
        recordSystem.addStudent(1, "Saurabh", 88);
        recordSystem.addStudent(2, "Sujal", 75);
        recordSystem.addStudent(3, "Nitesh", 92);
        recordSystem.addStudent(4, "Priyanshu", 85);
        recordSystem.addStudent(5, "Prasanna", 79);
        recordSystem.addStudent(6, "Shirish", 90);

        recordSystem.saveToFile("students.txt");

        cout << "Records have been saved!" << endl;

    } catch (const invalid_argument& e) {
        cout << "Invalid input: " << e.what() << endl;
    } catch (const runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}
