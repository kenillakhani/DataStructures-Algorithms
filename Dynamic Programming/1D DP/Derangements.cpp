#include <iostream>
#include <vector>

using namespace std;

int solve(int n)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }
    
    return (n-1)*(solve(n-1)+solve(n-2));
}

int solveMem(int n, vector<int> &dp)
{
    if(n==1)
    {
        return 0;
    }
    if(n==2)
    {
        return 1;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n] = (n-1)*(solveMem(n-1,dp)+solveMem(n-2,dp));
    return dp[n];
}

int solveTab(int n)
{
    vector<int> dp(n+1,-1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3;i<=n;i++)
    {
        dp[i] = (i-1)*(dp[i-1]+dp[i-2]);
    }

    return dp[n];
}

int countDerangements(int n)
{
    // Recursive approach
    // int ans = solve(n);
    // return ans;

    // Memoization approach
    // vector<int> dp(n+1,-1);
    // int ans = solveMem(n,dp);
    // return ans;

    // Tabulation approach
    int ans = solveTab(n);
    return ans;
}

int main()
{
    int n = 4;
    cout<<countDerangements(n)<<endl;
    return 0;
}