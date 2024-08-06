#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the value of n:";
    cin>>n;
    //cout<<n;
    int i=0;
    int ans=0;
    while(n!=0)
    {
        int rem = n%10;
        ans = rem*pow(2,i)+ans;
        n/=10;
        i++;
    }
    cout<<ans<<endl;
}