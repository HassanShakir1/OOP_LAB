#include<iostream>
using namespace std;
class Bank{
    float balance;
    public:
    Bank():balance(0.0){};
    void credit(float amount){
        balance+=amount;
    };
    void debit(float amount){
        if(balance>=amount){
            balance-=amount;
            cout<<"Amount Debited: "<<amount<<endl;
        }
        else{
            cout<<"Insufficient Balance"<<endl;
        }
    };
    void getBalance(){
        cout<<"Current Balance: "<<balance<<endl;
    };
};
int main(int argc,char* argv[]){
    Bank b;
    b.credit(atof(argv[1]));
    b.getBalance();
    b.debit(atof(argv[2]));
    b.getBalance();
    b.debit(atof(argv[3]));
    b.getBalance();
    return 0;
}