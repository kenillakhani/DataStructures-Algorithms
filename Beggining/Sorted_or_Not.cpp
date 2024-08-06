#include <iostream>
using namespace std;

bool isSorted(int arr[], int n)
{
    int count = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            count++;
        }
    }
    if (arr[0] < arr[n - 1])
        count++;

    if (count <= 1)
        return true;
    else
        return false;
}

int main()
{
    int arr[] = {4, 6, 11, 23, 1, 3};

    int n = sizeof(arr) / sizeof(int);

    if (isSorted(arr, n))
    {
        cout << "Sorted";
    }
    else
    {
        cout << "Not Sorted";
    }
    cout<<endl;
    return 0;
}