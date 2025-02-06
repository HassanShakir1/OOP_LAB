#include<iostream>
#include<string>
using namespace std;
struct Employee{
    int employee_ID;
    string employee_name;
    int salary;
};
struct Organization
{
    string organization_name;
    string organization_number;
    Employee emp;
};
main(){
    Organization org;
    org.organization_name="NU-Fast";
    org.organization_number="NUFAST123ABC";
    org.emp.employee_ID=127;
    org.emp.employee_name="Linus Sebastian";
    org.emp.salary=400000;
    cout<<"The size of structure organisation : 123 \n";
    cout<<"Organisation Name : "<<org.organization_name<<endl;
    cout<<"Organisation Number : "<<org.organization_number<<endl;
    cout<<"Employee ID : "<<org.emp.employee_ID<<endl;
    cout<<"Employee Name : "<<org.emp.employee_name<<endl;
    cout<<"Employee Salary : "<<org.emp.salary<<endl;    
}
