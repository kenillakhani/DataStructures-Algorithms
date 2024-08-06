// # Interview Question..
//  Facebook
//  Google

#include <iostream>
using namespace std;
bool isPossible(int arr[], int n, int s, int mid)
{
    int studentCount = 1;
    int totalPage = 0;
    for (int i = 0; i < n; i++)
    {
        if (totalPage + arr[i] <= mid)
        {
            totalPage += arr[i];
        }
        else
        {
            studentCount++;
            if (studentCount > s || arr[i] > mid)
                return false;

            totalPage = arr[i];
        }
    }
    return true;
}
int bookAlloc(int arr[], int n, int st)
{
    int s = 0;
    int e = 0;
    int ans = -1;
    for (int i = 0; i < n; i++)
    {
        e = e + arr[i];
    }
    int mid = s + (e - s) / 2;
    while (s < e)
    {

        if (isPossible(arr, n, st, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[]={10,20,20,30,40};
    int n= sizeof(arr)/sizeof(int);

    int s=3;
    cout<<bookAlloc(arr,n,s)<<endl;
    return 0;
}