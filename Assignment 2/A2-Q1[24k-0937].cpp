#include<iostream>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string location;
    bool activeCard;
public:
    Person(string n, string i, string l) : name(n), id(i), location(l), activeCard(false) {}
    virtual void payFee() = 0;
    bool isCardActive() { return activeCard; }
    string getLocation() { return location; }
    string getName() { return name; }
    virtual ~Person() {}
};

class Student : public Person {
    int attendanceCount;
public:
    Student(string n, string i, string l) : Person(n, i, l), attendanceCount(0) {}
    void payFee()  { 
        activeCard = true;
        cout<<"\n Student Pay per semester"; 
    }
    void tap() {
        if (activeCard) attendanceCount++;
    }
};

class Teacher : public Person {
public:
    Teacher(string n, string i, string l) : Person(n, i, l) {}
    void payFee()  { 
        cout<<"\n Teacher Pay per month"; 
        activeCard = true; }
};

class Staff : public Person {
public:
    Staff(string n, string i, string l) : Person(n, i, l) {}
    void payFee()  { activeCard = true;
        cout<<"\n Staff Pay per month"; 
     }
};

class Route {
    int routeNumber;
    string stop;
public:
    Route(int r, string s) : routeNumber(r), stop(s) {}
    string getStop() { return stop; }
    int getRouteNumber() { return routeNumber; }
    bool operator==(const Route& other) { return routeNumber == other.routeNumber && stop == other.stop; }
};

class Routes {
    Route** routes;
    int routeCount;
    int routeCapacity;
    Person** people;
    int personCount;
    int personCapacity;
public:
    Routes() : routeCount(0), routeCapacity(10), personCount(0), personCapacity(10) {
        routes = new Route*[routeCapacity];
        people = new Person*[personCapacity];
    }
    ~Routes() {
        for (int i = 0; i < routeCount; i++) delete routes[i];
        delete[] routes;
        for (int i = 0; i < personCount; i++) delete people[i];
        delete[] people;
    }
    void storePerson(Person* p) {
        if (personCount >= personCapacity) {
            personCapacity *= 2;
            Person** temp = new Person*[personCapacity];
            for (int i = 0; i < personCount; i++) temp[i] = people[i];
            delete[] people;
            people = temp;
        }
        people[personCount++] = p;
    }
    void storeRoute(Route* r) {
        if (routeCount >= routeCapacity) {
            routeCapacity *= 2;
            Route** temp = new Route*[routeCapacity];
            for (int i = 0; i < routeCount; i++) temp[i] = routes[i];
            delete[] routes;
            routes = temp;
        }
        routes[routeCount++] = r;
    }
    void assignRoutes() {
        for (int i = 0; i < routeCount; i++) {
            for (int j = 0; j < personCount; j++) {
                if (people[j]->isCardActive() && people[j]->getLocation() == routes[i]->getStop()) {
                    cout << "\n" << people[j]->getName() << " assigned to Route " << routes[i]->getRouteNumber();
                }
            }
        }
    }
    Person* findPerson(string name) {
        for (int i = 0; i < personCount; i++) {
            if (people[i]->getName() == name) return people[i];
        }
        return nullptr;
    }
};

int main() {
    Routes system;
    while (true) {
        cout << "\n--- Transport System Menu ---";
        cout << "\n1. Register Student";
        cout << "\n2. Register Teacher";
        cout << "\n3. Register Staff";
        cout << "\n4. Pay Fee";
        cout << "\n5. Add Route";
        cout << "\n6. Assign Routes";
        cout << "\n7. Exit";
        cout << "\nEnter choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1 || choice == 2 || choice == 3) {
            string id, name, loc;
            cout << "\nEnter ID: ";
            getline(cin, id);
            cout << "Enter Name: ";
            getline(cin, name);
            cout << "Enter Location: ";
            getline(cin, loc);
            if (choice == 1) system.storePerson(new Student(name, id, loc));
            else if (choice == 2) system.storePerson(new Teacher(name, id, loc));
            else system.storePerson(new Staff(name, id, loc));
        } else if (choice == 4) {
            string name;
            cout << "\nEnter Name: ";
            getline(cin, name);
            Person* p = system.findPerson(name);
            if (p) p->payFee();
        } else if (choice == 5) {
            int number;
            string stop;
            cout << "\nEnter Route Number: ";
            cin >> number;
            cin.ignore();
            cout << "Enter Stop Name: ";
            getline(cin, stop);
            system.storeRoute(new Route(number, stop));
        } else if (choice == 6) {
            system.assignRoutes();
        } else if (choice == 7) {
            cout << "\nExiting System...\n";
            break;
        }
    }
    return 0;
}
