#include<iostream>
#include<vector>
using namespace std;
class Vehicle{
    int price;
    public:
    Vehicle(int p):price(p){};
    int getPrice(){
        return price;
    }
};
class Car:public Vehicle{
    int seat;
    int door;
    string fuelType;
    public:
    Car(int s,int d,string f,int p):Vehicle(p),seat(s),door(d),fuelType(f){};
    int getSeat(){
        return seat;
    }
    int getDoor(){return door;}
    string getFuelType(){return fuelType;}
};
class Motorcycle:public Vehicle{
    int numCylinder;
    int numGear;
    int numWheel;
    public:
    Motorcycle(int c,int g,int w,int p):Vehicle(p),numCylinder(c),numGear(g),numWheel(w){}
    int getCylinder(){return numCylinder;}
    int getGear(){return numGear;}
    int getWheel(){return numWheel;}
};
class Audi:public Car{
    string model;
    public:
    Audi(string m,int s,int d,string f,int p):Car(s,d,f,p),model(m){};
    void display(){
        cout<<"\n Model : "<<model<<"\n Seating Capacity : "<<getSeat()<<"\n Number Of Door : "<<getDoor()<<"\n Fuel Type : "<<getFuelType()<<"\n Price : "<<getPrice();
    }
};
class Yamaha:public Motorcycle{
    string makeType;
    public:
    Yamaha(string m,int c,int g,int w,int p):Motorcycle(c,g,w,p),makeType(m){};
    void display(){
        cout<<"\n Make Type : "<<makeType<<"\n Number Of Cylinder : "<<getCylinder()<<"\n Number Of Gear : "<<getGear()<<"\n Number of Wheel : "<<getWheel()<<"\n Price : "<<getPrice();
    }
};

main(){
    Yamaha y("Pakistan",2,4,3,4000);
    Audi a("New",5,4,"Diesel",3000);
    y.display();
    a.display();
}