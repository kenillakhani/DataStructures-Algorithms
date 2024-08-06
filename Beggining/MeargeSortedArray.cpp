#include<iostream>
using namespace std;

int * merge(int arr1[],int a,int arr2[],int b)
{
    int *ans = new int[a+b];
    int i=0;
    int j=0;
    int k=0;
    while((i < a) && (j < b))
    {
        if(arr1[i] < arr2[j])
        {
            ans[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
            ans[k]=arr2[j];
            j++;
            k++;
        }
    }
    while(i<a)
    {
        ans[k]=arr1[i];
        i++;
        k++;
    }
    while(j<b)
    {
        ans[k]=arr2[j];
        j++;
        k++;
    }
    return ans;
}

int main()
{
    int arr1[5]={1,2,3,4,5};
    int arr2[5]={0,6,7,8,9};

    int a=sizeof(arr1)/sizeof(int);
    int b=sizeof(arr2)/sizeof(int);

    int *arr3 = merge(arr1,a,arr2,b);

    for(int i=0;i<a+b;i++)
    {
        cout<<arr3[i]<<" ";
    }
    cout<<endl;
    return 0;
}