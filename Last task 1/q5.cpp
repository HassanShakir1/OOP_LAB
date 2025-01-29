#include <iostream>
#include <iomanip> // For fixed and setprecision
#include <string>  // For handling strings

using namespace std;

int main() {
    string movieName;
    float adultTicketPrice, childTicketPrice;
    int adultTicketsSold, childTicketsSold;
    float percentageDonated;    
    cout << "Enter movie name: ";
    getline(cin, movieName);
    cout << "Enter adult ticket price: ";
    cin >> adultTicketPrice;
    cout << "Enter child ticket price: ";
    cin >> childTicketPrice;
    cout << "Enter number of adult tickets sold: ";
    cin >> adultTicketsSold;
    cout << "Enter number of child tickets sold: ";
    cin >> childTicketsSold;
    cout << "Enter percentage of gross amount to be donated: ";
    cin >> percentageDonated;
    int totalTicketsSold = adultTicketsSold + childTicketsSold;
    float grossAmount = (adultTicketPrice * adultTicketsSold) + (childTicketPrice * childTicketsSold);
    float amountDonated = (percentageDonated / 100) * grossAmount;
    float netSale = grossAmount - amountDonated;
    cout << fixed << setprecision(2);
    cout << "Movie Name: ...................................... " << movieName << endl;
    cout << "Number of Tickets Sold: .......................... " << totalTicketsSold << endl;
    cout << "Gross Amount: .................................... $ " << grossAmount << endl;
    cout << "Percentage of Gross Amount Donated: .............. " << percentageDonated << "%" << endl;
    cout << "Amount Donated: .................................. $ " << amountDonated << endl;
    cout << "Net Sale: ........................................ $ " << netSale << endl;

    return 0;
}
