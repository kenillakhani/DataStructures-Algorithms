#include <iostream>
using namespace std;

void rotateArray(int arr[], int n, int key)
{
    int *temp = new int[n];
    for (int i = 0; i < n; i++)
    {
        temp[(i + key) % n] = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}
int main()
{
    int arr[] = {1, 56, 99, 23, 45};
    int key = 3;

    int n = sizeof(arr) / sizeof(int);

    rotateArray(arr, n, key);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}