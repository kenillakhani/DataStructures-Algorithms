#include<iostream>
using namespace std;
int binary(int arr[], int s,int e,int key)
{
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2; 
    }
    return -1;
}
int getPivot(int arr[],int n)
{
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<e)
    {
        if(arr[mid]<arr[0])
        {
            e=mid;
        }
        else
        {
            s=mid+1;
        }
        mid = s+(e-s)/2; 
    }
    return s;
}
int search(int arr[],int n,int key)
{
    int p = getPivot(arr,n);
    int ans =-1;
    if(arr[p]<=key && arr[n-1]>=key)
    {
        // BS in pivote to end
        ans = binary(arr,p,n-1,key);

    }
    else{
        ans = binary(arr,0,p-1,key);
    }
    return ans;
}
int main()
{
    int arr[]={7,9,17,1,4,5,6};
    int n = sizeof(arr)/sizeof(int);
    int key;
    cin>>key;

    cout<<search(arr,n,key)<<endl;
return 0;
}