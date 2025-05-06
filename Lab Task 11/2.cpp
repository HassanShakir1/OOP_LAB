#include <iostream>
#include <vector>
#include <exception>
using namespace std;

class DimensionMismatchException : public exception {
public:
    const char* what() const noexcept override {
        return "Matrix dimensions do not match.";
    }
};

template<typename T>
class Matrix {
    int rows, cols;
    vector<vector<T>> data;
public:
    Matrix(int r, int c) : rows(r), cols(c), data(r, vector<T>(c)) {}

    void set(int r, int c, T val) {
        if (r >= rows || c >= cols || r < 0 || c < 0)
            throw out_of_range("Matrix index out of bounds.");
        data[r][c] = val;
    }

    T get(int r, int c) const {
        if (r >= rows || c >= cols || r < 0 || c < 0)
            throw out_of_range("Matrix index out of bounds.");
        return data[r][c];
    }

    Matrix operator+(const Matrix& other) {
        if (rows != other.rows || cols != other.cols)
            throw DimensionMismatchException();
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < cols; j++)
                result.data[i][j] = data[i][j] + other.data[i][j];
        return result;
    }

    Matrix operator*(const Matrix& other) {
        if (cols != other.rows)
            throw DimensionMismatchException();
        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++)
            for (int j = 0; j < other.cols; j++)
                for (int k = 0; k < cols; k++)
                    result.data[i][j] += data[i][k] * other.data[k][j];
        return result;
    }

    void display() {
        for (auto& row : data) {
            for (auto& val : row)
                cout << val << " ";
            cout << endl;
        }
    }
};

// Demo
int main() {
    try {
        Matrix<int> A(2, 2), B(2, 2);
        A.set(0, 0, 1); A.set(0, 1, 2);
        A.set(1, 0, 3); A.set(1, 1, 4);

        B.set(0, 0, 5); B.set(0, 1, 6);
        B.set(1, 0, 7); B.set(1, 1, 8);

        Matrix<int> C = A + B;
        cout << "Matrix A + B:\n";
        C.display();

        Matrix<int> D = A * B;
        cout << "Matrix A * B:\n";
        D.display();

    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }
    return 0;
}
