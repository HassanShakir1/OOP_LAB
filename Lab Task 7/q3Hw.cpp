#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    int employeeID;
public:
    virtual void getData() {
        cin >> employeeID;
    }
    virtual void displayData() {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    float monthlyIncome;
public:
    void getData() override {
        Person::getData();
        cin.ignore();
        getline(cin, name);
        cin >> monthlyIncome;
    }

    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }

    float bonus() {
        return monthlyIncome * 12 * 0.05;
    }
};

class Accounts : public Person {
protected:
    string name;
    float monthlyIncome;
public:
    void getData() override {
        Person::getData();
        cin.ignore();
        getline(cin, name);
        cin >> monthlyIncome;
    }

    void displayData() override {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: " << monthlyIncome << endl;
        cout << "Bonus: " << bonus() << endl;
    }

    float bonus() {
        return monthlyIncome * 12 * 0.05;
    }
};

int main() {
    Admin adminEmployee;
    Accounts accountsEmployee;

    adminEmployee.getData();
    accountsEmployee.getData();

    cout << "\nAdmin Employee Info:\n";
    adminEmployee.displayData();

    cout << "\nAccounts Employee Info:\n";
    accountsEmployee.displayData();

    return 0;
}
