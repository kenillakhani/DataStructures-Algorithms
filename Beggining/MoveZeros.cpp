#include<iostream>
using namespace std;

void moveZeros(int arr[], int n)
{
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main()
{
    int arr[] = {0, 2, 0, 0, 4, 18, 0, 34, 0, 0, 67};
    // We have to move all zeros from the array to the right side of the array.

    // new THING:
    // Array as refernce !!!!!

    int n = sizeof(arr) / sizeof(int);

    moveZeros(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout<<endl;

    return 0;
}
