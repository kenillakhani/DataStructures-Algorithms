#include <iostream>
using namespace std;

int quick(int *arr, int s, int e)
{
    int pivot = arr[s];
    int cnt = 0;
    for (int i = s + 1; i <= e; i++)
    {
        if (arr[i] <= pivot)
            cnt++;
    }

    int pindex = s + cnt;

    swap(arr[s], arr[pindex]);

    int i = s;
    int j = e;

    while (i < pindex && j > pindex)
    {
        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < pindex && j > pindex)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pindex;
}

void quickS(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int p = quick(arr, s, e);

    quickS(arr, s, p - 1);
    quickS(arr, p + 1, e);
}

int main()
{
    int arr[] = {3, 9, 12, 3, 1, 8};
    int n = sizeof(arr) / sizeof(int);

    quickS(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    cout << endl;

    return 0;
}