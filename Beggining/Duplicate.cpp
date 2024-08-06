#include<iostream>
using namespace std;
int duplicate(int arr[],int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans = ans^arr[i];
    }
    for(int i=1;i<n;i++)
    {
        ans=ans^i;
    }
    return ans;
}

int main()
{
    int n;
    cin>>n;
    int arr[100];  // in array all elements from 1 to n-1 is one time and one of them comes twice we have to find it.
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<duplicate(arr,n)<<endl;

    // 2 nd

    double sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
    }
    int ans = sum-(n*(n-1)/2);

    cout<<"Second: "<<ans<<endl;

return 0;
}