#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        int space = n-i;
        while(space)
        {
            cout<<" ";
            space--;
        }
        int j=1;
        while (j<=i)
        {
            cout<<j;
            j++;
        }
        int k=i-1;
        while(k)
        {
            cout<<k;
            k--;
        }
        cout<<endl;
    }
    
}
