#include<iostream>
using namespace std;
bool pow(int n)
{
    int count = 0;
    for(int i=0;i<31;i++)
    {
        if(n&1)
            count++;

        n=n>>1;    
    }
    if(count==1)
        return 1;

    return 0;
}

int main()
{
    int x;
    cin>>x;
    if(pow(x))
        cout<<"Yes.\n";
    else
        cout<<"No.\n";

// 2nd Methode is available Also....!!!

    return 0;
}