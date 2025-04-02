#include<iostream>
using namespace std;

class Currency {
protected:
    float amount;
    int currencyCode;
    string currencySymbol;

public:
    Currency(float a, int c, string cu) : amount(a), currencyCode(c), currencySymbol(cu) {}
    virtual float convertToBase() = 0;
    virtual float convertToPkr() = 0;
    virtual float convertToDollar() = 0;
    virtual float convertToEuro() = 0;
    virtual void display() = 0;
    virtual ~Currency() {}
};

class Dollar : public Currency {
public:
    Dollar(float a) : Currency(a, 1, "$") {}
    
    float convertToBase() override {
        return amount * 1.0; // Assuming Dollar is the base currency
    }

    float convertToPkr() override {
        return amount * 280.0; // Example exchange rate
    }
    
    float convertToDollar() override {
        return amount;
    }

    float convertToEuro() override {
        return amount * 0.92; // Example exchange rate
    }

    void display() override {
        cout << "Amount: " << currencySymbol << amount << " (USD)" << endl;
    }
};

class Pkr : public Currency {
public:
    Pkr(float a) : Currency(a, 2, "Rs") {}
    
    float convertToBase() override {
        return amount / 280.0; // Assuming Dollar is the base currency
    }

    float convertToPkr() override {
        return amount;
    }
    
    float convertToDollar() override {
        return amount / 280.0;
    }

    float convertToEuro() override {
        return (amount / 280.0) * 0.92;
    }

    void display() override {
        cout << "Amount: " << currencySymbol << amount << " (PKR)" << endl;
    }
};

class Euro : public Currency {
public:
    Euro(float a) : Currency(a, 3, "€") {}
    
    float convertToBase() override {
        return amount / 0.92; // Assuming Dollar is the base currency
    }

    float convertToPkr() override {
        return (amount / 0.92) * 280.0;
    }
    
    float convertToDollar() override {
        return amount / 0.92;
    }

    float convertToEuro() override {
        return amount;
    }

    void display() override {
        cout << "Amount: " << currencySymbol << amount << " (EUR)" << endl;
    }
};

int main() {
    Dollar d(100);
    d.display();
    cout << "In PKR: " << d.convertToPkr() << endl;
    cout << "In Euro: " << d.convertToEuro() << endl;
    
    Pkr p(28000);
    p.display();
    cout << "In USD: " << p.convertToDollar() << endl;
    cout << "In Euro: " << p.convertToEuro() << endl;
    
    Euro e(92);
    e.display();
    cout << "In USD: " << e.convertToDollar() << endl;
    cout << "In PKR: " << e.convertToPkr() << endl;
    
    return 0;
}
