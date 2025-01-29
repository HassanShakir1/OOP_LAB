#include<iostream>
#include<string>
using namespace std;
main(){
    string name;
    int id,unit;
    cout<<"Enter Customer ID : ";
    cin>>id;
    cout<<"Enter Customer Name : ";
    cin>>name;
    cout<<"Enter Units Consumed : ";
    cin>>unit;
    float total=0;
    float charge=0;
    if (unit<200)
    {
        total=unit*16.20;
        charge=16.20;
    }else if(unit>=200 && unit<300){
        charge=20.10;
        total=unit*charge;
    }else if (unit>=300 && unit<500)
    {
        charge=27.10;
        total=unit*charge;
    }else
    {
        charge=35.90;
        total=unit*charge;
    }
    float subcharge=0;
    if (total>18000)
    {
        subcharge=total*0.15;
    }
    float grandtotal=total+subcharge;
    cout<<"Amount Charge @Rs. "<<charge<<" per unit : "<<total<<endl;
    cout<<"Subcharge Amount "<<subcharge<<endl;
    cout<<"Net Amount Paid by the customer : "<<grandtotal<<endl;
}