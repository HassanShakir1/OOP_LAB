#include <iostream>
#include <vector>
using namespace std;

class Car {
public:
    string name;
    int id;

    Car(string n, int i) : name(n), id(i) {}

    void display() const {
        cout << "Car ID: " << id << ", Name: " << name << endl;
    }
};

class Garage {
    vector<Car*> cars; 

public:
    void parkCar(Car* car) {
        if (car) {
            cars.push_back(car);
            cout << car->name << " is parked in the garage." << endl;
        }
    }

    void listCars() const {
        if (cars.empty()) {
            cout << "Garage is empty." << endl;
            return;
        }

        cout << "Cars in the garage:" << endl;
        for (const auto& car : cars) {
            car->display();
        }
    }
};

int main() {
    Car car1("Tesla Model S", 101);
    Car car2("BMW M5", 102);
    Car car3("Audi R8", 103);

    Garage garage;
    garage.parkCar(&car1);
    garage.parkCar(&car2);
    garage.parkCar(&car3);

    garage.listCars(); 

    return 0;
}
