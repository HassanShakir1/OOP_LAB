#include<iostream>
using namespace std;
class Shape{
    float area;
    public:
    Shape(float a):area(a){}
    Shape operator+(Shape &a){
        Shape temp(this->area+a.area);
        return temp;
    }
    void display(){
        cout<<"\n area : "<<area;
    }
};
main(){
    Shape a(50.34),b(23.12);
    Shape c=a+b;
    a.display();
    b.display();
    c.display();
}