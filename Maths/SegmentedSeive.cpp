// If we have to find prime numbers in a range from a to b then we can use segmented seive
// Time Complexity: O(sqrt(b) + (b-a))
// Space Complexity: O(sqrt(b))

// Constraints:
// 1 <= a,b <= 10^12
// 1 <= b-a <= 10^6

// Concept:

// 1. Generate prime till square root of b.
// 2. Create a dummy array of size b-a+1 and mark all the elements as true.
// 3. mark all the multiples of prime numbers in (b-a) as false on dummy.

#include<iostream>
using namespace std;

int n=1000000;
bool sieve[1000001];
void createsieve()
{
    for(int i=0;i<=n;i++)
        sieve[i]=true;

    for(int i=2;i*i<=n;i++)
    {
        if(sieve[i]==true)
        {
            for(int j=i*i;j<=n;j+=i)
                sieve[j]=false;
        }
    }
}
vector<int> generatePrimes(int n)
{
    vector<int> ds;
    for(int i=2;i<=n;i++)
    {
        if(sieve[i]==true)
            ds.push_back(i);
    }
    return ds;
    
}
int main()
{
    createsieve();
    int a,b;
    cin>>a>>b;

    // Step1: Generates all prime numbers till square root of b.
    vector<int> primes=generatePrimes(sqrt(b));

    // Step2: Create a dummy array of size b-a+1 and mark all the elements as true.
    int dummy[b-a+1];
    for(int i=0;i<=b-a;i++)
        dummy[i]=1;
    
    // Step3: mark all the multiples of prime numbers in (b-a) as false on dummy.
    for(auto pr:primes)
    {
        int firstMultiple = (a/pr)*pr;
        if(firstMultiple<a)
            firstMultiple+=pr;

        for(int i=max(firstMultiple,pr*pr);i<=b;i+=pr)
            dummy[i-a]=0;
    }

    for(int i=0;i<=b-a;i++)
    {
        if(dummy[i]==1)
            cout<<i+a<<" ";
    }
    cout<<endl;

    return 0;
}