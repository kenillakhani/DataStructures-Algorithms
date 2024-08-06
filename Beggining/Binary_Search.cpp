#include <iostream>
using namespace std;

int binary(int arr[], int n, int key)
{
    int s = 0;
    int e = n - 1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
        mid = s + (e - s) / 2; // Error
    }
    return -1;
}
/*
    s=2^31 -1;
    e=2^31 -1;
    then mid = (s+e)/2 --> Error
*/

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(int);
    int key;
    cin >> key;

    cout << binary(arr, n, key);

    return 0;
}