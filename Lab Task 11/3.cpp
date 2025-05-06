#include <iostream>
#include <exception>
using namespace std;

class ArrayIndexOutOfBounds : public exception {
public:
    const char* what() const noexcept override {
        return "Array index out of bounds.";
    }
};

template<typename T>
class SafeArray {
    T* arr;
    int size;
public:
    SafeArray(int sz) : size(sz) {
        arr = new T[size];
    }

    ~SafeArray() {
        delete[] arr;
    }

    T& operator[](int index) {
        if (index < 0 || index >= size)
            throw ArrayIndexOutOfBounds();
        return arr[index];
    }

    int getSize() const { return size; }
};

// Demo
int main() {
    try {
        SafeArray<int> arr(5);
        for (int i = 0; i < arr.getSize(); i++)
            arr[i] = i * 10;

        for (int i = 0; i < arr.getSize(); i++)
            cout << arr[i] << " ";
        cout << endl;

        // Uncomment to trigger exception
        // cout << arr[10];

    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
