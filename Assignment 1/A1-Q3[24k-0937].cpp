#include <iostream>
using namespace std;

class Car {
    string model;
    float price;
    string eligibility;

public:
    Car(string m, float p, string e) : model(m), price(p), eligibility(e) {}

    void showCarDetails() {
        cout << "\n Model : " << model;
        cout << "\n Price : " << price;
        cout << "\n Eligibility : " << eligibility;
    }

    string getCarModel() {
        return model;
    }

    string getCarEligibility() {
        return eligibility;
    }
};

class User {
    int UserId;
    string name;
    string licence;
    int number;
    int age;

public:
    User(int id, string n, string l, int num,int a) : UserId(id), name(n), licence(l), number(num),age(a) {}

    void showUserDetails() {
        cout << "\n User ID : " << UserId;
        cout << "\n User Name : " << name;
        cout << "\n User Licence : " << licence;
        cout << "\n User Number : " << number;
    }

    void updateName(string n) {
        name = n;
        cout << "\n Name Updated";
    }

    void updateAge(int a) {
        age = a;
        cout << "\n Age Updated";
    }
    void updateNumber(int num) {
        number = num;
        cout << "\n Number Updated";
    }

    void updateLicence(string l) {
        licence = l;
        cout << "\n Licence Updated";
    }

    int getUserId() {
        return UserId;
    }

    string getLicence() {
        return licence;
    }
};

class Store {
    Car** cars;
    int carCount;
    int carCapacity;
    User** users;
    int userCount;
    int userCapacity;

public:
    Store() : carCapacity(10), carCount(0), userCapacity(10), userCount(0) {
        cars = new Car*[carCapacity];
        users = new User*[userCapacity];
    }

    void storeCar(Car* c) {
        if (carCount < carCapacity) {
            cars[carCount] = c;
            carCount++;
            cout << "\n Car Stored";
        } else {
            carCapacity *= 2;
            Car** temp = new Car*[carCapacity];
            for (int i = 0; i < carCount; i++) {
                temp[i] = cars[i];
            }
            delete[] cars;
            cars = temp;

            cars[carCount] = c;
            carCount++;
            cout << "\n Car Stored";
        }
    }

    void userRegistration(User* u) {
        if (userCount < userCapacity) {
            users[userCount] = u;
            userCount++;
            cout << "\n User Registered";
        } else {
            userCapacity *= 2;
            User** temp = new User*[userCapacity];
            for (int i = 0; i < userCount; i++) {
                temp[i] = users[i];
            }
            delete[] users; // Fix: Move deletion outside of loop
            users = temp;

            users[userCount] = u;
            userCount++;
            cout << "\n User Registered";
        }
    }

    void viewCars() {
        for (int i = 0; i < carCount; i++) {
            cars[i]->showCarDetails();
        }
    }

    void viewUsers() {
        for (int i = 0; i < userCount; i++) {
            users[i]->showUserDetails();
        }
    }

    void rent(User* u) {
        for (int i = 0; i < userCount; i++) {
            if (users[i]->getUserId() == u->getUserId()) {
                cout << "\n List of available cars : \n ";
                for (int j = 0; j < carCount; j++) {
                    cars[j]->showCarDetails();
                }
                string selection;
                cout << "\n Enter the model of the car you want to rent : ";
                getline(cin, selection);
                int flag = 0;
                for (int i = 0; i < carCount; i++) {
                    if (cars[i]->getCarModel() == selection) {
                        if ( u->getLicence()=="Full") {
                            cout << "\n Car Rented";
                            flag=1;
                        }else if(u->getLicence()=="Intermediate"){
                            if(cars[i]->getCarEligibility()=="Learner" || cars[i]->getCarEligibility()=="Intermediate"){
                                cout << "\n Car Rented";
                                flag=1;
                            }else{
                                cout << "\n User not eligible to rent this car";
                            }
                        }else if (u->getLicence()=="Learner")
                        {
                            if(cars[i]->getCarEligibility()=="Learner"){
                                cout << "\n Car Rented";
                                flag=1;
                            }else{
                                cout << "\n User not eligible to rent this car";
                            }
                        }
                        break; 
                    }
                }
                if (flag == 0) {
                    cout << "\n Car not found";
                }
            }
        }
    };
    void removeCar(Car* c) {
        int flag = 0;
        for (int i = 0; i < carCount; i++) {
            if (cars[i]->getCarModel() == c->getCarModel()) {
                for (int j = i; j < carCount - 1; j++) {
                    cars[j] = cars[j + 1];
                }
                flag = 1;
                carCount--;
            }
        }
        if (flag) {
            cout << "\n Car Removed";
        } else {
            cout << "\n Car Not Found";
        }
    }

    ~Store() { 
        for (int i = 0; i < carCount; i++)
            delete cars[i];
        delete[] cars;

        for (int i = 0; i < userCount; i++)
            delete users[i];
        delete[] users;
    }
};
int main() {
    Store store;

    User* user1 = new User(1, "Alice", "Full",1112233, 25);
    User* user2 = new User(2, "Bob", "Learner", 11223344,20);
    
    store.userRegistration(user1);
    store.userRegistration(user2);

    Car* car1 = new Car("Toyota Corolla", 25000, "Full");
    Car* car2 = new Car("Honda Civic", 27000, "Learner");
    Car* car3 = new Car("Ford Mustang", 50000, "Full");

    store.storeCar(car1);
    store.storeCar(car2);
    store.storeCar(car3);

    cout << "\n--- Registered Users ---\n";
    store.viewUsers();

    cout << "\n--- Available Cars ---\n";
    store.viewCars();

    cout << "\n--- Renting a Car ---\n";
    store.rent(user1);  

    cout << "\n--- Removing a Car ---\n";
    store.removeCar(car2); 

    cout << "\n--- Available Cars After Removal ---\n";
    store.viewCars();
    return 0;
}