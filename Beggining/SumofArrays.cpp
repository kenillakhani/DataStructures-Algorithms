#include <iostream>
using namespace std;

void SumofArray(int arr1[], int arr2[], int a, int b)
{
    int *arr3 = new int[max(a, b)+1];
    int i = a - 1, j = b - 1, k = 0;
    int carry = 0;
 
    while (i >= 0 && j >= 0)
    {
        arr3[k] = arr1[i] + arr2[j] + carry;
        carry = arr3[k] / 10;
        arr3[k] = arr3[k] % 10;
        i--;
        j--;
        k++;
    }
    while(i>=0)
    {
        arr3[k] = arr1[i] + carry;
        carry = arr3[k] / 10;
        arr3[k] = arr3[k] % 10;
        i--;
        k++;
    }
     while(j>=0)
    {
        arr3[k] = arr2[j] + carry;
        carry = arr3[k] / 10;
        arr3[k] = arr3[k] % 10;
        j--;
        k++;
    }
    while (carry)
    {
        arr3[k] = carry % 10;
        carry = carry / 10;
        k++;
    }
    
    k--;
    while (k >= 0)
    {
        cout << arr3[k];
        k--;
    }
    cout << endl;
}

int main()
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {9, 7, 8, 9, 0};

    int a = sizeof(arr1) / sizeof(int);
    int b = sizeof(arr2) / sizeof(int);

    SumofArray(arr1, arr2, a, b);

    return 0;
}