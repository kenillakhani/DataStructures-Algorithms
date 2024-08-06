#include<iostream>
#include<vector>

using namespace std;

bool solve(int index, int arr[], int n, int target, vector<vector<int> > &dp)
{
    if(index >= n || target < 0)
        return 0;
    
    if(target == 0)
        return 1;

    if(dp[index][target] != -1)
        return dp[index][target];
    
    bool inc = solve(index + 1, arr, n, target - arr[index], dp);
    bool exc = solve(index + 1, arr, n, target, dp);

    dp[index][target] = inc || exc;
    return dp[index][target];
}

bool solveTab(int n, int arr[], int target)
{
    // Space Optimization Possible
    // Do it at your own
    
    vector<vector<bool> > dp(n + 1, vector<bool>(target + 1, 0));

    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = 1; j <= target; j++)
        {
            bool inc = 0;
            if (j - arr[i] >= 0)
                inc = dp[i + 1][j - arr[i]];
            
            bool exc = dp[i + 1][j];

            dp[i][j] = inc || exc;
        }
    }
    return dp[0][target];
}


int equalPartition(int n, int arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    
    if (sum & 1)
        return 0;

    int target = sum / 2;

    // vector<vector<int> > dp(n + 1, vector<int>(target + 1, -1));

    // return solve(0, arr, n, target, dp);

    return solveTab(n, arr, target);
}

int main()
{
    int n = 4;
    int arr[] = {1, 5, 11, 5};

    cout << equalPartition(n, arr) << endl;

    return 0;
}