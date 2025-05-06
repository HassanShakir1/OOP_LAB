#include <iostream>
using namespace std;

template<typename T>
class Base {
protected:
    T a, b;
public:
    Base(T x, T y) : a(x), b(y) {}
    T multiplyBase() {
        return a * b;
    }
};

template<typename T>
class Derived : public Base<T> {
    T c, d;
public:
    Derived(T x, T y, T z, T w) : Base<T>(x, y), c(z), d(w) {}
    T multiplyDerived() {
        return c * d;
    }

    void printAll() {
        cout << "Base Product: " << this->multiplyBase() << endl;
        cout << "Derived Product: " << multiplyDerived() << endl;
    }
};

// Demo
int main() {
    Derived<int> obj(2, 3, 4, 5);
    obj.printAll();
    return 0;
}
