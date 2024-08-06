#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int solve(int n, vector<int> &dp)
{
    if(n == 0)
        return 0;

    if(dp[n] != -1)
        return dp[n];

    int ans = INT_MAX;

    for(int i=1;i*i<=n;i++)
    {
        ans = min(ans, solve(n - i*i,dp) + 1);
    }

    dp[n] = ans;
    return ans;
}

int solveTab(int n)
{
    vector<int> dp(n+1, INT_MAX);
    dp[0] = 0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j*j<=i;j++)
        {
            if(i - j*j >= 0)
                dp[i] = min(dp[i], dp[i - j*j] + 1);
        }
    }
    return dp[n];
}

int minSquares(int n)
{
    vector<int> dp(n+1, -1);
    return solveTab(n);
}

int main()
{
    int n;
    cin >> n;

    cout << minSquares(n) << endl;
    return 0;
}