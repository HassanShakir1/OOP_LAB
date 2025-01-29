#include<iostream>
using namespace std;
void argToInt(char *argv[],int num[],int n){
    for (int i = 0; i < n; i++)
    {
        num[i]=atoi(argv[i+1]);
    }
    
}
int sum(int num[],int n){
    int sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=num[i];
    }
    return sum;
}
main(int argc,char *argv[]){
    if (argc<3)
    {
        cout<<"Too few arguments";
        return 0;
    }
    int n=argc-1;
    int num[n];
    argToInt(argv,num,n);
    cout<<"\n Sum of Element is: "<<sum(num,n);
}