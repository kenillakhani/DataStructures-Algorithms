#include<iostream>
using namespace std;
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
int main()
{
    int arr[]={7,9,17,1,4,5,7};
    int n = sizeof(arr)/sizeof(int);

    cout<<getPivot(arr,n)<<endl;
return 0;
}