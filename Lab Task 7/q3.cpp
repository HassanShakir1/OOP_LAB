#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    vector<int> digits; // Digits stored in reverse (units place first)
    bool isNegative;

    void normalize() {
        while (digits.size() > 1 && digits.back() == 0) digits.pop_back();
        if (digits.size() == 1 && digits[0] == 0) isNegative = false;
    }

public:
    BigInteger() : isNegative(false) {
        digits.push_back(0);
    }

    BigInteger(const string& str) {
        isNegative = (str[0] == '-');
        int idx = (isNegative || str[0] == '+') ? 1 : 0;
        for (int i = str.size() - 1; i >= idx; --i) {
            digits.push_back(str[i] - '0');
        }
        normalize();
    }

    BigInteger(int val) {
        isNegative = val < 0;
        val = abs(val);
        while (val > 0) {
            digits.push_back(val % 10);
            val /= 10;
        }
        if (digits.empty()) digits.push_back(0);
        normalize();
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            BigInteger result;
            result.isNegative = isNegative;
            result.digits.clear();
            int carry = 0;
            size_t maxLength = max(digits.size(), other.digits.size());

            for (size_t i = 0; i < maxLength || carry; ++i) {
                int sum = carry;
                if (i < digits.size()) sum += digits[i];
                if (i < other.digits.size()) sum += other.digits[i];
                result.digits.push_back(sum % 10);
                carry = sum / 10;
            }

            result.normalize();
            return result;
        } else {
            BigInteger temp = other;
            temp.isNegative = !temp.isNegative;
            return *this - temp;
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            BigInteger temp = other;
            temp.isNegative = !temp.isNegative;
            return *this + temp;
        }

        const BigInteger *larger = this, *smaller = &other;
        bool resultNegative = false;

        if (*this < other) {
            resultNegative = !isNegative;
            swap(larger, smaller);
        }

        BigInteger result;
        result.digits.clear();
        int borrow = 0;

        for (size_t i = 0; i < larger->digits.size(); ++i) {
            int diff = larger->digits[i] - borrow;
            if (i < smaller->digits.size()) diff -= smaller->digits[i];

            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else borrow = 0;

            result.digits.push_back(diff);
        }

        result.isNegative = resultNegative;
        result.normalize();
        return result;
    }

    BigInteger operator*(const BigInteger& other) const {
        BigInteger result;
        result.digits.assign(digits.size() + other.digits.size(), 0);
        result.isNegative = isNegative != other.isNegative;

        for (size_t i = 0; i < digits.size(); ++i) {
            long long carry = 0;
            for (size_t j = 0; j < other.digits.size() || carry; ++j) {
                long long product = result.digits[i + j] + digits[i] * 1LL * (j < other.digits.size() ? other.digits[j] : 0) + carry;
                result.digits[i + j] = product % 10;
                carry = product / 10;
            }
        }

        result.normalize();
        return result;
    }

    bool operator==(const BigInteger& other) const {
        return digits == other.digits && isNegative == other.isNegative;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative)
            return isNegative;

        if (digits.size() != other.digits.size())
            return isNegative ? digits.size() > other.digits.size() : digits.size() < other.digits.size();

        for (int i = digits.size() - 1; i >= 0; --i) {
            if (digits[i] != other.digits[i])
                return isNegative ? digits[i] > other.digits[i] : digits[i] < other.digits[i];
        }

        return false;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const BigInteger& bigInt) {
        if (bigInt.isNegative && !(bigInt.digits.size() == 1 && bigInt.digits[0] == 0)) {
            os << "-";
        }
        for (int i = bigInt.digits.size() - 1; i >= 0; --i)
            os << bigInt.digits[i];
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& bigInt) {
        string str;
        is >> str;
        bigInt = BigInteger(str);
        return is;
    }
};

int main() {
    BigInteger a, b;
    cout << "Enter the first large number: ";
    cin >> a;
    cout << "Enter the second large number: ";
    cin >> b;

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "Sum (a + b): " << a + b << endl;
    cout << "Difference (a - b): " << a - b << endl;
    cout << "Product (a * b): " << a * b << endl;

    cout << boolalpha;
    cout << "a == b? " << (a == b) << endl;
    cout << "a < b? " << (a < b) << endl;
    cout << "a > b? " << (a > b) << endl;

    return 0;
}
