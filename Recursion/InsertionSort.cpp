#include <iostream>
using namespace std;

void insertion(int *arr, int c, int n)
{
    if (c == n)
        return;

    int temp = arr[c];
    int i = c - 1;
    while (i >= 0 && arr[i] > temp)
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = temp;

    return insertion(arr, ++c, n);
}

int main()
{
    int arr[] = {6, 2, 9, 11, 1, 5};
    int n = sizeof(arr) / sizeof(int);

    insertion(arr, 1, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}