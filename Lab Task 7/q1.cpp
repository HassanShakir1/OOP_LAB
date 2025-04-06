#include <iostream>
using namespace std;

class Rational {
private:
    int num, den;

    int computeGCD(int a, int b) {
        return (b == 0) ? (a < 0 ? -a : a) : computeGCD(b, a % b);
    }

    void simplify() {
        int commonDivisor = computeGCD(num, den);
        num /= commonDivisor;
        den /= commonDivisor;

        if (den < 0) {
            num *= -1;
            den *= -1;
        }
    }

public:
    Rational(int n = 0, int d = 1) : num(n), den(d) {
        if (den == 0) {
            cout << "Denominator cannot be zero. Defaulting to 1.\n";
            den = 1;
        }
        simplify();
    }

    Rational operator+(const Rational& rhs) const {
        return Rational(num * rhs.den + rhs.num * den, den * rhs.den);
    }

    Rational operator-(const Rational& rhs) const {
        return Rational(num * rhs.den - rhs.num * den, den * rhs.den);
    }

    Rational operator*(const Rational& rhs) const {
        return Rational(num * rhs.num, den * rhs.den);
    }

    Rational operator/(const Rational& rhs) const {
        return Rational(num * rhs.den, den * rhs.num);
    }

    bool operator==(const Rational& rhs) const {
        return num == rhs.num && den == rhs.den;
    }

    bool operator!=(const Rational& rhs) const {
        return !(*this == rhs);
    }

    bool operator<(const Rational& rhs) const {
        return num * rhs.den < rhs.num * den;
    }

    bool operator>(const Rational& rhs) const {
        return rhs < *this;
    }

    bool operator<=(const Rational& rhs) const {
        return !(rhs < *this);
    }

    bool operator>=(const Rational& rhs) const {
        return !(*this < rhs);
    }

    friend ostream& operator<<(ostream& out, const Rational& r);
    friend istream& operator>>(istream& in, Rational& r);
};

ostream& operator<<(ostream& out, const Rational& r) {
    if (r.den == 1)
        out << r.num;
    else
        out << r.num << "/" << r.den;
    return out;
}

istream& operator>>(istream& in, Rational& r) {
    string input;
    in >> input;
    size_t sep = input.find('/');
    if (sep != string::npos) {
        int n = stoi(input.substr(0, sep));
        int d = stoi(input.substr(sep + 1));
        r = Rational(n, d);
    } else {
        int n = stoi(input);
        r = Rational(n);
    }
    return in;
}

int main() {
    Rational r1(4, 8);
    Rational r2(3, 6);

    Rational rAdd = r1 + r2;
    Rational rSub = r1 - r2;
    Rational rMul = r1 * r2;
    Rational rDiv = r1 / r2;

    cout << "r1 = " << r1 << "\n";
    cout << "r2 = " << r2 << "\n";
    cout << "r1 + r2 = " << rAdd << "\n";
    cout << "r1 - r2 = " << rSub << "\n";
    cout << "r1 * r2 = " << rMul << "\n";
    cout << "r1 / r2 = " << rDiv << "\n";

    cout << "\nComparison Checks:\n";
    cout << "r1 == r2? " << (r1 == r2 ? "Yes" : "No") << endl;
    cout << "r1 != r2? " << (r1 != r2 ? "Yes" : "No") << endl;
    cout << "r1 < r2? "  << (r1 < r2  ? "Yes" : "No") << endl;
    cout << "r1 > r2? "  << (r1 > r2  ? "Yes" : "No") << endl;
    cout << "r1 <= r2? " << (r1 <= r2 ? "Yes" : "No") << endl;
    cout << "r1 >= r2? " << (r1 >= r2 ? "Yes" : "No") << endl;

    Rational userInput;
    cout << "\nInput a rational number (e.g., 3/4 or 5): ";
    cin >> userInput;
    cout << "You entered: " << userInput << "\n";

    return 0;
}
