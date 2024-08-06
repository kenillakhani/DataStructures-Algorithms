#include<iostream>
#include<climits>
#include<vector>

using namespace std;
    
int solve(int x, int y, int z, int n)
{
    if(n==0)
    {
        return 0;
    }

    if(n<0)
    {
        return INT_MIN;
    }

    int a = solve(x,y,z,n-x);
    int b = solve(x,y,z,n-y);
    int c = solve(x,y,z,n-z);

    return 1+max(a,max(b,c));
}

int solveMem(int x, int y, int z, int n, vector<int> &dp)
{
    if(n==0)
    {
        return 0;
    }

    if(n<0)
    {
        return INT_MIN;
    }

    if(dp[n]!=-1)
    {
        return dp[n];
    }

    int a = solveMem(x,y,z,n-x,dp);
    int b = solveMem(x,y,z,n-y,dp);
    int c = solveMem(x,y,z,n-z,dp);

    dp[n] = 1+max(a,max(b,c));
    return dp[n];
}

int solveTab(int x, int y, int z, int n)
{
    vector<int> dp(n+1,INT_MIN);
    dp[0] = 0;

    for(int i=1;i<=n;i++)
    {
        int a = INT_MIN, b = INT_MIN, c = INT_MIN;

        if(i-x>=0)
        {
            a = dp[i-x];
        }

        if(i-y>=0)
        {
            b = dp[i-y];
        }

        if(i-z>=0)
        {
            c = dp[i-z];
        }

        dp[i] = 1+max(a,max(b,c));
    }
    if(dp[n]<0)
    {
        return 0;
    }
    return dp[n];
}

int cutSegments(int n, int x, int y, int z)
{
    // Recursive
    // return solve(x, y, z, n);

    // Memoization
    // vector<int> dp(n+1,-1);
    // int ans = solveMem(x, y, z, n, dp); 
    // if(ans<0)
    // {
    //     return 0;
    // }
    // return ans;   

    // Tabulation                          
    return solveTab(x, y, z, n);
}

int main()
{
    int n = 7, x = 2, y = 3, z = 5;
    cout<<cutSegments(n, x, y, z)<<endl;
    return 0;
}