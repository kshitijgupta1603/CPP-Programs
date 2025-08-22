#include <iostream>
#include <string>
using namespace std;

struct Student {
    string first_Name;
    string last_Name;
    int roll_no;
    string branch;
    float percent;
} st[2];

int main() {
    cout << "Enter data of students\n";
    for (int i = 0; i < 2; i++) {
        cout << "Enter first name: ";
        cin >> st[i].first_Name;
        cout << "Enter last name: ";
        cin >> st[i].last_Name;
        cout << "Enter Branch: ";
        cin >> st[i].branch;
        cout << "Enter Roll-No.: ";
        cin >> st[i].roll_no;
        cout << "Enter Percentage: ";
        cin >> st[i].percent;
    }

    cout << "\nDisplaying the Information:\n";
    for (int i = 0; i < 2; i++) {
        cout << "\nFirst name: " << st[i].first_Name << "\n";
        cout << "Last name: " << st[i].last_Name << "\n";
        cout << "Roll_No: " << st[i].roll_no << "\n";
        cout << "Branch: " << st[i].branch << "\n";
        cout << "Percentage: " << st[i].percent << "\n";
    }

    return 0;
}
