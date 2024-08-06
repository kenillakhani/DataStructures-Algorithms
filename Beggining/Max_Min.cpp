#include<iostream>
using namespace std;
int getMax(int arr[],int n)
{
    int maxi = INT_MIN;
    for(int i=0;i<n;i++)
    {
        maxi=max(maxi,arr[i]); // function
    }
    return maxi;
}

int getMin(int arr[],int n)
{
    int mani = INT_MAX;
    for(int i=0;i<n;i++)
    {
        mani=min(mani,arr[i]); // function
    }
    return mani;
}
int main()
{
    int size;
    cout<<"Enter Size: ";
    cin>>size;
    int arr[100];
    cout<<"Enter Nuber:\n";
    for(int i=0;i<size;i++)
        cin>>arr[i];

    cout<<"Maximum: "<<getMax(arr,size);
    cout<<endl<<"Minimum: "<<getMin(arr,size)<<endl;
    return 0;
}