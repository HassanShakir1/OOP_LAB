#include<iostream>
using namespace std;
class Car{
    string engine;
    int horsePower;
    int seating_capacity;
    int no_of_speaker;
    public:
    Car(string e,int h,int s,int n){
        engine=e;
        horsePower=h;
        seating_capacity=s;
        no_of_speaker=n;
    }
    Car updateCar(string e,int h,int s,int n)const{
        return Car(e,h,s,n);
    };
    void display(){
        cout<<"Engine: "<<engine<<endl;
        cout<<"Horse Power: "<<horsePower<<endl;
        cout<<"Seating Capacity: "<<seating_capacity<<endl;
        cout<<"No of Speaker: "<<no_of_speaker<<endl;
    }
};
int main(){
    Car c1("V8",500,5,4);
    c1.display();
    Car c2=c1.updateCar("V12",700,7,8);
    c2.display();
    return 0;
}