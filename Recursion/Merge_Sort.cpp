#include <iostream>
using namespace std;

void merge(int *arr, int s, int e)
{
    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    int *arr1 = new int[len1];
    int *arr2 = new int[len2];

    int k = s;
    for (int i = 0; i < len1; i++)
    {
        arr1[i] = arr[k++];
    }
    for (int j = 0; j < len2; j++)
    {
        arr2[j] = arr[mid + j + 1];
    }

    int i = 0, j = 0;
    k = s;

    while (i < len1 && j < len2)
    {
        if (arr1[i] < arr2[j])
        {
            arr[k++] = arr1[i++];
        }
        else
        {
            arr[k++] = arr2[j++];
        }
    }
    while (i < len1)
    {
        arr[k++] = arr1[i++];
    }
    while (j < len2)
    {
        arr[k++] = arr2[j++];
    }
}

void mergesort(int *arr, int s, int e)
{
    if (s >= e)
        return;

    int mid = (s + e) / 2;

    mergesort(arr, s, mid);
    mergesort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int arr[] = {4, 2, 9, 1, 3, 7};
    int n = sizeof(arr) / sizeof(int);

    mergesort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}