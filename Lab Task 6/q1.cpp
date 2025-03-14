#include<iostream>
#include<vector>
using namespace std;
class BankAccount{
    int accountNumber;
    int balance;
    public:
    int limit;
    BankAccount(int accountNumber, int balance, int limit){
        this->accountNumber = accountNumber;
        this->balance = balance;
        this->limit = limit;
    }
    BankAccount(){};
    void deposit(int amount){
        balance += amount;
    }
    void withdraw(int amount){
        if(balance >= amount &&  amount <= limit){
            balance -= amount;
            cout << "Withdrawal successful" << endl;
        }
        else{
            cout << "Insufficient balance or limit exceed" << endl;
        }
    }
    void display(){
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
    int getBalance(){
        return balance;
    }
    int getAccountNumber(){
        return accountNumber;
    }
};
class SavingAccount: public BankAccount{
    int interestRate;
    public:
    SavingAccount(int accountNumber, int balance, int interestRate , int limit): BankAccount(accountNumber, balance,limit){
        this->interestRate = interestRate;
    }
    void addInterest(){
        int interest = getBalance() * interestRate / 100;
        deposit(interest);
    }
};
class checkingAccout: public BankAccount{
    int draftLimit;
    int draftCheck;
    public:
    checkingAccout(int accountNumber, int balance, int draftLimit ,int limit):draftCheck(0), BankAccount(accountNumber, balance,limit){
        this->draftLimit = draftLimit;
    }
    void draw(int amount){
        if(getBalance()<amount){
            if(amount-getBalance()>draftLimit){
                cout<<"\n Draft Limit Exceeded";
            }else{
                draftCheck = amount-getBalance();
                withdraw(getBalance());
            }
        }else{
            withdraw(amount);
        }
    }
};
class BusinessAccout:public BankAccount{
    int coperateTex;
    public:
    BusinessAccout(int accountNumber, int balance, int coperateTex,int limit):BankAccount(accountNumber, balance,limit){
        this->coperateTex = coperateTex;
    }
    void payTex(){
        int tex = getBalance() * coperateTex / 100;
        withdraw(tex);
    }
};
class User{
    public:
    BankAccount b;
};
class customer:public User{
    public:
    customer(BankAccount b){
        this->b = b;
    }
};
class employee:public User{
    vector<BankAccount> accounts;
    vector<int> freeze;
    public:
    void addAccount(BankAccount b){
        accounts.push_back(b);
        freeze.push_back(0);
    }
    void freezeAccount(int accountNumber){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == accountNumber){
                freeze[i] = 1;
                cout << "Account freezed" << endl;
                break;
            }
        }
    }
    void unfreezeAccount(int accountNumber){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == accountNumber){
                freeze[i] = 0;
                cout << "Account unfreezed" << endl;
                break;
            }
        }
    }
    void withDrawForUser(int accountNumber, int amount){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == accountNumber){
                if(freeze[i] == 0){
                    accounts[i].withdraw(amount);
                    break;
                }
                else{
                    cout << "Account is freezed" << endl;
                }
            }
        }
    }
    void depositForUser(int accountNumber, int amount){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == accountNumber){
                if(freeze[i] == 0){
                    accounts[i].deposit(amount);
                    break;
                }
                else{
                    cout << "Account is freezed" << endl;
                }
            }
        }
    }
};
class manager:public User{
    vector<BankAccount> accounts;
    vector<int> freeze;
    public:
    void addAccount(BankAccount b){
        accounts.push_back(b);
        freeze.push_back(0);
    }
    void freezeAccount(int accountNumber){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == accountNumber){
                freeze[i] = 1;
                cout << "Account freezed" << endl;
                break;
            }
        }
    }
    void unfreezeAccount(int accountNumber){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == accountNumber){
                freeze[i] = 0;
                cout << "Account unfreezed" << endl;
                break;
            }
        }
    }
    void withDrawForUser(int accountNumber, int amount){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == accountNumber){
                if(freeze[i] == 0){
                    accounts[i].withdraw(amount);
                    break;
                }
                else{
                    cout << "Account is freezed" << endl;
                }
            }
        }
    }
    void depositForUser(int accountNumber, int amount){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == accountNumber){
                if(freeze[i] == 0){
                    accounts[i].deposit(amount);
                    break;
                }
                else{
                    cout << "Account is freezed" << endl;
                }
            }
        }
    }
    void updateLimit(int l,int accountNumber){
        for(int i=0;i<accounts.size();i++){
            if(accounts[i].getAccountNumber() == accountNumber){
                accounts[i].limit = l;
                cout << "Limit updated" << endl;
                break;
            }
        }
    }
};
int main(){
    BankAccount b(123, 1000, 500);
    b.deposit(1000);
    b.withdraw(2000);
    b.display();
    SavingAccount s(123, 1000, 10, 500);
    s.addInterest();
    s.display();
    checkingAccout c(123, 1000, 500, 500);
    c.draw(2000);
    c.display();
    BusinessAccout ba(123, 1000, 10,500);
    ba.payTex();
    ba.display();
    customer cust(b);
    employee e;
    e.addAccount(b);
    e.freezeAccount(123);
    e.unfreezeAccount(123);
    e.withDrawForUser(123, 1000);
    e.depositForUser(123, 1000);
    manager m;
    m.addAccount(b);
    m.freezeAccount(123);
    m.unfreezeAccount(123);
    m.withDrawForUser(123, 1000);
    m.depositForUser(123, 1000);
    m.updateLimit(1000, 123);
    return 0;
}