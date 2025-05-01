#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include <sstream>
using namespace std;
struct Employee {
    int id;
    string name;
    string designation;
    int years;

    void print() const {
        cout << id << " " << name << " " << designation << " " << years << endl;
    }
};
vector<Employee> getAllEmployees(const string& fileName){
    vector<Employee> e;
    ifstream file(fileName);
    string line;
    while (getline(file,line))
    {
        istringstream iss(line);
        Employee emp;
        if (iss >> emp.id >> emp.name >> emp.designation >> emp.years) {
            e.push_back(emp);
        }
    }
    file.close();
    return e;
}

void writeToFile(const string& fileName,const vector<Employee>& employees){
    ofstream file(fileName);
    for(auto it : employees){
        file<<it.id<<" "<<it.name<<" "<<it.designation<<" "<<it.years<<endl;
    }
    file.close();
}

int main(){
    string fileName="data.txt";

    vector<Employee> e= getAllEmployees(fileName);

    vector<Employee> filter;
    for (int i = 0; i < e.size(); i++)
    {
        if (e[i].designation=="Manager" && e[i].years>=2)
        {
            filter.push_back(e[i]);
        }
        
    }
    cout << "Query a) Managers with at least 2 years of service:\n";
    for (const auto& emp : filter) {
        emp.print();
    }
    writeToFile(fileName,filter);
    cout << "\nQuery b) File updated with only filtered data.\n";
    for (auto& emp : filter) {
        emp.id += 100;     // increment ID
        emp.years += 1;    // increment years
    }

    ofstream outfile(fileName, ios::app); // append to file
    for (const auto& emp : filter) {
        outfile << emp.id << " " << emp.name << " " << emp.designation << " " << emp.years << endl;
    }

    cout << "\nQuery c) Data written with incremented IDs and years.\n";

    return 0;
}