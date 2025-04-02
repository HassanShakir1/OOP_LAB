#include<iostream>
#include<vector>
using namespace std;

class Account {
    int accountNumber;
    float balance;
    string accountHolderName;
protected:
    vector<pair<float, float>> transactions;
public:
    Account(int a, float b, string h) : accountNumber(a), balance(b), accountHolderName(h) {}
    
    void deposit(float b) {
        balance += b;
        cout << "\nAmount Deposited";
    }
    
    virtual void withdraw(float b) {
        if (balance < b) {
            cout << "\nInsufficient Balance";
        } else {
            balance -= b;
            transactions.push_back({b, balance});
            cout << "\nAmount Withdrawn";
        }
    }
    
    virtual void printStatement() {
        cout << "\nTransaction History .....";
        for (const auto& t : transactions) {
            cout << "\nWithdrawn Amount: " << t.first << " Total Balance: " << t.second;
        }
    }
    
    int getAccountNumber() { return accountNumber; }
    float getBalance() { return balance; }
    string getAccountHolderName() { return accountHolderName; }
    
    virtual void accountInfo() {
        cout << "\nAccount Number: " << getAccountNumber()
             << "\nBalance: " << getBalance()
             << "\nName: " << getAccountHolderName();
    }
    
    virtual void calculateInterest() {}
};

class SavingAccount : public Account {
    float interestRate;
    float minimumBalance;
public:
    SavingAccount(int a, float b, string h, float i, float m)
        : Account(a, b, h), interestRate(i), minimumBalance(m) {}
    
    void withdraw(float b) override {
        if (getBalance() < b) {
            cout << "\nInsufficient Balance";
        } else if (getBalance() - b < minimumBalance) {
            cout << "\nWithdraw violates minimum balance requirement";
        } else {
            deposit(-b);
            transactions.push_back({b, getBalance()});
            cout << "\nAmount Withdrawn";
        }
    }
    
    void calculateInterest() override {
        deposit(getBalance() * interestRate / 100);
    }
    
    void printStatement() override {
        cout << "\nAccount Type: Saving Account";
        cout << "\nInterest Rate: " << interestRate << "\nMinimum Balance: " << minimumBalance;
        Account::printStatement();
    }
};

class FixedDepositAccount : public Account {
    float fixedInterestRate;
    string maturityDate;
public:
    FixedDepositAccount(int a, float b, string h, float r, string m)
        : Account(a, b, h), fixedInterestRate(r), maturityDate(m) {}
    
    void calculateInterest() override {
        deposit(getBalance() * fixedInterestRate / 100);
    }
    
    void printStatement() override {
        cout << "\nAccount Type: Fixed Deposit Account";
        cout << "\nFixed Interest Rate: " << fixedInterestRate << "\nMaturity Date: " << maturityDate;
        Account::printStatement();
    }
};

int main() {
    SavingAccount sa(101, 5000, "Alice", 5.0, 1000);
    FixedDepositAccount fda(102, 10000, "Bob", 7.5, "31-12-2025");
    
    sa.deposit(2000);
    sa.withdraw(1500);
    sa.calculateInterest();
    sa.printStatement();
    sa.accountInfo();
    
    fda.calculateInterest();
    fda.printStatement();
    fda.accountInfo();
    
    return 0;
}
