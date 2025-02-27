#include <iostream>
using namespace std;

class Student {
    const int roll_no;
    string name;

public:
    Student(int roll, string n) : roll_no(roll), name(n) {}

    void display() const {
        cout << "\nStudent Name: " << name;
        cout << "\nRoll Number: " << roll_no << endl;
    }
};

int main() {
    int roll;
    string name;

    cout << "Enter Student Name: ";
    getline(cin, name);
    cout << "Enter Roll Number: ";
    cin >> roll;

    Student s1(roll, name);
    s1.display();

    return 0;
}
