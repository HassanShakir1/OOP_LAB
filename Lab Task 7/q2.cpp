#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Poly {
private:
    vector<int> coeffs;

    void removeTrailingZeros() {
        size_t last = 0;
        for (size_t i = 0; i < coeffs.size(); ++i)
            if (coeffs[i] != 0) last = i;
        coeffs.resize(last + 1);
        if (coeffs.empty()) coeffs.push_back(0);
    }

public:
    Poly() {}

    Poly(const vector<int>& inputCoeffs) : coeffs(inputCoeffs) {
        removeTrailingZeros();
    }

    friend Poly operator+(const Poly& lhs, const Poly& rhs);
    friend Poly operator-(const Poly& lhs, const Poly& rhs);
    friend Poly operator*(const Poly& lhs, const Poly& rhs);
    friend ostream& operator<<(ostream& out, const Poly& poly);

    friend class PolyHelper;
};

class PolyHelper {
public:
    static int evaluateAt(const Poly& poly, int x) {
        int result = 0, term = 1;
        for (int c : poly.coeffs) {
            result += c * term;
            term *= x;
        }
        return result;
    }

    static Poly getDerivative(const Poly& poly) {
        vector<int> deriv;
        for (size_t i = 1; i < poly.coeffs.size(); ++i)
            deriv.push_back(poly.coeffs[i] * i);
        return Poly(deriv);
    }
};

Poly operator+(const Poly& lhs, const Poly& rhs) {
    size_t n = max(lhs.coeffs.size(), rhs.coeffs.size());
    vector<int> sum(n, 0);
    for (size_t i = 0; i < lhs.coeffs.size(); ++i) sum[i] += lhs.coeffs[i];
    for (size_t i = 0; i < rhs.coeffs.size(); ++i) sum[i] += rhs.coeffs[i];
    return Poly(sum);
}

Poly operator-(const Poly& lhs, const Poly& rhs) {
    size_t n = max(lhs.coeffs.size(), rhs.coeffs.size());
    vector<int> diff(n, 0);
    for (size_t i = 0; i < lhs.coeffs.size(); ++i) diff[i] += lhs.coeffs[i];
    for (size_t i = 0; i < rhs.coeffs.size(); ++i) diff[i] -= rhs.coeffs[i];
    return Poly(diff);
}

Poly operator*(const Poly& lhs, const Poly& rhs) {
    vector<int> product(lhs.coeffs.size() + rhs.coeffs.size() - 1, 0);
    for (size_t i = 0; i < lhs.coeffs.size(); ++i)
        for (size_t j = 0; j < rhs.coeffs.size(); ++j)
            product[i + j] += lhs.coeffs[i] * rhs.coeffs[j];
    return Poly(product);
}

ostream& operator<<(ostream& out, const Poly& poly) {
    bool isFirst = true;
    for (int i = poly.coeffs.size() - 1; i >= 0; --i) {
        int val = poly.coeffs[i];
        if (val == 0) continue;

        if (!isFirst) {
            out << (val > 0 ? " + " : " - ");
            val = abs(val);
        } else {
            if (val < 0) {
                out << "-";
                val = -val;
            }
            isFirst = false;
        }

        if (i == 0) {
            out << val;
        } else {
            if (val != 1) out << val;
            out << "x";
            if (i > 1) out << "^" << i;
        }
    }

    if (isFirst) out << "0";
    return out;
}

int main() {
    Poly A({2, 0, -1, 3});   // Represents 3x^3 - x^2 + 2
    Poly B({-1, 2, 4});      // Represents 4x^2 + 2x - 1

    cout << "A: " << A << endl;
    cout << "B: " << B << endl;

    Poly added = A + B;
    Poly subtracted = A - B;
    Poly multiplied = A * B;

    cout << "A + B = " << added << endl;
    cout << "A - B = " << subtracted << endl;
    cout << "A * B = " << multiplied << endl;

    int x = 2;
    cout << "A evaluated at x = " << x << ": " << PolyHelper::evaluateAt(A, x) << endl;

    Poly A_deriv = PolyHelper::getDerivative(A);
    cout << "Derivative of A: " << A_deriv << endl;

    return 0;
}
