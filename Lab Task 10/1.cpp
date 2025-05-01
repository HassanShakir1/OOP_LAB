#include <iostream>
#include <fstream>
#include <string>
using namespace std;
string encrytion(string input)
{
    for (int i = 0; i < input.length(); i++)
    {
        input[i] += i + 1;
    }
    return input;
}
string decrytion(string input)
{
    for (int i = input.length(); i > 0; i--)
    {
        input[i-1] -= i ;
    }
    return input;
}
int main()
{
    ofstream file;
    file.open("input.txt");
    if (!file)
    {
        cout << "\n Failed to open file ";
        return -1;
    }
    string a;
    cout << "\n Enter string";
    getline(cin, a);
    file << encrytion(a);
    file.close();

    ifstream file1("input.txt");
    if (!file1)
    {
        cout << "\n Failed to open file ";
        return -1;
    }
    
    string line;
    while (getline(file1,line))
    {
       cout<<"\n Line : "<<line;
    }
    cout<<"\n decryted line "<<decrytion(line);
    file1.close();

    return 0;
} 