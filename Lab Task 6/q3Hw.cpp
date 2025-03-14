#include<iostream>
#include<vector>
using namespace std;
class Student{
    int id;
    string name;
    public:
    Student(int i,string n):id(i),name(n){}
    void getStudentDetails(){
        cout<<"\n ID : "<<id<<"\n Name : "<<name;
    }
};
class Marks:public Student{
    protected:
    int marks_oop,marks_pf,marks_ds,marks_db;
    public:
    Marks(int o,int p,int d,int dd,int i,string n):marks_oop(o),marks_pf(p),marks_ds(d),marks_db(dd),Student(i,n){}
    void getMarks(){
        cout<<"\n OOP : "<<marks_oop<<"\n PF : "<<marks_pf<<"\n DS : "<<marks_ds<<"\n DB : "<<marks_db;
    };
};
class Result:public Marks{
    protected:
    int total_marks;
    double avg_marks;
    public:
    Result(int o,int p,int d,int dd,int i,string n):Marks(o,p,d,dd,i,n),total_marks(0),avg_marks(0.0){}
    int getTotalMarks(){
        return marks_db+marks_ds+marks_oop+marks_pf;
    }
    double getAvg(){
        return (double)getTotalMarks()/4;
    };
    void display(){
        getStudentDetails();
        getMarks();
        cout<<"\n Total Marks : "<<getTotalMarks()<<"\n Average : "<<getAvg();
    }
};
main(){
    Result r(24,50,40,45,1,"hassan");
    r.display();
}