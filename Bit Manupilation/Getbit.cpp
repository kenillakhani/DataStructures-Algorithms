#include<iostream>
using namespace std;
bool getbit(int n,int pos)
{
    return (n & (1<<pos));
}
int main()
{
    cout<<getbit(6,1)<<endl;   
    return 0;
}