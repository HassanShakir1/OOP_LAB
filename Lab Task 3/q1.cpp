#include<iostream>
using namespace std;
class User{
    public:
        int age;
        string name;
};
main(){
    User u;
    u.name="Teo";
    u.age=24;
    cout<<"My Name is "<<u.name<<" and I'm "<<u.age<<" Years old";
}