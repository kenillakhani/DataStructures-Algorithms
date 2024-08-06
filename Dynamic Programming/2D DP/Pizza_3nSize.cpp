#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int solve(int index, int endIndex, vector<int>& slices, int n,vector<vector<int> > &dp)
    {
        if(n==0 || index > endIndex)
            return 0;

        if(dp[index][n] != -1)
            return dp[index][n];
        
        int take = slices[index] + solve(index+2,endIndex, slices, n-1,dp);
        int notTake = solve(index+1,endIndex, slices, n, dp);

        return dp[index][n] = max(take,notTake);
    }

int solveTab(vector<int> &slices)
{
    int k = slices.size();
    vector<vector<int> > dp1(k+2,vector<int>(k/3+1,0));
    vector<vector<int> > dp2(k+2,vector<int>(k/3+1,0));

    for(int i=k-2;i>=0;i--)
    {
        for(int j=1;j<=k/3;j++)
        {
            int take = slices[i] + dp1[i+2][j-1];
            int notTake = dp1[i+1][j];
            dp1[i][j] = max(take,notTake);
        }
    }
    int case1 = dp1[0][k/3];

    for(int i=k-1;i>=1;i--)
    {
        for(int j=1;j<=k/3;j++)
        {
            int take = slices[i] + dp2[i+2][j-1];
            int notTake = dp2[i+1][j];
            dp2[i][j] = max(take,notTake);
        }
    }
    int case2 = dp2[1][k/3];

    return max(case1,case2);
}

    int solveSpaceOpt(vector<int> &slices)
{
    int k = slices.size();

    vector<int> prev1(k+2,0);
    vector<int> curr1(k+2,0);
    vector<int> next1(k+2,0);

    for(int i=k-2;i>=0;i--)
    {
        for(int j=1;j<=k/3;j++)
        {
            int take = slices[i] + next1[j-1];
            int notTake = curr1[j];
            prev1[j] = max(take,notTake);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    int case1 = curr1[k/3];

    vector<int> prev2(k+2,0);
    vector<int> curr2(k+2,0);
    vector<int> next2(k+2,0);

    for(int i=k-1;i>=1;i--)
    {
        for(int j=1;j<=k/3;j++)
        {
            int take = slices[i] + next2[j-1];
            int notTake = curr2[j];
            prev2[j] = max(take,notTake);
        }
        next2 = curr2;
        curr2 = prev2;
    }
    int case2 = curr2[k/3];

    return max(case1,case2);
}

    int maxSizeSlices(vector<int>& slices) {
        
        int k = slices.size();

        vector<vector<int> > dp1(k+1,vector<int>(k/3+1,-1));
        int case1 = solve(0,k-2,slices,k/3,dp1);

        vector<vector<int> > dp2(k+1,vector<int>(k/3+1,-1));
        int case2 = solve(1,k-1,slices,k/3,dp2);

        return max(case1,case2);
    }