#include<iostream>
using namespace std;

// Other ways too.....
// But Complexity Matters.
void reverseArr(int arr[],int n)
{
    int i=0,j=n-1;
    while(i<j) // Complexity = O(n)
    {
        while(arr[i]==0 && i<j)
        {
            i++;
        }
        while(arr[j]==1 && i<j)
        {
            j--;
        }
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
}

int main()
{
    int arr[]={0,1,1,0,0,1,0,1,1,1,1,0,1};
    int n=sizeof(arr)/sizeof(int);

    reverseArr(arr,n);

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

return 0;
}