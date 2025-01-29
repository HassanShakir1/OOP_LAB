#include<iostream>
using namespace std;
void argcToFloat(char *argv[],float arr[],int n){
    for (int i=0;i<n;i++){
        arr[i]=atof(argv[i+1]);
    }
}
float secondHighest(float arr[],int n){
    float max=0;
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>max){
            max=arr[i];
        }
    }
    float max2=0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]>max2 && max2!=max)
        {
            max2=arr[i];
        }
    }
    return max2;
}
int main(int argc,char *argv[]){
    if (argc<3)
    {
        cout<<"Too few arguments";
        return 0;
    }
    int n=argc-1;
    float num[n];
    argcToFloat(argv,num,n);
    
    cout<<"\n Second Largest Element is: "<<secondHighest(num,n);
}