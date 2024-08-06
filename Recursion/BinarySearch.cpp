#include<iostream>
using namespace std;

bool bsearch(int* arr,int s,int e,int key)
{
    if(s>e)
        return false;

    int mid = s+(e-s)/2;

    if(arr[mid] == key)
        return true;

    if(arr[mid] < key)
        return bsearch(arr,mid+1,e,key);

    return bsearch(arr,s,mid-1,key);
}


int main()
{
    int arr[] = {2,4,6,10,14,16};
    int size = 6;
    int key = 2;

    if(bsearch(arr,0,size-1,key))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    return 0;
}