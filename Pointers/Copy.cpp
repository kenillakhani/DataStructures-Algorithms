#include<iostream>
using namespace std;

int main()
{
    int num = 5;
    int *p = &num;
    
    int *q=p; // Copy one pointer into Another.

    cout<<p<<" - "<<q<<endl;
    cout<<*p<<" - "<<*q<<endl;

    // Increment in pointer

    p=p+1;
    cout<<p<<endl; // Bcz the pointer is for integer if we incremet by 1 it will increment by 4.

    return 0;   
}