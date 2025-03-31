#include <iostream>
using namespace std;

class Vehicle {
protected:
    int Id;
    int speed;
    int energyEfficiency;
    int capacity;
    static int activeDeliveries;

public:
    Vehicle(int i, int s, int e, int c) : Id(i), speed(s), energyEfficiency(e), capacity(c) {}

    virtual void delivery(int packageId) = 0;
    virtual void delivery(int packageId, string urgency) = 0;
    virtual void calculateTime() { cout << endl << Id << " is estimating delivery time...\n"; }
    virtual void calculateRoute() { cout << endl << Id << " is calculating route...\n"; }
    static void showTotalDeliveries() {
        cout << "\nTotal active deliveries: " << activeDeliveries << endl;
    }
    virtual ~Vehicle() {
        if (activeDeliveries > 0) activeDeliveries--;
    }

    bool operator==(const Vehicle &v) {
        return (speed == v.speed && capacity == v.capacity && energyEfficiency == v.energyEfficiency);
    }

    friend Vehicle* resolveConflict(Vehicle* v1, Vehicle* v2);
};

Vehicle* resolveConflict(Vehicle* v1, Vehicle* v2) {
    cout << "\nResolving AI conflict between " << v1->Id << " and " << v2->Id << "...";

    int score1 = v1->speed + v1->capacity + v1->energyEfficiency;
    int score2 = v2->speed + v2->capacity + v2->energyEfficiency;

    if (score1 > score2) {
        cout << "\nVehicle " << v1->Id << " is chosen for the delivery.\n";
        return v1;
    } else {
        cout << "\nVehicle " << v2->Id << " is chosen for the delivery.\n";
        return v2;
    }
}

class RamadanDrone : public Vehicle {
public:
    RamadanDrone(int i, int s, int e, int c) : Vehicle(i, s, e, c) {}

    void delivery(int packageId) {
        activeDeliveries++;
        cout << "\n" << Id << " is delivering package " << packageId << " at normal speed: " << speed;
    }

    void delivery(int packageId, string urgency) {
        activeDeliveries++;
        cout << "\n" << Id << " is delivering package " << packageId << " at high speed: " << speed * 2;
    }
};

class RamadanHyperPod : public Vehicle {
public:
    RamadanHyperPod(int i, int s, int e, int c) : Vehicle(i, s, e, c) {}

    void delivery(int packageId) {
        activeDeliveries++;
        cout << "\n" << Id << " is delivering bulk package " << packageId << " through underground tunnel.";
    }

    void delivery(int packageId, string urgency) {
        activeDeliveries++;
        cout << "\n" << Id << " is prioritizing urgent bulk delivery " << packageId;
    }
};

class RamadanTimeShip : public Vehicle {
public:
    RamadanTimeShip(int i, int s, int e, int c) : Vehicle(i, s, e, c) {}

    void delivery(int packageId) {
        activeDeliveries++;
        cout << "\n" << Id << " is ensuring historical accuracy for " << packageId << " delivery.";
    }

    void delivery(int packageId, string urgency) {
        activeDeliveries++;
        cout << "\n" << Id << " is validating package: " << packageId << " since it's historically sensitive.";
    }
};
int Vehicle::activeDeliveries=0;
int main() {
    RamadanDrone drone(101, 50, 80, 10);
    RamadanHyperPod hyperPod(202, 40, 90, 30);
    RamadanTimeShip timeShip(303, 60, 85, 15);

    cout << "\nTesting deliveries:\n";
    
    drone.delivery(5001);
    drone.delivery(5002, "urgent");

    hyperPod.delivery(6001);
    hyperPod.delivery(6002, "urgent");

    timeShip.delivery(7001);
    timeShip.delivery(7002, "urgent");

    cout << "\nComparing Drone and HyperPod:\n";
    if (drone == hyperPod)
        cout << "Both vehicles are equally efficient.\n";
    else
        cout << "Vehicles have different efficiency levels.\n";

    cout << "\nComparing Drone and TimeShip:\n";
    if (drone == timeShip)
        cout << "Both vehicles are equally efficient.\n";
    else
        cout << "Vehicles have different efficiency levels.\n";
    Vehicle::showTotalDeliveries();

    Vehicle* selectedVehicle = resolveConflict(&drone, &hyperPod);
    selectedVehicle->delivery(8001);

    return 0;
}
