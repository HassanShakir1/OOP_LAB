#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Base class for all employees
class Employee {
protected:
    int id;
    string name;
public:
    Employee(int id, const string& name) : id(id), name(name) {}

    void showDetails() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
};

// Interface for taking orders
class IOrderTaker {
public:
    virtual void takeOrder(string order) = 0;
};

// Interface for preparing orders
class IOrderPreparer {
public:
    virtual void prepareOrder(string order) = 0;
};

// Interface for billing
class IBiller {
public:
    virtual void generateBill(double amount) = 0;
};

// Waiter can take orders
class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int id, string name) : Employee(id, name) {}

    void takeOrder(string order) override {
        cout << name << " (Waiter) took the order: " << order << endl;
    }
};

// Chef can prepare orders
class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int id, string name) : Employee(id, name) {}

    void prepareOrder(string order) override {
        cout << name << " (Chef) is preparing: " << order << endl;
    }
};

// Cashier can generate bills
class Cashier : public Employee, public IBiller {
public:
    Cashier(int id, string name) : Employee(id, name) {}

    void generateBill(double amount) override {
        cout << name << " (Cashier) generated a bill of $" << amount << endl;
    }
};

// Menu base class
class Menu {
protected:
    vector<pair<string, double>> items;
public:
    void addItem(string name, double price) {
        items.push_back({name, price});
    }

    void showMenu() {
        for (auto& item : items) {
            cout << item.first << " - $" << item.second << endl;
        }
    }

    virtual double calculateTotalCost() = 0;
};

// FoodMenu class
class FoodMenu : public Menu {
public:
    double calculateTotalCost() override {
        double total = 0;
        for (auto& item : items) {
            total += item.second;
        }
        return total;
    }
};

// BeverageMenu class
class BeverageMenu : public Menu {
public:
    double calculateTotalCost() override {
        double total = 0;
        for (auto& item : items) {
            total += item.second * 1.1; // 10% beverage tax
        }
        return total;
    }
};

// Main function
int main() {
    // Employees
    Waiter w1(101, "Alice");
    Chef c1(102, "Bob");
    Cashier ca1(103, "Charlie");

    // Taking orders
    w1.takeOrder("Burger");
    w1.takeOrder("Coffee");

    // Preparing orders
    c1.prepareOrder("Burger");
    c1.prepareOrder("Coffee");

    // Menus
    FoodMenu foodMenu;
    foodMenu.addItem("Burger", 8.99);
    foodMenu.addItem("Pizza", 12.49);

    BeverageMenu beverageMenu;
    beverageMenu.addItem("Coke", 2.50);
    beverageMenu.addItem("Coffee", 3.99);

    cout << "\nFood Menu:\n";
    foodMenu.showMenu();
    cout << "Total Food Cost: $" << foodMenu.calculateTotalCost() << endl;

    cout << "\nBeverage Menu:\n";
    beverageMenu.showMenu();
    cout << "Total Beverage Cost: $" << beverageMenu.calculateTotalCost() << endl;

    // Generating bill
    double totalBill = foodMenu.calculateTotalCost() + beverageMenu.calculateTotalCost();
    ca1.generateBill(totalBill);

    return 0;
}
