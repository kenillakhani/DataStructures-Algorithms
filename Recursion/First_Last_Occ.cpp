#include <iostream>
using namespace std;

int firstOcc(int *arr, int s, int e, int key)
{
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == key)
    {
        if (mid == 0 || arr[mid - 1] != key)
            return mid;
        else
            return firstOcc(arr, s, mid - 1, key);
    }

    if (arr[mid] < key)
        return firstOcc(arr, mid + 1, e, key);

    return firstOcc(arr, s, mid - 1, key);
}
int lastOcc(int* arr,int s,int e,int key)
{
    if(s>e)
    return -1;

    int mid = s+(e-s)/2;

    if(arr[mid]==key)
    {
        if(arr[mid+1]!=key || mid==e)
            return mid;
        else
            return lastOcc(arr,mid+1,e,key); 
    }

    if(arr[mid]<key)
        return lastOcc(arr,mid+1,e,key);
    
    return lastOcc(arr,s,mid-1,key);
    
    
}

int main()
{
    int arr[] = {1, 3, 5, 5, 5, 6, 7, 7, 11, 17, 17};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;
    
    cout<<firstOcc(arr, 0, n - 1, key)<<endl;
    cout<<lastOcc(arr, 0, n - 1, key)<<endl;
    return 0;
}