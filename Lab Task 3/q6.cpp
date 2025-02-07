#include <iostream>
using namespace std;

class Matrix {
private:
    int rows, cols;
    int** mat;

public:
    Matrix(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        mat = new int*[rows];
        for (int i = 0; i < rows; i++) {
            mat[i] = new int[cols]();
        }
    }

    int getRows() {
        return rows;
    }

    int getCols() {
        return cols;
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            mat[i][j] = value;
        }
    }

    void display() {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }

    Matrix add(Matrix& other) {
        if (rows != other.getRows() || cols != other.getCols()) {
            cout << "Matrices cannot be added" << endl;
            exit(0);
        }
        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.setElement(i, j, mat[i][j] + other.mat[i][j]);
            }
        }
        return result;
    }

    Matrix multiply(Matrix& other) {
        if (cols != other.getRows()) {
            cout << "Matrices cannot be multiplied" << endl;
            exit(0);
        }
        Matrix result(rows, other.getCols());
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.getCols(); j++) {
                result.setElement(i, j, 0);
                for (int k = 0; k < cols; k++) {
                    result.mat[i][j] += mat[i][k] * other.mat[k][j];
                }
            }
        }
        return result;
    }

    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] mat[i];
        }
        delete[] mat;
    }
};

int main(int argc, char* argv[]) {
    int rows1 = stoi(argv[1]);
    int cols1 = stoi(argv[2]);
    int rows2 = stoi(argv[3]);
    int cols2 = stoi(argv[4]);

    Matrix m1(rows1, cols1);
    Matrix m2(rows2, cols2);

    int index = 5;
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            m1.setElement(i, j, stoi(argv[index++]));
        }
    }

    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            m2.setElement(i, j, stoi(argv[index++]));
        }
    }

    cout << "Matrix 1:\n";
    m1.display();

    cout << "Matrix 2:\n";
    m2.display();

    cout << "Matrix 1 + Matrix 2:\n";
    m1.add(m2).display();

    cout << "Matrix 1 * Matrix 2:\n";
    m1.multiply(m2).display();

    return 0;
}
