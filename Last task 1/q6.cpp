#include <iostream>
#include <iomanip> // For fixed and setprecision
#include <string>  // For handling strings

using namespace std;

int main() {
    string name;
    float scores[5], total = 0.0, average;
    cout << "Enter the student's name : ";
    getline(cin,name);

    for (int i = 0; i < 5; i++) {
        cout << "Enter test score " << i + 1 << " : ";
        cin >> scores[i]; 
        total += scores[i];
    }
    average = total / 5;
    cout << "\nStudent name: " << name<< endl;

    cout << "Test scores: ";
    for (int i = 0; i < 5; i++) {
        cout << fixed << setprecision(2) << scores[i] << " ";
    }
    cout << endl;

    cout << "Average test score: " << fixed << setprecision(2) << average << endl;

    return 0;
}
