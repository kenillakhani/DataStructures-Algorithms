#include <iostream>
using namespace std;

int getsum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += i[arr];
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n]; // Variable size Array

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Sum: " << getsum(arr, n)<<endl;

    return 0;
}