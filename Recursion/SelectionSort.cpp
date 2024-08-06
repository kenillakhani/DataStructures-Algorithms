#include <iostream>
using namespace std;

void selection(int *arr, int n)
{
    if (n == 0 || n == 1)
        return;

    int min = 100000;
    int m = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            m = i;
        }
    }

    swap(arr[0], arr[m]);

    return selection(arr + 1, n - 1);
}

int main()
{
    int arr[] = {3, 7, 4, 12, 8, 1};
    int n = sizeof(arr) / sizeof(int);

    selection(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}