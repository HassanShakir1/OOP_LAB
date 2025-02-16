#include<iostream>
using namespace std;
class Invoice{
    string number;
    string description;
    int quantity;
    float price;
    public:
    Invoice(string n, string d, int q, float p):number(n),description(d){
        if(q<0){
            quantity=0;
        }
        else{
            quantity=q;
        }
        if(p<0){
            price=0.0;
        }
        else{
            price=p;
        }
    };
    double getInvoiceAmount(){
        return quantity*price;
    };
};
int main(int argc,char* argv[]){
    Invoice i(argv[1],argv[2],atoi(argv[3]),atof(argv[4]));
    cout<<"Price : "<<i.getInvoiceAmount();
}