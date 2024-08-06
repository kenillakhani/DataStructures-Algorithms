#include <iostream>
using namespace std;
int bubbleSort(int arr[],int n)
{
    int count =0;
    for(int i=1;i<n;i++)
    {
        bool swappped = false;
        for(int j=0;j<n-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                count++;
                swappped = true;
            }
        }
        if(swappped == false)
        {
            break;   // Optimised
        }
    }
    return count;

}

// Time Complexity = O(n^2)
// Best case --> already Sorted = O(n)  --> break na lidhe
// Worst case --> decending order = O(n^2)

// Space Complexity = O(1)

int main()
{
    int arr[] = {8,22,7,9,31,5,13};
    int n = sizeof(arr) / sizeof(int);

    int count = bubbleSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout<<count<<endl;
    return 0;
}