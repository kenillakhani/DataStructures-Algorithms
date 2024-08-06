#include <iostream>
using namespace std;
void reverse(int arr[], int size, int ind)
{
    int s=ind+1;
    int e=size-1;
    while(s<e)
    {
        swap(arr[s],arr[e]);
        s++;
        e--;
    }
}
void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {23, 65, 43, 56, 78, 90, 1}; // After index m
    int n = sizeof(arr) / sizeof(int);
    int m=2;
    reverse(arr, n, m);

    printArr(arr, n);

    return 0;
}