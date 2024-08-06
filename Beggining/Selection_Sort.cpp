#include<iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
    // One by one move boundary of
    // unsorted subarray
    for (i = 0; i < n - 1; i++) {
 
        // Find the minimum element in
        // unsorted array
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
 
        // Swap the found minimum element
        // with the first element
        if (min_idx != i)
            swap(arr[min_idx], arr[i]);
    }
}


int main()
{
    int arr[] = {23,54,12,11,8,5,67,43};
    int n = sizeof(arr)/sizeof(int);

    selectionSort(arr,n);
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";

    cout<<endl;    
return 0;
}
// Time Complexity = O(n^2)
// Best case = O(n^2)
// Worst case = O(n^2) --> Same.

// Space Compexity = O(1)  Extra space n par dependent thay evi rite nathi lidhi..

// USE --> When array has small size then we use Selection sort.