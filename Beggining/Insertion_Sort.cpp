#include<iostream>
using namespace std;
void insertionSort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int temp = arr[i];
        while(j>=0)
        { 
            if(arr[j]>temp)
            {
                arr[j+1]=arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
    }
}
int main()
{
    int arr[] = {8,22,7,9,31,5,13};
    int n = sizeof(arr) / sizeof(int);

    insertionSort(arr, n);
 
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}