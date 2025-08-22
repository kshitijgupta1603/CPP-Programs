#include <iostream>
#include <iomanip> // For std::setw
#include <string>  // For std::string

using namespace std;

// Function to calculate the starting day of the month (0 for Sunday, 1 for Monday, etc.)
// Uses Zeller's congruence algorithm
int getStartDay(int month, int year) {
    int day = 1; // We always check for the 1st day of the month
    int m[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    if (month < 3) { // Adjust month and year for January and February
        year--;
    }
    // Zeller's congruence formula
    return (year + year / 4 - year / 100 + year / 400 + m[month - 1] + day) % 7;
}

// Function to print the calendar for a given month and year
void printCalendar(int month, int year) {
    // Array of month names
    string months[] = { "January", "February", "March", "April", "May", "June",
                        "July", "August", "September", "October", "November", "December" };
    // Array of days in each month (non-leap year)
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // Check for leap year and adjust days in February
    if (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) {
        daysInMonth[1] = 29;
    }

    // Get the starting day of the month (0=Sunday, 1=Monday, ...)
    int startDay = getStartDay(month, year);

    // Print calendar header
    cout << "\nCalendar for " << months[month - 1] << " " << year << endl;
    cout << "Sun Mon Tue Wed Thu Fri Sat" << endl;

    // Print leading spaces for the first week
    for (int i = 0; i < startDay; i++) {
        cout << "    "; // 4 spaces for alignment with setw(3) + 1 space
    }

    // Print days of the month
    for (int i = 1; i <= daysInMonth[month - 1]; i++) {
        cout << setw(3) << i << " "; // Set width to 3 for number, then a space
        if ((i + startDay) % 7 == 0) { // If it's Saturday (end of week)
            cout << endl; // Move to the next line
        }
    }
    cout << endl; // Ensure a newline at the end of the month
}

int main() {
    int month, year;

    // Get month and year input from the user
    cout << "Enter month (1-12): ";
    cin >> month;
    cout << "Enter year: ";
    cin >> year;

    // Validate month input
    if (month < 1 || month > 12) {
        cout << "Invalid month entered. Please enter a number between 1 and 12.\n";
        return 1; // Indicate an error
    }

    // Print the calendar
    printCalendar(month, year);

    return 0; // Indicate successful execution
}