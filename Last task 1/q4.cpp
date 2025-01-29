#include<iostream>
#include <iomanip>
using namespace std;
main(){
    float mass,mass1;
    cout<<"Enter Mass of the object in kg : ";
    cin>>mass;
    mass1=mass*2.2;
    cout<<"\n Mass in KG : "<<fixed<<setprecision(2)<<mass;
    cout << "\n Mass in pounds : " <<fixed<<setprecision(2)<< mass1;
}