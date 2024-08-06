#include<iostream>
using namespace std;
int main()
{
    int num = 5;
    int *ptr = &num;

    cout<<"Address is: "<<ptr<<endl;    // OR
    cout<<"Address is: "<<&num<<endl;

    cout<<"Value is: "<<*ptr<<endl;

    double d = 5.6;
    double *p = &d;

    cout<<"Address is: "<<p<<endl;
    cout<<"Value is: "<<*p<<endl;

    cout<<"Size of ptr is: "<<sizeof(ptr)<<endl;  // Always 8 Byte
    cout<<"Size of p is: "<<sizeof(p)<<endl;

    return 0;
}