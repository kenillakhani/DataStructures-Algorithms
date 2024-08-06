#include<iostream>
using namespace std;
int main()
{
    int n = 10;
    void *ptr = &n;

    cout<<"This is how we have to typecast: "<<*(int*)ptr<<endl;   
    return 0;
}