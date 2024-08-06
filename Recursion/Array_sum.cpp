#include<iostream>
using namespace std;

int getSum(int* arr,int size)
{
    if(size==1)
        return arr[0];

    return arr[0] + getSum(arr+1,size-1);
}

int main()
{
    int arr[] = {2,6,9,11,45};
    int size = 5;

    cout<<getSum(arr,size)<<endl;   
    return 0;
}