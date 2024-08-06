// To use Binary search in Question there is an hint like given in question..
// like as.
// 1. find minimum of all maximum of all possible case
// 2. find maximum of all minimum of all possible cases

// Important Question on Binary Search..

#include <iostream>
using namespace std;

int *sorti(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    return arr;
}
bool isPossible(int arr[], int n, int c, int mid)
{
    int cowCount = 1;
    int lastPoss = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - lastPoss >= mid)
        {
            cowCount++;
            if (cowCount == c)
                return true;

            lastPoss = arr[i];
        }
    }
    return false;
}
int agressiveCow(int arr[], int n, int c)
{
    sorti(arr, n);
    int s = 0;
    int e = arr[n - 1] - arr[0];
    int ans = -1;
    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        if (isPossible(arr, n, c, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main()
{
    int arr[] = {4, 2, 1, 3, 7};
    int n = sizeof(arr) / sizeof(int);

    int c = 3;
    cout << agressiveCow(arr, n, c) << endl;
    return 0;
}