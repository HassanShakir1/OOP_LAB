#include <iostream>
#include <vector>
using namespace std;

class Menu {
public:
    string name;
    string type; 
    double price;

    Menu(string n, string t, double p) : name(n), type(t), price(p) {}
};

class CoffeeShop {
public:
    const string name;
    vector<Menu> menu;
    vector<string> orders;

    CoffeeShop(string n) : name(n) {}

    void addMenuItem(string name, string type, double price) {
        menu.push_back(Menu(name, type, price));
        cout << "\nItem added: " << name;
    }

    void addOrder(string item) {
        for (const auto& m : menu) {
            if (m.name == item) {
                orders.push_back(item);
                cout << "\nOrder added: " << item;
                return;
            }
        }
        cout << "\nThis item is currently unavailable!";
    }

    void fulfillOrder() {
        if (!orders.empty()) {
            cout << "\nThe " << orders.front() << " is ready!";
            orders.erase(orders.begin());
        } else {
            cout << "\nAll orders have been fulfilled!";
        }
    }

    void listOrders() {
        if (!orders.empty()) {
            cout << "\nCurrent orders:";
            for (const auto& order : orders) {
                cout << "\n- " << order;
            }
        } else {
            cout << "\nNo orders yet.";
        }
    }

    double dueAmount() {
        double total = 0;
        for (const auto& order : orders) {
            for (const auto& m : menu) {
                if (m.name == order) {
                    total += m.price;
                    break;
                }
            }
        }
        return total;
    }

    string getCheapestItem() {
        if (menu.empty()) return "No items on the menu!";
        
        const Menu* cheapest = &menu[0];
        for (const auto& m : menu) {
            if (m.price < cheapest->price) {
                cheapest = &m;
            }
        }
        return cheapest->name;
    }

    void displayDrinksOnly() {
        cout << "\nDrinks available:";
        for (const auto& m : menu) {
            if (m.type == "drink") {
                cout << "\n- " << m.name;
            }
        }
    }

    void displayFoodOnly() {
        cout << "\nFood available:";
        for (const auto& m : menu) {
            if (m.type == "food") {
                cout << "\n- " << m.name;
            }
        }
    }
};

int main() {
    CoffeeShop shop("Java Cafe");

    shop.addMenuItem("Cappuccino", "drink", 3.50);
    shop.addMenuItem("Latte", "drink", 4.00);
    shop.addMenuItem("Espresso", "drink", 2.50);
    shop.addMenuItem("Sandwich", "food", 5.00);
    shop.addMenuItem("Cake", "food", 3.00);

    shop.addOrder("Latte");
    shop.addOrder("Cake");
    shop.addOrder("Espresso");

    shop.listOrders();

    cout << "\nTotal amount due: $" << shop.dueAmount();

    shop.fulfillOrder();
    shop.fulfillOrder();
    shop.fulfillOrder();
    shop.fulfillOrder(); 

    cout << "\nCheapest item: " << shop.getCheapestItem();

    shop.displayDrinksOnly();
    shop.displayFoodOnly();

    return 0;
}
