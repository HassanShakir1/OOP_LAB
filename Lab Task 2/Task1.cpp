#include<iostream>
#include<cstdlib>
using namespace std;

void initialize(int num[], char* argv[], int n) {
    for (int i = 1; i <= n; i++) {
        num[i - 1] = atoi(argv[i]);  
    }
}

int main(int argc, char* argv[]) {
    int n = argc - 1;
    int* num = new int[n];
    initialize(num, argv, n);
   
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += *(num + i);
    }
   
    cout << "Sum is: " << sum << endl;

    delete[] num;
    return 0;
}