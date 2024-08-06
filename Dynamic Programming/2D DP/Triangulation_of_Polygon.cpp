#include<iostream>
#include<vector>
#include<climits>

using namespace std;

int solveMem(vector<int> &v, int i, int j, vector<vector<int> > &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }

    if (dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;

    for (int x = i + 1; x <= j - 1; x++)
    {
        ans = min(ans, v[i] * v[j] * v[x] + solveMem(v, i, x, dp) + solveMem(v, x, j, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}

int solveTab(vector<int> &v)
{
    int n = v.size();
    vector<vector<int> > dp(n, vector<int>(n, 0));

    for(int i=n-1;i>=0;i--)
    {
        for(int j=i+2;j<n;j++)
        {
            int ans = INT_MAX;
            for(int x=i+1;x<=j-1;x++)
            {
                ans = min(ans,v[i]*v[j]*v[x]+dp[i][x]+dp[x][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n-1];
}

int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int> > dp(n, vector<int>(n, -1));
    return solveMem(values, 0, n - 1, dp);

    // return solveTab(values);
}

int main()
{
    vector<int> values;
    values.push_back(1);
    values.push_back(3);
    values.push_back(2);
    values.push_back(4);
    
    cout << minScoreTriangulation(values) << endl;
    return 0;
}