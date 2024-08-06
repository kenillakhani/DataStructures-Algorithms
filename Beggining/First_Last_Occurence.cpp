#include<iostream>
using namespace std;

int firstOcc(int arr[],int n,int key)
{
    int s=0;
    int e=n-1;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            e=mid-1;
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
int lastOcc(int arr[],int n,int key)
{
    int s=0;
    int e=n-1;
    int ans=-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(arr[mid]==key)
        {
            ans=mid;
            s=mid+1;
        }
        else if(arr[mid]>key)
        {
            e=mid-1;
        }
        else
        {
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;
}
pair<int,int> firstlastOcc(int arr[],int n,int key) // New Concept
{
    pair<int,int> p;
    p.first=firstOcc(arr,n,key);
    p.second=lastOcc(arr,n,key);
    return p;
}
int main()
{
    int arr[]={1,3,5,5,5,6,7,7,11,17,17};
    int n=sizeof(arr)/sizeof(int);
    int key;
    cin>>key;
    pair<int,int> p=firstlastOcc(arr,n,key);
    cout<<p.first<<" "<<p.second<<endl;
    //cout<<firstOcc(arr,n,key)<<endl;
    //cout<<lastOcc(arr,n,key)<<endl;
return 0;
}