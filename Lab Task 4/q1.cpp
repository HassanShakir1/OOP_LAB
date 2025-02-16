#include<iostream>
using namespace std;
class Circle{
    float radius;
    public:
    Circle(float r):radius(r){}
    float getArea(){
        return 3.14*radius*radius;
    };
    float getPerimeter(){
        return 2*3.14*radius;
    };
};
int main(int argc,char* argv[]){

    Circle c(atof(argv[1]));
    cout<<"Area of Circle: "<<c.getArea()<<endl;
    cout<<"\n Perimeter of Circle: "<<c.getPerimeter()<<endl;
}