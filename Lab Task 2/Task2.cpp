#include<iostream>
#include<cstdlib>
using namespace std;

void initialize(int num[], char* argv[], int n) {
    for (int i = 1; i <= n; i++) {
        num[i - 1] = atoi(argv[i]);
    }
}

void* add(void* num, int n) {
    int* arr = (int*)num;
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] + i + 1; 
    }
    return (void*)arr;
}

int main(int argc, char* argv[]) {
    int n = argc - 1;
    int* num = new int[n];
    initialize(num, argv, n);
    
    void* newArr = add(num, n);
    int* newArrInt = (int*)newArr;  

    for (int i = 0; i < n; i++) {
        cout << endl << newArrInt[i];  
    }

    delete[] num;
    return 0;
}
