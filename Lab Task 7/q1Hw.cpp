#include<iostream>
using namespace std;
class Check{
    int i;
    public:
    Check(int a):i(a){}
    void operator--(){
        i= i*4;
    }
    void operator--(int){
        i= i/4;
    }
    void display(){
    cout<<"\n hello : "<<i;	
	}
    
};

int main(){
    Check a(4),b(8);
    a--;
    --b;
    a.display();
    b.display();
    return 0;
}