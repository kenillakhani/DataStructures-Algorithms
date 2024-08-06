#include<iostream>
using namespace std;

int pivote(int* arr,int s,int e)
{
    if(s>=e)
        return s;

    int mid = s+(e-s)/2;

    if(arr[0]>arr[mid])
        return pivote(arr,s,mid);
    else
        return pivote(arr,mid+1,e);
}
int BS(int* arr,int s,int e,int key)
{
    if(s>e)
        return -1;
    
    int mid = s+(e-s)/2;

    if(arr[mid]==key)
        return mid;
    else if(arr[mid]>key)
        return BS(arr,s,mid-1,key);
    else
        return BS(arr,mid+1,e,key);
}
int search(int* arr,int n,int key)
{
    int p = pivote(arr,0,n);
    int ans;
    if(arr[p]<=key && arr[n]>=key)
    {
        ans = BS(arr,p,n,key);
    }
    else
    {
        ans = BS(arr,0,p-1,key);
    }
    return ans;
}


int main()
{
    int arr[]={7,9,17,1,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;

    cout<<search(arr,n-1,key)<<endl; 
    return 0;
}