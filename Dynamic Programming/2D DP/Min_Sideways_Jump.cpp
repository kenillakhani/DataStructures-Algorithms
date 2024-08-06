#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int solve(vector<int> &obstacles, int currLane, int currPos, vector<vector<int> > &dp)
{
    int n = obstacles.size();

    if (currPos == n - 1)
    {
        return 0;
    }

    if (dp[currLane][currPos] != -1)
        return dp[currLane][currPos];

    if (obstacles[currPos + 1] != currLane)
        return solve(obstacles, currLane, currPos + 1, dp);

    else
    {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (currLane != i && obstacles[currPos] != i)
            {
                ans = min(ans, 1 + solve(obstacles, i, currPos, dp));
            }
        }
        dp[currLane][currPos] = ans;
        return dp[currLane][currPos];
    }
}

int solveTab(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<vector<int> > dp(4, vector<int>(n, INT_MAX));

    for (int i = 0; i < 4; i++)
    {
        dp[i][n - 1] = 0;
    }

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (obstacles[i + 1] != j)
            {
                dp[j][i] = dp[j][i + 1];
            }
            else
            {
                dp[j][i] = INT_MAX;
                for (int k = 1; k <= 3; k++)
                {
                    if (j != k && obstacles[i] != k)
                    {
                        dp[j][i] = min(dp[j][i], 1 + dp[k][i+1]);
                    }
                }
            }
        }
    }
    return min(dp[2][0], min(1+dp[1][0], 1+dp[3][0]));
}

int Optimized(vector<int> &obstacles)
{
    int n = obstacles.size();
    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);   

    next[0] = 0;
    next[1] = 0;
    next[2] = 0;
    next[3] = 0;

    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 1; j <= 3; j++)
        {
            if (obstacles[i + 1] != j)
            {
                curr[j] = next[j];
            }
            else
            {   
                curr[j] = INT_MAX;
                for (int k = 1; k <= 3; k++)
                {
                    if (j != k && obstacles[i] != k)
                    {
                        curr[j] = min(curr[j], 1 + next[k]);
                    }
                }
            }
        }
        next = curr;
    }
    return min(next[2], min(1+next[1], 1+next[3]));
}

int minSideJumps(vector<int> &obstacles)
{

    vector<vector<int> > dp(4, vector<int>(obstacles.size() + 1, -1));
    return solve(obstacles, 2, 0, dp);

    // return solveTab(obstacles);

    // return Optimized(obstacles); 
}