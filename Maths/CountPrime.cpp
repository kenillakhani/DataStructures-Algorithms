// Sieve of Eratosthenes..
// Complexity = n * log(logn)

#include<iostream>
using namespace std;

int countPrime(int n)
{
    int cnt=0;
    bool arr[5000001];

    for(int i=0;i<=n;i++)
        arr[i]=true;

    for(int i=2;i*i<=n;i++)
    {
        if(arr[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
            {
                arr[j]=false;
            }
        }
    }
    for(int i=2;i<n;i++)
    {
        if(arr[i]==true)
            cnt++;
    }
    return cnt;
}

int main()
{
    int n;
    cin>>n;

    int x = countPrime(n);
    cout<<x<<endl;
    return 0;
}