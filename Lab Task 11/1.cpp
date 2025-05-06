#include <iostream>
#include <any>
#include <exception>
using namespace std;

class BadTypeException : public exception {
public:
    const char* what() const noexcept override {
        return "Bad type requested from TypeSafeContainer.";
    }
};

class TypeSafeContainer {
    any value;
public:
    template<typename T>
    void store(const T& val) {
        value = val;
    }

    template<typename T>
    T get() const {
        if (!value.has_value() || value.type() != typeid(T)) {
            throw BadTypeException();
        }
        return any_cast<T>(value);
    }
};

// Demo
int main() {
    try {
        TypeSafeContainer container;
        container.store<int>(42);
        cout << "Stored int: " << container.get<int>() << endl;

        // Uncomment to see exception
        // cout << container.get<string>() << endl;
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
