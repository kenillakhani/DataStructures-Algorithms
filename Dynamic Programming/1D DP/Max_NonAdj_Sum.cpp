#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solveMem(vector<int> &nums, int n, vector<int> &dp)
{
    if(n<0)
    {
        return 0;
    }
    if(n==0)
    {
        return nums[0];
    }
    if(dp[n]!=-1)
    {
        return dp[n];
    }

    int incl = solveMem(nums,n-2,dp) + nums[n];
    int excl = solveMem(nums,n-1,dp);

    dp[n] = max(incl,excl);
    return dp[n];
}

int solveTab(vector<int> &nums, int n)
{
    vector<int> dp(n+1,-1);
    dp[0] = nums[0];
    dp[1] = max(nums[0],nums[1]);

    for(int i=2;i<n;i++)
    {
        dp[i] = max(dp[i-2]+nums[i],dp[i-1]);
    }

    return dp[n-1];
}

int solveSpaceOptimized(vector<int> &nums, int n)
{
    int a = nums[0];
    int b = 0;

    for(int i=1;i<n;i++)
    {
        int c = max(b+nums[i],a);
        b = a;
        a = c;
    }

    return a;
}

int maxNonAdjSum(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n,-1);

    int ans = solveMem(nums,n-1,dp);

    // int ans = solveTab(nums,n);
    // int ans = solveSpaceOptimized(nums,n);
    
    return ans;
}