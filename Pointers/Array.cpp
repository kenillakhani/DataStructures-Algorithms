#include<iostream>
using namespace std;

int main()
{
    int arr[10] = {2,5,6};

    // 1st Way..
    cout<<"Address of 1st Memory block of Array is: "<<arr<<endl;

    // 2nd Way..
    cout<<"Address of 1st Memory block of Array is: "<<&arr[0]<<endl;

    cout<<*arr<<endl;
    cout<<++(*arr)<<endl;
    cout<<*(arr+1)<<endl;
    cout<<arr[2]<<" - "<<*(arr+2)<<endl; 
    
    // arr[i] = *(arr+i); so,
    // i[arr] = *(i+arr) = arr[i]   Very Important

    cout<<2[arr]<<endl;

    int *p = &arr[0];
    cout<<sizeof(arr)<<endl;
    cout<<sizeof(*arr)<<endl;
    cout<<sizeof(p)<<endl;
    cout<<sizeof(*p)<<endl;
    cout<<sizeof(&p)<<endl;

    cout<<&arr[0]<<endl;
    cout<<arr<<endl;
    cout<<&arr<<endl; // All 3 are Same.

    // entry in symbol table can not be changed.

    // arr = arr+1;  --> Gives error
    // p=p+1   -->Possible


    return 0;
}