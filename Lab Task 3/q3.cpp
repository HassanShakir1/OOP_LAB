#include<iostream>
using namespace std;
class Glass{
    public:
        int liquidLevel;
        void refill(){
            liquidLevel=200;
        };
        void drink(int l){
            liquidLevel-=l;
            if (liquidLevel<100)
            {
                refill();
            }
            
        }
};
int main(){
    Glass g;
    g.liquidLevel=200;
    while (1)
    {
        int n;
        cout<<"Select 1. to Drink and any other key to exit : ";
        cin>>n;
        switch (n)
        {
        case 1:
            g.drink(50);
            break;
        
        default:
            return 0;
        }
    }
    
}