#include<iostream>
using namespace std;
class Date{
    private:
        int day;
        int month;
        int year;
    public:
        void setDate(int d,int m,int y){
            day=d;
            month=m;
            year=y;
        };
        void displayDate(){
            cout<<day<<"/"<<month<<"/"<<year;
        }
};
main(){
    Date dateTest;
    dateTest.setDate(3,12,2024);
    dateTest.displayDate();
}