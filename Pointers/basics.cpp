#include<iostream>
using namespace std;
int main()
{
    int i=5;
    int *q=&i;

    cout<<q<<endl;
    cout<<*q<<endl;

//  int *p; only  "Do not Assign like this"

    int *p=0;
    p=&i;

    cout<<p<<endl;
    cout<<*p<<endl;

    (*p)++;  // i ni value change thia jaay....
    cout<<i<<endl;
    (*p)*=2; 
    cout<<i<<endl;

    return 0;
}