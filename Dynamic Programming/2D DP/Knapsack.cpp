#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int W)
{
    if(index==0)
    {
        if(weight[0]<=W)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    int include = 0;

    if(weight[index]<=W)
    {
        include = value[index]+solve(weight,value,index-1,W-weight[index]);
    }
    int exclude = solve(weight,value,index-1,W);

    return max(include,exclude);
}

int solveMem(vector<int> &weight, vector<int> &value, int index, int W, vector<vector<int> > &dp)
{
    if(index==0)
    {
        if(weight[0]<=W)
        {
            return value[0];
        }
        else
        {
            return 0;
        }
    }

    if(dp[index][W]!=-1)
    {
        return dp[index][W];
    }

    int include = 0;

    if(weight[index]<=W)
    {
        include = value[index]+solveMem(weight,value,index-1,W-weight[index],dp);
    }
    int exclude = solveMem(weight,value,index-1,W,dp);

    dp[index][W] = max(include,exclude);
    return dp[index][W];
}

int solveTab(vector<int> &weight, vector<int> &value, int n, int W)
{
    vector<vector<int> > dp(n,vector<int>(W+1,0));

    for(int i=0;i<=W;i++)
    {
        if(weight[0]<=i)
        {
            dp[0][i] = value[0];
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            int include = 0;

            if(weight[i]<=j)
            {
                include = value[i]+dp[i-1][j-weight[i]];
            }
            int exclude = dp[i-1][j];

            dp[i][j] = max(include,exclude);
        }
    }
    return dp[n-1][W];
}

int solveSpaceOptimize(vector<int> &weight, vector<int> &value, int n, int W)
{
    vector<int> dp(W+1,0);

    for(int i=0;i<=W;i++)
    {
        if(weight[0]<=i)
        {
            dp[i] = value[0];
        }
    }

    for(int i=1;i<n;i++)
    {
        for(int j=W;j>=1;j--)
        {
            int include = 0;

            if(weight[i]<=j)
            {
                include = value[i]+dp[j-weight[i]];
            }
            int exclude = dp[j];

            dp[j] = max(include,exclude);
        }
    }
    return dp[W];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Recursive approach
    // int ans = solve(weight,value,n-1,maxWeight);
    // return ans;

    // Memoization approach
    // vector<vector<int> > dp(n,vector<int>(maxWeight+1,-1));
    // return solveMem(weight,value,n-1,maxWeight,dp);

    // Tabulation approach
    // return solveTab(weight,value,n,maxWeight);

    // Space optimized approach
    return solveSpaceOptimize(weight,value,n,maxWeight);
}

int main()
{
    vector<int> weight;
    weight.push_back(10);
    weight.push_back(20);
    weight.push_back(30);

    vector<int> value;
    value.push_back(60);
    value.push_back(100);
    value.push_back(90);

    int n = weight.size();
    int maxWeight = 40;

    cout<<knapsack(weight,value,n,maxWeight)<<endl;

    return 0;
}