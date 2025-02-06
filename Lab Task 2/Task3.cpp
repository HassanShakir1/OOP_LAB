#include<iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n=1,flag=0;
    int* arr= new int[n];
    while (1)
    {
        int opt;
        cout<<"1. to add number else press any number to exit";
        cin>>opt;
        switch (opt)
        {
        case 1:
            if (flag+1==n)
            { 
                n*=2;
                int* newArr = new int[n];
                for (int i = 0; i < flag; i++) {
                    newArr[i] = arr[i];
                }
                delete[] arr;
                arr=newArr;
            }
            
            int number;
            cout<<"\n Enter Element : ";
            cin>>number;
            arr[flag]=number;
            flag++;
            break;
        
        default:
            n=flag;
            int* newArr = new int[n];
                for (int i = 0; i < flag; i++) {
                    newArr[i] = arr[i];
                }
            delete[] arr;
            arr=newArr;
            cout<<"\n Array's maximum length : "<<n;
            cout<<"\n Array after resizing to maximum length : ";
            cout<<endl;
            for (int i = 0; i < n; i++)
            {
                cout<<arr[i]<<" , ";
            }
            delete[] arr;
            return 0;
        }
    }
}