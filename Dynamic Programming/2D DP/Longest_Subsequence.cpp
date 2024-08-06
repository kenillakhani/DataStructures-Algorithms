#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(int n, int a[], int index, int prev)
{
    if (index == n)
        return 0;

    int include = 0;

    if (prev == -1 || a[index] > a[prev])
        include = 1 + solve(n, a, index + 1, index);

    int exclude = solve(n, a, index + 1, prev);

    int ans = max(include, exclude);
    return ans;
} 

int solveMem(int n, int a[], int index, int prev, vector<vector<int> > &dp)
{
    if (index == n)
        return 0;

    if (dp[index][prev+1] != -1)
        return dp[index][prev+1];

    int include = 0;

    if (prev == -1 || a[index] > a[prev])
        include = 1 + solveMem(n, a, index + 1, index, dp);

    int exclude = solveMem(n, a, index + 1, prev, dp);

    int ans = max(include, exclude);
    return dp[index][prev+1] = ans;
}

int solveTab(int n, int a[])
{
    vector<vector<int> > dp(n+1, vector<int>(n+1, 0));

    for (int curr = n-1; curr >= 0; curr--)
    {
        for (int prev = curr-1; prev >= -1; prev--)
        {
            int include = 0;

            if (prev == -1 || a[curr] > a[prev])
                include = 1 + dp[curr+1][curr+1];

            int exclude = dp[curr+1][prev+1];

            dp[curr][prev+1] = max(include, exclude);
        }
    }
    return dp[0][0];
}

int solveSpaceOpt(int n, int a[])
{
    vector<int> currRow(n+1, 0);
    vector<int> nextRow(n+1, 0);

    for (int curr = n-1; curr >= 0; curr--)
    {
        for(int prev = curr-1; prev >= -1; prev--)
        {
            int include = 0;

            if (prev == -1 || a[curr] > a[prev])
                include = 1 + nextRow[curr+1];

            int exclude = nextRow[prev+1];

            currRow[prev+1] = max(include, exclude);
        }
        nextRow = currRow;
    }
    return nextRow[0];
}

int solveOpt(int n, int a[])
{
    if(n==0)
        return 0;
    
    vector<int> ans;
    ans.push_back(a[0]);

    for(int i=1; i<n; i++)
    {
        if(a[i] > ans.back())
            ans.push_back(a[i]);
        else
        {
            // find index of just badaa element in ans

            int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
            ans[index] = a[i];
        } 
    }
    return ans.size();
}

// Time Complexity: O(n*log(n))
// Space Complexity: O(n)

int longestSubsequence(int n, int a[])
{
    // vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
    // return solveMem(n,a,0,-1,dp);

    // return solveTab(n,a); 

    return solveOpt(n,a);
}

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << longestSubsequence(n, a) << endl;
    return 0;
}