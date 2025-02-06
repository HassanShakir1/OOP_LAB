#include<iostream>
#include<string>
using namespace std;
struct Employee{
    int ID;
    string name;
};

main(){
    int n;
    cout<<"Enter the number of Structure: ";
    cin>>n;
    Employee e[n];
    for (int i = 0; i < n; i++)
    {
        cout<<"Enter the ID of Employee "<<i+1<<" : ";
        cin>>e[i].ID;
        cin.ignore();
        cout<<"Enter the Name of Employee "<<i+1<<" : ";
        getline(cin,e[i].name);
    }
    int max=0;
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (e[j].ID>e[j+1].ID)
            {
                Employee temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
            
        }
        
    }
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (e[j].ID == e[j + 1].ID && e[j].name[0]>e[j+1].name[0])
            {
                Employee temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
        
    }
    cout<<"\n The sorted list of Employees : \n";
    for (int i = 0; i < n; i++)
    {
        cout<<"ID: "<<e[i].ID<<" Name: "<<e[i].name<<endl;
    }

}
