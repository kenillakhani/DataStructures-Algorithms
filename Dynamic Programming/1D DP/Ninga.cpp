// # Ninga has to paint the n walls with k different colours. 
//   He has to paint the walls in such a way that no more than two adjacent walls have the same colour. 
//   Find the number of ways in which he can paint the walls.

#include <iostream>
#include <vector>

using namespace std;

int solve(int n, int k)
{
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
        return k*k;
    }

    return (k-1)*(solve(n-1,k)+solve(n-2,k));
}

int solveMem(int n, int k, vector<int> &dp)
{
    if(n==1)
    {
        return k;
    }
    if(n==2)
    {
        return k*k;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    dp[n] = (k-1)*(solveMem(n-1,k,dp)+solveMem(n-2,k,dp));
    return dp[n];
}

int solveTab(int n, int k)
{
    vector<int> dp(n+1,-1);
    dp[1] = k;
    dp[2] = k*k;

    for(int i=3;i<=n;i++)
    {
        dp[i] = (k-1)*(dp[i-1]+dp[i-2]);
    }

    return dp[n];
}

int numberOfWays(int n, int k)
{
    // Recursive approach
    // int ans = solve(n,k);
    // return ans;

    // Memoization approach
    // vector<int> dp(n+1,-1);
    // int ans = solveMem(n,dp);
    // return ans;

    // Tabulation approach
    int ans = solveTab(n,k);
    return ans;
}

int main()
{
    int n = 3;
    int k = 3;

    cout<<numberOfWays(n,k)<<endl;

    return 0;
}