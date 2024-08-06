#include<iostream>
using namespace std;

int n = 1000000;
int spf[1000000];
void createSeive()
{
    for(int i=0;i<=n;i++)
        spf[i] = i;
    
    for(int i=2;i*i<=n;i++)
    {
        if(spf[i] == i)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                if(spf[j] == j)
                    spf[j] = i;
            }
        }
    }

}
int main()
{
    createSeive();
    int t;
    while(t--)
    {
        int x;
        cin>>x;
        while(x!=1)
        {
            cout<<spf[x]<<" ";
            x = x/spf[x];
        }
        cout<<endl;
    }
    return 0;
}