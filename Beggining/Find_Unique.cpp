#include <iostream>
using namespace std;
int unique(int arr[],int n)
{
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans=ans^arr[i];
    }
    return ans;
}

int main()
{
    int arr[] = {23, 65, 43, 65, 78, 78, 23};
    int n = sizeof(arr) / sizeof(int);

    cout<<"Unique Element: "<<unique(arr,n)<<endl;
    return 0;
}