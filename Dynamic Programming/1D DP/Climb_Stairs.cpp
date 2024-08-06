#include<iostream>
# define MOD 1000000007

using namespace std;

int solve(long long stairs,int i)
{
    if(i>stairs)
    {
        return 0;
    }
    if(i==stairs)
    {
        return 1;
    }
    return (solve(stairs,i+1)+solve(stairs,i+2)) % MOD;
}

int countDistinctWayToClimbStairs(long long stairs)
{
    int ans = solve(stairs,0);
    return ans;
}

int main()
{
    long long stairs;
    cin>>stairs;
    cout<<countDistinctWayToClimbStairs(stairs)<<endl;
    return 0;
}