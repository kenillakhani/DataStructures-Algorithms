#include<iostream>
using namespace std;

int fib(int n)
{
     if(n==0 || n==1)
        return n;

    return fib(n-1) + fib(n-2); 

}

// Time complexity = O(2^n)

int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl; 
    return 0;
}