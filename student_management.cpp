#include <iostream>
#include <vector>
#include <string>
#include <limits> // Required for numeric_limits

using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Constructor to initialize student data
    Student(string n, int r, float m) : name(n), rollNumber(r), marks(m) {}

    // Function to display student information
    void displayStudent() const {
        cout << "Name: " << name << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Marks: " << marks << endl;
    }

    // Function to get roll number
    int getRollNumber() const {
        return rollNumber;
    }
};

class StudentManagementSystem {
private:
    vector<Student> students;

public:
    // Function to add a new student
    void addStudent(const string& name, int rollNumber, float marks) {
        // Optional: Check for duplicate roll numbers before adding
        for (const auto& student : students) {
            if (student.getRollNumber() == rollNumber) {
                cout << "Error: Student with Roll Number " << rollNumber << " already exists." << endl;
                return;
            }
        }
        students.push_back(Student(name, rollNumber, marks));
        cout << "Student added successfully!" << endl;
    }

    // Function to display all students
    void displayAllStudents() const {
        if (students.empty()) {
            cout << "No students found." << endl;
            return;
        }
        cout << "\n--- All Students ---\n";
        for (const auto& student : students) {
            student.displayStudent();
            cout << "--------------------\n"; // Separator for better readability
        }
    }

    // Function to search for a student by roll number
    void searchStudentByRollNumber(int rollNumber) const {
        bool found = false;
        for (const auto& student : students) {
            if (student.getRollNumber() == rollNumber) {
                cout << "\n--- Student Found ---\n";
                student.displayStudent();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with Roll Number " << rollNumber << " not found." << endl;
        }
    }
};

int main() {
    StudentManagementSystem sms;

    int choice;
    string name;
    int rollNumber;
    float marks;

    do {
        cout << "\n--- Student Management System ---" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display All Students" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Clear input buffer after reading an integer
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                // Add a new student
                cout << "Enter student's name: ";
                getline(cin, name); // Use getline for names with spaces
                cout << "Enter roll number: ";
                cin >> rollNumber;
                cout << "Enter marks: ";
                cin >> marks;
                // Clear input buffer after reading numerical inputs if followed by getline
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                sms.addStudent(name, rollNumber, marks);
                break;

            case 2:
                // Display all students
                sms.displayAllStudents();
                break;

            case 3:
                // Search student by roll number
                cout << "Enter roll number to search: ";
                cin >> rollNumber;
                // Clear input buffer
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                sms.searchStudentByRollNumber(rollNumber);
                break;

            case 4:
                cout << "Exiting the system..." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}