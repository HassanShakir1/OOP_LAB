#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct Subject
{
    string name;
};

struct Student{
    int id;
    vector<Subject> subjects;
};
main(){
    int numSub,numStu;
    cout<<"\n Enter the number of Student : ";
    cin>>numStu;
    cin.ignore();
    Student *students=new Student[numStu];
    for (int i = 0; i < numStu; i++)
    {
        cout<<"\n Enter Student "<<i+1<<" ID : ";
        cin>>students[i].id;
        cin.ignore();
        cout<<"\n Enter the number of Subjects for Student "<<i+1<<" : ";
        cin>>numSub;
        cin.ignore();
        students[i].subjects.resize(numSub);
        for (int j = 0; j < numSub; j++)
        {
            cout<<"\n Enter Student "<<i+1<<" Subject "<<j+1<<" Name : ";
            getline(cin,students[i].subjects[j].name);
        }
        
    };
    for (int i = 0; i < numStu; i++)
    {
        cout<<"\n Student ID : "<<students[i].id;
        cout<<"\n Subjects : ";
        for (int j = 0; j < students[i].subjects.size(); j++)
        {
            cout<<students[i].subjects[j].name<<" , ";
        }
        
    }
    delete[] students;
    
}
