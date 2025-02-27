#include<iostream>
using namespace std;
class Blend{
    public:
    void blendJuice(){
        int a;
        cout<<"\n Select the juice you want to blend: \n 1. Apple Juice \n 2. Orange Juice \n 3. Mango Juice \n 4. Pineapple Juice \n 5. Watermelon Juice \n 6. Pomegranate Juice \n 7. Kiwi Juice \n 8. Strawberry Juice \n 9. Grape Juice \n 10. Banana Juice \n";
        cin>>a;
        for (int i = 0; i < 5; i++)
        {
            cout<<"Blending Juice for "<< i+1<<"second"<<endl;
        }
    }
};
class Grind{
    public:
    void grind(){
        for (int i = 0; i < 5; i++)
        {
            cout<<"\n Sleep for "<<i+1<<" second"<<endl;
        }
        cout<<"\n Grind done";
    }
};
class JuiceMaker{
    Blend b;
    Grind g;
    public:
    void makeJuice(){
        b.blendJuice();
        g.grind();
    }
};
int main(){
    JuiceMaker j;
    j.makeJuice();
    return 0;
}
