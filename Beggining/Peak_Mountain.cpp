#include <iostream>
using namespace std;

int peak(int arr[],int n)
{
    int s=0;
    int e=n-1;
    int  mid = s+(e-s)/2;
    while(s<e)
    {
        if(arr[mid]>arr[mid+1])
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
    int arr[] = {3, 4, 4, 7, 8, 9, 17, 1};
    int n = sizeof(arr) / sizeof(int);

    cout << arr[peak(arr, n)];
    return 0;
}