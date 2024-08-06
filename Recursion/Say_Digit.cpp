#include<iostream>
using namespace std;

void sayDigit(int n,string arr[])
{
    if(n==0)
        return;

    sayDigit(n/10,arr);
    cout<<arr[n%10]<<" ";
}

int main()
{
    int n;
    string arr[] = {"zero","one","two","three","four","five","six","seven","eigth","nine"};
    cin>>n;
    sayDigit(n,arr); 
    cout<<endl;  
    return 0;
}