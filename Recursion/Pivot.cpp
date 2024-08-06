#include <iostream>
using namespace std;

int getPivot(int *arr, int s, int n)
{
    if (s >= n)
        return s;

    int mid = s + (n - s) / 2;

    if (arr[mid] < arr[0])
    {
        return getPivot(arr, s, mid);
    }
    else
    {
        return getPivot(arr, mid + 1, n);
    }
}

int main()
{
    int arr[] = {7, 9, 17, 1, 4, 5, 7};
    int n = sizeof(arr) / sizeof(int);

    cout << getPivot(arr, 0, n - 1) << endl;

    return 0;
}