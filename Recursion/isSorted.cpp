#include<iostream>
using namespace std;

bool isSorted(int* arr,int size)
{
    if(size == 1)
        return true;
    
    if(arr[0] > arr[1])
        return false;
    
    return isSorted(arr+1,size-1);
}

int main()
{
    int arr[] = {2,14,7,8,10};
    int size = 5;
    
    if(isSorted(arr,size))
        cout<<"Sorted"<<endl;
    else
        cout<<"Not Sorted"<<endl;   
    return 0;
}