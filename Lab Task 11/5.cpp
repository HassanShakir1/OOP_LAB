#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class StackUnderflowException : public exception {
public:
    const char* what() const noexcept override {
        return "Stack underflow error.";
    }
};

template<typename T>
class Stack {
    vector<T> data;
public:
    void push(T val) {
        data.push_back(val);
    }

    void pop() {
        if (data.empty())
            throw StackUnderflowException();
        data.pop_back();
    }

    T top() {
        if (data.empty())
            throw StackUnderflowException();
        return data.back();
    }

    bool empty() {
        return data.empty();
    }
};

// Demo
int main() {
    try {
        Stack<string> s;
        s.push("FAST");
        s.push("CS");
        cout << "Top: " << s.top() << endl;
        s.pop();
        s.pop();
        // Uncomment to throw exception
        // s.pop();
    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
