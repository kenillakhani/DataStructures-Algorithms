#include<iostream>
#include<vector>

using namespace std;

int fib(int n,vector<int> &dp)
{
    if(n==0 || n==1)
    {
        return n;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n]=fib(n-1,dp)+fib(n-2,dp);
    return dp[n];
}

int main()
{
    int n;
    cin>>n;

    // # Recursion && Memoization (Top Down Approach)

    // vector<int> dp(n+1,-1);
    // cout<<fib(n,dp)<<endl;

    // # Tabulation (Bottom Up Approach)

    // vector<int> dp(n+1);

    // dp[1] = 1;
    // dp[0] = 0;
    // for(int i=2;i<=n;i++)
    // {
    //     dp[i] = dp[i-1]+dp[i-2];
    // }
    // cout<<dp[n]<<endl;

    // # Space Optimization

    int prev1 = 0;
    int prev2 = 1;
    int curr = 1;

    if(n==0)
        curr = 0;

    for(int i=2;i<=n;i++)
    {
        curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }
    cout<<curr<<endl;

    return 0;
}