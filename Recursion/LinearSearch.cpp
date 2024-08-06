#include<iostream>
using namespace std;

bool search(int* arr,int size,int n)
{
    if(size==0)
        return false;
    
    if(n==arr[0])
        return true;

    return search(arr+1,size-1,n);

}

int main()
{
    int arr[] = {2,4,7,9,23};
    int n;
    int size = 5;
    cin>>n;
    if(search(arr,size,n))
        cout<<"Found"<<endl;
    else
        cout<<"Not Found"<<endl;

    return 0;
}