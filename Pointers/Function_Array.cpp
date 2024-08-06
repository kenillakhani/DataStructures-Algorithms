#include<iostream>
using namespace std;

int getSum(int arr[] /* or *arr both same */,int n)
{

    cout<<"Size of arr:"<<sizeof(arr)<<endl;

    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=i[arr];
    }
    return sum;
}

int main()
{
    int arr[5] = {1,2,3,4,5};
    
    cout<<getSum(arr,5)<<endl; // pointer goes into the function so we have an advantage that we can sent part of an array into the funtion.

    return 0;
}